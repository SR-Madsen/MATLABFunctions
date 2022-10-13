clear, close all, clc;

%% Steady-state, one phase, full-load
load("scopedata_nodelay_onephase.mat")
time = ScopeData4.time;
signal = ScopeData4.signals(1).values;

amplitude = squeeze(signal(1,1,:));

%plot(time,amplitude)

time_cut = time(floor(3*end/5):end);
amplitude_cut = amplitude(floor(3*end/5):end);
nsamp=length(time_cut);

Tsamp = time_cut(4)-time_cut(3);
fsamp = 1/Tsamp;

figure(1)
subplot(2,1,1)
plot(time_cut,amplitude_cut)

Nfft = nsamp;
[Pxx, f] = pwelch(amplitude_cut,gausswin(Nfft),Nfft/2,Nfft,fsamp)

subplot(2,1,2)
plot(f,Pxx)


%thd(amplitude_cut)