
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

%% Subtask 1:
% Is the plant controllable? Proof.

% First the state-space matrices are found.
[A, B, C, D] = tf2ss(Gs.Numerator{1,1}, Gs.Denominator{1,1})

% The controllability matrix is then found for a second-order system
C0 = [B A*B];
ctrl_rank = rank(C0); % = 2, indicating full rank and controllable


%% Subtask 2:
% Is the plant observable? Proof.

% The observability matrix is found for a second-order system
O0 = [C; C*A];
obs_rank = rank(O0); % = 2, indicating full rank and observable


%% Subtask 3:
% Design the state estimator - 2 times quicker than the system.



%% Subtask 4:
% Design the state feedback.


%% Subtask 5:
% Simulate in Simulink - let the initial states in the analog plant differ
% frm the initial digital estimated states.