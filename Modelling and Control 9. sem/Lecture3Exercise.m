clear, close all, clc;

%% Lecture 3 Exercise
% There is a plant G(s) = 10/(s^2 + 2s) controlled with a PD controller.
Gs = tf(10, [1 2 0]);

%% Task 1:
% Part 1:
% Calculate the controller parameters Kp and Kd so the system gets a
% settling time of 1.5 seconds and all poles are located at the same point.
Ts = 1.5; % Settling time
n = 2; % Order of the system
syms sp
solve(Ts==1.5*(n+1)*-1/sp, sp); % = -3
sp_calc = -3;

% The expected characteristic function is then calculated as
alph_exp = expand((sp-sp_calc)^2); % = s^2 + 6*s + 9

% This is compared to the actual characteristic equation, which is

% alpha_act = 1 + (Kp - Kd*s) * B(s)/A(s)
% in which A(s) = (s^2 + 2s) and B(s) = 10

% alpha_act = 1 + (Kp - Kd*s) * 10/(s^2 + 2s)
%           = s^2 + 2s + 10*Kp - 10*Kd*s
%           = s^2 + (2 + 10*Kd)*s + 10*Kp

% 2 + 10*Kd = 6
Kd = 4/10

% 10*Kp = 9
Kp = 9/10

G_sys_cl = tf([10*Kd 10*Kp], [1 (2+10*Kd) (10*Kp)]);


% Part 2:
% Calculate the system bandwidth (3 dB)
bw_3db = bandwidth(G_sys_cl);


% Part 3:
% Calculate the Nyquist gain and phase margin (remember open loop)
sp = tf('s');
G_sys_op = (Kp + Kd*sp) * Gs;
figure(1)
margin(G_sys_op)


%% Task 2:
% Part 1:
% Transform the plant transfer function into a state-space representation.
[A, B, C, D] = tf2ss(Gs.Numerator{1,1}, Gs.Denominator{1,1});

% Part 2:
% Calculate a full state feedback so the system gets a settling time of 1.5
% seconds, and all poles are located at the same point.
K12 = acker(A, B, [sp_calc sp_calc])