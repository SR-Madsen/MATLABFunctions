%% Project Lab Measurements
clear, close all, clc;


%% Transformer

% All 40 Hz to 5 MHz
% ZDMF = Differential-Mode, impedance/phase with large terminal overlap
% ZDMF2 = Differential-Mode, impedance/phase with small terminal overlap
% ZDML = Differential-Mode, Ls-Rs
% ZDML2 = Differential-Mode, Ls-Rs with small terminal overlap
% ZS = Shorted output, both shorted and non-shorted terminals
% ZCM = Common-Mode

%DC resistance
R_DC_p = 6.773e-3
R_DC_s = 2.348e-3


% AC resistance
zs_data = readmatrix('ProjectLabMeasurements/ZS.TXT');

f = zs_data(1:1:length(zs_data)/2-1,1);
amp = zs_data(1:1:length(zs_data)/2-1,2);
phase = zs_data(length(zs_data)/2+2:1:length(zs_data),2);

figure(1)
subplot(2,1,1)
semilogx(f, amp, 'LineWidth', 4)
grid on
set(gca, 'FontSize', 18)
title('Short Scenario Impedance and Phase as a Function of Frequency', 'FontSize', 26)
xlabel('Frequency [Hz]', 'FontSize', 22)
ylabel('Impedance [\Omega]', 'FontSize', 22)
subplot(2,1,2)
semilogx(f, phase, 'LineWidth', 4)
grid on
set(gca, 'FontSize', 18)
xlabel('Frequency [Hz]', 'FontSize', 22)
ylabel('Phase [\circ]', 'FontSize', 22)

phase_rads = (2*pi)/360*phase;
[R_zs, L_zs] = pol2cart(phase_rads, amp);

figure(2)
subplot(2,1,1)
semilogx(f, R_zs, 'LineWidth', 4)
grid on
set(gca, 'FontSize', 18)
title('Short Scenario AC Resistance as a Function of Frequency', 'FontSize', 26)
xlabel('Frequency [Hz]', 'FontSize', 22)
ylabel('AC Resistance [\Omega]', 'FontSize', 22)

R_AC = R_zs(144) % = Rp + Rs/n^2, for stop = 5 MHz
% Read on impedance analyzer: 20.6 mOhm

% Leakage inductance
L_lk = L_zs(146)/(2*pi*f(146)) % = Lp + Ls/n^2, for stop = 5 MHz
L_lk_p = L_zs./(2*pi.*f);
% Read on impedance analyzer: 57.49 nH

%figure(3)
subplot(2,1,2)
semilogx(f,L_lk_p, 'LineWidth', 4)
grid on
set(gca, 'FontSize', 18)
title('Short Scenario Leakage Inductance as a Function of Frequency', 'FontSize', 26)
xlabel('Frequency [Hz]', 'FontSize', 22)
ylabel('Leakage Inductance [H]', 'FontSize', 22)

% Magnetizing inductance
zdml_data = readmatrix('ProjectLabMeasurements/ZDML2.TXT');
f = zdml_data(1:1:length(zdml_data)/2-1,1);
L = zdml_data(1:1:length(zdml_data)/2-1,2);
R = zdml_data(length(zdml_data)/2+1:1:length(zdml_data),2);

figure(4)
semilogx(f,L, 'LineWidth', 4)
grid on
set(gca, 'FontSize', 18)
title('Differential Scenario Magnetizing Inductance as a Function of Frequency', 'FontSize', 26)
xlabel('Frequency [Hz]', 'FontSize', 22)
ylabel('Magnetizing Inductance [H]', 'FontSize', 22)

Lm = zdml_data(146,2)


% Intra-winding capacitance
zdmf_data = readmatrix('ProjectLabMeasurements/ZDMF2.TXT');
f = zdmf_data(1:1:length(zdmf_data)/2-1,1);
amp = zdmf_data(1:1:length(zdmf_data)/2-1,2);
phase = zdmf_data(length(zdmf_data)/2+2:1:length(zdmf_data),2);

figure(5)
subplot(2,1,1)
semilogx(f,amp, 'LineWidth', 4)
grid on
set(gca, 'FontSize', 18)
title('Differential Scenario Impedance and Phase as a Function of Frequency', 'FontSize', 26)
xlabel('Frequency [Hz]', 'FontSize', 22)
ylabel('Impedance [\Omega]', 'FontSize', 22)
subplot(2,1,2)
semilogx(f,phase, 'LineWidth', 4)
grid on
set(gca, 'FontSize', 18)
xlabel('Frequency [Hz]', 'FontSize', 22)
ylabel('Phase [\circ]', 'FontSize', 22)

% fres for ZDMF = 7.21074026e05
% fres for ZDMF2 = 8.63389815e05
% fres for ZDMF2 from datapoint = 8.59871396e5
syms C
Cdm = double(solve(8.59871396e+05 == 1/(2*pi*sqrt(Lm*C)),C))


% Inter-winding capacitance
zcm_data = readmatrix('ProjectLabMeasurements/ZCM.TXT');

f = zcm_data(1:1:length(zcm_data)/2-1,1);
cs = zcm_data(1:1:length(zcm_data)/2-1,2);
rs = zcm_data(length(zcm_data)/2+2:1:length(zcm_data),2);

