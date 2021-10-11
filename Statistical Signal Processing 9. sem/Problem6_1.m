clear, close all, clc;

%% Problem 6.1
% The signal and observation models for a non-linear system without control
% inputs are, respectively
% x_k = f(x_k-1, w_k-1) = x^2_k-1 + w_k-1
% z_k = h(x_k, v_k) = x^3_k + v_k
% The noises are zero-mean, with a standard sigma^2 variance.

% Calculate the Jacobians from the equations below, knowing that the system
% is a first-order and thus no matrices are involved.
% A_k = df/dx | x^_k-1
% W_k = df/dw | x^_k-1
% H_k = dh/dx | x^-_k
% V_k = dh/dv | x^-_k

% By replacing the x with the develpoment point and finding the derivative,
% we get the Jacobians

% A_k = d/dx((x^_k-1)^2 + w_k-1) = 2x^_k-1
% H_k = d/dx((x^-_k)^3 + v_k) = 3(x^-_k)^2

% W_k = d/dw((x^_k-1)^2 + w_k-1) = 1
% V_k = d/dv((x^-_k)^3 + v_k) = 1


% Find the extended Kalman filter equations for this system by using the
% predict-update system structure.
% (x^_k-1 and P_k-1 are given from previous iteration)

% Noise is left out as it is mean-zero:
% x^-_k = f(x^_k-1) = (x^_k-1)^2
% z^-_k = h(x^-_k) = (x^-_k)^3 = ((x^_k-1)^2)^3 = (x^_k-1)^6
% P-_k = A_kP_k-1A^T_k + Q_k = (2x^_k-1)*P_k-1*(2x^_k-1) + sigma^2_w
%      = (2x^_k-1)^2*P_k-1 + sigma^2_w = 4x^_k-1 * P_k-1 + sigma^2_w

% K_k = P-_k * H^T_k * [H_k * P-_k * H^T_k + R_k]^-1
%     = P-_k * H_k * [H^2_k * P-_k + sigma^2_v]^-1
%     = ((4x^_k-1 * P_k-1 + sigma^2_w) * 3(x^-_k)^2) /
%       ((3(x^-_k)^2)^2 * (4x^_k-1 * P_k-1 + sigma^2_w) + sigma^2_v)
% x^_k = x^-_k + K_k * (z_k - z^-_k)
%      = (x^_k-1)^2 + K_k * (z_k - (x^_k-1)^6))
% P_k = (I - K_kH_k)P-_k
%     = (1 - K_k*3*(x^-_k)^2) * (4x^_k-1 * P_k-1 + sigma^2_w)