clear, close all, clc;

%% In-Lecture Exercise: Linear State Feedback
% Design a Linear State Feedback (K-value) so the settling time is 3
% seconds.

% Using matrixes:
A = [0 1; -1 -2];
B = [0; 1];
C = [10 0];

% See Drives & Control Lecture 14 notes (PowerPoint or in hand) for
% calculations of K values.
K = [1.25, 1]

% Alternate way of calculating using MATLAB:
sp = -1.5; % Calculated by hand
K_ml = acker(A,B,[sp sp])

% This must then be simulated (step response) in Simulink using blocks (see
% PowerPoint from Lecture 14 for block diagram)