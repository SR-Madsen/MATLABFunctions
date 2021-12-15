%% GaN vs Si Figure of Merit
clear, close all, clc;


%% GaN Transistors
% All 100 V. All resistances in mOhm, charges in nC

% EPC2204
Rdson_EPC2204 = 4.4;
Qg_EPC2204 = 5.7;
fom_EPC2204 = Rdson_EPC2204 * Qg_EPC2204;

% EPC2218
Rdson_EPC2218 = 2.4;
Qg_EPC2218 = 10.5;
fom_EPC2218 = Rdson_EPC2218 * Qg_EPC2218;

% EPC2045
Rdson_EPC2045 = 5.6;
Qg_EPC2045 = 6;
fom_EPC2045 = Rdson_EPC2045 * Qg_EPC2045;

% EPC2052
Rdson_EPC2052 = 10;
Qg_EPC2052 = 3.5;
fom_EPC2052 = Rdson_EPC2052 * Qg_EPC2052;

% GS61004B
Rdson_GS61004B = 16;
Qg_GS61004B = 3.3;
fom_GS61004B = Rdson_GS61004B * Qg_GS61004B;

% GS61008T
Rdson_GS61008T = 7;
Qg_GS61008T = 8;
fom_GS61008T = Rdson_GS61008T * Qg_GS61008T;

Rds_GaN = [Rdson_EPC2204, Rdson_EPC2218, Rdson_EPC2045, Rdson_EPC2052, Rdson_GS61004B, Rdson_GS61008T];
Qg_GaN = [Qg_EPC2204, Qg_EPC2218, Qg_EPC2045, Qg_EPC2052, Qg_GS61004B, Qg_GS61008T];
fom_GaN = [fom_EPC2204, fom_EPC2218, fom_EPC2045, fom_EPC2052, fom_GS61004B, fom_GS61008T];


%% Si Transistors
% All 100 V. All resistances in mOhm, charges in nC.

% SI7454FDP-T1-RE3
Rdson_SI7454 = 24.6;
Qg_SI7454 = 17.4;
fom_SI7454 = Rdson_SI7454 * Qg_SI7454;

% AUIRF7669L2TR
Rdson_AUIRF7669 = 3.5;
Qg_AUIRF7669 = 81;
fom_AUIRF7669 = Rdson_AUIRF7669 * Qg_AUIRF7669;

% IPT020N10N3
Rdson_IPT020N10N3 = 1.7;
Qg_IPT020N10N3 = 156;
fom_IPT020N10N3 = Rdson_IPT020N10N3 * Qg_IPT020N10N3;

% NTMFS10N3D2
Rdson_NTMFS = 2.4;
Qg_NTMFS = 60;
fom_NTMFS = Rdson_NTMFS * Qg_NTMFS;

% FDB0300N1007L
Rdson_FDB0300 = 2.4;
Qg_FDB0300 = 81;
fom_FDB0300 = Rdson_FDB0300 * Qg_FDB0300;

% FDMS86104
Rdson_FDMS = 20;
Qg_FDMS = 11.7;
fom_FDMS = Rdson_FDMS * Qg_FDMS;

% ISC0805NLS
Rdson_ISC08 = 7.2;
Qg_ISC08 = 13;
fom_ISC08 = Rdson_ISC08 * Qg_ISC08;

Rds_Si = [Rdson_SI7454, Rdson_AUIRF7669, Rdson_IPT020N10N3, Rdson_NTMFS, Rdson_FDB0300, Rdson_FDMS, Rdson_ISC08];
Qg_Si = [Qg_SI7454, Qg_AUIRF7669, Qg_IPT020N10N3, Qg_NTMFS, Qg_FDB0300, Qg_FDMS, Qg_ISC08];
fom_Si = [fom_SI7454, fom_AUIRF7669, fom_IPT020N10N3, fom_NTMFS, fom_FDB0300, fom_FDMS, fom_ISC08];


%% Plots
%x_GaN = 1:1:length(fom_GaN)
%x_Si = length(fom_GaN)+1:1:length(fom_GaN)+length(fom_Si)

figure(1)
hold on
grid on

% FoM of transistor
%plot(x_GaN, fom_GaN, '*', x_Si, fom_Si, '.', 'LineWidth', 4)

% Gate charge vs on-resistance
plot(Rds_GaN, Qg_GaN, '*', Rds_Si, Qg_Si, '*', 'LineWidth', 8)

set(gca, 'FontSize', 18)

legend('Gallium Nitride', 'Silicon')

title('GaN and Si FETs on-resistance and gate charge', 'FontSize', 26)
xlabel('On-resistance [m\Omega]', 'FontSize', 22)
ylabel('Gate charge [nC]', 'FontSize', 22)