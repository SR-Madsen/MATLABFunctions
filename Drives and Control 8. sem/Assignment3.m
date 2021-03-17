clear, close all, clc;

%% Assignment 3: A plant is given. Design a digital PID and IPD controller.
% The controlled system characteristic equation must become
% alpha_c(s) = (s + 1)^3

% Use MATLAB / Simulink and simulate step response for the PID and the IPD.
% Try with different sampling times.

% The plant is G_p(s) = 2/(s^2 + 2*s + 2)
% Thus B(s) = 2
% A(s) = (s^2 + 2*s + 2)

Gp = tf([2], [2 2 2]);
bw = bandwidth(Gp);
T = [1/(2.5*bw) 1/(10*bw) 1/(25*bw)];

syms s
alpha_c = expand((s + 1)^3); % = s^3 + 3 * s^2 + 3 * s + 1

% This must be compared with the expected values for the characteristic
% equation, which is:
% alpha_act = A(s) * s + (K_p + K_i/s + K_d*s)*s * B(s)
% = s^3 + 2*s^2 + 2s + 2*K_p*s + 2*K_i + 2*K_d*s^2
% = s^3 + (2+2*K_d)*s^2 + (2+2*K_p)*s + 2*K_i
% From which the values can then be found by comparing,
Kd = 1/2; % 2 + 2 * K_d = 3 --> 1 = 2 * Kd
Kp = 1/2; % 2 + 2 * K_p = 3 --> 1 = 2 * K_p
Ki = 1/2; %                     1 = 2 * K_i