%% Total Power Stage Power Losses Across All Output Powers
clear, close all, clc;

f_array = [200e3, 200e3, 200e3];
vo_array = [60, 60, 60];
vi_array = [130, 130, 130];


for s = 1:1:length(f_array)
%% Converter properties
fs = f_array(s); % [Hz]
Ts = 1/fs; % [s]
Vin = vi_array(s); % [V]
Vout = vo_array(s); % [V]
Iout = 25; % [A]
n_trafo = 0.5;

% For changing both output voltage and current
%D = 0.01:0.01:0.49;
%Rout = Vout/Iout; % [Ohm]
%Vout = 2*Vin*n_trafo*D; % [V]
%Iout = Vout./Rout; % [A]

% For changing only output current
D = Vout/(2*Vin*n_trafo);
Iout = 0.5:0.5:25;
Rout = Vout./Iout;

% For trafo
D_L = 2.*D;
fs_L = 2.*fs;

%% Transformer core properties
mu_0 = 1.25663706*10^-6;
mu_r_fe = 1690;
Ae = 178 * 10^-6; % [m]
le = 97 * 10^-3; % [m]
Ve = 17300 * 10^-9; % [m]

% Steinmetz
Kc = 0.009498;
alpha = 1.424;
beta = 2.383;
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

% Capacitor capacitance
dQ = 0.5 .* dIL/2 .* 0.5.*Ts./2;
pVo = 0.01;
dVo = Vout.*pVo;
Co = dQ./dVo;

% Capacitor max ESR
ESR_max = dVo./dIL;


%%%%%%%%%%%%%%%%%%%%% Parameters %%%%%%%%%%%%%%%%%%%%%
N = 6;
L = 4.5e-6; % Measured

% Calculating currents again based on actual L
dIL = (Vin.*n_trafo-Vout)./L.*D_L.*1./(fs_L);   % new dIL
IL_rms = sqrt(IL_avg.^2 + ((dIL./2)/sqrt(3)).^2);
IC_rms = 1/sqrt(3).*dIL./2;
m = 1:N;

h_tape = 0.055e-3*2;
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

P_DC = R_DC.*IL_avg.^2;

%%%%%%%%%%%%%%%%%%%%% R_AC & P_AC %%%%%%%%%%%%%%%%%%%%%
T = 50; % degrees C
rho_w = 1.68e-8*(1+0.003862*(T-20));
mu_0 = 4e-7*pi;
skindepth = sqrt(rho_w/(pi*mu_0*fs_L));
phi = h/skindepth;

for i = 1:length(m)
    FR_j(m) = phi/2 * (( sinh(phi) + sin(phi) ) / ( cosh(phi) - cos(phi) )) ...
            + phi/2 * (2 * m(i) - 1)^2 ...
            * (( sinh(phi) - sin(phi) ) / ( cosh(phi) + cos(phi) )); 
end

R_ACj = FR_j .* R_DCj;
for i= 1:length(h)
    R_AC(i,1) = sum(R_ACj(i,:));
end 

P_AC = R_AC.*IC_rms.^2;


%%%%%%%%%%%%%%%%%%%%% Intra-winding Capacitance %%%%%%%%%%%%%%%%%%%%%

k = 0;
for i = 1:(length(m)+1)
    V(:,i) = Vin*n_trafo - k.*(Vin*n_trafo-Vout)./length(m);
    k = k+1;
end

for j = 1:1:size(V,1)
    for i = 1:(length(m)-1)
        Vaj(j,i) = V(j,i+1)-V(j,i);
        Vbj(j,i) = V(j,i+2)-V(j,i+1);
    end
end

epsi_0 = 8.85419e-12;
epsi_r = 3.4;
V_tot = Vin*n_trafo;

for i = 1:1:size(V,1)
    for j = 1:(length(m)-1)
        Cdmj(i,j) = w*lw(j+1)/h_tape*(Vaj(i,j).^2+Vaj(i,j).*Vbj(i,j)+Vbj(i,j).^2);
    end
end

for i = 1:1:size(V,1)
    Cdm(i,1) = epsi_0*epsi_r/(3*V_tot^2) * sum(Cdmj(i,:));
end

