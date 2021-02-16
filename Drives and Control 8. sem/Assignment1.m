clear, close all, clc

%% Assignment 1: Controlling a DC electrical motor
% Design a suitable digital serial controller for the DC motor.
% The rotational velocity omega is the controlled output.
% Open-loop cross frequency must be omega_c = 300 rad/s.
% The steady-state error e_ss must be 0.
% The phase margin PM must be at or above 70 degrees.

% Simulate the system with control in Simulink.

% The following motor data is known:
K = 1.5; % Back-EMF factor, Nm/A and Vs/rad
L = 0.01; % Motor inductance, H
R = 1.9; % Motor resistance, Ohm
J = 1.2e-2; % Moment of inertia, kg m²
Kb = 1.1e-2; % Frictional factor, Nms/rad (F_friction = Kb * omega)

wc = 300;
PM = 70;
%T = 0.001;

% Using a sampling rate 20 times faster than the cross frequency
T = 1/((20*wc)/(2*pi))

% Equation for voltage:
% v = R * I + L * I * s + K * omega

% Equation for motor rotation:
% J * omega * s = K * I - Kb * omega (- load torque)

% Isolating the second equation for I results in:
% I = ((J * s + Kb) * omega) / K

% The transfer function is then:
% omega/v = K / ((R + L * s) * (J * s + Kb) + K²)
num = [K];
%syms s
%den = expand((R + L*s) * (J*s + Kb) + K^2)
den = [3/25000 2291/100000 22709/10000];
Gp = tf(num, den)

% Map the plant into discrete time
Gpz = c2d(Gp, T);

% Make a bilinear transformation by Tustin mapping back into continuous
Gpw = d2c(Gpz, 'tustin');
[gain, phase] = bode(Gpw, wc)
figure(1)
margin(Gpw)

% Design the PID controller in the continuous time
% The proportional part is solely a constant
kp = 1/gain;

% The integral part is then calculated
ki = 1; % I part's steady-state value, should not impact the system
wi = 30; % I part's natural frequency, should be around a decade lower than system's frequency due to phase impact
ti = 1/wi; % I part's time constant

% Bode plot of plant with PI controller to check phase
Dps = tf([ti 1], [ti 0]);
figure(2)
[gain, phase] = bode(Gpw*kp*Dps, wc)
margin(Gpw*kp*Dps)

% Calculating required phase boost
Fmax = PM - (phase - 180);

% The derivative part is then calculated
alpha = (1 - sind(Fmax))/(1 + sind(Fmax));
kd = sqrt(alpha);
td = 1/(sqrt(alpha)*wc);
Dds = tf(kd * [td 1], [alpha*td 1]);
figure(3)
margin(Gpw*kp*Dps*Dds)

% The resulting PID controller is then:
Dpids = kp * Dps * Dds

% This must be transferred to the z-domain by Tustin
Dpidz = c2d(Dpids, T, 'tustin')

% Check to confirm that the digital plant and controller have same
% transfer function as analog versions
figure(4)
margin(Dpidz*Gpz)