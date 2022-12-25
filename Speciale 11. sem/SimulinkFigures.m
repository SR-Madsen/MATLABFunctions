clear, close all, clc;

%% Steady-State No Load
ss_nl = load('steady_state_no_load.mat');
time = ss_nl.time;

figure(1)
subplot(2,1,1)
plot(time,ss_nl.signals(1).values(:),'LineWidth',4)
ylim([-400 400])
grid on
set(gca,'FontSize',18)
ylabel('Voltage [V]', 'FontSize', 22)
title('Output Voltage under No Load')
subplot(2,1,2)
plot(time,ss_nl.signals(2).values(:),'LineWidth',4)
grid on
set(gca,'FontSize',18)
xlabel('Time [s]', 'FontSize', 22)
ylabel('Current [A]', 'FontSize', 22)
title('Output Current under No Load')

%% Steady-State Full Load
ss_fl = load('steady_state_full_load.mat');
time = ss_fl.time;

figure(2)
subplot(2,1,1)
plot(time,ss_fl.signals(1).values(:),'LineWidth',4)
ylim([-400 400])
grid on
set(gca,'FontSize',18)
ylabel('Voltage [V]', 'FontSize', 22)
title('Output Voltage under Full Load')
subplot(2,1,2)
plot(time,ss_fl.signals(2).values(:),'LineWidth',4)
grid on
set(gca,'FontSize',18)
xlabel('Time [s]', 'FontSize', 22)
ylabel('Current [A]', 'FontSize', 22)
title('Output Current under Full Load')


%% Steady-State Nonlinear Load
ss_nll = load('steady_state_nonlinear_load.mat');
time = ss_nll.time;

figure(3)
subplot(2,1,1)
plot(time,ss_nll.signals(1).values(:),'LineWidth',4)
ylim([-400 400])
grid on
set(gca,'FontSize',18)
ylabel('Voltage [V]', 'FontSize', 22)
title('Output Voltage under Nonlinear Load')
subplot(2,1,2)
plot(time,ss_nll.signals(2).values(:),'LineWidth',4)
grid on
set(gca,'FontSize',18)
xlabel('Time [s]', 'FontSize', 22)
ylabel('Current [A]', 'FontSize', 22)
title('Output Current under Nonlinear Load')


%% Overcurrent Fault
ss_oc = load('steady_state_overcurrent_load.mat');
time = ss_oc.time;

figure(4)
subplot(2,1,1)
plot(time,ss_oc.signals(1).values(:),'LineWidth',4)
ylim([-400 400])
grid on
set(gca,'FontSize',18)
ylabel('Voltage [V]', 'FontSize', 22)
title('Output Voltage under Short-Circuit')
subplot(2,1,2)
plot(time,ss_oc.signals(2).values(:),'LineWidth',4)
ylim([-300 300])
grid on
set(gca,'FontSize',18)
xlabel('Time [s]', 'FontSize', 22)
ylabel('Current [A]', 'FontSize', 22)
title('Output Current under Short-Circuit')


%% Capacitor Charge
ss_cc = load('steady_state_capcharge_load.mat');
time = ss_cc.time;

figure(5)
subplot(2,1,1)
plot(time,ss_cc.signals(1).values(:),'LineWidth',4)
ylim([-400 400])
grid on
set(gca,'FontSize',18)
ylabel('Voltage [V]', 'FontSize', 22)
title('Output Voltage under Capacitor Charge')
subplot(2,1,2)
plot(time,ss_cc.signals(2).values(:),'LineWidth',4)
ylim([-250 250])
grid on
set(gca,'FontSize',18)
xlabel('Time [s]', 'FontSize', 22)
ylabel('Current [A]', 'FontSize', 22)
title('Output Current under Capacitor Charge')

%% Kalman Estimates

% Capacitor voltage
ss_vc = load('vc_estimate.mat');
time = ss_vc.time;
figure(6)
plot(time,ss_vc.signals(2).values(:),time,ss_vc.signals(1).values(:),'LineWidth',4)
legend('Estimate', 'Actual')
xlim([0.022 0.05])
ylim([-350 500])
grid on
set(gca,'FontSize',18)
ylabel('Voltage [V]', 'FontSize', 22)
xlabel('Time [s]', 'FontSize', 22)
title('Actual versus estimated capacitor voltage')

ss_vc_err = load('vc_esterror.mat');
time = ss_vc_err.time;
figure(7)
plot(time,ss_vc_err.signals(1).values(:),'LineWidth',4)
xlim([0.022 0.05])
ylim([-40 35])
grid on
set(gca,'FontSize',18)
ylabel('Voltage [V]', 'FontSize', 22)
xlabel('Time [s]', 'FontSize', 22)
title('Capacitor voltage estimation error')

