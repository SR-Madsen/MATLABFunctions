clear, close all, clc;

%% Exercise 1: Design a digital PID controller D(z) with a w_c of 10 rad/s, PM of 50 degrees and T = 0.1 second.
T = 0.1; % 0.1 second sample time
wc = 10; % 10 rad/s crossover frequency
PM = 50; % 50 degree phase margin

% The plant/system transfer function is G_P(s) = 10 / (s^2 + 3 * s + 4)
Gp = tf([10], [1 3 4]);

% Map from continuous time into discrete time
Gpz = c2d(Gp, T);

% Make a bilinear transformation by Tustin mapping back into continuous
Gpw = d2c(Gpz, 'tustin');
[gain, phase] = bode(Gpw, wc);
figure(1)
margin(Gpw)

% Design the PID controller in the continuous time
% The proportional part is solely a constant
kp = 1/gain;

% The integral part is then calculated
ki = 1; % I part's steady-state value, should not impact the system
wi = 1; % I part's natural frequency, should be around a decade lower than system's frequency due to phase impact
ti = 1/wi; % I part's time constant

% Bode plot of plant with PI controller to check phase
Dps = tf([ti 1], [ti 0]);
figure(2)
[gain, phase] = bode(Gpw*kp*Dps, wc);
margin(Gpw*kp*Dps)

% Calculating required phase boost
Fmax = PM - (180 + phase);

% The derivative part is then calculated
alpha = (1 - sind(Fmax))/(1 + sind(Fmax));
kd = sqrt(alpha);
td = 1/(sqrt(alpha)*wc);
Dds = tf(kd * [td 1], [alpha*td 1]);
figure(3)
margin(Gpw*kp*Dps*Dds)

% The resulting PID controller is then:
Dpids = kp * Dps * Dds

% This must be transferred to the z-domain by Tustin
Dpidz = c2d(Dpids, T, 'tustin')

% Check to confirm that the digital plant and controller have same
% transfer function as analog versions
figure(4)
margin(Dpidz*Gpz)

%% Exercise 2: Design a discrete PID controller in Simulink, first with T = 0.01 and then T = 0.1.
% The plant transfer function is G_p = 10 / (s^2 + 3 * s + 4)
% The characteristic equation will be alpha(s) = (s + 2)^3

Gpn = [10]; % A(s)
Gpd = [1 3 4]; % B(s)

Gp = tf(Gpn, Gpd);
T = 0.1; % Sampling time

% Expanding the characteristic equation:
syms s
alpha = expand((s+2)^3)

% Comparing the expanded equation with expected values of:
% (s^2 + 3s + 4) * s + (Kds^2 + Kps + Ki) * A(s) = s^3 + 3 * s^2 + 4 * s + 10 * Kd * s^2 + 10 * Kp * s + 10 * Ki
% = s^3 + (3 + 10 * Kd) * s^2 + (4 + 10 * Kp) * s + 10 * Ki
% Results in:
% 3 + 10 * Kd = 6
% 4 + 10 * Kp = 12
% 10 * Ki = 8

% The values are then calculated as
Kd = (6-3)/10
Kp = (12-4)/10
Ki = 8/10

%sim('Lecture4_DiscretePID')