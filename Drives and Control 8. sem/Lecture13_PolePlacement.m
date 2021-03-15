clear, close all, clc;

%% In-Lecture Exercise: Place all three poles for a PID and IPD at -0.5 and simulation a step response.
% What are the settling times?
% Use the plant G(s) = 10 / (s^2 + 2*s + 1)
Gs = tf([10], [1 2 1]);
% B(s) = 10, A(s) = s^2 + 2*s + 1)

% Using the 5% formula:
% T_s is the settling time.
% Poles are placed at 1.5 * (1 + n) / T_s, where n is the order.
% Thus (1.5 * (1 + 3)) / T_s = 0.5
% The settling time is then (1.5 * (1 + 3)) / 0.5 = 12 s

% The Ki, Kp, and Kd values must then be calculated.
% The characteric equation will be
p = 0.5;
syms s
alpha = expand((s+p)^3); % s^3 + 1.5*s^2 + 3/4*s + 1/8

% This must be compared with the expected values for the characteristic
% equation, which is:
% alpha_act = A(s) * s + (K_p + K_i/s + K_d*s)*s * B(s)
% = s^3 + 2*s^2 + s + 10*K_p*s + 10*K_i + 10*K_d*s^2
% = s^3 + (2+10*K_d)*s^2 + (1+10*K_p)*s + 10*K_i
% From which the values can then be found by comparing,
Kd = -0.5/10; % 2 + 10 * K_d = 1.5 --> -0.5 = 10 * Kd
Kp = -0.25/10; % 1 + 10 * K_p = 3/4 --> -0.25 = 10 * K_p
Ki = (1/8)/10;