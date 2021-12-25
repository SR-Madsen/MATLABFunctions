%% Estimation of inductances on power boards
clear, close all, clc;

mu_0 = 1.25663706*10^-6;
epsilon_0 = 8.85418782e-12;
epsilon_r = 4.4;

% Assuming 1.2mm PCB thickness, 4 layers
h = 0.11e-3; % [m] = 0.11 mm
h_core = 0.8e-3; % [m]
h_tot = 1.2e-3; % [m]


%% Estimates for Primary PCB
w_powerloop = 3/5*2.8e-3 + 2/5*0.6e-3;
l_powerloop = 1/2*17.65e-3 + 1/2 * (5.5e-3 + 13.71e-3);
w_bottleneck = 0.13e-3;
l_bottleneck = 1e-3;
L_powerloop_q3q4 = mu_0 * h/w_powerloop * l_powerloop * (0.27/(1-0.74*exp(-0.45*h/w_powerloop))) + ...
              mu_0 * h/w_bottleneck * l_bottleneck * (0.27/(1-0.74*exp(-0.45*h/w_bottleneck)))

w_bottleneck = 0.6e-3;
l_bottleneck = 1.5e-3;
L_powerloop_q1q2 = mu_0 * h/w_powerloop * l_powerloop * (0.27/(1-0.74*exp(-0.45*h/w_powerloop))) + ...
              mu_0 * h/w_bottleneck * l_bottleneck * (0.27/(1-0.74*exp(-0.45*h/w_bottleneck)))      


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
l_powerloop = 1/2 * (12.45e-3 + 3.3e-3);
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


%% Capacitances for Primary PCB
% DC to GND
A_pri_top = 2*1.1*(1.65e-3*6.5e-3 + 3.5e-3*3.5e-3 + 4.5e-3*2e-3 + ... 
            2.4e-3*4.2e-3 + 6.2e-3*2.5e-3);
A_pri_bot = 2*1.1*(3.8e-3*6e-3 + 5.7e-3*5.3e-3 + 2.4e-3*4.2e-3 + 6.2e-3*2.5e-3);
C_pri_pcb = (epsilon_0*epsilon_r*A_pri_top)/h + ... 
    (epsilon_0*epsilon_r*A_pri_bot)/h_core + (epsilon_0*epsilon_r*A_pri_bot)/h;

% Inter-switchnode
A_pri_inter = 14.1e-3 * 17.8e-3;
C_pri_inter = (epsilon_0*epsilon_r*A_pri_inter)/h + ... 
    (epsilon_0*epsilon_r*A_pri_inter)/h_core + (epsilon_0*epsilon_r*A_pri_inter)/h;

% Switchnode 1 to GND
C_pri_sw1 = 0;

% Switchnode 2 to GND
C_pri_sw2 = 0;


%% Capacitances for Secondary PCB
% DC to GND
A_sec_top = 2*1.1*(0);
A_sec_bot = 2*1.1*(0);
C_sec_pcb = (epsilon_0*epsilon_r*A_sec_top)/h + ... 
    (epsilon_0*epsilon_r*A_sec_bot)/h_core + (epsilon_0*epsilon_r*A_sec_bot)/h;

% Inter-switchnode
A_sec_inter = 12.7e-3 * 17.4e-3;
C_sec_inter = (epsilon_0*epsilon_r*A_sec_inter)/h;

% Switchnode 1 to GND
C_sec_sw1 = 0;

% Switchnode 2 to GND
A_sec_sw2 = 12.7e-3 * 17.4e-3;
C_sec_sw2 = (epsilon_0*epsilon_r*A_sec_sw2)/h_core;


%% Measured for Primary PCB
pri_vds_data = readmatrix('TestMeasurements/C1Trace00005.dat');

time = pri_vds_data(1000:end-1500,1);
vds = pri_vds_data(1000:end-1500,2);

t_p2p = 1.3161e-8 - (3.161e-9+2.911e-9)/2;
f_pri = 1/t_p2p

Coss_pri_63V = 555*10^-12;

C_meas = 15e-12;

L_loop_pri = t_p2p^2/(4*pi^2 * (2*Coss_pri_63V + C_pri_pcb + C_meas))


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

t_p2p = 2.1161e-8 - 1.3161e-8;
f_sec = 1/t_p2p

Coss_sec_30V = 310*10^-12;

C_meas = 15e-12;


L_loop_sec = t_p2p^2/(4*pi^2 * (2*Coss_sec_30V + C_sec_pcb + C_meas))


figure(2)
plot(time, vds, 'LineWidth', 4)
grid on
set(gca, 'FontSize', 18)
title('Secondary Side V_D_S Switching at 200 kHz', 'FontSize', 26)
xlabel('Time [s]', 'FontSize', 22)
ylabel('Voltage [V]', 'FontSize', 22)