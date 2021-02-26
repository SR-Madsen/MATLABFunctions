clear, close all, clc

% Assignment 2:
%% Part 1: Design a dq model of the PMSM in Simulink
% Datasheet:
Lq   = 1*10^-3; % H
Ld   = 1*10^-3; % H
R    = 1.5    ; % Ohm
L_M  = 0.1    ; % Nm/A
Kf   = 0.25   ; % Nm*s/rad
J    = 2      ; % kg*m²

% The q-part is completed by using the block diagram from Lecture 6
% PowerPoint. The d-part is found from the equation in same PowerPoint:
% vd = Rd*id + Ld * did/dt - Lq*w*iq

%% Part 2: Design and implement analog PI controllers for the system and simulate a
% torque step response. Try different bandwidths for the system.

wc = 50; % Resulting bandwidth: 1.5 * wc rad/s
wc1 = 250;
wc2 = 1000;

% The dynamic models for dq are (roughly):
Gd_num = [1];
Gd_den = [Ld R];
Gd = tf(Gd_num, Gd_den);

Gq_num = [1];
Gq_den = [Lq R];
Gq = tf(Gq_num, Gq_den);

% As the models are identical for this assignment, just one transfer
% function needs to be found for the PI Controller, here using i_d.
[gain, phase] = bode(Gd, wc);
figure(1)
margin(Gd) % Plot of i_d model

% Design the PI controller in the continuous time
% The proportional part is solely a constant
kp = 1/gain; % Ensures crossover frequency is as wanted

% The integral part is then calculated
ki = 1; % I part's steady-state value, should not impact the system
wi = wc/10; % I part's natural frequency, should be around a decade lower than system's frequency due to phase impact
ti = 1/wi; % I part's time constant

Dps_num = ki*[ti 1];
Dps_den = [ti 0];
Dps = tf(Dps_num, Dps_den);

% The resulting PI controller is then:
Ddpis = kp * Dps;

% Calculate new gain and phase of plant with PI controller
[gain, phase] = bode(Gd*Ddpis, wc);

% Change gain to adjust perfectly
kp = kp * 1/gain;
Ddpis = kp * Dps;

% Bode plot of final plant and PI controller
figure(2)
[gain, phase] = bode(Gd*Ddpis, wc);
margin(Gd*Ddpis)

% Values for Simulink:
Kp = kp;
Ki = kp/ti;
Kp1 = Kp;
Kp2 = Kp;
Ki1 = kp/(1/(wc1/10));
Ki2 = kp/(1/(wc2/10));

%% Part 3: Design and implement a digital PI controller and simulate torque step response.
% Try different design approaches (Nyquist, Tustin, Pole Placement) and
% sample times.

wc = 1000; % Resulting bandwidth: ~1500 rad/s
T = 1/((25*wc)/(2*pi));

% The dq models are identical, but mapped into the discrete domain.
Gdz = c2d(Gd, T);
Gdw = d2c(Gdz, 'Tustin');

figure(3)
[gain, phase] = bode(Gdw, wc);
margin(Gdw)

% Design the PI controller in the continuous time
% The proportional part is solely a constant
kp = 1/gain; % Ensures crossover frequency is as wanted

% The integral part is then calculated
ki = 1; % I part's steady-state value, should not impact the system
wi = wc/10; % I part's natural frequency, should be around a decade lower than system's frequency due to phase impact
ti = 1/wi; % I part's time constant

Dps_num = [ti 1];
Dps_den = [ti 0];
Dps = tf(Dps_num, Dps_den);

% The resulting PI controller is then found and mapped into the discrete
% domain
Ddpis = kp * Dps;
Ddpiz = c2d(Ddpis, T, 'Tustin')

% Bode plot of plant with digital controller
figure(4)
[gain, phase] = bode(Ddpiz*Gdz,wc);
margin(Ddpiz*Gdz)

% Notes on simulation:
% Different sample times and design approaches were tested.
% Results:
% Tustin
% Nyquist
% Pole Placement?
% T = wc
% T = 5*wc
% T = 20*wc
% T = 50*wc