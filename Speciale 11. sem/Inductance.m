clear, close all, clc;

%% Inductor calculation
n_cores = 2;
N = 26;
AL = 66*10^-9; % H/N^2
Ae = 2.940*10^-4; % m^2
IL_avg = 200000/230;
mu_r = 26;
mu_0 = 4*pi*10^-7;
mu = mu_r * mu_0;

L = n_cores*N^2*AL

% Inductor ripple
Vh = 400-(230*sqrt(2));
Vl = 400-0;
f = 24000;
DT = 1/f;

Delta_I_h = (Vh*DT)/L
Delta_I_l = (Vl*DT)/L

% Fields
B_max = (L*(IL_avg+Delta_I_h/2))/(N*n_cores*Ae)
H_max = B_max/mu
H_max_oe = H_max * 0.0125663706

%% Test
N = 76;
AL = 66*10^-9;
Ae = 2.940*10^-4;

L = N^2*AL
I = 30;
B_DC = (L*I)/(N*Ae)
H_DC = B_DC/mu
H_DC_oe = H_DC * 0.0125663706