clear, close all, clc;

%% In-Lecture Exercise: Linear State Feedback with Integrator
% Design a LSF with integrator (K and Ki) so the settling time is 3 sec.
% Build the system in Simulink blocks and simulate step response.
% The state space matrices are:
A = [0 1; -1 -2];
B = [0; 1];
C = [10 0];
D = 0;

% The poles, choosing t_settle = 3 seconds, with a third order system is:
n = 3;
s_p = -(1.5*(1+n))/3;

% The characteristic equation must then be
syms s
alpha_c = expand((s+s_p)^n); %s^3 - 6 * s^2 + 12 * s - 8 = 0
% This must be compared with the value of alpha_c for the LSF with int:
% alpha_c = |sI - [A-BK, BKi; -C, 0]| = 0
syms K1 K2 Ki
alpha_sys = det(s*eye(n)-[A-B*[K1 K2], B*Ki; -C, 0]);
% = s^3 + (2 + K2) * s^2 + (1 + K1) * s + 10 * Ki
% 10 * Ki = -8; Ki = -0.8
% 1 + K1 = 12; K1 = 11
% 2 + K2 = 6; K2 = 4

A_mark = [A, [0; 0]; -C, 0]
B_mark = [B; 0]
K = acker(A_mark, B_mark, [s_p, s_p, s_p])
K12 = [K(1) K(2)];
Ki = -K(3);
% Output is as follows: K1, K2, Ki