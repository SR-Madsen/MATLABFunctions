clear, close all, clc;

% dSpace Lab Project
%% SimScape Simulation and Motor Parameters:
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
% Ra: Apply known voltage at known rotation. R = (V-Ke*rads)/I
% La: Use an LCR meter
% Ke: Rotate at known speed and measure the winding voltage
% Kv: When using steady-state values, Kv = Ke * di/dw (d = delta)
% Jr: Apply a known torque, measure the acceleration (J = t/a)
% Tf?: Find lowest voltage that doesn't make the motor rotate?

% Measurements:
% Frequencies [100 Hz, 120 Hz, 1 kHz, 10 kHz, 100 kHz]
% La = [2.742e-3, 2.82e-3, 2.637e-3, 2.126e-3, 1.536e-3]
% Ra = 
% Ke =
% Kv = 
% Jr = 
% Extra inertia load on setup
JL = 0.001; % [kg m^2]

% Resistor for load motor
RL = 10;

% For simulation
Vin = 24;
D = 0.5;
R_fet = 0.01; % [Ohm]
G_fet = 1e-8; % [1/Ohm]

%% Controller Design:
% A digital PI controller will be designed in two different ways.
% The DC motor system to be controlled has the transfer function:
G_DC = tf([1], [La Ra]);

% The switching frequency is
f_sw = 1000;

% The sampling frequency is
f_s = 40000;
T_s = 1/f_s;

% A higher cross-frequency will mostly result in better control, but is
% also more difficult to attain. For testing, the following is used:
f_c = 100;
w_c = 2*pi*f_c;

% The DC motor model is mapped into the discrete domain and ZOH'd:
G_DC_d = c2d(G_DC, T_s);
G_DC_zoh = d2c(G_DC_d, 'Tustin');
figure(1)
[gain, phase] = bode(G_DC_zoh, w_c);
margin(G_DC_zoh)

% This model is then used for designing the two controllers. These are
% first designed in the continuous domain, and then later mapped.


% First the PI Controller:
% Proportional gain is adjusted to hit the cross-frequency.
kp = 1/gain;

% The integrator is then designed.
ki = 1; % Gain should not impact system
tau_i = La/Ra; % If they are accurate, this is good. Else try wi = wc/10.
%tau_i = 1/(w_c/10);

% The transfer function is thus
D_pi_num_s = (ki*[tau_i 1]);
D_pi_den_s = [tau_i 0];
D_pi_s = tf(D_pi_num_s, D_pi_den_s);

% Re-calculate gain for accuracy
[gain, phase] = bode(kp*D_pi_s*G_DC_zoh, w_c);
kp = kp * 1/gain;
D_pi_s = D_pi_s * kp;

% Which is mapped into the discrete domain
D_pi_z = c2d(D_pi_s, T_s, 'Tustin');

figure(2)
margin(G_DC_d*D_pi_z)

% PI Controller values for Simulink:
Kp_pi = kp;
Ki_pi = ki/tau_i;