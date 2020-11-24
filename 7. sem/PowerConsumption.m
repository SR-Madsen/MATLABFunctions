% This script calculates the power dissipated within the Master Controller
% enclosure from all sources, and calculates the resulting heat.
%% Setup
clc, clear, close all;

V_LV = [12; 24]; % [V, V], 12V and 24V nominal LV supplies
V_buck = [3.3, 5]; % [V, V], 3V3 and 5V power supplies'
V_boost = 12; % [V]

%% Power Dissipation 5V Supply
% Steer. Ang. Sensor Supply + 2x Torque Pedal Sensor
P_o_12V = (12*0.025) + 2*12^2/(2.1e3+1.24e3+2.5e3)
% Boost Converter Efficiency
eta_12V = 0.85;
P_in_12V = P_o_12V/eta_12V
P_diss_12V = P_in_12V * (1-eta_12V)
P_pico_5V = 7; P_exp_5V = 1; P_dist = 0.15; P_Pmeas = 0.15;
P_INS = 0.5 + 5*0.02; % VN-200 Power Consumption + Active Antenna consumption, dissipated outside of case
% PicoZed + Exp. Board + 12V Supply + INS + LVS Distribution
P_o_5V = P_pico_5V + P_exp_5V + P_in_12V + P_dist + P_INS + P_Pmeas;

%% Power Dissipation 3V3 Supply
P_pico_3V3 = 1; P_exp_3V3 = 0.5; P_CAN = 2*3.3*(0.02); P_DV = 0.2; P_ROM = 0.01;
P_SD = 3.3*0.1; P_sensor = 0.25;
% PicoZed IO Banks + Exp. Board + 2x CAN Transceivers + DV Eth + EEPROM +
% SD Card + Sensor filters and supplies
P_o_3V3 = P_pico_3V3 + P_exp_3V3 + P_CAN + P_DV + P_ROM + P_SD + P_sensor;
P_o = [P_o_3V3, P_o_5V]
I_o = P_o./V_buck;
eta = [0.85, 0.89; 0.76, 0.84]
P_in = P_o./eta
P_diss_buck = sum(P_in .* (1-eta),2)

%% Thermal Calculations Buck Converters
Rth_JA_buck = 12; % Junction-to-Ambient Thermal Resistance [K/W]
Rth_JC_buck = 1.9; % Junction-to-Case Thermal Resistance [K/W]
T_JA_buck = P_diss_buck * Rth_JA_buck
T_JC_buck = P_diss_buck * Rth_JC_buck

%% Power Dissipation for PoE Converter
P_o_PoE = 24*0.3; % [W] Power Consumption of Wireless Access Point
eta_PoE = 0.9;
P_in_PoE = P_o_PoE/eta_PoE
P_diss_PoE = P_in_PoE * (1-eta_PoE)

%% PROFET Power Dissipation
Rth_JA_1ch = 28; % [K/W]
Rth_JA_2ch = 29; % [K/W]

R_Dual = 38e-3; % BTT6030-2EKA at 85 degrees
R_Single = 13e-3; % BTT6010-1EKB at 85 degrees

I_Dual = 9e-3; % BTT6030-2EKA operating current
I_Single = 5e-3; % BTT6010-1EKB operating current

I_PFET1 = [1, 1]; I_PFET1(2,:) = 0.7*I_PFET1; % [A]
I_PFET2 = [2,2.5]; I_PFET2(2,:) = 0.7*I_PFET2; % [A]
I_PFET3 = [1,2.5]; I_PFET3(2,:) = 0.7*I_PFET3; % [A]
I_PFET4 = 7; I_PFET4(2,:) = 0.7 * I_PFET4; % [A]
I_PFET5 = 0.5; % [A]

P_PFET1 = sum(I_PFET1.^2 * R_Dual,2) + I_Dual * V_LV
T_JA_FET1 = P_PFET1 * Rth_JA_2ch
P_PFET2 = sum(I_PFET2.^2 * R_Dual,2) + I_Dual * V_LV
T_JA_FET2 = P_PFET2 * Rth_JA_2ch
P_PFET3 = sum(I_PFET3.^2 * R_Dual,2) + I_Dual * V_LV
T_JA_FET3 = P_PFET3 * Rth_JA_2ch
P_PFET4 = sum(I_PFET4.^2 * R_Single,2) + I_Single * V_LV
T_JA_FET4 = P_PFET4 * Rth_JA_1ch
P_PFET5 = sum(I_PFET5.^2 * R_Single,2) + I_Single * 24
T_JA_FET5 = P_PFET5 * Rth_JA_1ch

