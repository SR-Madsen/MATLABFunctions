clear, close all, clc;

%% In-Lecture Exercise: Polynomial control

% Plant is given: Gp(s) = 2/(s^2 + 5s - 6)
Gp = tf(2, [1 5 -6]);

b1 = Gp.Numerator{1,1}(2);
b0 = Gp.Numerator{1,1}(3);
a1 = Gp.Denominator{1,1}(2);
a0 = Gp.Denominator{1,1}(3);

% Calculate the feedback and filter transfer functions

% First the poles are placed from the settling time and final order
T_set = 3; % [s]
n = 3;

s_p = (-1.5 * (n + 1)) / T_set; % = -1.5

% The wanted characteristic equation is then found
syms s
alpha_c = expand((s-s_p)^(n)); % = s^3 + 6s^2 + 12s + 8

% From this we get:
d2 = 6;
d1 = 12;
d0 = 8;

D = [1; d2; d1; d0];

% Also P matrix 
P = [1, 0, 0, 0;
    a1, 1, b1, 0;
    a0, a1, b0, b1;
    0, a0, 0, b0];

% Calculate K values
K = P\D;

f1 = K(1);
f0 = K(2);
h1 = K(3);
h0 = K(4);

Fs = tf(1, [f1, f0]);
Hs = tf([h1, h0], 1);