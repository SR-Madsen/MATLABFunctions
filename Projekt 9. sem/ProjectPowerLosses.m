%% Total Power Stage Power Losses Across All Output Powers
clear, close all, clc;


%% Converter properties
fs = 200*10^3; % [Hz]
Ts = 1/fs; % [s]
Vin = 130; % [V]
Vout = 60; % [V]
Iout = 25; % [A]
Rout = Vout/Iout; % [Ohm]
D = 0.01:0.01:0.5;

n_trafo = 0.5;
Vout = 2*Vin*n_trafo*D; % [V]
Iout = Vout./Rout; % [A]

%Lout = 4*10^-6; % [H]
%Delta_I = (Vin*n_trafo - Vout).*D./(Lout*2*fs); % [A]


%% Transformer core properties
mu_0 = 1.25663706*10^-6;
mu_r_fe = 1690;
Ae = 178 * 10^-6; % [m]
le = 97 * 10^-3; % [m]
Ve = 17300 * 10^-9; % [m]

% Steinmetz
Kc = 0.01493;
alpha = 1.493;
beta = 2.466;
Ki = Kc/(2^(beta-1)*pi^(alpha-1)*(1.1044+6.8244/(alpha+1.354)));

w_foil_p = 18*10^-3; % [m]
t_foil_p = 0.15*10^-3; % [m]
w_foil_s = w_foil_p; % [m]
t_foil_s = 0.3*10^-3; % [m]
t_kapton = 0.055*10^-3; % [m]


%% Inductor core properties
% EPCOS TDK, E32/16/9, N87
% approx. 1mm airgap
AL = 145e-9;
Ae_l = 83e-6;
Ve_l = 6140e-9;
%h_window = (22.7e-3 - 9.5e-3)/2;
h_window = 6e-3;
la = 11.6e-3; 
lb = 11.6e-3;
w_bobbin = 21.9e-3-2*0.9e-3;
w = 18e-3; % foil width

%% Physical properties
T = 70; % [C]
mu_r_cu = 0.999994;
rho_cu = 1.68*10^-8*(1+0.003862*(T-20)); % [Ohm/m]

% Penetration depth
delta_w = sqrt(rho_cu/(pi*fs*mu_0*mu_r_cu)); % [m]


%% Inductor parameters
% Currents
IL_avg = Iout;
pIL = 0.2;
dIL = IL_avg*pIL;

% Inductor inductance
L = (Vin.*n_trafo-Vout)./dIL.*D.*1./(2.*fs);
L = 4e-6;       % Adding a margin

%dIL = (Vin.*n_trafo-Vout)./L.*D.*1/(2.*fs)   % new dIL
%IL_rms = sqrt(IL_avg.^2 + ((dIL./2)/sqrt(3)).^2);
%IC_rms = 1/sqrt(3).*dIL./2;

% Capacitor capacitance
dQ = 0.5 .* dIL/2 .* 0.5.*Ts./2;
pVo = 0.01;
dVo = Vout.*pVo;
Co = dQ./dVo;
%Co./3.3e-6;

% Capacitor max ESR
ESR_max = dVo./dIL;


%%%%%%%%%%%%%%%%%%%%% Parameters %%%%%%%%%%%%%%%%%%%%%
%N = ceil(sqrt(L/AL))
N = 6;
Pv_l = 16.5e3; % W/m^3 read at D = 0.25 N = 6
L = N^2*AL;
% Calculating currents again based on actual L
dIL = (Vin.*n_trafo-Vout)./L.*D.*1./(2.*fs);   % new dIL
IL_rms = sqrt(IL_avg.^2 + ((dIL./2)/sqrt(3)).^2);
IC_rms = 1/sqrt(3).*dIL./2;
m = 1:N;

h_tape = 0.055e-3*2;
h = [0.15e-3 0.2e-3 0.3e-3 0.4e-3]'; % foil thickness
h = 0.4e-3;
h_free_window = h_window - (N*h+N*h_tape);
l_creepage = h_free_window + (w_bobbin - w);

