clear, close all, clc;

%% System Setup
%syms Rlc Rcc Lc Lg Rlg Zo Cc

% Components
Lc = 90.375*10^-6;
%Lc = 33.15*10^-6; % Worst-case at maximum load (109.5 ARMS = 155 A peak)
Lg = 2*10^-6;
Cc = 30*10^-6;
Rlc = 5e-3;
Rlg = 3e-3;
Rcc = 1e-3;
Zo = (230*sqrt(3))/((50000/(3*230))*1.5); % Maximum load for current controller (150% of nominal load)

% State space of plant
% Input: Vi
% States: [iL; vcap, io]
% Output: [iL; vcap]
%Zo = 2.116;
A = [-(Rlc+Rcc)/Lc -1/Lc Rcc/Lc;
     1/Cc 0 -1/Cc;
     Rcc/Lg 1/Lg -(Rlg+Rcc)/Lg];
B = [1/Lc Rcc/Lc;
     0 -1/Cc;
     0 -(Rlg+Rcc)/Lg];
%C = [1 0 0]; % Output matrix for iL output
C = [1 0 0;
     0 1 0]; % Output matrix for [iL; vcap]
D = [0, 0; 0, 0];

% Matrices for using derivative of vcap as state (that is, functional!)
% Excludes the grid inductor
% A_1 = [0 0 0;
%      0 1 0;
%      -1/(L_c*C_c) -(R_Lc/L_c+R_Cc/L_c) -R_Lc/(L_c*C_c)];
% B_1 = [0 1;
%      0 0;
%      1/(L_c*C_c) -1/C_c];

% Including grid inductor (using dio/dt)
% A = [-R_Lg/L_g 1/L_g C_c*R_Cc/L_g;
%      0 1 0;
%      -1/(L_c*C_c) -(R_Lc/L_c+R_Cc/L_c) -R_Lc/(L_c*C_c)];
% B = [0 0;
%      0 0;
%      1/(L_c*C_c) -1/C_c];

% (using dvc/dt) - best performance in simulation
% A = [0 0 0;
%      R_Lg/(R_Cc*C_c) -1/(C_c*R_Cc) 0;
%      -1/(L_c*C_c) -(R_Lc/L_c+R_Cc/L_c) -R_Lc/(L_c*C_c)];
% B = [0 1;
%      0 L_g/(C_c*R_Cc);
%      1/(L_c*C_c) -1/C_c];

states = {'iL' 'vcap' 'io'};
input = {'vi', 'io'};
outputs = {'iL' 'vcap'};

% For when used with only one input
%B = [1/Lc; 0; 0];
%D = [0; 0;];
%input = {'vi'};

lcl_sys = ss(A,B,C,D,'statename',states,'inputname',input,'outputname',outputs)

%% Observability
%obs_matrix = [C; C*A; C*A^2]; % (aka obsv(A,C))
%if rank(obs_matrix)==length(A)
%    disp('System is observable.')
%end

% Eigenvalue approach, more accurate for higher orders
% See "Properties of numerical algorithms related to computing
% controllability"
e_vals = eig(A)';
obs_matrix = [C; A-e_vals*eye(3)];
if rank(obs_matrix)==length(A)
    disp('System is observable.')
end

%% Discretization
fs = 48000;
Ts = 1/fs;

lcl_sys_z = c2d(lcl_sys,Ts,'zoh');

%Ad = expm(A*Ts);
%Bd = inv(A)*(expm(A*Ts)-eye(3))*B;
%Cd = C;
%Dd = D;

% Estimate the system noise
G = [0; 0; 0];
Gd = A\(expm(A*Ts)-eye(3))*G; % Also known as B1d
Gd = [0;0;0];
[Agd, Gd] = c2d(A,G,Ts);
H = [0; 0]; % For MIMO use [0; 0], only [0] for SISO
Rw = 1;
Rv = 1e-3;
Rwv = 0;
lcl_sys_z_noise = ss(lcl_sys_z.A,[lcl_sys_z.B, Gd],lcl_sys_z.C, [lcl_sys_z.D, H], Ts);
%[kalmf, L_K, P] = kalman(lcl_sys_z_noise, Rw, Rv, Rwv);