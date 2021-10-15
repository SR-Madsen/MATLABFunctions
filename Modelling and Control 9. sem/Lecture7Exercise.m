clear, close all, clc;

%% Lecture 7: Kalman Observer Exercise

% Given a state-space model in continuous time, calculate the optimal
% observer gain L0 with various plant noise Rw and measuring noise Rv
% variances. There is no noise cross covariance.

A = [0, 1; -1, -2];
B = [0; 1];
B1 = [1; 1];
C = [1, 0];
D = 0;

plant = ss(A, [B B1], C, D); % As in MATLAB's Kalman documentation

Rwv = 0;

% Calculate with different noise variances and simulate in Simulink.

% a) Rw = Rv = 1
Rw = 1;
Rv = 1;
[kalmf, L, P] = kalman(plant, Rw, Rv, Rwv)

% b) Rw = 0.1, Rv = 1
%Rw = 0.1;
%Rv = 1;
%[kalmf, L, P] = kalman(plant, Rw, Rv, Rwv)

% c) Rw = 1, Rv = 0.1
%Rw = 1;
%Rv = 0.1;
%[kalmf, L, P] = kalman(plant, Rw, Rv, Rwv)


% LQR feedback (random)
Q = [1 0; 0 1];
R = 1;
[K, S, eigen] = dlqr(A, B, Q, R);