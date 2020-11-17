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
% -29102 + 19644 * T - 4424 * T^2 + 333 * T^3

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

NTCInacc % In degrees

%% Inaccuracy due to equation
EquationInacc = 1:length(NTCTemp);
for i = 1:length(NTCTemp)
    if NTCTemp(i) < 40
        EquationInacc(i) = (19.8 * OutputVoltage(i) - 52.3) - NTCTemp(i);
    else
        %EquationInacc(i) = (2728 - 1261 * OutputVoltage(i) + 148 * OutputVoltage(i)^2) - NTCTemp(i);
        EquationInacc(i) = (-29104 + 19644 * OutputVoltage(i) - 4424 * OutputVoltage(i)^2 + 333 * OutputVoltage(i)^3) - NTCTemp(i);
    end
end

EquationInacc % In degrees

%% Inaccuracy due to ADC
ADCConvInacc = 11 * 5/(2^12); % 11 LSB inaccuracy

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

ADCInacc % In degrees

%% Inaccuracy due to resistor tolerance
ResTol = 1; % [%]

WorstOutputVoltage = SupplyVoltage * (SeriesRes * (1 + ResTol/100)) ./ (SeriesRes + NTCResistance);

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

ResInacc % In degrees

%% Accumulated inaccuracy
TotalInacc = abs(NTCInacc) + abs(EquationInacc) + abs(ADCInacc) + abs(ResInacc)

plot(NTCTemp(4:end-5), TotalInacc(4:end-5))