% Below use values from tests
%P_PFET1 = sum([38.5, 38.5]*1e-3); % [mW]
%T_JA_FET1 = P_PFET1 * Rth_JA_2ch
%P_PFET2 = sum([138.7, 209.7]*1e-3); % [mW]
%T_JA_FET2 = P_PFET2 * Rth_JA_2ch
%P_PFET3 = sum([38.5, 209.7]*1e-3); % [mW]
%T_JA_FET3 = P_PFET3 * Rth_JA_2ch
%P_PFET4 = 773.2e-3; % [mW]
%T_JA_FET4 = P_PFET4 * Rth_JA_1ch
%P_PFET5 = 7.7e-3; % [mW]
%T_JA_FET5 = P_PFET5 * Rth_JA_1ch

P_diss_PFET = P_PFET1 + P_PFET2 + P_PFET3 + P_PFET4 + P_PFET5

%% LED/Relay/Optocoupler Power Dissipation
I_LED = 5e-3; % LED currents are all 5 mA
LED_3V3 = 10; % Amount of 3.3V LEDs
LED_5V = 1; % Amount of 5V LEDs
LED_LVS = 3; % Amount of LVS LEDs
P_LED = LED_3V3 * (I_LED * 3.3) + LED_5V * (I_LED * 5) + LED_LVS ...
    * (I_LED .* V_LV)

I_2Opto = 4.8e-3; % Dual optocoupler (24V/12V) currents
I_1Opto = 1e-3; % Single optocoupler (5V) current
Opto_LVS = 11; % Amount of LVS optocouplers
Opto_5V = 1; % Amount of 5 V optocouplers
P_opto = Opto_5V * (I_1Opto * 5) + Opto_LVS * (I_2Opto .* V_LV)

I_SSR = 1.5e-3; % Solid-State Relay currents are 1.5 mA
SSR_1V8 = 2; % Amount of 1.8 V SSRs
P_SSR = SSR_1V8 * (I_SSR * 1.8)

%% Shunts Power Dissipation
P_LVS_Shunt = [20^2 * 0.001, (0.7*20)^2 * 0.001]
P_RTDS_Shunt = 0.008^2 * 5.6
P_Brake_Shunt = 0.06^2 * 0.75
P_Shunts = [P_LVS_Shunt(1) + P_RTDS_Shunt + P_Brake_Shunt; P_LVS_Shunt(2) ...
    + P_RTDS_Shunt + P_Brake_Shunt];

%% Fuses Power Dissipation
P_Fuse_SC_2A = Opto_LVS * 55.6*10^-3 .* [I_2Opto; I_2Opto/2].^2;
P_Fuse_SensNet_2A = 37.3*10^-3 .* I_PFET3(:,1);
P_Fuse_LV_15A = (7.42*10^-3 .* (sum(I_PFET1,2) + sum(I_PFET4,2)).^2) + (4.58*10^-3 .* (sum(I_PFET2,2) + sum(I_PFET3,2)).^2);
P_Fuse_ACT_375mA = (0.4518 * (8 * 10^-3)^2) + (0.4518 * (60 * 10^-3)^2);
P_Fuse_24V_1A = 77.6 * 10^-3 .* [1; 0.7*1].^2;
P_Fuse_Choke_7A = 9.2 * 10^-3 .* [5; 0.7*5].^2;
P_Fuse_12V_375mA = 0.4518 .* [0.1; 0.1].^2;
P_Fuse_5V_5A = 12.7*10^-3 .* [2; 2].^2;
P_Fuse_3V3_5A = 12.7*10^-3 .* [1; 1].^2;
P_Fuse_5VSens_1A = 77.6*10^-3 .* [0.3; 0.3].^2;
P_Fuse_CMC_10A = 3 * (5.8*10^-3 .* [20/3; 0.7*20/3].^2);

P_Fuses = P_Fuse_SC_2A + P_Fuse_SensNet_2A + P_Fuse_LV_15A + P_Fuse_ACT_375mA + ...
    P_Fuse_24V_1A + P_Fuse_Choke_7A + P_Fuse_12V_375mA + P_Fuse_5V_5A + P_Fuse_3V3_5A + ...
    P_Fuse_5VSens_1A + P_Fuse_CMC_10A

%% Power Consumption Calculations
P_diss = P_diss_12V + P_diss_buck + P_diss_PoE + P_diss_PFET + P_dist + ...
    P_DV + P_exp_3V3 + P_exp_5V + P_pico_3V3 + P_pico_5V + P_SD + ...
    P_sensor + P_LED + P_opto + P_SSR + P_Shunts + P_Fuses + P_Pmeas

c_P = 1.012; % [J/gK] Air specific heat (typical room)
rho = 1190; % [g/m3] Air density (50% humidity)
A = (0.246 * 0.171) - (0.013^2 * pi); % [m] Internal area of case, minus rounded corners
h = 0.057; % [m] Internal height of case
m_air = rho * A * h; % [g] Mass of air

% Energy to heat the case a critical amount (30 degrees Celcius)
T_delta = 30; % [C]
U = (c_P * m_air * T_delta) * 1000; % [J]

% How long will this take with the power dissipation of the PCB?
%t_delta = U ./ P_diss % [s]
t_delta_mins = (U ./ P_diss) / 60 % [min]