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
T = [1/((1*wc)/(2*pi)) 1/((10*wc)/(2*pi)) 1/((25*wc)/(2*pi)) 1/((50*wc)/(2*pi))];

% The dq models are identical, but mapped into the discrete domain.
Gdz = c2d(Gd, T(1));
Gdz1 = c2d(Gd, T(2));
Gdz2 = c2d(Gd, T(3));
Gdz3 = c2d(Gd, T(4));

Gdw = d2c(Gdz, 'Tustin');
Gdw1 = d2c(Gdz1, 'Tustin');
Gdw2 = d2c(Gdz2, 'Tustin');
Gdw3 = d2c(Gdz3, 'Tustin');

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

Dps_num = ki*[ti 1];
Dps_den = [ti 0];
Dps = tf(Dps_num, Dps_den);

% The resulting PI controller is then:
Ddpis = kp * Dps;

% Calculate new gain and phase of plant with PI controller
[gain, phase] = bode(Gdw*Ddpis, wc);

% Change gain to adjust perfectly
%kp = kp * 1/gain;

% The resulting PI controller is then found and mapped into the discrete
% domain
Ddpis = kp * Dps;
Ddpiz = c2d(Ddpis, T(1), 'Tustin')



[gain, phase] = bode(Gdw1, wc);

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
[gain, phase] = bode(Gdw1*Ddpis, wc);

% Change gain to adjust perfectly
%kp = kp * 1/gain;

% The resulting PI controller is then found and mapped into the discrete
% domain
Ddpis = kp * Dps;
Ddpiz1 = c2d(Ddpis, T(2), 'Tustin')



[gain, phase] = bode(Gdw2, wc);

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
[gain, phase] = bode(Gdw2*Ddpis, wc);

% Change gain to adjust perfectly
%kp = kp * 1/gain;

% The resulting PI controller is then found and mapped into the discrete
% domain
Ddpis = kp * Dps;
Ddpiz2 = c2d(Ddpis, T(3), 'Tustin')



[gain, phase] = bode(Gdw3, wc);

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
[gain, phase] = bode(Gdw3*Ddpis, wc);

% Change gain to adjust perfectly
%kp = kp * 1/gain;

% The resulting PI controller is then found and mapped into the discrete
% domain
Ddpis = kp * Dps;
Ddpiz3 = c2d(Ddpis, T(4), 'Tustin')



% Bode plot of plant with digital controller
figure(4)
subplot(2,2,1)
margin(Ddpiz*Gdz)

subplot(2,2,2)
margin(Ddpiz1*Gdz1)

subplot(2,2,3)
margin(Ddpiz2*Gdz2)

subplot(2,2,4)
margin(Ddpiz3*Gdz3)

% Values for Simulink:
Kp = kp/2;
Ki = kp/ti;

% Pole Placement values
Kp_pole = 0.018;
Ki_pole = 0.5062;

%Kp = Kp_pole;
%Ki = Ki_pole;

T(1) = T(3);
d = 0.005;

figure(5)
s = tf('s');
margin(Ddpiz2*Gdz2*c2d(exp(-d*s),T(1)))