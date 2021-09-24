clear, close all, clc;

%% Lecture 4 Exercise 1:
% Digital Linear State Feedback with Integrator

% The plant is a discrete second order system, state space model given:
Ad = [0.8, -0.36; 0.09, 0.98];
Bd = [0.09; 0.0047];
Cd = [0, 10];
Dd = [0; 0];

% Sample time is 0.1 seconds
T = 0.1;

% Design a digital LSF with integrator so all three poles are at sp = -1.
sp = -1;
zp = exp(sp*T);

Ad_mark = [Ad, [0; 0]; -Cd, 1];
Bd_mark = [Bd; 0];

KKi = acker(Ad_mark, Bd_mark, [zp, zp, zp]);
K = [KKi(1) KKi(2)]
Ki = -KKi(3)

% What is the settling time?
n = 3; % With integrator, the system is 3rd order
Ts = 1.5*(n+1)*-1/sp; % = 6 seconds

% Simulate in Simulink and compare.
% The measured settling time (manually) in Simulink is 5.988 seconds, which
% is what it was designed for.


%% Lecture 4 Exercise 2:
% Design a current observer for the system from exercise 1.
% A current observer will calculate u(k) from y(k) at the exact time
% instant. Oppositely, a prediction observer will calculate u(k+1) from
% y(k), meaning it predicts the next outputs.

% The current observer is more robust and less susceptible to noise in the
% system, however it is best that the control calculations take below 10%
% of the sampling time. If that is not possible, using the prediction
% observer will grant much more time for calculations.

% The predictor will be designed with twice the speed of the plant.
s_pe = sp*2;
z_pe = exp(s_pe*T);

Lc = acker(Ad', (Cd*Ad)', [z_pe, z_pe])'

% Simulate in Simulink and compare.