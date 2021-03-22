clear, close all, clc;

%% In-Lecture Exercise: Linear State Feedback
% Design a digital Linear State Feedback (K-value) so the settling time is 3
% seconds.

% Using matrixes (corresponds to 10/(s^2+2*s+1):
A = [0 1; -1 -2];
B = [0; 1];
C = [10 0];

% Select a proper sampling time.
T = 1 / ((25 * bandwidth(tf([10], [2 2 1]))));

% Transform the state-space model to digital
[Ad, Bd] = c2d(A, B, T)
Cd = C;

% See Drives & Control Lecture 15 PowerPoint
% From Lecture 14 we know
s_p = -1.5;
% corresponding to
z_p = exp(1)^(s_p*T)

K = acker(Ad, Bd, [z_p, z_p])