clear, close all, clc;

%% Laboratory measurements

% Differential - getting magnetizing inductance and differential capactiance
zdml_data = readmatrix('LabMeasurements/ZDML.TXT');
zdmf_data = readmatrix('LabMeasurements/ZDMF.TXT');

%f = zdmf_data(1:1:length(zdmf_data)/2,1)
%amp = zdmf_data(1:1:length(zdmf_data)/2,2)
%phase = zdmf_data(length(zdmf_data)/2+1:1:length(zdmf_data),2)
%figure(1)
%plot(f,amp)
%figure(2)
%plot(f,phase)

Lm = zdml_data(112,2)

% fres = 6.10187769000e+05
syms C
Cdm = double(solve(6.10187769000e+05 == 1/(2*pi*sqrt(Lm*C)), C))


% Shorted output - getting AC resistance and leakage inductance
zs_data = readmatrix('LabMeasurements/ZSGOOD.TXT');

f = zs_data(1:1:length(zs_data)/2,1);
amp = zs_data(1:1:length(zs_data)/2,2);
phase = zs_data(length(zs_data)/2+1:1:length(zs_data),2);
figure(3)
plot(f,amp)
figure(4)
plot(f,phase)

phase_rads = (2*pi)/360*phase;
[a, b] = pol2cart(phase_rads, amp)

%figure(3)
%plot(f,a)
%figure(4)
%plot(f,b)

freq_real = [f, a];
freq_im = [f, b];

R_AC = 0.008359957817498
Llk = 0.005189576729769/(3.962020300000000e+04*2*pi)


% Common-mode - getting common-mode capacitance
zcm_data = readmatrix('LabMeasurements/ZCM.TXT');

f = zcm_data(1:1:length(zcm_data)/2,1);
cs = zcm_data(1:1:length(zcm_data)/2,1);

Ccm = 7.685370000000000e-09;