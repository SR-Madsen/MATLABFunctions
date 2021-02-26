clear, close all, clc

%% In-Lecture Exercise: Loop Delays
% Calculate 3 delays:
% 1. System must be stable.
% 2. System must be marginally stable - calculate exact delay
% 3. System must be unstable.
% Simulate everything in Simulink.

wc = 10; % Where the gain is 1

% Calculating the marginally stable delay:
% Knowing that the angle of the delay = -omega * d, and that the phase
% margin is 90 degrees for the plant, the delay for a marginally stable
% loop can be calculated.
delay = (-pi/2)/(-wc);

% Using a delay slightly smaller or larger than this results in stable and
% unstable respectively.

% Design the transfer function in MATLAB and plot the Bode plot.
s = tf('s');
Gd = exp(-delay*s) * 10/s;
margin(Gd)