clear, close all, clc;

%% Power Electronics 7: In-lecture exercise for power losses in inverter
% Use the transistor at this link:
% https://www.infineon.com/dgdl/Infineon-IPB015N08N5-DataSheet-v02_02-EN.pdf?fileId=5546d4624a75e5f1014aca3499a41e96
% Assume T_j = 60 degrees

% Values given in assignment:
I_RMS = 100; % [A]
VDC = 48; % [V]
V_DS = VDC;
f_sw = 8000; % [Hz]

% Values from datasheet:
R_DS = 1.8*10^-3; % [Ohm] Maximum value at 60 degrees, Diagram 9.
V_F = 1.25; % [V] Maximum value estimated at 60 degrees, 100 A, Diagram 12.
t_on = 32 * 10^-9; % [s] From Table 5 (Ignoring turn-on time).
t_off = 28 * 10^-9; % [s] From Table 5 (Ignoring turn-off time).
T_dead = 2*t_off; % [s] Double to be sure.

% Power loss calculations:
P_fet_con = I_RMS^2 * R_DS
P_fet_sw = 1/2 * I_RMS * V_DS * (t_on + t_off) * f_sw
P_D = I_RMS * V_F * 2 * T_dead * f_sw

P_total = 6 * (P_fet_con + P_fet_sw + P_D)

T_A = 40; % [Degrees C]
R_jc = 0.4; % [K/W] Maximum value, Table 3.
R_ca = 1; % [K/W] Heatsink, random value.
T_j = T_A + P_total * (R_jc + R_ca)