clear, close all, clc;

%% Lecture 6 Exercise:
% Design a digital state space DC motor model with the terminal voltage as
% input and the position as output.

% Motor parameters:
Ra = 1;
La = 1;
Km = 0.1; Ka = Km;
J = 0.1;
B = 0.05;

% The differential equations are:
% v_in = R*i + L*di/dt + K_m*dtheta/dt
% => di/dt = 1/L*v_in - R/L*i - K_m/L*dtheta/dt
% J*d2theta/dt2 = K_a*i - B*dtheta/dt
% => d2theta/dt2 = K_a/J*i - B/J*dtheta/dt
% dtheta/dt = omega
% While the states are [theta; omega; i]

% d[theta; omega; i]/dt = [0 1 0; 0 -B/J K_a/J; 0 -K_m/L -R/L] [theta; omega; i]
%                       + [0; 0; 1/L] v_in
% theta = [1 0 0] [theta; omega; i] + [0 0 0] v_in

% Thus
A = [0 1 0; 0 -B/J Ka/J; 0 -Km/La -Ra/La]
B  = [0; 0; 1/La]
C = [1 0 0]
D = 0

% The switching frequency must be 20*BW_3db.
[num, den] = ss2tf(A,B,C,D);
Gs = tf(num,den)
% The integrator must be removed because of infinite DC gain
Gs_without_integrator = tf(1, [1 1.5 0.6])
omega_3db = bandwidth(Gs_without_integrator)

fs = 20*omega_3db;
Ts = 1/fs;

% Discretize state-space model
[Ad, Bd] = c2d(A, B, Ts)
Cd = C;
Dd = D;

% Then design a steady-state optimal LSF control with:
% a) Focus on the input voltage
% b) Focus on the input voltage and current
% c) Focus on the output

% Q and R must be chosen for each of these focus points.
% Q is the weight of the states, while R is the weight of the input.
Q_a = [1 0 0; 0 1 0; 0 0 1];
R_a = 10;

Q_b = [1 0 0; 0 1 0; 0 0 10];
R_b = 10;

Q_c = [10 0 0; 0 1 0; 0 0 1];
R_c = 1;

[K_a, S_a, eigen_a] = dlqr(Ad, Bd, Q_a, R_a)
[K_b, S_b, eigen_b] = dlqr(Ad, Bd, Q_b, R_b)
[K_c, S_c, eigen_c] = dlqr(Ad, Bd, Q_c, R_c)

% Simulate the three cases and compare voltage, current, position, and pole
% placement.