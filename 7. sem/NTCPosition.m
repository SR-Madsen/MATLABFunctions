% This script calculates and graphically shows the inaccuracies for an NTC
% when placed high-side and low-side.
%% Setup
clear, close all, clc;

NTC_R = [45313, 26114, 15462, 9397, 5896, 3792, 2500,...
    1707, 1175, 834, 596, 436, 323, 243,...
    187, 144, 113, 89];
T = linspace(-40,130,18);
NTC_Tol = 5/100;

Res_R = 6980;
Res_Tol = 1/100;

Supply = 5;

NTC_min = NTC_R .* (1-NTC_Tol);
NTC_max = NTC_R .* (1+NTC_Tol);
Res_min = Res_R .* (1-Res_Tol);
Res_max = Res_R .* (1+Res_Tol);

%% Calculating scenarios for high-side NTC
V_nom_high = Supply .* Res_R ./ (NTC_R + Res_R);
V_minmin_high = Supply .* Res_min ./ (NTC_min + Res_min);
V_minmax_high = Supply .* Res_min ./ (NTC_max + Res_min);
V_maxmin_high = Supply .* Res_max ./ (NTC_min + Res_max);
V_maxmax_high = Supply .* Res_max ./ (NTC_max + Res_max);

figure(1)
plot(V_nom_high, T, V_minmin_high, T, V_minmax_high, T, V_maxmin_high, T, V_maxmax_high, T, 'LineWidth', 2)
grid on
title('Temperature as a function of voltages with different combinations of tolerance combinations, high-side NTC')
legend('Nominal', 'Min-min', 'Min-max', 'Max-min', 'Max-max', 'Location', 'northwest')
xlabel('Voltage [V]')
ylabel('Temperature [C]')

%% Calculating scenarios for low-side NTC
V_nom_low = Supply .* NTC_R ./ (NTC_R + Res_R);
V_minmin_low = Supply .* NTC_min ./ (NTC_min + Res_min);
V_minmax_low = Supply .* NTC_max ./ (NTC_max + Res_min);
V_maxmin_low = Supply .* NTC_min ./ (NTC_min + Res_max);
V_maxmax_low = Supply .* NTC_max ./ (NTC_max + Res_max);

figure(2)
plot(V_nom_low, T, V_minmin_low, T, V_minmax_low, T, V_maxmin_low, T, V_maxmax_low, T, 'LineWidth', 2)
grid on
title('Temperature as a function of voltages with different combinations of tolerance combinations, low-side NTC')
legend('Nominal', 'Min-min', 'Min-max', 'Max-min', 'Max-max', 'Location', 'northwest')
xlabel('Voltage [V]')
ylabel('Temperature [C]')

%% Relative accuracies
rel_acc_minmin_high = V_minmin_high ./ V_nom_high;
rel_acc_minmax_high = V_minmax_high ./ V_nom_high;
rel_acc_maxmin_high = V_maxmin_high ./ V_nom_high;
rel_acc_maxmax_high = V_maxmax_high ./ V_nom_high;
rel_acc_minmin_low = V_minmin_low ./ V_nom_low;
rel_acc_minmax_low = V_minmax_low ./ V_nom_low;
rel_acc_maxmin_low = V_maxmin_low ./ V_nom_low;
rel_acc_maxmax_low = V_maxmax_low ./ V_nom_low;

figure(3)
%plot(T, rel_acc_minmin_high, T, rel_acc_maxmax_high, T, rel_acc_minmin_low, T, rel_acc_maxmax_low)
plot(T, rel_acc_minmax_high, T, rel_acc_minmax_low, 'LineWidth', 2)
grid on
title('Relative accuracy of min-max tolerances as a function of temperature')
legend('High-side NTC', 'Low-side NTC', 'Location', 'northwest')
xlabel('Temperature [C]')
ylabel('Relative accuracy')

%% Including ADC inaccuracy
ADC_errbit = 11;
ADC_error = 11 * 5 / 4096;

V_ADC_high = V_minmax_high + ADC_error;
V_ADC_low = V_minmax_low + ADC_error;

rel_acc_ADC_high = V_ADC_high ./ V_nom_high;
rel_acc_ADC_low = V_ADC_low ./ V_nom_low;

figure(4)
plot(T, rel_acc_ADC_high, T, rel_acc_ADC_low, 'LineWidth', 2)
grid on
title('Relative accuracy of min-max tolerances with ADC inaccuracy as a function of temperature')
legend('High-side NTC', 'Low-side NTC', 'Location', 'northwest')
xlabel('Temperature [C]')
ylabel('Relative accuracy')