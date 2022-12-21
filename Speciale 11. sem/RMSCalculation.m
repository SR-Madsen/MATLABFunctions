clear, close all, clc;

%% Calculate RMS of steady-state wave
SSdata = load('steady_state_wave.mat');
time = SSdata.time;
SSamplitude = SSdata.signals(1).values(:);

n_halfcycle = (10e-3)/(1/(24000*500));

%for i = 1:(length(time)-n_halfcycle)
%    rms_ss(i) = rms(SSamplitude(i:(i+n_halfcycle)));
%end
rms_ss = load('steady_state_rms.mat').rms_ss;

%plot(time(1:(length(time)-n_halfcycle)),rms_ss)

%% Calculate RMS of 100% step
SLdata = load('step_load_wave.mat');
SLamplitude = SLdata.signals(1).values(:);

%for i = 1:(length(time)-n_halfcycle)
%    rms_sl(i) = rms(SLamplitude(i:(i+n_halfcycle)));
%end
rms_sl = load('step_load_rms.mat').rms_sl;

%plot(time(1:(length(time)-n_halfcycle)),rms_sl)


%% Calculate RMS of 80% step removal
SRdata = load('step_remove_wave.mat');
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
semilogx(time(1:(length(time)-n_halfcycle)),p_e_rms_sl)
xlim([5e-3 1])
ylim([-0.4 0.4])

e_rms_sr = rms_sr-rms_ss;
p_e_rms_sr = e_rms_sr./rms_ss.*100;

figure(2)
semilogx(time(1:(length(time)-n_halfcycle)),p_e_rms_sr)
xlim([5e-3 1])
ylim([-0.6 0.4])

%% Calculate instant deviation
e_inst_sl = SLamplitude-SSamplitude;
p_e_inst_sl = e_inst_sl./SSamplitude.*100;

figure(3)
semilogx(time,p_e_inst_sl)
xlim([5e-3 9e-3])
ylim([-40 20])

e_inst_sr = SRamplitude-SSamplitude;
p_e_inst_sr = e_inst_sr./SSamplitude.*100;

figure(4)
semilogx(time,p_e_inst_sr)
xlim([5e-3 9e-3])
ylim([-30 40])

%% Plots on top of each other
figure(5)
grid on
plot(time, SSamplitude, 'Color', [0.5 0.5 0.5], 'LineWidth', 4)
hold on
plot(time, SLamplitude, "r", 'LineWidth', 4) % Load step

figure(6)
grid on
plot(time, SSamplitude, 'Color', [0.5 0.5 0.5], 'LineWidth', 4)
hold on
plot(time, SRamplitude, "r", 'LineWidth', 4) % Remove step