clear, close all, clc;

%% Inverter
VDC = 800; % [V]

% Gate drivers
T_on = 500; % Turn-on propagation delay [ns]
T_off = 100; % Turn-off propagation delay [ns]
R_on = 2; % On driver resistance [Ohm]
R_off = 1; % Off driver resistance [Ohm]

% IGBTs
V_ft = 2; % Transistor forward voltage [V]
V_fd = 2; % Integral diode forward voltage [V]
R_ont = 3e-3; % Transistor on-resistance [Ohm]
R_ond = 5e-3; % Integral diode on-resistance [Ohm]

%% Reference non-linear load values PER PHASE
Vout = 230; % [V] Rated RMS output voltage
Vout_amp = 230*sqrt(2); % [V] Maximum output voltage amplitude, for sine gen
f_o = 50; % [Hz] Output frequency
Uc = 1.22*Vout; % [V] Rectified voltage

S_tot = 8000; % [VA] Total apparent power across full non-linear load (max)
R_nl_s = 0.04*Vout^2/S_tot; % [Ohm] Series line resistor
R_nl_load = Uc^2/(0.66*S_tot); % [Ohm] Non-linear load resistor
C_nl = 7.5/(f_o*R_nl_load); % [F] Non-linear load capacitor

%S_20p = 0.2*S_tot; % [VA] Apparent power across 20% load
%S_80p = 0.8*S_tot; % [VA] Apparent power across 80% load
%
% 20% load
%R_nl_s_20p = 0.04*Vout^2/S_20p; % [Ohm] Series line resistor
%R_nl_load_20p = Uc^2/(0.66*S_20p); % [Ohm] Non-linear load resistor
%C_nl_20p = 7.5/(f_o*R_nl_load_20p); % [F] Non-linear load capacitor
%
% 80% load
%R_nl_s_80p = 0.04*Vout^2/S_80p;
%R_nl_load_80p = Uc^2/(0.66*S_80p);
%C_nl_80p = 7.5/(f_o*R_nl_load_80p);
%
% NOTICE: SERIES RESISTORS HAVE BEEN OVERRIDDEN FOR NOW DUE TO RINGING
%R_nl_s_20p = 1e-3;
%R_nl_s_80p = 1e-3;

R_C_nl = 1e-3; % [Ohm] ESR of non-linear load capacitor
V_f = 1.0; % [V] Forward voltage of rectifier diodes
R_d = 5e-3; % [Ohm] On-resistance of rectifier diodes

% Remaining power must be dissipated in a linear load
overcurrent_factor = 1.5; % 1.5 for peak
P_tot = (50000*overcurrent_factor)/3; % [W]
P_lin = P_tot - S_tot; % [W] Total power across linear load
R_l_nl = Vout^2/P_lin; % [Ohm] Linear load resistor

%% Linear load values PER PHASE when non-linear load is disconnected
% That is, reference test load
P_lin = P_tot; % [W] For when only using linear load

P_lin_20p = 0.2*P_lin; % [W] Power across 20% load
P_lin_80p = 0.8*P_lin; % [W] Power across 80% load

R_l_20p = Vout^2/P_lin_20p; % [Ohm] 20% linear load resistor
R_l_80p = Vout^2/P_lin_80p; % [Ohm] 80% linear load resistor

%% Output filter (see PlantModel.m and Inductance.m)
f_sw = 24000; % [Hz] Switching frequency
T_sw = 1/f_sw; % [s]

% Values
L_c = 90.375*10^-6; % [H]
L_g = 2*10^-6; % [H]
C_c = 30*10^-6; % [F]
C_r = 20*10^-6; % [F]
L_r = (1/(2*pi*f_sw))^2/C_r; % [H] (resulting in 24 kHz resonance frequency)

% Parasitics
R_Lc = 5.6e-3; % [Ohm]
R_Lg = 5.6e-3; % [Ohm]
R_Cc = 9e-3; % [Ohm]
R_Cr = 0.5e-3; % [Ohm]
R_Lr = 2e-3; % [Ohm]

