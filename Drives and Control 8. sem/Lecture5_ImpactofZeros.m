clear, close all, clc

%% The impact of zeros. Try three different numerators and see the resulting step response.
den = [1 4 4];
num1 = [4];
num2 = [4 4];
num3 = [-4 4];

Gs1 = tf(num1, den);
Gs2 = tf(num2, den);
Gs3 = tf(num3, den);

figure(1)
subplot(2,1,1)
step(Gs1)

subplot(2,1,2)
step(Gs2)

figure(2)
step(Gs3)

% With no zeros, the curve is a common charging curve, with no ringing.
% With a positive zero, the step response reacts very quickly, but
% overshoots significantly.
% With a negative zero, the step response goes negative (instant
% undershoot?) before following a charging curve similar to with no zeros.