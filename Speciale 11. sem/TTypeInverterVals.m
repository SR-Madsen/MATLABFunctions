clear, close all, clc;

%% Non-linear load values
U = 230; % [V] Rated RMS output voltage
f_o = 50; % [Hz] Output frequency
S = 8000; % [VA] Apparent power across reference non-linear load (max)

Uc = 1.22*U; % [V] Rectified voltage

R_nl_s = 0.04*U^2/S; % [Ohm] Series line resistor
R_nl_load = Uc^2/(0.66*S); % [Ohm] Non-linear load resistor
C_nl = 7.5/(f_o*R_nl_load); % [F] Non-linear load capacitor

V_f = 0.7; % [V] Forward voltage of rectifier diodes
R_d = 0.01; % [Ohm] On-resistance of rectifier diodes

%% Linear load value
P_tot = 200000; % [W]
P_lin = P_tot - S; % [W]

R_l = U^2/P_lin; % [Ohm] Linear load resistor

%% Output filter
f_sw = 24000; % [Hz] Switching frequency

% Values
L_c = 89*10^-6; % [H]
C_c = 30*10^-6; % [F]
C_r = 20*10^-6; % [F]
L_r = (1/(2*pi*f_sw))^2/C_r; % [H] (resulting in 24 kHz resonance frequency)
L_g = 2.5*10^-6; % [H]

% Parasitics
R_Lc = 0.1; % [Ohm]
R_Cc = 1e-6; % [Ohm]
R_Cr = 1e-6; % [Ohm]
R_Lr = 1; % [Ohm]
R_Lg = 0; % [Ohm]