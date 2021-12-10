%% Estimation of inductances on power boards
clear, close all, clc;

mu_0 = 1.25663706*10^-6;

% Assuming 1.2mm PCB thickness, 4 layers
h = 0.11e-3; % [m] = 0.11 mm
h_tot = 1.2e-3; % [m]


% Primary PCB
w_input = 3e-3; % [m] = 3 mm
l_input = 3.25e-3; %[m] = 3.25 mm

w_csih = 2.5e-3; % [m] = 2.5 mm
l_csih = 4.5e-3; % [m] = 4.5 mm

w_csil = 2.5e-3; % [m] = 2.5 mm
l_csil = 7e-3; % [m] = 7 mm

w(1) = w_input; w(2) = w_csih; w(3) = w_csil;
l(1) = l_input; l(2) = l_csih; l(3) = l_csil;

L_para_pri = mu_0 .* h./w.*l .* (0.27./(1-0.74.*exp(-0.45.*h./w)))

L_highloop_pri = L_para_pri(1);
L_swnode_pri = L_para_pri(2);
L_lowloop_pri = L_para_pri(3);


% Secondary PCB
w_input = 5e-3; % [m]
l_input = h_tot + 4e-3; %[m]

w_csih = 4.5e-3; % [m]
l_csih = 2.75e-3; % [m]

w_csil = 3.5e-3; % [m]
l_csil = 3.5e-3; % [m]

w(1) = w_input; w(2) = w_csih; w(3) = w_csil;
l(1) = l_input; l(2) = l_csih; l(3) = l_csil;

L_para_sec = mu_0 .* h./w.*l .* (0.27./(1-0.74.*exp(-0.45.*h./w)))

L_highloop_sec = L_para_sec(1);
L_swnode_sec = L_para_sec(2);
L_lowloop_sec = L_para_sec(3);