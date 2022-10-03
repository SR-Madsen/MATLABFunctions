clear, close all, clc;

%% Inductor calculation

% Core characteristics (KS250-026A-E20-HF)
n_cores = 2;
N = 26;
AL = 66*10^-9; % H/N^2
Ae = 2.940*10^-4; % m^2
mu_r = 26;
mu_0 = 4*pi*10^-7;
mu = mu_r * mu_0;

% Inverter characteristics
V_ph = 230;
V_ll = 230*sqrt(3); % For star connection
P_o = 200000;
I_ph = P_o/(V_ll*sqrt(3))
IL_avg = I_ph;

L = n_cores*N^2*AL

% Inductor ripple
Vh = 400-(230*sqrt(2));
Vl = 400-0;
f = 24000;
Ts = 1/f;
D = (230*sqrt(2))/400;

Delta_I_h = (Vh*D*Ts)/L
Delta_I_l = (Vl*D*Ts)/L

% Magnetic fields
B_max = (L*(IL_avg+Delta_I_h/2))/(N*n_cores*Ae)
H_max = B_max/mu
H_max_oe = H_max * 0.0125663706

%% Test according to conditions shown in datasheet
N = 76;
AL = 66*10^-9;
Ae = 2.940*10^-4;

L = N^2*AL
I = 30;
B_DC = (L*I)/(N*Ae)
H_DC = B_DC/mu
H_DC_oe = H_DC * 0.0125663706