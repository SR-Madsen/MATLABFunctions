clear, close all, clc;

% Mini-Project 2:
% Design of transformer for our application from mini-project 1.

%% 1) Consider your operation specifications - which parameters should be
% prioritized?

% Due to the high frequency, especially capacitance is prioritized for
% reducing power loss. Size should be minimized but still allow for
% transferring the power.
% We want to design for maximum power at maximum voltage (60 Vo, 25 Io),
% thus sacrificing efficiency at lower power. This also means the copper
% and iron core loss must be equal.


%% 2) Determine the best suit of magnetic components
% a) Core: Ferroxcube E55/28/25, 3C95A

% Core properties
mu_0 = 1.25663706*10^-6;
%mu_r_fe = 2300;
%Ae = 420*10^-6; % [m]
%le = 123*10^-3; % [m]
%Ve = 52000*10^-9; % [m^3]

% Steinmetz coefficients from Ferroxcube's Excel sheet for materials
%Kc = 0.00747061809845703;
%alpha = 1.955;
%beta = 3.07;
%Ki = Kc/(2^(beta-1)*pi^(alpha-1)*(1.1044 + 6.8244/(alpha + 1.354)));


% a) Core: EPCOS TDK E42/21/15, N87

% Core properties
mu_r_fe = 1690;
Ae = 178 * 10^-6; % [m]
le = 97 * 10^-3; % [m]
Ve = 17300 * 10^-9; % [m]

% Steinmetz
Kc = 0.009498;
alpha = 1.424;
beta = 2.383;
Ki = Kc/(2^(beta-1)*pi^(alpha-1)*(1.1044+6.8244/(alpha+1.354)));


% Calculate core reluctance
%R_core = le/(mu_0*mu_r_fe*Ae);

% b) Primary + secondary winding: Copper foil, 25mm width, 0.3mm thickness

% Winding properties
% w_foil_p = 25*10^-3; % [m]
% t_foil_p = 0.3*10^-3; % [m]
% w_foil_s = w_foil_p; % [m]
% t_foil_s = t_foil_p; % [m]


% b) Primary + secondary winding: Copper foil, 18mm width, 0.3mm thickness
% (Cut 25mm width to 18mm)
w_foil_p = 18*10^-3; % [m]
t_foil_p = 0.15*10^-3; % [m]
w_foil_s = w_foil_p; % [m]
t_foil_s = 0.3*10^-3; % [m]


%% 3) Propose a stackup for the magnetic design
% Kapton tape thickness = 0.055 mm
t_kapton = 0.055*10^-3; % [m]

% Preliminary calculation of thickness - will it blend/fit in window?
sects = 5;
t_sect = (8*t_kapton + 2*t_foil_p + t_foil_s);
t_stackup = sects*t_sect + 3*t_kapton

% Stackup definition, assuming none in parallel
Nrow = 1;

%syms P S

% Stackup for Ferroxcube E55/28/25
% stackup = [P, t_foil_p, 1, w_foil_p;
%            S, t_foil_s, 0.5, w_foil_s;
%            P, t_foil_p, 1, w_foil_p;
%            P, t_foil_p, 1, w_foil_p;
%            S, t_foil_s, 0.5, w_foil_s;
%            P, t_foil_p, 1, w_foil_p;
%            P, t_foil_p, 1, w_foil_p;
%            S, t_foil_s, 0.5, w_foil_s;
%            P, t_foil_p, 1, w_foil_p;
%            P, t_foil_p, 1, w_foil_p;
%            S, t_foil_s, 0.5, w_foil_s;
%            P, t_foil_p, 1, w_foil_p;
%            P, t_foil_p, 1, w_foil_p;
%            S, t_foil_s, 0.5, w_foil_s;
%            P, t_foil_p, 1, w_foil_p;
%            P, t_foil_p, 1, w_foil_p;
%            S, t_foil_s, 0.5, w_foil_s;
%            P, t_foil_p, 1, w_foil_p;];


