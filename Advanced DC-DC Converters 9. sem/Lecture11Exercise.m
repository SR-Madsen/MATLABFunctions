clear, close all, clc;

%% In-Lecture Exercise: Input (driving, bypass) capacitor

% Using a Buck converter, assuming infinite output inductance and no input
% inductance. We want 1% input ripplevoltage.

Vo = 350;
Po = 20000;
D = 0.5;
fs = 70000;
eff = 0.97;

Vin = 350/0.5;
Delta_Vin = 0.01*Vin;

Pin = 20000/0.97;
Iin = Pin/Vin;

Ic_max = Iin * D;

C_min = (Ic_max*1/fs*D)/Delta_Vin


%% In-Lecture Exercise: LC input filter

% Design an input filter to a converter with the following specs.

% Filter attenuation 80 dB @ fs
%Vin = 30 to 50 V
% For finding minimum input impedance, 30 V
Vin = 30;
Pin = 3000;
fs = 270000;

Zin_min = Vin^2/Pin;

fc = 270000/10^2; % = 2.7 kHz
% fc = 1/(2*pi*sqrt(LC))

% 3*Zin > Z_char
Z_char = Zin_min / 3;
% Z_char = sqrt(L/C)

% Guess on C. Assume it must be much larger than L.
C = 600*10^-6;
L = C*Z_char^2

f_3db = 1/(2*pi*sqrt(L*C)) % Close enough

% Alternatively, use 2 equations, 2 variables, and adjust them.