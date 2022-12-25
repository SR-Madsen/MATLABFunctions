clear, close all, clc;

%% Calculate RMS of steady-state wave
SSdata = load('~/Desktop/steady_state_wave.mat');
time = SSdata.time;
SSamplitude = SSdata.signals(1).values(:);

n_halfcycle = (10e-3)/(1/(24000*500));

%for i = 1:(length(time)-n_halfcycle)
%    rms_ss(i) = rms(SSamplitude(i:(i+n_halfcycle)));
%end
rms_ss = load('steady_state_rms.mat').rms_ss;

%plot(time(1:(length(time)-n_halfcycle)),rms_ss)

%% Calculate RMS of 100% step
SLdata = load('~/Desktop/step_load_wave.mat');
SLamplitude = SLdata.signals(1).values(:);

%for i = 1:(length(time)-n_halfcycle)
%    rms_sl(i) = rms(SLamplitude(i:(i+n_halfcycle)));
%end
rms_sl = load('step_load_rms.mat').rms_sl;

%plot(time(1:(length(time)-n_halfcycle)),rms_sl)


%% Calculate RMS of 80% step removal
SRdata = load('~/Desktop/step_remove_wave.mat');
SRamplitude = SRdata.signals(1).values(:);

%for i = 1:(length(time)-n_halfcycle)
%    rms_sr(i) = rms(SRamplitude(i:(i+n_halfcycle)));
%end
rms_sr = load('step_remove_rms.mat').rms_sr;

%plot(time(1:(length(time)-n_halfcycle)),rms_sr)


%% Calculate RMS deviation
e_rms_sl = rms_sl-rms_ss;
p_e_rms_sl = e_rms_sl./rms_ss.*100;

figure(1)
plot(time(1:(length(time)-n_halfcycle))-5.1e-3,p_e_rms_sl)
xlim([0 1-5.1e-3])
ylim([-0.4 0.4])

e_rms_sr = rms_sr-rms_ss;
p_e_rms_sr = e_rms_sr./rms_ss.*100;

figure(2)
plot(time(1:(length(time)-n_halfcycle))-5.1e-3,p_e_rms_sr)
xlim([0 1-5.1e-3])
ylim([-0.6 0.4])

%% Calculate instant deviation
e_inst_sl = SLamplitude-SSamplitude;
p_e_inst_sl = e_inst_sl./SSamplitude.*100;

figure(3)
plot(time-5.1e-3,p_e_inst_sl)
xlim([0 9e-3-5.1e-3])
ylim([-40 20])

e_inst_sr = SRamplitude-SSamplitude;
p_e_inst_sr = e_inst_sr./SSamplitude.*100;

figure(4)
plot(time-5.1e-3,p_e_inst_sr)
xlim([0 9e-3-5.1e-3])
ylim([-30 40])

%% RMS and instant deviation
figure(7)
hold on
plot(time(n_halfcycle/2+n_halfcycle/100:n_halfcycle-n_halfcycle/10)-5e-3,p_e_inst_sl(n_halfcycle/2+n_halfcycle/100:n_halfcycle-n_halfcycle/10), 'LineWidth', 4)
plot(time(1:(length(time)-n_halfcycle))-5e-3,p_e_rms_sl, 'LineWidth', 4)
xlim([0.1e-3 9e-3-5e-3])
ylim([-40 20])
grid on
set(gca,'FontSize',18)
xlabel('Time [s]', 'FontSize', 22)
ylabel('Voltage Deviation [%]', 'FontSize', 22)
title('Output voltage deviation from 0.1 ms after load step')
legend('Instant Deviation', 'RMS Deviation')

figure(8)
hold on
plot(time(n_halfcycle/2+n_halfcycle/100:n_halfcycle-n_halfcycle/10)-5e-3,p_e_inst_sr(n_halfcycle/2+n_halfcycle/100:n_halfcycle-n_halfcycle/10), 'LineWidth', 4)
plot(time(1:(length(time)-n_halfcycle))-5e-3,p_e_rms_sr, 'LineWidth', 4)
xlim([0.1e-3 9e-3-5e-3])
ylim([-30 40])
grid on
set(gca,'FontSize',18)
xlabel('Time [s]', 'FontSize', 22)
ylabel('Voltage Deviation [%]', 'FontSize', 22)
title('Output voltage deviation from 0.1 ms after load removal')
legend('Instant Deviation', 'RMS Deviation')

%% Plots on top of each other
figure(5)
grid on
plot(time, SSamplitude, 'Color', [0.5 0.5 0.5], 'LineWidth', 4)
hold on
plot(time, SLamplitude, "r", 'LineWidth', 4) % Load step
set(gca,'FontSize',18)
xlabel('Time [s]', 'FontSize', 22)
ylabel('Output Voltage [V]', 'FontSize', 22)
title('Output voltage during 100% load step')
legend('Steady-State No Load', 'Load Step')
xlim([4.9e-3 6e-3])
ylim([200 370])

figure(6)
grid on
plot(time, SSamplitude, 'Color', [0.5 0.5 0.5], 'LineWidth', 4)
hold on
plot(time, SRamplitude, "r", 'LineWidth', 4) % Remove step
set(gca,'FontSize',18)
xlabel('Time [s]', 'FontSize', 22)
ylabel('Output Voltage [V]', 'FontSize', 22)
title('Output voltage during 80% load removal')
legend('Steady-State No Load', 'Load Removal')
xlim([4.9e-3 5.8e-3])
ylim([240 450])