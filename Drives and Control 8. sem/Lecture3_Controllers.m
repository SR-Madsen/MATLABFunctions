clear, close all, clc

%% Task 1: Implement a P controller in a system to increase the phase margin to roughly 50 degrees, thus increasing stability.

G = tf([10],[1 1 0]); % System is G(s) = 10/(s*(s+1))
figure(1)
margin(G) % System before implementing P controller

% P controller is simply a factor implemented in series with the system
kp = 0.1; % P controller value
figure(2)
margin(kp*G) % System after implementing P controller

% Using a kp value of 0.1 results in a phase margin of 51.8 degrees. This
% value has been increased by 33.8 degrees from 18 degrees.

%% Task 2: Implement a PI controller for G(s) so that the phase margin is affected with around -7 degrees.

% The PI controller is calculated as D(s) = Ki * (1 + t_i * s) / (t_i * s)

ki = 1; % PI controller steady-state value, should not impact the system
wi = 0.308; % PI controller natural frequency, should be around a decade lower than system's frequency due to phase impact
ti = 1/wi; % PI controller's time constant

D = tf(ki*[ti 1], [ti 0]) % PI controller transfer function

figure(3)
margin(D*G) % System after implementing PI controller

% Using a ki of 1 and a wi of 0.308 rad/s results in a phase margin of
% around 12 degrees, which is 6 degrees lower than before using the PI.

% The best performance for a PI controller is obtained by using a frequency
% around a decade lower than the crossover frequency.

%% Task 3: Implement a lead (PD) controller for G(s) so that the phase margin is affected with around +50 degrees.

% The PD controller is calculated as 
% D(s) = Kd * (1 + t_d * s) / (1 + alpha * t_d * s), where alpha < 1
% The peak of the lead regulator is located at 1 / (sqrt(alpha) * td)
% alpha = (1 - sin(phase_max)) / (1 + sin(phase_max))

phase = 50; % Phase to implement
kd = 1; % PD controller's attenuation
% If the crossover frequency is to remain unchanged, calculate kd with kd =
% sqrt(alpha)

alpha = (1 - sind(phase))/(1 + sind(phase)); % Alpha value for controller

% We wish to place the phase peak at the final system's crossover frequency.
wc = 5.2;
td = 1 / (wc * sqrt(alpha));

D = tf(kd*[td 1], [alpha*td 1]) % PD controller transfer function

figure(4)
margin(D*G) % System after implementing PD controller

% The phase margin is increased from 18 degrees to 60.9 degrees.
% An increase of 42.9 degrees.

% If a lower kd is used, the phase margin is improved further,
% at a cost of lower cutoff frequency and generally worse performance. A kd
% of 0.37 results in an unchanged cutoff frequency, which may be wanted.

%% Task 4: With pole placement, design a PID controller with steady state error -> 0 and characteristic equation (s+2)^3.
% This will result in 3 poles at position -3.
% The expanded equation is: s^3 + 6 * s^2 + 12 s + 8

% The plant/system used is Gp(s) = 10/(s^2 + 3s + 4)

% The PID controller is calculated as 
% D(s) = kp + ki/s + kd * s

% y/yr(s) = ( (kp + ki/s + kd * s) * 10 / (s^2 + 3s + 4) ) / ( 1 + ( kp +
% ki/s + kd * s) * 10 / (s^2 + 3s + 4) )

% This can be further changed by simplifying to:
% = ( (kp + ki/s + kd * s) * 10 ) / ( (s^2 + 3s + 4 + (kp + ki/s + kd *s) *
% 10)

% We now multiply by s in both numerator and denominator
% = ( (kp * s + ki + kd * s^2) * 10 ) / ( (s^3 + (3 + 10 * kd) * s^2 + (4 +
% 10 * kp) * s + 10 * ki) )

% Each of these parts are now set equal to the expanded characteristic
% equation. This results in:
% kd = 0.3
% kp = 0.8
% ki = 0.8

%% Task 5: Implement a PID controller with a crossover frequency of 10 rad/s and phase margin of 50 degrees.
% The plant/system used is Gp(s) = 10 / (s^2 + 3s + 4)
Gp = tf([10], [1 3 4]);
figure(5)
margin(Gp)

% A PID controller's transfer function is:
% D(s) = kp + ki * (1 + t_i * s) / (t_i * s) + Kd * (1 + t_d * s) / (1 + alpha * t_d * s)

% The gain at 10 rad/s is -20.1 dB, which must be accounted for with the
% proportional gain part.
kp = 10^(20.1/20);

% Alternative to using the Bode plot for finding gain:
% [gain,phase] = bode(Gp, wc)

% The integration part is then calculated
ki = 1; % I part's steady-state value, should not impact the system
wi = 1; % I part's natural frequency, should be around a decade lower than system's frequency due to phase impact
ti = 1/wi; % I part's time constant

Dpi = tf(kp * [ti 1], [ti 0]); % These can also be split up as P and I.
figure(6)
margin(Gp*Dpi)

% The derivative part is then calculated, knowing that the phase margin is
% 11.6 degrees when accounting for the integration.
% Roughly 38.4 degrees of phase boost is thus required.
phase = 38.4;
alpha = (1 - sind(phase))/(1 + sind(phase));
kd = sqrt(alpha);

wc = 10;
td = 1 / (wc * sqrt(alpha));

Dd = tf(kd*[td 1], [alpha*td 1]);
Ds = Dpi * Dd;

figure(7)
margin(Gp*Ds)