% Converter-side inductor non-linearity tables
N_Lc = 26;
Ae_Lc = 2.940*10^-4; % [m^2]
le_Lc = 14.370e-2; % [m]

Lc_nonlin_H = load("nonlinear_inductor_H.mat").H_nonlinear;
Lc_nonlin_B = load("nonlinear_inductor_B.mat").B_nonlinear;
Lc_nonlin_i = load("nonlinear_inductor_i.mat").I_nonlinear;
Lc_nonlin_phi = load("nonlinear_inductor_phi.mat").phi_nonlinear;

%% Controllers (see ControllerDesign.m)
% Sampling frequency and delay
fs = 4*f_sw; % [Hz]
fs = 96006.141; % [Hz] For Imperix simulation
Ts = 1/fs; % [s]
Td = 2*Ts; % [s] Unused in simulation as ZOH and SimScape inductor account for it
Tcomp = T_sw/8; % [s] Estimate of computation and propagation time


% Proportional controller
Kc = 2.5;


% Lead-Lag
%s = tf('s');
%omega_max = 3.35e4; %0.2*f_sw*2*pi; % For capacitor control % 1/(sqrt((L_c+L_g)*C_c));
%phi_max = 40; % [degrees]
%kv = 3.5;
%
%KT_ll = omega_max/(tan(omega_max*Ts/2));
%kf = (1-sind(phi_max))/(1+sind(phi_max));
%tau_a = 1/(sqrt(kf)*omega_max);
%tau_b = kf*tau_a;
%
%G_ll_s = ((1+s*tau_a)/(1+s*tau_b));
%opt = c2dOptions('Method','tustin','PrewarpFrequency',omega_max);
%G_ll_z = c2d(G_ll_s,Ts,opt);


% Harmonic compensation
omega_c_i = 0.2*2*pi*f_sw;

omega_p5 = f_o*2*pi*5;
omega_w5 = 0.1*2*pi;
Kr5 = omega_c_i/(4*5*15);
omega_p7 = f_o*2*pi*7;
omega_w7 = 0.1*2*pi;
Kr7 = omega_c_i/(4*7*10);

omega_p15 = f_o*2*pi*15;
omega_w15 = 0.1*2*pi;
Kr15 = 40;
omega_p21 = f_o*2*pi*21;
omega_w21 = 0.1*2*pi;
Kr21 = 40;

z = tf('z',Ts);
G_pr_r_5_z = -(2*Kr5*Ts*omega_w5*z*exp(Ts*omega_w5)*(omega_w5*sinh(Ts*(omega_w5^2 - omega_p5^2)^(1/2)) ...
             + cosh(Ts*(omega_w5^2 - omega_p5^2)^(1/2))*(omega_w5^2 - omega_p5^2)^(1/2) ... 
             - z*exp(Ts*omega_w5)*(omega_w5^2 - omega_p5^2)^(1/2)))/((omega_w5^2 - omega_p5^2)^(1/2) ...
             *(exp(2*Ts*omega_w5)*z^2 - 2*exp(Ts*omega_w5)*cosh(Ts*(omega_w5^2 - omega_p5^2)^(1/2))*z + 1));
G_pr_r_7_z = -(2*Kr7*Ts*omega_w7*z*exp(Ts*omega_w7)*(omega_w7*sinh(Ts*(omega_w7^2 - omega_p7^2)^(1/2)) ...
             + cosh(Ts*(omega_w7^2 - omega_p7^2)^(1/2))*(omega_w7^2 - omega_p7^2)^(1/2) ... 
             - z*exp(Ts*omega_w7)*(omega_w7^2 - omega_p7^2)^(1/2)))/((omega_w7^2 - omega_p7^2)^(1/2) ...
             *(exp(2*Ts*omega_w7)*z^2 - 2*exp(Ts*omega_w7)*cosh(Ts*(omega_w7^2 - omega_p7^2)^(1/2))*z + 1));