%%%%%%%%%%%%%%%%%%%%% R_DC & P_DC %%%%%%%%%%%%%%%%%%%%%
for i = 1:length(h)
    k = 0;
    for j = 1:length(m)
        lw(i,j) = la*2+lb*2 + k*8*(h+h_tape);
        k = k+1;
    end
end
rho = 1.68 * 10^(-8);
A = w*h;

R_DCj = rho*lw./A;
for i = 1:length(h)
    R_DC(i,1) = sum(R_DCj(i,:));
end

% R_DCj = [layer1,h1 layer2,h1 ...
%          layer1,h2 layer2,h2 ...
% R_DC = [h1; h2; h3; h4]
%R_DC
P_DC = R_DC.*IL_avg.^2;

%%%%%%%%%%%%%%%%%%%%% R_AC & P_AC %%%%%%%%%%%%%%%%%%%%%
T = 50; % degrees C
rho_w = 1.68e-8*(1+0.003862*(T-20));
mu_0 = 4e-7*pi;
skindepth = sqrt(rho_w/(pi*mu_0*2*fs));

j = 1;
for p = [0.15e-3 0.2e-3 0.3e-3 0.4e-3] % foil thickness
    phi = p/skindepth;
    FR = 0;
    for i = 1:length(m)
        FR_j = phi/2 * ((exp(phi)-exp(-phi))/2+sind(phi))/((exp(phi)+exp(-phi))/2-cosd(phi)) + phi/2*(2*m(i)-1)^2*((exp(phi)-exp(-phi))/2-sind(phi))/((exp(phi)+exp(-phi))/2+cosd(phi));
        FR_j_array(j,i) = FR_j;
        FR = FR + FR_j;
    end 
    FR_array(j) = FR/length(m);
    j = j+1;
end
% FR_j_array: [FR_1(h1) FR_2(h1) FR_3(h1) FR_4(h1); 
%              FR_1(h2) FR_2(h2) FR_3(h2) FR_4(h2); ...

R_ACj = FR_j_array .* R_DCj;
for i= 1:length(h)
    R_AC(i,1) = sum(R_ACj(i,:));
end 

% R_ACj = [layer1,h1 layer2,h1 ...
%          layer1,h2 layer2,h2 ...
% R_AC = [h1; h2; h3; h4]
%R_AC
P_AC = R_AC.*IC_rms.^2;

% figure(1)
% plot(h*1e3,(R_DC*1e3)', h*1e3,FR_array, h*1e3,(R_AC*1e3)')
% legend('R_{DC}', 'F_R', 'R_{AC}', 'Location', 'NorthWest')
% xlabel('h_{foil} [mm]')
% ylabel('F_R, R_{DC} [m\Omega], R_{AC} [m\Omega]')

%%%%%%%%%%%%%%%%%%%%% Intra-winding Capacitance %%%%%%%%%%%%%%%%%%%%%
V1 = Vin.*n_trafo;
k = 0;
for i = 1:(length(m)+1)
    V(:,i) = Vin.*n_trafo - k.*(Vin.*n_trafo-Vout)./length(m);
    k = k+1;
end

for j = 1:1:length(V)
    for i = 1:(length(m)-1)
        Vaj(j,i) = V(j,i+1)-V(j,i);
        Vbj(j,i) = V(j,i+2)-V(j,i+1);
    end
end

epsi_0 = 8.85419e-12;
epsi_r = 3.4;
V_tot = Vin.*n_trafo;

for i = 1:length(V)
    for j = 1:(length(m)-1)
        Cdmj(i,j) = w*lw(j+1)/h_tape*(Vaj(i,j).^2+Vaj(i,j).*Vbj(i,j)+Vbj(i,j).^2);
    end
end

for i = 1:1:length(V)
    Cdm(i,1) = epsi_0*epsi_r/(3*V_tot^2) * sum(Cdmj(i,:));
end

%Cdm
P_Cdm = 0.5.*Cdm.*V_tot.^2.*2.*fs;

%%%%%%%%%%%%%%%%%%%%% Leakage Inductance %%%%%%%%%%%%%%%%%%%%%
Nrow = 1;
I_tot = IL_avg;

I_enclosed = (m'*IL_avg)';
i = 1;
Lj = lw(i,1)*h./(3*Nrow*w) * (I_enclosed(1)^2);
for i = 1:length(V)
    for j = 2:length(m)
        Lj(i,j) = lw(j)*h./(3*Nrow*w) .* (I_enclosed(i,j).^2 + I_enclosed(i,j).*I_enclosed(i,j-1)+I_enclosed(i,j-1).^2);
    end
end

for i = 1:length(V)
    for j = 1:length(m)-1
        Lj_insul(i,j) = lw(j)*h./w .* (I_enclosed(i,j+1)-I_enclosed(i,j)).^2;
    end
end

for i = 1:length(V)
    for j = 1:length(m)-1
        L_llk(i,:) = mu_0./I_tot.^2.*(sum(Lj(i,:)) + sum(Lj_insul(i,:)));
    end
end

%%%%%%%%%%%%%%%%%%%%% Core Loss %%%%%%%%%%%%%%%%%%%%%

dB = D.*(Vin.*n_trafo-Vout)./(N.*Ae_l.*2.*fs);
Bpk = L.*(IL_avg+dIL./2)./(N.*Ae_l); % 127mT

Kc_l = 1.766;
alpha_l = 1.36;
beta_l = 2.10;

Ki_l = Kc_l/(2^(beta_l-1)*pi^(alpha_l-1)*(1.1044+6.8244/(alpha_l+1.354)));

Pv_l = Ki_l.*dB.^beta_l.*2.*fs.^alpha_l.*(D.^(1-alpha_l)+(1-D).^(1-alpha_l));
Pv_l = double(Pv_l);

P_core_notstein = Pv_l*Ve_l;

%%%%%%%%%%%%%%%%%%%%% Total Losses %%%%%%%%%%%%%%%%%%%%%
P_L = P_Cdm + P_DC' + P_AC' + P_core_notstein';


%% Transformer stackup properties
% Stackup definition, assuming none in parallel
Nrow = 1;

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

Delta_B = (D * Vin)/(Np * Ae * fs);

% Find currents of each winding in stackup
for i = 1:1:length(stackup)
    if stackup(i) == 1
        I_stackup(i) = 1;
    elseif stackup(i) == 2
        I_stackup(i) = -1/n_trafo;
    end
end


%% Transformer parameters

for i = 1:1:length(stackup) % Calculate phi from copper thickness
    phi_j(i) = stackup(length(stackup)+i)/(delta_w);
end

% Magnetizing inductance
Lm = (mu_0*mu_r_fe*Ae*Np^2)/le;
Im = (D*(1/fs)*Vin)/Lm;

Ip = Iout .* 2.*D .* n_trafo + Im./2;


% DC resistances
R_DC_jp = rho_cu * ln_p / (w_foil_p*t_foil_p);
R_DC_p = sum(R_DC_jp);
R_DC_js = rho_cu * ln_s / (w_foil_s*t_foil_s);
R_DC_s = sum(R_DC_js);

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
R_AC_p = double(sum(R_AC_jp));
R_AC_s = double(sum(R_AC_js));


% Leakage inductance
for j = 1:1:length(Ip)
    I_enclosed(j,1) = 0;
end
for j = 1:1:length(Ip)
    for i = 2:1:length(stackup)+1  % Find enclosed current
        I_enclosed(j,i) = I_enclosed(j,i-1) + I_stackup(i-1) * Ip(j);
    end
end

for j = 1:1:length(Ip)
    for i = 1:1:length(stackup)  % Find copper inductance
        L_lkj(j,i) = (ln(i)*stackup(length(stackup)+i))/(3*Nrow*stackup(length(stackup)*3+i)) ...
                 * (I_enclosed(j,i)^2 + I_enclosed(j,i)*I_enclosed(j,i+1) + I_enclosed(j,i+1)^2);
    end
end

for j = 1:1:length(Ip)
    for i = 1:1:length(stackup)  % Find insulation inductance
        L_lkk(j,i) = ln(i)*t_iso(i)/stackup(length(stackup)*3+i) * I_enclosed(j,i+1)^2;
    end
end

for j = 1:1:length(Ip) % Calculate total leakage inductance
    L_lk(j) = double(mu_0/Ip(j)^2 * ( sum(L_lkj(j,:)) + sum(L_lkk(j,:)) )); % = Lp + Ls/n^2
end
L_lk;

% Capacitive parasitics calculated in Excel
% Capacitors do not change as function of duty cycle/output power
C_cm = 3.92359e-09;
C_dm = 1.11762e-10;


%% Transformer losses

Delta_I = dIL;
% AC resistance losses
u_s = 1/3*((Iout+Delta_I./2).^2 + (Iout+Delta_I./2).*(Iout-Delta_I./2) + (Iout-Delta_I./2).^2);
I_RMS_s = sqrt(D.*u_s+(1-D).*u_s);
u1_m = 1/3*(-Im/2).^2; u2_m = 1/3*(Im/2).^2;
I_RMS_m = sqrt((D./2).*u1_m+(D./2).*u2_m+((1-D)./2).*u2_m+((1-D)./2).*u1_m);
I_RMS_p = I_RMS_s*n_trafo + I_RMS_m;
P_Rac_p = R_AC_p * I_RMS_p.^2;
P_Rac_s = R_AC_s .* I_RMS_s.^2;
P_cu = P_Rac_p + P_Rac_s;

% Core loss
Pv = Ki .* (Delta_B/2).^beta .* fs.^alpha .* 1000; % [W/m3] % For EPCOS TDK, push-pull, from Magnetic Design Tool
P_fe = Pv .* Ve;

% Inductance loss
P_llk = L_lk .* n_trafo.^2 .* (Iout + Delta_I./2).^2 .* fs;

% Capacitive loss
P_cdm = C_dm * Vin^2 * fs;

% Total transformer loss
P_trafo = P_cu + P_fe + P_llk + P_cdm;


%% Gate drive circuit
% Gate charges
Qg_p = 13.6*10^-9; Qg_s = 8*10^-9;

% Gate resistances
R_DSON_N = 0.6; R_DSON_P = 0.8;

R_on = 8.2; R_on_p = R_on + 0.4; R_on_s = R_on + 0.6;
R_off = 0; R_off_p = R_off + 0.4; R_off_s = R_off + 0.6;

% Gate driver supplies
V_DD_p = 5; GND_p = -1;
V_DD_s = 6; GND_s = -2;

% Thermal resistance
Rth_ja = 45;

P_gate_p = Qg_p * (V_DD_p - GND_p)^2 * fs; P_gate_s = Qg_s * (V_DD_s - GND_s)^2 * fs;

P_adum_p = P_gate_p * (0.5*(R_DSON_P/(R_on_p+R_DSON_P)) + 0.5*(R_DSON_N/(R_off_p+R_DSON_N)));
P_adum_s = P_gate_s * (0.5*(R_DSON_P/(R_on_s+R_DSON_P)) + 0.5*(R_DSON_N/(R_off_p+R_DSON_N)));

T_adum_p = Rth_ja * 2 * P_adum_p; T_adum_s = Rth_ja * 2 * P_adum_s;


%% FET conduction


%% Efficiency curve with total losses

% Lacking: FET conduction, FET switching, FET capacitors,
% (blocking losses), body diode losses (deadtime, reverse?)

Pout = Vout.*Iout;
P_tot = P_trafo + P_gate_p + P_gate_s + P_L'

eff = Pout./(Pout+P_tot)
plot(Pout,eff)