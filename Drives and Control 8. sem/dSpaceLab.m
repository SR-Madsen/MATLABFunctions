clear, close all, clc;

%% dSpace Lab Project
% A report must be made containing:
% Measurement of DC-motor parameters and comparision with datasheet
% Deriving the DC-motor transfer function
% Simulation of the system without controller (PWM, H-bridge, motor)
% Comparing transfer function with simulation
% Design minimum two controllers, compare and comment on pros and cons.
% Implement the two controllers in dSpace, and compare with simulation.

% The simulation will be performed in SimScape (see dSpaceLab.slx)

% The datasheet's DC-motor parameters:
Ke = 0.0365; % [Vs/rad]
Ra = 2.96; % [Ohm]
La = 0.00251; % [H]
Kv = 2.6*10^-6; % [Nms/rad]
Jr = 4.2*10^-6; % [kg m^2]
Tf = 0.0042; % [Nm]

% Ideas on how to measure:
% Ra and La: Use an LCR meter
% Ke: Rotate at known speed and measure the winding voltage?
% Kv: When using steady-state values, Kv = Ke * di/dw (d = delta)
% Jr: Apply a known torque, measure the acceleration (J = t/a)
% Tf?: Find lowest voltage that doesn't make the motor rotate?

% Extra inertia load on setup
JL = 0.001; % [kg m^2]

% Resistor for load motor
RL = 10;

% For simulation
Vin = 24;
D = 0.5;
R_fet = 0.01; % [Ohm]
G_fet = 1e-8; % [1/Ohm]