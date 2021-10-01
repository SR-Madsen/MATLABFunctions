clc, clear, close all;
% Constants
V_ref = 5; % [V]
lw = 1.5; % LineWidth
T = linspace(-40,130,18); % Array of temperatures
Rth = [45.313, 26.114, 15.462, 9.397, 5.896, 3.792, 2.5,...
    1.707, 1.175, 0.834, 0.596, 0.436, 0.323, 0.243,...
    0.187, 0.144, 0.113, 0.089]; %[k Ohm], array of thermistor resistance
R = 6.98; % [kOhm]
Vout_nom = V_ref*R./(R+Rth); % Nominal output voltage
C2K = 273.15; % Celsius to Kelvin offset
ADC_error = 1.71e-3; % [V], ADC Error

% Remaking Thermistor tolerance dependent on temperature
R_tol = ones(1,18);
tol_a = (1-Vout_nom(1))/(25-(-40));
tol_b = (Vout_nom(end)-1)/(130-25);
tol_off1 = 1 - (tol_a*25);
tol_off2 = 1 - (tol_b*25);
R_tol(1:8) = R_tol(1:8) * tol_a.*T(1:8) + tol_off1;
R_tol(9:end) = R_tol(9:end) * tol_b.*T(9:end) + tol_off2;
figure(1)
plot(T,R_tol,'LineWidth',lw); title('Tolerance vs Temperature'); 
ylabel('Tolerance, [%]'), xlabel('Temperature, [\circC]')
axis([-40,130,0,5]), grid

R_tol = R_tol/100; % Percentage to decimal number

% Calculation of maximal and minimal thermistor resistances
Rth_max = Rth.*(1+R_tol);
Rth_min = Rth.*(1-R_tol);

% Calculation of maximal and minimal resistor resistance
R_max = R*1.01;
R_min = R*0.99;

% Calculation of output voltages in different 
% combinations of maximal and minimal values
Vout_MM = V_ref*R_max./(R_max + Rth_max); % Max-Max
Vout_mM = V_ref*R_min./(R_min + Rth_max); % min-Max
Vout_Mm = V_ref*R_max./(R_max + Rth_min); % Max-min
Vout_mm = V_ref*R_min./(R_min + Rth_min); % min-min

figure(2)
plot(T,Vout_MM,'r','LineWidth',lw); hold on; grid
plot(T,Vout_mM,'b','LineWidth',lw);
plot(T,Vout_Mm,'k','LineWidth',lw);
plot(T,Vout_mm,'g','LineWidth',lw);
title('Output voltage vs temperature')
ylabel('Output Voltage, [V]'), xlabel('Temperature, [\circC]')
legend('min-Max','Max-Max','Max-min',...
    'min-min', 'Location', 'northeast')
axis([-40,130,0,3])

% Relative Accuracies
rel_acc_mM = Vout_mM./Vout_nom;
rel_acc_MM = Vout_MM./Vout_nom;
rel_acc_Mm = Vout_Mm./Vout_nom;
rel_acc_mm = Vout_mm./Vout_nom;

figure(3)
plot(T,rel_acc_mM,'k','LineWidth',lw); hold on; grid
plot(T,rel_acc_MM,'b','LineWidth',lw);
plot(T,rel_acc_Mm,'r','LineWidth',lw);
plot(T,rel_acc_mm,'g','LineWidth',lw);
title('Relative Accuracies vs temperature')
ylabel('Relative Accuracy'), xlabel('Temperature, [\circC]')
legend('min-Max','Max-Max','Max-min',...
    'min-min', 'Location', 'northwest')
axis([-40,130,0.95,1.05])

T = T + C2K;
% Absolute Accuracies
T_X_mM = T.*rel_acc_mM - T;
T_X_MM = T.*rel_acc_MM - T;
T_X_Mm = T.*rel_acc_Mm - T;
T_X_mm = T.*rel_acc_mm - T;

T = T - C2K;

% With ADC error
V_ADC = Vout_Mm + ADC_error;
rel_acc_adc = V_ADC./Vout_nom;

T = T + C2K;
T_X_ADC = T.*rel_acc_adc - T;
T = T - C2K;

figure(4)
plot(T,T_X_mM,'k','LineWidth',lw); hold on; grid
plot(T,T_X_MM,'b','LineWidth',lw);
plot(T,T_X_Mm,'r','LineWidth',lw);
plot(T,T_X_mm,'g','LineWidth',lw);
plot(T,T_X_ADC,'r--','LineWidth',lw)
title('Absolute Accuracy of temperature sensor vs Temperature')
ylabel('Absolute Accuracy, [\circC]')
xlabel('Temperature, [\circC]')
legend('min-Max','Max-Max','Max-min','min-min',...
    ['Max-min', newline, 'with ADC error'],'Location', 'northeast')
axis([-40,130,-10,10])
