clear, close all, clc

%% Assignment 2:
% Part 1: Design a dq model of the PMSM in Simulink
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