clear, close all, clc;

%% Soft-Switching of Secondary Side
n = 0.5;

L = 4.5e-6;

Coss = 230e-12;
Cdm_pri = 1.11762e-10; % Change to actual capacitance of trafo?
Cdm_sec = Cdm_pri/n^2;

f_res = 1/(2*pi*sqrt(L*(2*Coss+Cdm_sec)))
Ts = 1/f_res;
dt_min = Ts/4