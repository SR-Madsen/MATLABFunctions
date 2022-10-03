clear, close all, clc;

%% Plant
% Components
Lc = 89*10^-6;
Lg = 12*10^-6;
Cc = 30*10^-6;
Rcc = 1e-3;
Rlc = 5e-3;
Rlg = 3e-3;

% Load
Zo = 1; % TEMP
Zo_max = 0.9136;

% Transfer functions
Gvc_num = [Cc*Lg*Rcc Lg+Cc*Rcc*(Rlg+Zo) Rlg+Zo];
Gvc_den = [Cc*Lg*Lc ...
           Cc*(Lg*(Rcc+Rlc)+Lc*(Rlg+Rcc+Zo)) ...
           Lg+Lc+Cc*Rcc*(Rlg+Zo)+Cc*Rlc*(Rlg+Rcc+Zo) ...
           Rlc + Rlg + Zo];
Gvc = tf(Gvc_num, Gvc_den)

Gil_num = [Cc*Lg Cc*(Rlg+Rcc+Zo) 1];
Gil_den = [Cc*Lg*Lc ...
           Cc*(Lg*(Rcc+Rlc)+Lc*(Rlg+Rcc+Zo)) ...
           Lg+Lc+Cc*Rcc*(Rlg+Zo)+Cc*Rlc*(Rlg+Rcc+Zo) ...
           Rlc + Rlg + Zo];
Gil = tf(Gil_num, Gil_den)

Gil_num = [Cc*Lg Cc*(Rlg+Rcc+Zo_max) 1];
Gil_den = [Cc*Lg*Lc ...
           Cc*(Lg*(Rcc+Rlc)+Lc*(Rlg+Rcc+Zo_max)) ...
           Lg+Lc+Cc*Rcc*(Rlg+Zo_max)+Cc*Rlc*(Rlg+Rcc+Zo_max) ...
           Rlc + Rlg + Zo_max];
Gil = tf(Gil_num, Gil_den)

% Delay
fs = 24000;
Td = 0.75*1/fs;


%% Current Controller
s = tf('s');

Kc = 3;

b_opt = bodeoptions('cstprefs');
b_opt.FreqUnits = 'Hz';

Gic = Kc*Gil*exp(-s*Td);
%bodeplot(Gic,b_opt)
margin(Gic)