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

%% Non-linear load values PER PHASE
Vout = 230; % [V] Rated RMS output voltage
Vout_amp = Vout*sqrt(2); % [V] Peak output voltage amplitude
f_o = 50; % [Hz] Output frequency
Uc = 1.22*Vout; % [V] Rectified voltage

S_tot = 8000; % [VA] Total apparent power across full non-linear load (max)
S_20p = 0.2*S_tot; % [VA] Apparent power across 20% load
S_80p = 0.8*S_tot; % [VA] Apparent power across 80% load

% 20% load
R_nl_s_20p = 0.04*Vout^2/S_20p; % [Ohm] Series line resistor
R_nl_load_20p = Uc^2/(0.66*S_20p); % [Ohm] Non-linear load resistor
C_nl_20p = 7.5/(f_o*R_nl_load_20p); % [F] Non-linear load capacitor

% 80% load
R_nl_s_80p = 0.04*Vout^2/S_80p;
R_nl_load_80p = Uc^2/(0.66*S_80p);
C_nl_80p = 7.5/(f_o*R_nl_load_80p);

V_f = 0.7; % [V] Forward voltage of rectifier diodes
R_d = 0.01; % [Ohm] On-resistance of rectifier diodes

%% Linear load values PER PHASE
overcurrent_factor = 1; % 1.5 for peak
P_tot = (200000*overcurrent_factor)/3; % [W]
%P_lin = P_tot - S_tot; % [W] Total power across linear load
P_lin = P_tot;
P_lin_20p = 0.2*P_lin; % [W] Power across 20% load
P_lin_80p = 0.8*P_lin; % [W] Power across 80% load

R_l_20p = Vout^2/P_lin_20p; % [Ohm] Linear load resistor
R_l_80p = Vout^2/P_lin_80p;

%% Output filter (see PlantModel.m and Inductance.m)
f_sw = 24000; % [Hz] Switching frequency

% Values
L_c = 90.375*10^-6; % [H]
L_g = 12*10^-6; % [H]
C_c = 30*10^-6; % [F]
C_r = 20*10^-6; % [F]
L_r = (1/(2*pi*f_sw))^2/C_r; % [H] (resulting in 24 kHz resonance frequency)

% Parasitics
R_Lc = 5e-3; % [Ohm]
R_Lg = 3e-3; % [Ohm]
R_Cc = 1e-6; % [Ohm]
R_Cr = 1e-6; % [Ohm]
R_Lr = 1; % [Ohm]

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
Td = 1.5*Ts; % [s]
Tcomp = 2e-6; % [s] Estimate of computation and propagation time

% Proportional controller
%Kc = 2.3856;

% PI Controller
Kc = 0.8515;
Ki = 5.6549e03;

% PR controller
omega_o = 2*pi*f_o; % [rad/s]
omega_w = 0.1*2*pi; % [rad/s]
Kp = 1.5894;
Kr = 628.3185;