P_Cdm = 0.5.*Cdm.*V_tot.^2.*fs_L;

%%%%%%%%%%%%%%%%%%%%% Leakage Inductance %%%%%%%%%%%%%%%%%%%%%
Nrow = 1;
I_tot = IL_avg;
m = 0:1:length(m);

I_enclosed = (m'*IL_avg)';
i = 1;
Lj = lw(i,1)*h./(3*Nrow*w) * (I_enclosed(1)^2);
for i = 1:length(I_enclosed)
    for j = 1:length(m)-1
        Lj(i,j) = lw(j)*h./(3*Nrow*w) .* (I_enclosed(i,j).^2 + I_enclosed(i,j).*I_enclosed(i,j+1)+I_enclosed(i,j+1).^2);
    end
end

for i = 1:length(I_enclosed)
    for j = 1:length(m)-1
        Lj_insul(i,j) = lw(j)*h./w .* (I_enclosed(i,j+1)).^2;
    end
end

for i = 1:length(I_enclosed)
    L_llk(i) = mu_0./(I_tot(i).^2).*(sum(Lj(i,:)) + sum(Lj_insul(i,:)));
end


%%%%%%%%%%%%%%%%%%%%% Core Loss %%%%%%%%%%%%%%%%%%%%%

dB = D_L.*(Vin.*n_trafo-Vout)./(N.*Ae_l.*fs_L);
Bpk = L.*(IL_avg+dIL./2)./(N.*Ae_l);

Kc_l = 0.009836;
alpha_l = 1.475;
beta_l = 2.592;

Ki_l = Kc_l/(2^(beta_l-1)*pi^(alpha_l-1)*(1.1044+6.8244/(alpha_l+1.354)));

Pv_l = Ki_l.*(dB/2).^beta_l.*fs_L.^alpha_l.*(D_L.^(1-alpha_l) + (1-(D_L))^(1-alpha_l)) .* 1000;
Pv_l = double(Pv_l);

P_core = Pv_l*Ve_l;


%%%%%%%%%%%%%%%%%%%%% Total Losses %%%%%%%%%%%%%%%%%%%%%
P_L = P_Cdm + P_DC + P_AC + P_core;


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

Ip = Iout .* 2.*D .* n_trafo;


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

L_lk = 57e-9;
% Capacitive parasitics calculated in Excel
% Capacitors do not change as function of duty cycle/output power
C_cm = 3.92359e-09;
C_dm = 1.11762e-10;
C_dm = 38e-12;


%% Transformer losses

Delta_I = dIL;
% AC resistance losses
u_s1 = 1/3.*((Iout+Delta_I./2).^2 + (Iout+Delta_I./2).*(Iout-Delta_I./2) + (Iout-Delta_I./2).^2);
u_s2 = 1/3.*(((Iout+Delta_I./2)./2).^2 + ((Iout+Delta_I./2)/2).*((Iout-Delta_I./2)/2) + ((Iout-Delta_I./2)./2).^2);
I_RMS_s = sqrt(D.*u_s1+(0.5-D).*2.*u_s2);

u1_m = 1/3*(-Im/2).^2; u2_m = 1/3*(Im/2).^2;
I_RMS_m = sqrt((D./2).*u1_m+(D./2).*u2_m+((1-D)./2).*u2_m+((1-D)./2).*u1_m);
I_RMS_p = I_RMS_s*n_trafo + I_RMS_m;

P_Rac_p = R_AC_p * I_RMS_p.^2;
P_Rac_s = R_AC_s .* I_RMS_s.^2;
P_cu = P_Rac_p + P_Rac_s;

% Core loss
Pv = Ki .* (Delta_B/2).^beta .* fs.^alpha .* (2.*D^(1-alpha)) .* 1000; % [W/m3] % For EPCOS TDK, push-pull, from Magnetic Design Tool
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
V_DD_p = 5; GND_p = -2;
V_DD_s = 6; GND_s = -2;

% Thermal resistance
Rth_ja = 45;

P_gate_p = Qg_p * (V_DD_p - GND_p)^2 * fs * 4; P_gate_s = Qg_s * (V_DD_s - GND_s)^2 * fs * 4;

P_adum_p = P_gate_p * (0.5*(R_DSON_P/(R_on_p+R_DSON_P)) + 0.5*(R_DSON_N/(R_off_p+R_DSON_N)));
P_adum_s = P_gate_s * (0.5*(R_DSON_P/(R_on_s+R_DSON_P)) + 0.5*(R_DSON_N/(R_off_p+R_DSON_N)));

T_adum_p = Rth_ja * 2 * P_adum_p; T_adum_s = Rth_ja * 2 * P_adum_s;


%% FET losses

Vo = Vout;
Io = Iout;
Po = Vo.*Io;
Iin = Ip; 
n = n_trafo;
d = D;
deltaI_L = dIL;
Ilmax = Io+deltaI_L./2;
Ilmin = Io-deltaI_L./2;
Iswmax = Ilmax.*n;
Iswmin = Ilmin.*n;


% Primary
    IpriRMS = I_RMS_p;
    
    I_D_turnon      = n.*Ilmin-Im/2;
    I_D_turnoff     = n.*Ilmax+Im/2;
    V_DS            = Vin/2;    
    
    V_GS = V_DD_p;
    R_gext = R_on_p;
    
    % EPC2215
    %R_DSon  = 8e-3;     % typ: 6e-3 | max: 8e-3
    R_DSon = 10.8e-3; % at 81 degrees
    C_GD = 105.65e-12;
    V_TH = 1.1; % 2.5;
    C_iss_VDS = 1356e-12; % max: 1790e-12;
    R_G_on = R_gext;
    R_G_off = R_off_p + R_DSON_N;
    Q_GD = 2.1e-9;
    V_gp = 2.1;

    t_ir = R_G_on * C_iss_VDS*log((V_GS-V_TH)/(V_GS-V_gp));
    t_vf = R_G_on * C_GD * V_DS/(V_GS-V_gp);
    t_vr = R_G_off * C_GD * V_DS/V_gp;
    t_if = R_G_off * C_iss_VDS*log(V_gp/V_TH);
    
    P_sw_EPC2215  = 0.5*V_DS.*I_D_turnon*(t_ir+t_vf).*fs + 0.5*V_DS.*I_D_turnoff*(t_if+t_vr).*fs;
    P_con_EPC2215 = R_DSon * IpriRMS.^2;

    P_tot_EPC2215 = P_con_EPC2215 + P_sw_EPC2215;

    
% Secondary
    IsecRMS = I_RMS_s;

    I_D_turnon      = Ilmin/2;
    I_D_turnoff     = Ilmax/2;
    V_DS            = n.*Vin;
    
    V_GS = V_DD_s;
    R_gext = R_on_s;
    
    
    % GaN Systems: GS61008T
    %R_DSon  = 9.5e-3;   % typ: 7e-3 | max: 9.5e-3
    R_DSon  = 10.1e-3; % at 77 degrees
    C_GD = 84.965e-12;
    V_TH = 1.7; % 2.6;
    C_iss_VDS = 600e-12;
    R_G_on = R_gext;
    R_G_off = R_off_s + R_DSON_N;
    Q_GD = 1.7e-9;
    V_gp = 3.5;

    t_ir = R_G_on * C_iss_VDS*log((V_GS-V_TH)/(V_GS-V_gp));
    t_vf = R_G_on * C_GD * V_DS/(V_GS-V_gp);
    t_vr = R_G_off * C_GD * V_DS/V_gp;
    t_if = R_G_off * C_iss_VDS*log(V_gp/V_TH);

    P_sw_GS61008T    = 0.5.*V_DS.*I_D_turnon.*(t_ir+t_vf).*fs + 0.5.*V_DS.*I_D_turnoff.*(t_if+t_vr).*fs;
    P_con_GS61008T   = R_DSon * IsecRMS.^2;

    P_tot_GS61008T   = P_con_GS61008T + P_sw_GS61008T;
    
    
% Total Converter Power Loss
    P_sw = (P_sw_GS61008T + P_sw_EPC2215)*4;
    P_con = (P_con_GS61008T + P_con_EPC2215)*4;
    P_FETs = P_tot_EPC2215*4 + P_tot_GS61008T*4;

    
%% FET blocking losses
I_leak_p = 0.5e-3;
I_leak_s = 50e-6;

P_leak_p = (1-D).*I_leak_p.*Vin*4;
P_leak_s = D.*I_leak_s.*Vin.*n_trafo*4;


%% FET capacitive losses
% Primary FET charges
Q_p_Vin = 80.9*10^-9; % [C] at 130 V
Q_p_oneplusnhalfVin = 69*10^-9; % [C] at (1+n)/2 * Vin = 97.5 V
Q_p_oneminusnhalfVin = 31.6*10^-9; % [C] at (1-n)/2 * Vin = 32.5 V

% Secondary FET charges
nVin = n_trafo.*Vin; % [V]
oneminushalfnVin = (1-n_trafo)./2.*Vin; % [V]

Coss_s_nVin = 236*10^-12; % [F] at n*Vin = 65 V
Q_s_nVin = nVin .* Coss_s_nVin;

% Total losses, as calculated from "Demonstration of a Compact
% Hard-Switched 3.5 kW DCDC Converter (...)"
P_caps = fs .* Vin .* (Q_p_Vin + 2 .* n_trafo .* Q_s_nVin + n_trafo .* ...
         (Q_p_oneplusnhalfVin - Q_p_oneminusnhalfVin));

     
%% FET "body diode" conduction losses
% Note: There is no actual body diode, however the behavior can be modelled
% as a body diode.
% There is no reverse recovery in the diode.
Vgs_th = 1.7; % [V]
V_F = Vgs_th - GND_s; % Modelled forward voltage, increased due to negative gate voltage
R_D = R_DSon;

t_dead = 50*10^-9; % [s]

I_Davg = Iout*t_dead/Ts;
I_Drms = sqrt(t_dead./(24.*Ts)) .* sqrt(12.*Iout.^2 + 3.*dIL.^2 + Vout.*t_dead./L.^2 .* ...
         (4.*Vout.*t_dead - 6.*L.*dIL));

P_diodes = 4 .* (V_F .* I_Davg + R_D .* I_Drms.^2);
P_diodes = 0;

% Due to the length of our dead-time, and the ringing in the converter, we
% will not experience any conduction losses for the body diode.

%% Sense Resistor
R_sens_pri = 10e-3;
R_sens_sec = 5e-3;

P_sens_pri = ((I_RMS_p + I_RMS_m).^2 .* R_sens_pri) .* 2;
P_sens_sec = ((I_RMS_s).^2 .* R_sens_sec) .* 2;

%% Efficiency curve with total losses

Pout = Vout.*Iout;
P_tot = P_trafo + P_L + P_FETs + P_leak_p + P_leak_s + P_caps + P_sens_pri + P_sens_sec;% + P_gate_p + P_gate_s + P_diodes;

%P_diss_EPC2215 = (P_tot_EPC2215*4 + P_leak_p + P_caps/2 + P_cdm + P_llk)/4

eff(s,:) = Pout./(Pout+P_tot)*100;
end

figure(1)
hold on
for j = 1:1:length(f_array)
    plot(Pout, eff(j,:), 'LineWidth', 4)
end
xlim([100 1500])
ylim([92 98])
%ylim([80 98])

% For frequency vs. efficiency plot
% for j = 1:1:length(f_array)
%     scatter(f_array(j), eff(j,50), 'LineWidth', 4)
% end

set(gca, 'FontSize', 18)
grid on
legend('100 kHz', '200 kHz', '300 kHz')
%legend('20 V', '40 V', '60 V')
%legend('130 V', '150 V', '170 V')
title('Power Stage Efficiency', 'FontSize', 26)
xlabel('Output Power [W]', 'FontSize', 22)
ylabel('Efficiency [%]', 'FontSize', 22)

figure(2)
plot(Pout, Pout./(Pout+P_trafo)*100, 'LineWidth', 4)
xlim([100 1500])
ylim([97 100])
set(gca, 'FontSize', 18)
grid on
legend('200 kHz')
title('Transformer Efficiency', 'FontSize', 26)
xlabel('Output Power [W]', 'FontSize', 22)
ylabel('Efficiency [%]', 'FontSize', 22)