num5 = abs(G_pr_r_5_z.Numerator{1,1});
den5 = abs(G_pr_r_5_z.Denominator{1,1});
num7 = abs(G_pr_r_7_z.Numerator{1,1});
den7 = abs(G_pr_r_7_z.Denominator{1,1});

G_pr_r_15_z = -(2*Kr15*Ts*omega_w15*z*exp(Ts*omega_w15)*(omega_w15*sinh(Ts*(omega_w15^2 - omega_p15^2)^(1/2)) ...
             + cosh(Ts*(omega_w15^2 - omega_p15^2)^(1/2))*(omega_w15^2 - omega_p15^2)^(1/2) ... 
             - z*exp(Ts*omega_w15)*(omega_w15^2 - omega_p15^2)^(1/2)))/((omega_w15^2 - omega_p15^2)^(1/2) ...
             *(exp(2*Ts*omega_w15)*z^2 - 2*exp(Ts*omega_w15)*cosh(Ts*(omega_w15^2 - omega_p15^2)^(1/2))*z + 1));
G_pr_r_21_z = -(2*Kr21*Ts*omega_w21*z*exp(Ts*omega_w21)*(omega_w21*sinh(Ts*(omega_w21^2 - omega_p21^2)^(1/2)) ...
             + cosh(Ts*(omega_w21^2 - omega_p21^2)^(1/2))*(omega_w21^2 - omega_p21^2)^(1/2) ... 
             - z*exp(Ts*omega_w21)*(omega_w21^2 - omega_p21^2)^(1/2)))/((omega_w21^2 - omega_p21^2)^(1/2) ...
             *(exp(2*Ts*omega_w21)*z^2 - 2*exp(Ts*omega_w21)*cosh(Ts*(omega_w21^2 - omega_p21^2)^(1/2))*z + 1));
num15 = abs(G_pr_r_15_z.Numerator{1,1});
den15 = abs(G_pr_r_15_z.Denominator{1,1});
num21 = abs(G_pr_r_21_z.Numerator{1,1});
den21 = abs(G_pr_r_21_z.Denominator{1,1});


% PR controller
omega_c_o = f_o*20*2*pi; % Target cross-frequency
omega_o = f_o*2*pi; % Fundamental frequency
Kp = 0.9444; % Proportional PR gain

%omega_p = [f_o*2*pi*1 f_o*2*pi*3 f_o*2*pi*5 f_o*2*pi*7]; % Resonant frequency
%KT = [omega_p(1)/(tan(omega_p(1)*Ts/2)) omega_p(2)/(tan(omega_p(2)*Ts/2)) ...
%      omega_p(3)/(tan(omega_p(3)*Ts/2)) omega_p(4)/(tan(omega_p(4)*Ts/2))]; % Pre-warp factor
%Kr = [omega_c_o/(4) omega_c_o/(4*3) omega_c_o/(4*5) omega_c_o/(4*7)]; % Resonant gain
%Kr = [omega_c_o/2 omega_c_o/(4*3*20) (omega_c_o/(4*3*20)) (omega_c_o/(4*3*20))];
%omega_w = [0.1*2*pi 0.1*2*pi 0.1*2*pi 0.1*2*pi]; % Resonance width

omega_p = f_o*2*pi;
Kr = omega_c_o/2;
omega_w = 0.1*2*pi;

G_pr_r_z = -(2*Kr*Ts*omega_w*z*exp(Ts*omega_w)*(omega_w*sinh(Ts*(omega_w^2 - omega_p^2)^(1/2)) ...
             + cosh(Ts*(omega_w^2 - omega_p^2)^(1/2))*(omega_w^2 - omega_p^2)^(1/2) ... 
             - z*exp(Ts*omega_w)*(omega_w^2 - omega_p^2)^(1/2)))/((omega_w^2 - omega_p^2)^(1/2) ...
             *(exp(2*Ts*omega_w)*z^2 - 2*exp(Ts*omega_w)*cosh(Ts*(omega_w^2 - omega_p^2)^(1/2))*z + 1));
