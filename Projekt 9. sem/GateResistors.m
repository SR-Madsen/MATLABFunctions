%% Gate Resistor Calculation
clear, close all, clc;


% Chosen turn-on and turn-off times
t_on_p = 50*10^-9; % [s]
t_off_p = 50*10^-9; % [s]
t_on_s = 50*10^-9; % [s]
t_off_s = 50*10^-9; % [s]


% Driver
V_g_on_p = 5; % [V]
V_g_on_s = 6; % [V]
V_g_off_p = -2; % [V]
V_g_off_s = -2; % [V]

R_off_dr = 0.6; % [Ohm]
R_on_dr = 0.8; % [Ohm]


% Primary side
Qg_p = 13.6*10^-9; % [C]
Qgd_p = 2.1*10^-9; % [C]
V_plat_p = 2.1; % [V]
R_int_p = 0.4; % [Ohm]

I_on_p = Qg_p/t_on_p; % [A]
I_off_p = Qg_p/t_off_p; % [A]

R_p_on = (V_g_on_p - V_plat_p)/I_on_p - R_on_dr - R_int_p % [Ohm]
R_p_off = (V_plat_p)/I_off_p - R_off_dr - R_int_p % [Ohm]


% Secondary side
Qg_s = 8*10^-9; % [C]
Qgd_s = 1.7*10^-9; % [C]
V_plat_s = 3.5; % [V]
R_int_s = 0.6; % [Ohm]

I_on_s = Qg_s/t_on_s; % [A]
I_off_s = Qg_s/t_off_s; % [A]

R_s_on = (V_g_on_s - V_plat_s)/I_on_s - R_on_dr - R_int_s % [Ohm]
R_s_off = (V_plat_s)/I_off_s - R_off_dr - R_int_s % [Ohm]