clear, close all, clc;

% Lecture 5 Exercises:

%% Exercise 1:
% A system is digitally described by A, B, C, and D.

A = [2.7 0.8 0.7; 1 0 0; 0 1 0];
B = [1; 0; 0];
C = [0 0 1];
D = 0;

% Find the observer gain L for the reduced observer when the characteristic
% equation for the observer is given by
syms z
zper = 0.8;
alpha_er = expand((z - zper)^2); % = z^2 - 8/5*z + 16/25

% As C = [0 0 1], the Aaa, Aab, Aba, and Abb do not follow the picture from
% Lecture 5. For this reason, we change it to C = [1 0 0], which then
% necessitates using the state matrix [x3; x2; x1] instead of [x1; x2; x3].

% This requires also changing the A and B matrix.
C_adj = [C(3) C(2) C(1)];
B_adj = [B(3); B(2); B(1)];

% Additionally, the columns are reversed for the A matrix to ensure
% identical outputs.
A_adj = [A(3,3) A(3,2) A(3,1); A(2,3) A(2,2) A(2,1); A(1,3) A(1,2) A(1,1)];

% The A vectors are then found by using the approach as the picture from
% Lecture 5, in which known and unknown values are separated.
A_aa = A_adj(1,1)
A_ab = [A_adj(1,2) A_adj(1,3)]
A_ba = [A_adj(2,1); A_adj(3,1)]
A_bb = [A_adj(2,2) A_adj(2,3); A_adj(3,2) A_adj(3,3)]

L = acker(A_bb', A_ab', [zper zper])'


%% Exercise 2:
% Design a digital LSF controller and a digital reduced observer for the
% system G(s) and simulate.

fs = 50; % [Hz]
Ts = 1/fs; % [s]
T_set = 5; % [s]

% The transfer function of G(s) is
Gs = tf([4], [1 2 4 4]);

% The state-space matrices are
[A, B, C, D] = tf2ss(Gs.Numerator{1,1}, Gs.Denominator{1,1});

% And discretely
[Ad, Bd] = c2d(A, B, Ts);
Cd = C;
Dd = D;

% The poles of the system and faster observer are found
n = 3;
s_p = 1.5*(n+1)*-1/T_set;
s_per = s_p*2;

% Discretized
z_p = exp(s_p*Ts);
z_per = exp(s_per*Ts);


% To ease the calculations, the matrices are reversed to match the picture
% from the blackboard in Lecture 5.
C_adj = [Cd(3) Cd(2) Cd(1)];
B_adj = [Bd(3); Bd(2); Bd(1)];
A_adj = [Ad(3,3) Ad(3,2) Ad(3,1)
         Ad(2,3) Ad(2,2) Ad(2,1)
         Ad(1,3) Ad(1,2) Ad(1,1)];

A_aa = A_adj(1,1)
A_ab = [A_adj(1,2) A_adj(1,3)]
A_ba = [A_adj(2,1); A_adj(3,1)]
A_bb = [A_adj(2,2) A_adj(2,3); A_adj(3,2) A_adj(3,3)]

L_er = acker(A_bb', A_ab', [z_per z_per])'

B_a = B_adj(1);
B_b = [B_adj(2); B_adj(3)];


% The LSF values are calculated
K = acker(A_adj, B_adj, [z_p z_p z_p])