figure(6)
semilogx(f, cs, 'LineWidth', 4)
grid on
set(gca, 'FontSize', 18)
title('Inter-Winding Capacitor Value as a Function of Frequency', 'FontSize', 26)
xlabel('Frequency [Hz]', 'FontSize', 22)
ylabel('Capacitance [F]', 'FontSize', 22)

% subplot(2,1,1)
% semilogx(f, rs, 'LineWidth', 4)
% grid on
% set(gca, 'FontSize', 18)
% title('Common-Mode Real and Imaginary Values as a Function of Frequency', 'FontSize', 26)
% xlabel('Frequency [Hz]', 'FontSize', 22)
% ylabel('Resistance [\Omega]', 'FontSize', 22)
% subplot(2,1,2)
% semilogx(f, cs, 'LineWidth', 4)
% grid on
% set(gca, 'FontSize', 18)
% xlabel('Frequency [Hz]', 'FontSize', 22)
% ylabel('Impedance [\Omega]', 'FontSize', 22)

% [phase, amp] = cart2pol(rs,cs);
% phase = phase/(2*pi)*360
% 
% figure(11)
% subplot(2,1,1)
% semilogx(f(20:end), amp(20:end), 'LineWidth', 4)
% grid on
% 
% subplot(2,1,2)
% semilogx(f(20:end), phase(20:end), 'LineWidth', 4)
% grid on

Ccm = cs(146) % = 200 kHz

%% Inductor

% ZLCORE = Measurement with core, 40 Hz to 50 MHz, terminals "free"
% ZLCORE2 = Measurement with core, 40 Hz to 50 MHz, terminals clamped
% ZLEMPTY = Measurement without empty, 40 Hz to 110 MHz

% DC resistance
R_DC_L = 1.189e-3; % [Ohm]


% AC resistance
zlc_data = readmatrix('ProjectLabMeasurements/ZLCORE2.TXT');

f = zlc_data(1:1:length(zlc_data)/2-1,1);
amp = zlc_data(1:1:length(zlc_data)/2-1,2);
phase = zlc_data(length(zlc_data)/2+2:1:length(zlc_data),2);

figure(7)
subplot(2,1,1)
semilogx(f, amp, 'LineWidth', 4)
grid on
set(gca, 'FontSize', 18)
title('Inductor Impedance and Phase as a Function of Frequency', 'FontSize', 26)
xlabel('Frequency [Hz]', 'FontSize', 22)
ylabel('Impedance [\Omega]', 'FontSize', 22)
subplot(2,1,2)
semilogx(f, phase, 'LineWidth', 4)
grid on
set(gca, 'FontSize', 18)
xlabel('Frequency [Hz]', 'FontSize', 22)
ylabel('Phase [\circ]', 'FontSize', 22)

phase_rads = (2*pi)/360*phase;
[R_L, L_L] = pol2cart(phase_rads, amp);

figure(8)
subplot(2,1,1)
semilogx(f, R_L, 'LineWidth', 4)
grid on
set(gca, 'FontSize', 18)
title('Inductor with Core: AC Resistance as a Function of Frequency', 'FontSize', 26)
xlabel('Frequency [Hz]', 'FontSize', 22)
ylabel('AC Resistance [\Omega]', 'FontSize', 22)

subplot(2,1,2)
semilogx(f, L_L./(2*pi.*f), 'LineWidth', 4)
grid on
set(gca, 'FontSize', 18)
title('Inductor with Core: Inductance as a Function of Frequency', 'FontSize', 26)
xlabel('Frequency [Hz]', 'FontSize', 22)
ylabel('Inductance [H]', 'FontSize', 22)

R_AC_L = R_L(132)


% Inductance
% figure(9)
% semilogx(f, L_L, 'LineWidth', 4)
% grid on
% set(gca, 'FontSize', 18)
% title('Inductor Inductance as a Function of Frequency', 'FontSize', 26)
% xlabel('Frequency [Hz]', 'FontSize', 22)
% ylabel('Inductance [H]', 'FontSize', 22)

Lm_L = L_L(132)/(2*pi*394000)


% Capacitance
% fres with terminals not clamped together = 1.1e7;
% fres with terminals clamped together = 9.169414065e6;
% fres from data point = 9.275574176e6;
syms C
C_L = double(solve(9.275574176e+06 == 1/(2*pi*sqrt(Lm_L*C)), C))


% Leakage inductance
zle_data = readmatrix('ProjectLabMeasurements/ZLEMPTY.TXT');

f = zle_data(1:1:length(zle_data)/2-1,1);
amp = zle_data(1:1:length(zle_data)/2-1,2);
phase = zle_data(length(zle_data)/2+2:1:length(zle_data),2);

phase_rads = (2*pi)/360*phase;
[R_LE, L_L_lk] = pol2cart(phase_rads, amp);

figure(10)
semilogx(f, L_L_lk./(2.*pi.*f), 'LineWidth', 4)
grid on
set(gca, 'FontSize', 18)
title('Inductor without Core: Leakage Inductance as a Function of Frequency', 'FontSize', 25)
xlabel('Frequency [Hz]', 'FontSize', 22)
ylabel('Leakage Inductance [H]', 'FontSize', 22)

L_lk_L = L_L_lk(125)/(2*pi*400000)

% OR
% fres = 4.8666e07
syms L
L_lk_L = double(solve(4.8666e07 == 1/(2*pi*sqrt(L*C_L)), L))