num = abs(G_pr_r_z.Numerator{1,1});
den = abs(G_pr_r_z.Denominator{1,1});

% Maximum current (anti-windup saturation)
io_nom = (50000/(Vout*3));
pr_sat_val = ceil(3*io_nom);
Klim = 5; % Anti-windup limiting gain

% PI Controller [legacy]
%Kpc = 2.0678;
%Ki = 7.5398e03;

%% Differentiator
% Generalized Integrator
close all
omega_mark = (2*pi*fs)/2; % Nyquist frequency for maximum flattening
omega_c = (2*pi*fs)/3; % Selected for optimal performance
G_diff_s = tf([omega_mark^2 0],[1 omega_c omega_mark^2]);
G_diff_z = c2d(G_diff_s,Ts,'foh');

% opt = bodeoptions;
% opt.Grid = 'on';
% opt.Title.String = 'Bode plot of continuous and discrete differentiator';
% opt.FreqUnits = 'Hz';
% opt.Title.FontSize = 26;
% opt.XLabel.FontSize = 22;
% opt.YLabel.FontSize = 22;
% bodeplot(G_diff_z, opt)
% Fh = gcf;                                                   % Handle To Current Figure
% Kids = Fh.Children;                                         % Children
% AxAll = findobj(Kids,'Type','Axes');                        % Handles To Axes
% Ax1 = AxAll(1);                                             % First Set Of Axes
% LinesAx1 = findobj(Ax1,'Type','Line');                      % Handle To Lines
% LinesAx1(2).LineWidth = 4;                                  % Set 4LineWidth’
% Ax2 = AxAll(2);                                             % Second Set Of Axes
% LinesAx2 = findobj(Ax2,'Type','Line');                      % Handle To Lines
% LinesAx2(2).LineWidth = 4;    
% hold on
% s = tf('s');
% bodeplot(s, opt)
% Fh = gcf;                                                   % Handle To Current Figure
% Kids = Fh.Children;                                         % Children
% AxAll = findobj(Kids,'Type','Axes');                        % Handles To Axes
% Ax1 = AxAll(1);                                             % First Set Of Axes
% LinesAx1 = findobj(Ax1,'Type','Line');                      % Handle To Lines
% LinesAx1(2).LineWidth = 4;                                  % Set 4LineWidth’
% Ax2 = AxAll(2);                                             % Second Set Of Axes
% LinesAx2 = findobj(Ax2,'Type','Line');                      % Handle To Lines
% LinesAx2(2).LineWidth = 4;                                  % Set 4LineWidth’

% Lead-lag based for resonance damping
% s = tf('s');
% omega_max_llr = 3.2e4;
% phi_max_llr = 30; % [degrees]
% kv_llr = 0.3;
% 
% KT_llr = omega_max_llr/(tan(omega_max_llr*Ts/2));
% kf_llr = (1-sind(phi_max_llr))/(1+sind(phi_max_llr));
% tau_a_llr = 1/(sqrt(kf_llr)*omega_max_llr);
% tau_b_llr = kf_llr*tau_a_llr;
% 
% G_llr_s = kv_llr*((1+s*tau_a_llr)/(1+s*tau_b_llr));
% opt = c2dOptions('Method','tustin','PrewarpFrequency',omega_max_llr);
% G_llr_z = c2d(G_llr_s,Ts,opt);

%% Kalman filter (see KalmanFilter.m)

% ------------------- FIRST ----------------------------
% State space of plant for first derivative formulation
states = {'iL' 'vcap' 'ic'};
inputs = {'vi' 'io'};
outputs = {'iL' 'vc'};

% Matrices
A = [-R_Lc/L_c -1/L_c -R_Cc/L_c;
      0 0 1/C_c;
      -C_c*R_Lc/L_c -C_c*(1/L_c + 1/L_g) -C_c*(R_Cc/L_g + R_Cc/L_c)];
B = [1/L_c 0;
      0 0;
      C_c*1/L_c C_c*R_Lg/L_g];