% Stackup for EPCOS TDK E42/21/15
stackup = [1, t_foil_p, 1, w_foil_p;
           2, t_foil_s, 0.5, w_foil_s;
           1, t_foil_p, 1, w_foil_p;
           1, t_foil_p, 1, w_foil_p;
           2, t_foil_s, 0.5, w_foil_s;
           1, t_foil_p, 1, w_foil_p;
           1, t_foil_p, 1, w_foil_p;
           2, t_foil_s, 0.5, w_foil_s;
           1, t_foil_p, 1, w_foil_p;
           1, t_foil_p, 1, w_foil_p;
           2, t_foil_s, 0.5, w_foil_s;
           1, t_foil_p, 1, w_foil_p;
           1, t_foil_p, 1, w_foil_p;
           2, t_foil_s, 0.5, w_foil_s;
           1, t_foil_p, 1, w_foil_p;];
       
% Find isolation thickness between each layer
for i = 1:1:length(stackup)
    if (stackup(i) == 1 && stackup(i+1) == 2) || (stackup(i) == 2 && stackup(i+1) == 1)
        t_iso(i) = 3*t_kapton;
    else
        t_iso(i) = 2*t_kapton;
    end
end
       
% Find length of each turn

% Bobbin for Ferroxcube E55/28/25
%w_bobbin = 0.02; % [m]
%h_bobbin = 0.028; % [m]

% Bobbin for EPCOS TDK E42/21/15
w_bobbin_wind = 0.0174; % [m]
h_bobbin_wind = 0.0151; % [m]
ln(1) = 2*w_bobbin_wind + 2*h_bobbin_wind;
for i = 2:1:length(stackup)
    ln(i) = ln(i-1) + ((t_iso(i-1) + stackup(length(stackup)+(i-1))) * 8);
end

% Winding summation
Np = 0;
Ns = 0;
k_p = 1;
k_s = 1;
for i = 1:1:length(stackup)
    if stackup(i) == 1
        Np = Np + 1;
        ln_p(k_p) = ln(i);
        k_p = k_p + 1;
    elseif stackup(i) == 2
        Ns = Ns + 1;
        ln_s(k_s) = ln(i);
        k_s = k_s + 1;
    end
end

n_trafo = Ns/Np;

% Find currents of each winding in stackup
for i = 1:1:length(stackup)
    if stackup(i) == 1
        I_stackup(i) = 1;
    elseif stackup(i) == 2
        I_stackup(i) = -1/n_trafo;
    end
end


%% 4) Calculate equivalent circuit parameters

% Converter characteristics
fs = 200000; % [Hz]
Vin = 130; % [V]
Vout = 60; % [V]
D = (Vout/Vin)/(2*n_trafo);
Pout = 1500; % [V]
Iout = Pout/Vout; % [A]

Lout = 4*10^-6; % [H]
Delta_I = (Vin*n_trafo - Vout)*D/(Lout*2*fs) % [A]

% Physical properties
T = 70; % [C]
mu_r_cu = 0.999994;
rho_cu = 1.68*10^-8*(1+0.003862*(T-20)); % [Ohm/m]


% Penetration depth
delta_w = sqrt(rho_cu/(pi*fs*mu_0*mu_r_cu)) % [m]

for i = 1:1:length(stackup) % Calculate phi from copper thickness
    phi_j(i) = stackup(length(stackup)+i)/(delta_w);
end


% Magnetizing inductance
Lm = (mu_0*mu_r_fe*Ae*Np^2)/le
Im = (D*(1/fs)*Vin)/Lm

Ip = Iout * 2*D * n_trafo + Im/2;

% Determine if maximum B field is lower than saturation B field
% B_max = 0.3 T, B_sat = 0.5 T
Delta_B = (D * Vin)/(Np * Ae * fs)


% DC resistances
R_DC_jp = rho_cu * ln_p / (w_foil_p*t_foil_p);
R_DC_p = sum(R_DC_jp)
R_DC_js = rho_cu * ln_s / (w_foil_s*t_foil_s);
R_DC_s = sum(R_DC_js)

% AC-to-DC resistance factor
for j = 1:1:length(phi_j)
    Fr_j(j) = phi_j(j)/2 * (( sinh(phi_j(j)) + sin(phi_j(j)) ) / ( cosh(phi_j(j)) - cos(phi_j(j)) )) ...
            + phi_j(j)/2 * (2 * stackup(length(stackup)*2+j) - 1)^2 ...
            * (( sinh(phi_j(j)) - sin(phi_j(j)) ) / ( cosh(phi_j(j)) + cos(phi_j(j)) ));
