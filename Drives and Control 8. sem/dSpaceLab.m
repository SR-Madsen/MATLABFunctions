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
%Ke = 0.0365; % [Vs/rad]
%Ra = 2.96; % [Ohm]
%La = 0.00251; % [H]
%Kv = 2.6*10^-6; % [Nms/rad]
%Jr = 4.2*10^-6; % [kg m^2]
Tf = 0.0042; % [Nm]
Tf = 0;

% Ideas on how to measure:
% Ra: Apply known voltage at known rotation. R = (V-Ke*rads)/I
%     OR apply known voltage when fixing motor. R = V/I.
% La: Use an LCR meter
% Ke: Rotate at known speed and measure the winding voltage
% Kv: When using steady-state values, Kv = Ke * di/dw (d = delta)
% Jr: Apply a known torque, measure the acceleration (J = t/a)
% Tf?: Find lowest voltage that doesn't make the motor rotate?

% Measurements:
% Frequencies [100 Hz, 120 Hz, 1 kHz, 10 kHz, 100 kHz]
% La = [2.742e-3, 2.82e-3, 2.637e-3, 2.126e-3, 1.536e-3]
La = 2.637e-3
% Ra = 1.92/0.83; 0.95/0.41; 2.39/1.06; = 2.3
Ra = 1.92/0.83
% Ke = 6.07/(1560/60*2*pi); 10.62/(2800/60*2*pi); = 0.0365;
Ke = 6.07/(1560/60*2*pi)
% Kv = Ke * ((0.161-0.118)/((3500-1000)/60*2*pi)) = 6e-6;
%      OR Ke * ((0.161-0.149)/(3500-2450)/60*2*pi)) = 4e-6;
%
%   RPM = 1560 --> i = 0.260
%   RPM = 2390 --> i = 0.310
%
%   RPM = 2890 --> i = 0.33
%   RPM = 4490 --> i = 0.39
%
%   RPM = 1500 --> i = 0.25
%   RPM = 2390 --> i = 0.3
%
%   RPM = 2890 --> i = 0.33
%   RPM = 4490 --> i = 0.39
Kv_setup = Ke * ((0.161-0.149)/((3500-2450)/60*2*pi));
Kv_motor = Kv_setup/2
% Jr = tau/acc  --> tau = I * Ke = 2 * Ke, acc = deltaY/deltaX = 
%                   ((1266.35-56.89)/60*2*pi)/(0.10005-0.02005)
tau = 2 * Ke;
acc = ((1266.35-56.89)/60*2*pi)/(0.10005-0.02005);
J = tau/acc % TOTAL INTERTIA

% Extra inertia load on setup
rho_alu = 2700;
%rho_steel = 7800;
r = 3/100;
h = 1/100;
mass_alu = r^2*pi*h*rho_alu;
%mass_steel = r^2*pi*h*rho_steel;

JL = 1/2 * mass_alu * r^2; % [kg m^2]

Jr = (J - JL)/2 % INERTIA FOR ONE MOTOR

% Resistor for load motor
RL = 10;

% For simulation
Vin = 24;
V_load = -5;
D = 0.5;
R_fet = 0.01; % [Ohm]
G_fet = 1e-8; % [1/Ohm]


%% Controller Design:
% A digital PI controller will be designed in two different ways.
% The DC motor system to be controlled has the transfer function:
A = [-2*Kv_setup/J, Ke/J; -Ke/La, -Ra/La];
B = [0; 1/La];
C = [1, 0];
D = 0;

[num, den] = ss2tf(A,B,C,D)
G_DC = tf(num,den);

% The switching frequency is
f_sw = 750;

% The sampling frequency is
f_s = 20000;
T_s = 50e-6;

% A higher cross-frequency will mostly result in faster control, but is
% also more difficult to attain and results in overshoot and undershoot.
% For testing, the following is used:
f_c = 10;
w_c = 2*pi*f_c;

% The DC motor model is mapped into the discrete domain and ZOH'd:
G_DC_d = c2d(G_DC, T_s);
G_DC_zoh = d2c(G_DC_d, 'Tustin');
figure(1)
[gain, phase] = bode(G_DC_zoh, w_c);
margin(G_DC_zoh)

figure(2)
opt = stepDataOptions('StepAmplitude', 10);
step(G_DC, opt)

% This model is then used for designing the two controllers. These are
% first designed in the continuous domain, and then later mapped.

% First the PI Controller is designed using bilinear transformation:
% Proportional gain is adjusted to hit the cross-frequency.
kp = 1/gain;

% The integrator is then designed.
ki = 1; % Gain should not impact system
tau_i = 1/(w_c/25);

% The transfer function is thus
D_pi_num_s = kp*(ki*[tau_i 1]);
D_pi_den_s = [tau_i 0];
D_pi_s = tf(D_pi_num_s, D_pi_den_s);

% Which is mapped into the discrete domain
D_pi_z = c2d(D_pi_s, T_s, 'Tustin')

figure(3)
margin(G_DC_d*D_pi_z)

G_controlled = feedback(G_DC_d*D_pi_z, 1);
figure(4)
step(G_controlled)
%opt = stepDataOptions('StepAmplitude', 2000);
%step(G_controlled, opt)

% Bilinear (classic) PI Controller values for Simulink:
Kp_pi = kp;
Ki_pi = ki/tau_i;


% Calculation of PI Controller using LSF with integrator:
% The design is based on a wanted settling time of 0.1 second.
T_settle = 0.1;
n = 3;
syms s_p;
eq = T_settle == 1.5*(1+n)*-1/s_p;
s_p = double(vpasolve(eq,s_p))
z_p = exp(s_p*T_s)

% Marked matrices are designed for calculating K-values.
A_mark = [A [0; 0]; -C 0];
B_mark = [B; 0];

[Ad_mark, Bd_mark] = c2d(A_mark, B_mark, T_s);

% K-values to be used in Simulink
K_LSF = acker(Ad_mark, Bd_mark, [z_p, z_p, z_p]);
K_LSF_i = -K_LSF(3)
K_LSF_p = [K_LSF(2) K_LSF(1)]