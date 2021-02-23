clear, close all, clc

%% Assignment 2:
% Part 1: Design a dq model of the PMSM in Simulink
% Datasheet:
Lq   = 1*10^-3; % H
Ld   = 1*10^-3; % H
R    = 1.5    ; % Ohm
L_M  = 0.1    ; % Nm/A
Kf   = 0.25   ; % Nm*s/rad
J    = 2      ; % kg*m²

% The q-part is completed by using the block diagram from Lecture 6
% PowerPoint. The d-part is found from the equation in same PowerPoint:
% vd = Rd*id + Ld * did/dt - Lq*w*iq

% Part 2: Design and implement PI controllers for the system and simulate a
% torque step response.

% notes: try different delays, bandwidths etc.

wc = 1000; % Resulting bandwidth: ~1500 rad/s
T = 1/((20*wc)/(2*pi));

% The dynamic models for dq are (roughly):
Gd = tf([1], [Ld R]);
Gq = tf([1], [Lq R]);

% As the models are identical for this assignment, just one transfer
% function needs to be found for the PI Controller, here using i_d.
% Map from continuous time into discrete time
Gdz = c2d(Gd, T);

% Make a bilinear transformation by Tustin mapping back into continuous
Gdw = d2c(Gdz, 'tustin');
[gain, phase] = bode(Gdw, wc);
figure(1)
margin(Gdw) % Plot of i_d model

% Design the PI controller in the continuous time
% The proportional part is solely a constant
kp = 1/gain; % Ensures crossover frequency is as wanted

% The integral part is then calculated
ki = 1; % I part's steady-state value, should not impact the system
wi = wc/10; % I part's natural frequency, should be around a decade lower than system's frequency due to phase impact
ti = 1/wi; % I part's time constant
Dps = tf([ti 1], [ti 0]);

% The resulting PI controller is then:
Ddpis = kp * Dps;

% Bode plot of plant with PI controller
figure(2)
[gain, phase] = bode(Gdw*kp*Dps, wc);
margin(Gdw*Ddpis)

% This must be transferred to the z-domain by Tustin
Ddpiz = c2d(Ddpis, T, 'tustin')

% Variables for use in Simulink:
Kp = kp;
Ti = ti;
Ki = Kp/ti;