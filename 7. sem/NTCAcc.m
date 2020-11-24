% This script contains calculations on the NTC accuracy to find the
% deviation across the entire temperature range.
%% Initialization and Bosch NTC M12 characteristics
clear, close all, clc;

% Create matrices for relationship between temperature and resistance.
NTCTemp = [-40:10:150]; % [C]
NTCResistance = [45313,26114,15462,9397,5896,3792,2500,1707,1175, ... 
                 834,596,436,323,243,187,144,113,89,71,57]; % [Ohm]
InaccLow = 1.4; % [C]
InaccHigh = 3.4; % [C]
TempLow = 20; % [C]
TempHigh = 100; % [C]

SeriesRes = 6980; % [Ohm]
SupplyVoltage = 5; % [V]

OutputVoltage = SupplyVoltage * SeriesRes ./ (SeriesRes + NTCResistance);

% Perfect equation of temperature as a function of voltage below 30 degrees
% -65,4 + 43,1 * T - 11,6 * T^2 + 1,68 * T^3

% Perfect equation of temperature as a function of voltage above 30 degrees
% -29104 + 19644 * T - 4424 * T^2 + 333 * T^3

%% Inaccuracy due to NTC tolerance
% NTC inaccuracy assumed constant 1.4 C under 25 degrees and linear from 25
% degrees to 100 degrees C, where it is 3.4 C. Assumed constant over 100 C.
NTCInacc = 1:length(NTCTemp);
for i = 1:length(NTCTemp)
    if NTCTemp(i) < 25
        NTCInacc(i) = InaccLow;
    elseif NTCTemp(i) < 105
        NTCInacc(i) = InaccLow + (InaccHigh-InaccLow)/(TempHigh-TempLow) * NTCTemp(i-2);
    else
        NTCInacc(i) = InaccHigh;
    end
end

disp('Inaccuracy due to NTC:')
NTCInacc(3:end-5) % In degrees

%% Inaccuracy due to equation
EquationInacc = 1:length(NTCTemp);
for i = 1:length(NTCTemp)
    if NTCTemp(i) < 40
        EquationInacc(i) = (19.8 * OutputVoltage(i) - 52.3) - NTCTemp(i);
        %EquationInacc(i) = (-35 + 6.11 * OutputVoltage(i) + 2.46 * OutputVoltage(i)^2) - NTCTemp(i);
    else
        EquationInacc(i) = (2728 - 1261 * OutputVoltage(i) + 148 * OutputVoltage(i)^2) - NTCTemp(i);
        %EquationInacc(i) = (-29104 + 19644 * OutputVoltage(i) - 4424 * OutputVoltage(i)^2 + 333 * OutputVoltage(i)^3) - NTCTemp(i);
    end
end

disp('Inaccuracy due to equation:')
EquationInacc(3:end-5) % In degrees

%% Inaccuracy due to ADC
ADCLSBAcc = 11; % 11 LSB inaccuracy
ADCBit = 12; % 12-bit accuracy
ADCConvInacc = ADCLSBAcc * SupplyVoltage/(2^ADCBit);

ADCMeasVolt = OutputVoltage + ADCConvInacc;

ADCInacc = 1:length(NTCTemp);
for i = 1:length(NTCTemp)
    if NTCTemp(i) < 40
        ADCInacc(i) = (-65.4 + 43.1 * ADCMeasVolt(i) - 11.6 * ADCMeasVolt(i)^2 + 1.68 * ADCMeasVolt(i)^3) - ...
                      (-65.4 + 43.1 * OutputVoltage(i) - 11.6 * OutputVoltage(i)^2 + 1.68 * OutputVoltage(i)^3);
    else
        ADCInacc(i) = (-29104 + 19644 * ADCMeasVolt(i) - 4424 * ADCMeasVolt(i)^2 + 333 * ADCMeasVolt(i)^3) - ...
                      (-29104 + 19644 * OutputVoltage(i) - 4424 * OutputVoltage(i)^2 + 333 * OutputVoltage(i)^3);
    end
end

disp('Inaccuracy due to ADC:')
ADCInacc(3:end-5) % In degrees

%% Inaccuracy due to resistor tolerance
ResTol = 1; % [%]

WorstOutputVoltage = SupplyVoltage * (SeriesRes * (1 + ResTol/100)) ./ (SeriesRes * (1 + ResTol/100) + NTCResistance);

ResInacc = 1:length(NTCTemp);
for i = 1:length(NTCTemp)
    if NTCTemp(i) < 40
        ResInacc(i) = (-65.4 + 43.1 * WorstOutputVoltage(i) - 11.6 * WorstOutputVoltage(i)^2 + 1.68 * WorstOutputVoltage(i)^3) - ...
                      (-65.4 + 43.1 * OutputVoltage(i) - 11.6 * OutputVoltage(i)^2 + 1.68 * OutputVoltage(i)^3);
    else
        ResInacc(i) = (-29104 + 19644 * WorstOutputVoltage(i) - 4424 * WorstOutputVoltage(i)^2 + 333 * WorstOutputVoltage(i)^3) - ...
                      (-29104 + 19644 * OutputVoltage(i) - 4424 * OutputVoltage(i)^2 + 333 * OutputVoltage(i)^3);
    end
end

disp('Inaccuracy due to resistor tolerance:')
ResInacc(3:end-5) % In degrees

%% Accumulated inaccuracy
TotalInacc = abs(NTCInacc(3:end-5)) + abs(EquationInacc(3:end-5)) + abs(ADCInacc(3:end-5)) + abs(ResInacc(3:end-5))
%TotalInaccNonAbs = NTCInacc(3:end-5) + EquationInacc(3:end-5) + ADCInacc(3:end-5) + ResInacc(3:end-5)

plot(NTCTemp(3:end-5), TotalInacc(1:end), 'LineWidth', 2)
grid on
title('Total temperature variance due to all inaccuracies', 'FontSize', 20)
xlabel('Temperature [°C]', 'FontSize', 16)
ylabel('Inaccuracy [°C]', 'FontSize', 16)
