clear, close all, clc;

%% Problem 7.1
% Falling body system: Unscented Kalman filter and non-linear system state
% estimation
% A body is entering the atmosphere and falling towards earth. It has a
% non-linear continuous time state-space model. The states used are
% position, speed, and ballistic coefficient. The abilities of an extended
% Kalman filter will be compared to the unscented Kalman filter.

% dx1/dt = x2(t) + w1(t)
% dx2/dt = 1/2 rho * e^(-x1(t)/D) x2^2(t) x3(t) - g + w2(t)
% dx3/dt = w3(t)
% z(t) = sqrt(L^2 + (x1(t) - a)^2) + v(t)


% Theoretical part of the problem
% Convert the continuous non-linear state-space model to a discrete
% non-linear state-space model on the form
% xk = f(xk-1) + wk-1       E[wk] = 0       cov[wk] = Q
% zk = h(xk) + vk           E[vk] = 0       E[vk^2] = sigma_v^2

% (Hint: use a simple first-order discrete-time approximation:
%        dr/dt = s(t) => rk = rk-1 + sk-1*Ts)