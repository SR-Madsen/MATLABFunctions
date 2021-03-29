clear, close all, clc;

%% Assignment 4: A state space model is given for a dynamic plant.
% Implement an analog Linear State Feedback controller with integrator.
% Implement a digital Linear State Feedback controller with integrator.
% The characteristic equation must be alpha_c = (s + 1)^3.
% The digital controller must have a sampling frequency of [10 100] Hz.
% Simulate step response for all three solutions.

A = [0 1; -5 -2];
B = [0; 1];
C = [5 0];
D = [0];

% Analog
syms s
alpha_c = expand((s+1)^3); % alpha_c = s^3 + 3 * s^2 + 3 * s + 1
% This is also equal to |sI - [A-BK, BKi; -C, 0]| = 0, from which
% K-placement can be performed. In the interest of time, however:
s_p = [-1 -1 -1];

A_mark = [A [0; 0]; -C 0]
B_mark = [B; 0]

K = acker(A_mark, B_mark, s_p)
% K = [K1, K2, Ki]

% Digital
T_10Hz = 1/10;
T_100Hz = 1/100;

% Transform the state-space model to digital
[Ad, Bd] = c2d(A_mark, B_mark, T_10Hz)
Cd = C;
Dd = D;

[Ad_100, Bd_100] = c2d(A_mark, B_mark, T_100Hz);

% The digital poles are then found
z_p_1 = exp(1)^(s_p(1)*T_10Hz)
z_p_2 = exp(1)^(s_p(1)*T_100Hz)

% K-placement
K_10 = acker(Ad, Bd, [z_p_1, z_p_1, z_p_1])
K_100 = acker(Ad_100, Bd_100, [z_p_2, z_p_2, z_p_2])