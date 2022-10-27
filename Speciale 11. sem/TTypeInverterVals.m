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
V_f = 0.1;%1.5; % [V] Forward voltage of rectifier diodes
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

% Values
L_c = 90.375*10^-6; % [H]
L_g = 2*10^-6; % [H]
C_c = 30*10^-6; % [F]
C_r = 20*10^-6; % [F]
L_r = (1/(2*pi*f_sw))^2/C_r; % [H] (resulting in 24 kHz resonance frequency)

% Parasitics
R_Lc = 5e-3; % [Ohm]
R_Lg = 3e-3; % [Ohm]
R_Cc = 1e-3; % [Ohm]
R_Cr = 1e-3; % [Ohm]
R_Lr = 3e-3; % [Ohm]

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
fs = 2*f_sw; % [Hz]
Ts = 1/fs; % [s]
Td = 1.5*Ts; % [s] Unused in simulation as ZOH and SimScape inductor account for it
Tcomp = 1e-6; % [s] Estimate of computation and propagation time

% Proportional controller
Kc = 1;

% Lead-Lag
s = tf('s');
omega_max = 0.175*f_sw*2*pi; %0.2*f_sw*2*pi; % For capacitor control % 1/(sqrt((L_c+L_g)*C_c));
phi_max = 30; % [degrees]
kv = 0.3377; % 0.3189; % For capacitor control

KT_ll = omega_max/(tan(omega_max*Ts/2));
kf = (1-sind(phi_max))/(1+sind(phi_max));
tau_a = 1/(sqrt(kf)*omega_max);
tau_b = kf*tau_a;

G_ll_s = kv*((1+s*tau_a)/(1+s*tau_b));
opt = c2dOptions('Method','tustin','PrewarpFrequency',omega_max);
G_ll_z = c2d(G_ll_s,Ts,opt);

% PR controller
omega_c_o = f_o*60*2*pi; %3e4; % For inductor control %f_o*20*2*pi; % Target cross-frequency
omega_o = f_o*2*pi; % Fundamental frequency
omega_p = [f_o*2*pi*1 f_o*2*pi*3 f_o*2*pi*5 f_o*2*pi*7]; % Resonant frequency
KT = [omega_p(1)/(tan(omega_p(1)*Ts/2)) omega_p(2)/(tan(omega_p(2)*Ts/2)) ...
      omega_p(3)/(tan(omega_p(3)*Ts/2)) omega_p(4)/(tan(omega_p(4)*Ts/2))]; % Pre-warp factor
Kr = [omega_c_o/(4) omega_c_o/(4*3) omega_c_o/(4*5) omega_c_o/(4*7)]; % Resonant gain
omega_w = [0.1*2*pi 0.1*2*pi 0.1*2*pi 0.1*2*pi]; % Resonance width
Kp = 1.7674; %1.856; %For capacitor current control % Proportional PR gain
Klim = 1; % Anti-windup limiting gain

% Maximum current (anti-windup saturation)
iL_max = ((50000*overcurrent_factor)/(Vout*3))*sqrt(2);
pr_sat_val = 5*ceil(iL_max+1);

% PI Controller [legacy]
Kpc = 2.0678;
Ki = 7.5398e03;

%% Differentiator
% Generalized Integrator
omega_mark = (2*pi*fs)/2; % Nyquist frequency for maximum flattening
omega_c = (2*pi*fs)/3; % Selected for optimal performance
G_diff_s = tf([omega_mark^2 0],[1 omega_c omega_mark^2]);
G_diff_z = c2d(G_diff_s,Ts,'foh');
%bode(G_diff_z)

%% Kalman filter (see KalmanFilter.m)
% State space of plant
% Input: [vi; dio/dt]
% States: [io; vcap; dvcap/dt]
% Output: [io; vcap]

% using both dio/dt and dvc/dt (interesting! Same performance as above)
A = [-R_Lg/L_g 1/L_g C_c*R_Cc/L_g;
     R_Lg/(R_Cc*C_c) -1/(C_c*R_Cc) 0;
     -1/(L_c*C_c) -(R_Lc/L_c+R_Cc/L_c) -R_Lc/(L_c*C_c)];
B = [0 0;
     0 L_g/(C_c*R_Cc);
     1/(L_c*C_c) -1/C_c];
C = [1 0 0;
     0 1 0]; % Output matrix for [io; vcap]
D = [0 0;
     0 0]; % Transmission matrix = 0

% ic is non-functional because it is 90 degrees phase-shifted and too low
% amplitude

states = {'io' 'vcap' 'dvcap/dt'};
input = {'vi', 'dio/dt'};
outputs = {'io' 'vcap'};

% Create discrete state space system
lcl_sys = ss(A,B,C,D,'statename',states,'inputname',input,'outputname',outputs);
lcl_sys_z = c2d(lcl_sys,Ts,'zoh');
Ad = lcl_sys_z.A;
Bd = lcl_sys_z.B;

e_vals = eig(Ad)';
obs_matrix = [C; Ad-e_vals*eye(3)];
if rank(obs_matrix)==length(Ad)
    disp('System is observable.')
end

% Noise estimation
G = [0; 0; 0];
Gd = A\(expm(A*Ts)-eye(3))*G; % Also known as B1d
Gd = [0;0;0];
H = [0; 0];
Rw = 1;
Rv = 1e-3;
Rwv = 0;