end

% Total AC resistance
k_p = 1;
k_s = 1;
for j = 1:1:length(Fr_j)
    if stackup(j) == 1
        R_AC_jp(k_p) = R_DC_jp(k_p) * Fr_j(j);
        k_p = k_p + 1;
    elseif stackup(j) == 2
        R_AC_js(k_s) = R_DC_js(k_s) * Fr_j(j);
        k_s = k_s + 1;
    end
end
R_AC_p = double(sum(R_AC_jp))
R_AC_s = double(sum(R_AC_js))


% Leakage inductance
I_enclosed(1) = 0;
for i = 2:1:length(stackup)+1  % Find enclosed current
    I_enclosed(i) = I_enclosed(i-1) + I_stackup(i-1) * Ip;
end

for i = 1:1:length(stackup)  % Find copper inductance
    L_lkj(i) = (ln(i)*stackup(length(stackup)+i))/(3*Nrow*stackup(length(stackup)*3+i)) ...
             * (I_enclosed(i)^2 + I_enclosed(i)*I_enclosed(i+1) + I_enclosed(i+1)^2);
end

for i = 1:1:length(stackup)  % Find insulation inductance
    L_lkk(i) = ln(i)*t_iso(i)/stackup(length(stackup)*3+i) * I_enclosed(i+1)^2;
end

L_lk = double(mu_0/Ip^2 * ( sum(L_lkj) + sum(L_lkk) )) % = Lp + Ls/n^2


% Parasitic capacitance
% Found in the capacitive losses Excel sheet

% For Ferroxcube
%C_cm = 6.96667e-09; % Does not result in losses
%C_dm = 2.13468e-10;

% For EPCOS TDK
C_cm = 3.92359e-09;
C_dm = 1.11762e-10;

%% 5) Calculate power losses and estimate temperature rise

% DC resistance losses = 0 W
% AC resistance losses
u_s1 = 1/3.*((Iout+Delta_I./2).^2 + (Iout+Delta_I./2).*(Iout-Delta_I./2) + (Iout-Delta_I./2).^2);
u_s2 = 1/3.*(((Iout+Delta_I./2)./2).^2 + ((Iout+Delta_I./2)/2).*((Iout-Delta_I./2)/2) + ((Iout-Delta_I./2)./2).^2);
I_RMS_s = sqrt(D.*u_s1+(0.5-D).*2.*u_s2);

u1_m = 1/3*(-Im/2).^2; u2_m = 1/3*(Im/2).^2;
I_RMS_m = sqrt((D./2).*u1_m+(D./2).*u2_m+((1-D)./2).*u2_m+((1-D)./2).*u1_m);
I_RMS_p = I_RMS_s*n_trafo + I_RMS_m;

P_Rac_p = R_AC_p * I_RMS_p.^2;
P_Rac_s = R_AC_s .* I_RMS_s.^2;
P_cu = P_Rac_p + P_Rac_s

% Core loss
%Pv = Ki * Delta_B^beta * fs^alpha * (2 * D^(1-alpha)); % For Ferroxcube
Pv = Ki .* (Delta_B/2).^beta .* fs.^alpha .* (2.*D^(1-alpha)) .* 1000; % [W/m3] % For EPCOS TDK, push-pull, from Magnetic Design Tool
P_fe = Pv .* Ve;

% Inductance loss
P_llk = L_lk * n_trafo^2 * (Iout + Delta_I/2)^2 * fs

% Capacitive loss
P_cdm = C_dm * Vin^2 * fs

% Total loss
P_tot = P_cu + P_fe + P_llk + P_cdm

eff = Pout./(Pout+P_tot)


% Approximate temperature rise
t_bobbin = 3.5; % [cm]
w_bobbin = 2.92; % [cm]
h_bobbin = 2.81; % [cm]

P_trafo = P_fe + P_cu;
A_su = 2*(t_bobbin*w_bobbin) + 2*(t_bobbin*h_bobbin) + 2*(w_bobbin*h_bobbin); % Surface area of bobbin
Delta_T = ((P_trafo * 1000)/(A_su))^0.833