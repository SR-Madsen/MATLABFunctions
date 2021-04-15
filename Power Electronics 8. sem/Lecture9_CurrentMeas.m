clear, close all, clc;

%% In-Lecture Exercise: Current Measurement Resistor
% This is an example of shunt resistor design in a high-power converter.
% The currents are
I_RMS = 41;
I_PK = sqrt(2)*I_RMS;

% The measured current must then be higher to give a buffer;
I_meas = I_PK * 1.3;

% Choose either the 50 mV or 250 mV AMC1306 isolated ADC IC. Find a shunt
% resistor that complies with your choice and calculate the following:
% R_shunt, V_shunt, P_shunt, T_shunt. Use a graph for T_shunt.

% If using 250 mV:
R_250mV = 0.250/I_meas;
P_250mV = I_RMS^2 * R_250mV;
% This is 5.5 W, much too much for a resistor.
% The choice must then be 50 mV.
R_50mV = 0.05/I_meas; % = 663 µOhm.
% The closest real resistor is 680 µOhm.
R_50mV = 680e-6;
P_50mV = I_RMS^2 * R_50mV;
V_50mV = I_meas * R_50mV; % Slightly higher than 50 mV, but that's okay.
T_50mV = 30; % + Ambient; found from graph.