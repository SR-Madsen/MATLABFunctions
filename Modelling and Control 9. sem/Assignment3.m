clear, close all, clc;

%% Assignment 3:
% A plant model is given Gs = 10/(s^2 + 3*s)
Gs = tf(10, [1 3 0]);

% Design a digital controller with full state feedback and observer for the
% states.
% The controlled system should have a damping ratio zeta = 1 and natural
% frequency of omega_n = 4 rad/s.
% The sampling frequency is fs = 10 Hz.
zeta = 1;
omega_n = 4;
fs = 10;
Ts = 1/fs;

%% Subtask 1:
% Is the plant controllable? Proof.

% First the state-space matrices are found.
[A, B, C, D] = tf2ss(Gs.Numerator{1,1}, Gs.Denominator{1,1})

[Ad, Bd] = c2d(A, B, Ts);
Cd = C;
Dd = D;

% The controllability matrix is then found for a second-order system
C0 = [B A*B]
ctrl_rank = rank(C0) % = 2, indicating full rank and controllable


%% Subtask 2:
% Is the plant observable? Proof.

% The observability matrix is found for a second-order system
O0 = [C; C*A];
obs_rank = rank(O0); % = 2, indicating full rank and observable


%% Subtask 3:
% Design the state estimator - 2 times quicker than the system.
s_pse = -2*omega_n;
z_pse = exp(s_pse*Ts); % = 0.4493

L = acker(Ad', Cd', [z_pse, z_pse])'

%% Subtask 4:
% Design the state feedback.
s_p = -omega_n;
z_p = exp(s_p*Ts); % = 0.6703

K = acker(Ad, Bd, [z_p, z_p])

%% Subtask 5:
% Simulate in Simulink - let the initial states in the analog plant differ
% from the initial digital estimated states.

% The Simulink model is created by using an analog plant (A, B, C,
% continuous integrator) and digital state estimator (using Ad, Bd, Cd
% time delay z^-1)