C = [1 0 0;
     0 1 R_Cc];
D = [0 0;
     0 0];

% Der er ganget igennem med Cc - hvorfor virker det???
% SERIØST!

% Create discrete state space system
lcl_sys = ss(A,B,C,D,'statename',states,'inputname',inputs,'outputname',outputs);
lcl_sys_z = c2d(lcl_sys,Ts,'zoh');
Ad = lcl_sys_z.A;
Bd = lcl_sys_z.B;

% Observability test
e_vals = eig(Ad)';
obs_matrix = [C; Ad-e_vals*eye(3)];
if rank(obs_matrix)==length(Ad)
    disp('System is observable.')
end

% % ------------------- SECOND ----------------------------
% % State space of plant for second derivative formulation
% states2 = {'io' 'vcap' 'dvcap/dt'};
% inputs2 = {'vi', 'dio/dt'};
% outputs2 = {'iL' 'vc'};
% 
% % Matrices
% A2 = [0 0 0;%-R_Lg/L_g 1/L_g (C_c*R_Cc)/L_g;
%      R_Lg/(R_Cc*C_c) -1/(C_c*R_Cc) 0;
%      -R_Lc/(L_c) -1/(L_c) -(R_Lc/L_c+R_Cc/L_c)];
% B2 = [0 1;%0 0;
%      0 L_g/(C_c*R_Cc);
%      1/(L_c) -1/C_c];
% C2 = [1 0 C_c;
%      0 1 R_Cc*C_c]; % Output matrix for [iL; vc]
% D2 = [0 0;
%      0 0];
% 
% % Der er ganget igennem med Cc - hvorfor virker det?
% 
% % Create discrete state space system
% lcl_sys2 = ss(A2,B2,C2,D2,'statename',states2,'inputname',inputs2,'outputname',outputs2);
% lcl_sys_z2 = c2d(lcl_sys2,Ts,'zoh');
% Ad2 = lcl_sys_z2.A;
% Bd2 = lcl_sys_z2.B;
% 
% % Observability test
% e_vals2 = eig(Ad2)';
% obs_matrix2 = [C2; Ad2-e_vals2*eye(3)];
% if rank(obs_matrix2)==length(Ad2)
%     disp('System 2 is observable.')
% end

% -----------------------------------------------------------
% Noise calculation

% ADC characteristics
V_peak = 5;
n_bit = 16;
Delta_q = (V_peak-(-V_peak))/(2^n_bit);
ADC_full_error = 12; % [LSB]

% Current Transducer HO 150-NP characteristics
CT_offset = 5e-03; % [V]
CT_RMS_noise = 7e-03; % [Vpp]

% Current Transducer HO 8-NSM characteristics
CT_offset = 7e-03; % [V]
CT_RMS_noise = 80e-03; % [Vpp]

% Errors in volts
e_quant = Delta_q;
e_full = ADC_full_error*Delta_q;
e_ct_offset = CT_offset;
e_ct_noise = CT_RMS_noise;

% Error covariances
R_vc = ((e_quant+e_full)^2)/12;
R_iL = ((e_quant+e_full+e_ct_offset+e_ct_noise)^2)/12;

% Noise estimation
Q = eye(3); % Also known as Rw.
R = [R_iL 0;
      0 R_vc]; % Also known as Rv. Two plant outputs (Noise on iL, noise on vc)
N = [0]; % Also known as Rwv. One noise cross-covariance.

% Initialization and system information
UKF_data.Ts = Ts;
UKF_data.x_0 = [0; 0; 0];
UKF_data.y_0 = [0; 0];
UKF_data.P_0 = eye(3);
UKF_data.n = 3;
UKF_data.kappa = 0;
UKF_data.Q = Q;
UKF_data.R = R;
UKF_data.C = C;
UKF_data.RLc = R_Lc;
UKF_data.RCc = R_Cc;
UKF_data.RLg = R_Lg;
UKF_data.Cc = C_c;
UKF_data.Lg = L_g;
UKF_data.Lc = L_c;