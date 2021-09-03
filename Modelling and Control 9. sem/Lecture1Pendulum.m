clear, close all, clc;

% Pendulum stats
L = 1; % [m]
m_gram = 900; % [g]
m = m_gram/1000; % [kg]
g = 9.82; % [m/s^2]

% Newton's law:
% J * alpha = tau_res
% For a ball, J = m * L^2
J = m * L^2

% 1. Design a model with input T (torque) and output theta (angle) in time
% and frequency domain.

% (m*L^2) * theta'' = tau_res = T - t_grav
% t_grav = m * g * L * sin(theta).

% With small-angle approximation, this is simply theta.
% t_grav = m * g * L * theta

% Thus
% J * theta'' = T - m * g * L * theta
% --> theta'' = T/(m*L^2) - (m*g*L*theta)/(m*L^2)

% or
% T = m * L * theta * (s^2*L + g)
% --> theta/T = (1/m*L)/(s^2*L + g)


% 2. Simulate a step in Simulink, see Lecture1Pendulum.slx.

% 3. Add friction, Tf = 0.5 Nms/rad and repeat 1. and 2.
Tf = 0.5;
% Thus J * theta'' = T - m * g * L * theta - Tf * theta'
% --> theta'' = T/(m*L^2) - (m*g*L*theta)/(m*L^2) - (Tf*theta')/(m*L^2)

% or
% mL^2*theta*s^2 = T - Lmg*theta - Tf * theta*s
% T = mL^2*theta*s^2 + Tf*theta*s + Lmg*theta
% T = mL * theta * (L*s^2 + Tf/mL*s + g)
% theta/T = 1/(mL)/(s^2*L + s*Tf/mL + g)