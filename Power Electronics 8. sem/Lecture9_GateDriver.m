clear, close all, clc;

%% Gate Driver Design In-Lecture Exercise
% An SMPS for a gaming pc is under development.
% The company already uses the MOSFET IPZ60R017C7 (see datasheet),
% and the gate driver IC UCC27710 (see datasheet), which must be re-used.
% Design the gate driver circuits.

% 1) For what type of gate driver is the gate driver IC recommended?
% It is designed as a floating channel with bootstrap operation.

% 2) What is the minimum gate voltage if the maximum voltage drop VDS,on
% should not exceed 4 V at Tj = 125 C and ID = 100 A?
% See Diagram 6 of MOSFET datasheet; approximately
VGS = 6; % [V]

% 3) What is the recommended and maximum gate voltage for the MOSFET?
% The maximum static (i.e. supplied) gate voltage is 20 V per Table 2 of
% the datasheet. The maximum dynamic (i.e. supplied + noise) gate voltage
% is 30 V.

% The maximum on-time for the MOSFET will be Ton = 100 µs, and the supplied
% voltage Vdd = 11 V. The capacitor has a leakage current I_leak = 35 µA,
% and the bootstrap diode has a forward voltage of VF = 0.75 V.
T_on = 100e-6;
Vdd = 11;
I_leak = 35e-6;
V_F = 0.75;

% 4) Find the remaining parameters to design the bootstrap capacitor from
% the datasheets.
% The capacitor is calculated as C_B = Q_total / Delta V_B
% in which Q_total = Q_G + (I_IC + I_leak)*T_on
% and Delta V_B = Vdd - V_IC - V_F - V_GE,min
Q_G = 240e-9; % Per Table 6 of datasheet
I_IC = 100e-6; % Per Section 7.5 of datasheet (only high-side is relevant)

V_IC = 110e-3; % Per Output Block of Section 7.5 of datasheet
V_GE = 3; % Per Table 4 of datasheet

% 5) Calculate the minimum capacity of the bootstrap capacitor including a
% safety margin of 100%
Q_total = Q_G + (I_IC + I_leak)*T_on;
DV_B = Vdd - V_IC - V_F - V_GE;
C_B = Q_total/DV_B;
C_B_safe = C_B * 2

% 6) What are the minimum values for the gate resistors R_G,on and R_G,off?
% From the gate driver datasheet:
I_on_max = 0.5;
I_off_max = 1;

% Then the resistors are, using the bootstrapped voltage,
R_G_on = (Vdd-V_F)/I_on_max
R_G_off = (Vdd-V_F)/I_off_max

% 7) What is the average power consumption of the gate driver if a
% switching frequency of 20 kHz is assumed?
f_sw = 20000;
% P_G,av = V_G * Q_G * f_sw
P_G = (Vdd-V_F) * Q_G * f_sw