% Inductor current
ss_iL = load('iL_estimate.mat');
time = ss_iL.time;
figure(8)
plot(time,ss_iL.signals(1).values(:),time,ss_iL.signals(2).values(:),'LineWidth',4)
legend('Actual', 'Estimate')
xlim([0.022 0.05])
ylim([-200 250])
grid on
set(gca,'FontSize',18)
ylabel('Current [A]', 'FontSize', 22)
xlabel('Time [s]', 'FontSize', 22)
title('Actual versus estimated converter-side inductor current')

ss_iL_err = load('iL_esterror.mat');
time = ss_iL_err.time;
figure(9)
plot(time,ss_iL_err.signals(1).values(:),'LineWidth',4)
xlim([0.022 0.05])
ylim([-55 45])
grid on
set(gca,'FontSize',18)
ylabel('Current [A]', 'FontSize', 22)
xlabel('Time [s]', 'FontSize', 22)
title('Converter-side inductor current estimation error')

% Output current
ss_io = load('io_estimate.mat');
time = ss_io.time;
figure(10)
plot(time,ss_io.signals(2).values(:),time,ss_io.signals(1).values(:),'LineWidth',4)
legend('Estimate', 'Actual')
xlim([0.022 0.05])
ylim([-200 200])
grid on
set(gca,'FontSize',18)
ylabel('Current [A]', 'FontSize', 22)
xlabel('Time [s]', 'FontSize', 22)
title('Actual versus estimated output current')

% SKF vs UKF
ss_skfvsukf = load('SKF_vs_UKF.mat');
ss_skfvsukf = load('SKF_vs_UKF_R10.mat');
time = ss_skfvsukf.time;
figure(11)
subplot(2,1,1)
plot(time,ss_skfvsukf.signals(1).values(:,1),time,ss_skfvsukf.signals(1).values(:,2),'LineWidth',4)
legend('Unscented', 'Standard')
xlim([0.022 0.05])
ylim([-200 200])
grid on
set(gca,'FontSize',18)
ylabel('Current [A]', 'FontSize', 22)
title('Converter-side inductor current estimates')

subplot(2,1,2)
plot(time,ss_skfvsukf.signals(2).values(:,1),time,ss_skfvsukf.signals(2).values(:,2),'LineWidth',4)
legend('Unscented', 'Standard')
xlim([0.022 0.05])
ylim([-350 450])
grid on
set(gca,'FontSize', 18)
ylabel('Voltage [V]', 'FontSize', 22)
xlabel('Time [s]', 'FontSize', 22)
title('Capacitor voltage estimates')

% Three-Phase
ss_3p_nl = load('three_phase_full_load.mat');
time = ss_3p_nl.time;
figure(12)
subplot(2,1,1)
plot(time,ss_3p_nl.signals(1).values(:,1),time,ss_3p_nl.signals(1).values(:,2),time,ss_3p_nl.signals(1).values(:,3),'LineWidth',4)
xlim([0.005 0.05])
ylim([-400 400])
grid on
set(gca,'FontSize',18)
ylabel('Voltage [V]', 'FontSize', 22)
title('Output Voltage')

subplot(2,1,2)
plot(time,ss_3p_nl.signals(2).values(:,1),time,ss_3p_nl.signals(2).values(:,2),time,ss_3p_nl.signals(2).values(:,3),'LineWidth',4)
xlim([0.005 0.05])
ylim([-200 200])
grid on
set(gca,'FontSize', 18)
ylabel('Current [A]', 'FontSize', 22)
xlabel('Time [s]', 'FontSize', 22)
title('Output Current')

ss_3p_steps = load('three_phase_steps.mat');
time = ss_3p_steps.time;
figure(13)
subplot(2,1,1)
plot(time,ss_3p_steps.signals(1).values(:,1),time,ss_3p_steps.signals(1).values(:,2),time,ss_3p_steps.signals(1).values(:,3),'LineWidth',4)
xlim([0.005 0.04])
ylim([-400 400])
grid on
set(gca,'FontSize',18)
ylabel('Voltage [V]', 'FontSize', 22)
title('Output Voltage')

subplot(2,1,2)
plot(time,ss_3p_steps.signals(2).values(:,1),time,ss_3p_steps.signals(2).values(:,2),time,ss_3p_steps.signals(2).values(:,3),'LineWidth',4)
xlim([0.005 0.04])
ylim([-200 200])
grid on
set(gca,'FontSize', 18)
ylabel('Current [A]', 'FontSize', 22)
xlabel('Time [s]', 'FontSize', 22)
title('Output Current')