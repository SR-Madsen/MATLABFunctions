%% Estimation of inductances on power boards
clear, close all, clc;

mu_0 = 1.25663706*10^-6;

% Assuming 1.2mm PCB thickness, 4 layers
h = 0.11e-3; % [m] = 0.11 mm
h_tot = 1.2e-3; % [m]


%% Estimates for Primary PCB
w_powerloop = 3/5*2.8e-3 + 2/5*0.6e-3;
l_powerloop = 1/2*17.65e-3 + 1/2 * (5.5e-3 + 13.71e-3);
w_bottleneck = 0.13e-3; % Bottleneck only present on one half-bridge
l_bottleneck = 1e-3;
L_powerloop_bottlenecked = mu_0 * h/w_powerloop * l_powerloop * (0.27/(1-0.74*exp(-0.45*h/w_powerloop))) + ...
              mu_0 * h/w_bottleneck * l_bottleneck * (0.27/(1-0.74*exp(-0.45*h/w_bottleneck)))
L_powerloop = mu_0 * h/w_powerloop * l_powerloop * (0.27/(1-0.74*exp(-0.45*h/w_powerloop)))          


w_hgateon = 1/4 * (0.5e-3 + 1e-3) + 1/2 * (1.8e-3);
l_hgateon = 1/4 * (3.8e-3 + 2.6e-3) + 1/2 * (8.5e-3);
L_hgateon = mu_0 * h/w_hgateon * l_hgateon * (0.27/(1-0.74*exp(-0.45*h/w_hgateon)))


w_hgateoff = 1/4 * (1e-3 + 0.5e-3) + 1/2 * (1.8e-3);
l_hgateoff = 1/2 * (7.4e-3 + 6.5e-3);
L_hgateoff = mu_0 * h/w_hgateoff * l_hgateoff * (0.27/(1-0.74*exp(-0.45*h/w_hgateoff)))


w_lgateon = 1/4 * (0.5e-3 + 1.5e-3) + 1/2 * (1.8e-3);
l_lgateon = 1/2 * (8.5e-3) + 1/2 * (11.2e-3);
L_lgateon = mu_0 * h/w_lgateon * l_lgateon * (0.27/(1-0.74*exp(-0.45*h/w_lgateon)))


w_lgateoff = 1/4 * (0.5e-3 + 1.5e-3) + 1/2 * (1.8e-3);
l_lgateoff = 1/2 * (10.8e-3) + 1/2 * (7.8e-3);
L_lgateoff = mu_0 * h/w_lgateoff * l_lgateoff * (0.27/(1-0.74*exp(-0.45*h/w_lgateoff)))


%% Estimates for Secondary PCB
w_powerloop = 4.5e-3;
l_powerloop = 1/2 * 12.45e-3 + 1/2 * 36e-3;
L_powerloop = mu_0 * h_tot/w_powerloop * l_powerloop * (0.27/(1-0.74*exp(-0.45*h_tot/w_powerloop)))          


w_hgateon = 1/4 * (0.5e-3 + 1.4e-3) + 1/2 * 2e-3;
l_hgateon = 1/2 * 7.8e-3 + 1/2 * 8.8e-3;
L_hgateon = mu_0 * h/w_hgateon * l_hgateon * (0.27/(1-0.74*exp(-0.45*h/w_hgateon)))


w_hgateoff = 1/4 * (0.5e-3 + 1.4e-3) + 1/2 * 2e-3;
l_hgateoff = 1/2 * 9.2e-3 + 1/2 * 10.2e-3;
L_hgateoff = mu_0 * h/w_hgateoff * l_hgateoff * (0.27/(1-0.74*exp(-0.45*h/w_hgateoff)))


w_lgateon = 1/4 * (0.5e-3 + 1.4e-3) + 1/2 * 2e-3;
l_lgateon = 1/2 * 7.6e-3 + 1/2 * 10e-3;
L_lgateon = mu_0 * h/w_lgateon * l_lgateon * (0.27/(1-0.74*exp(-0.45*h/w_lgateon)))


w_lgateoff = 1/4 * (0.5e-3 + 1.4e-3) + 1/2 * 2e-3;
l_lgateoff = 1/2 * 9.1e-3 + 1/2 * 10e-3;
L_lgateoff = mu_0 * h/w_lgateoff * l_lgateoff * (0.27/(1-0.74*exp(-0.45*h/w_lgateoff)))


%% Measured for Primary PCB
pri_vds_data = readmatrix('TestMeasurements/C1Trace00005.dat');

time = pri_vds_data(1000:end-1500,1);
vds = pri_vds_data(1000:end-1500,2);

t_p2p = 1.3161e-8 - 3.161e-9
f_osc = 1/t_p2p

Coss = 390*10^-12;
C_decoup = 2 * (100*10^-9 + 10*10^-9);

syms L
L_pri = double(solve(f_osc==1/(2*pi*sqrt(L*(Coss+C_decoup))),L))

figure(1)
plot(time, vds, 'LineWidth', 4)
grid on
set(gca, 'FontSize', 18)
title('Primary Side V_D_S Switching at 200 kHz', 'FontSize', 26)
xlabel('Time [s]', 'FontSize', 22)
ylabel('Voltage [V]', 'FontSize', 22)

%% Measured for Secondary PCB
sec_vds_data = readmatrix('TestMeasurements/C1Trace00002.dat');

time = sec_vds_data(1500:end-1000,1);
vds = sec_vds_data(1500:end-1000,2);

t_p2p = 2.1161e-8 - 1.2911e-8;
f_osc = 1/t_p2p

Coss = 250*10^-12;
C_snubber = 2.1*10^-6;

syms L
L_sec = double(solve(f_osc==1/(2*pi*sqrt(L*(Coss))),L))

figure(2)
plot(time, vds, 'LineWidth', 4)
grid on
set(gca, 'FontSize', 18)
title('Secondary Side V_D_S Switching at 200 kHz', 'FontSize', 26)
xlabel('Time [s]', 'FontSize', 22)
ylabel('Voltage [V]', 'FontSize', 22)