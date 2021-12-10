clc, clear, close all

%%%%%%%%%%%%%%%%%%%%% Parameters and initial design %%%%%%%%%%%%%%%%%%%%%
Vin = 130;
Vo = 60;
n = 0.5;
D = Vo/Vin/(2*n);
fs = 200e3;
Ts = 1/fs;

D = 0.25;   % FOUND AT WORST CASE IN 'inductance.m'
Vo = 2*n*D*Vin

% Currents
IL_avg = 25
pIL = 0.2;
dIL = IL_avg*pIL

% Inductor inductance
L = (Vin*n-Vo)/dIL*D*1/(2*fs)
L = 4e-6;       % Adding a margin

dIL = (Vin*n-Vo)/L*D*1/(2*fs)   % new dIL
IL_rms = sqrt(IL_avg^2 + ((dIL/2)/sqrt(3))^2)
IC_rms = 1/sqrt(3)*dIL/2

% Capacitor capacitance
dQ = 0.5 * dIL/2 * 0.5*Ts/2
pVo = 0.01;
dVo = Vo*pVo;
Co = dQ/dVo
Co/3.3e-6

% Capacitor max ESR
ESR_max = dVo/dIL

%%%%%%%%%%%%%%%%%%%%% Core Specific Parameters %%%%%%%%%%%%%%%%%%%%%
% EPCOS TDK, E32/16/9, N87
% approx. 1mm airgap
AL = 145e-9;
Ae = 83e-6;
Ve = 6140e-9;
h_window = (22.7e-3 - 9.5e-3)/2;
h_window = 6e-3;
la = 11.6e-3; 
lb = 11.6e-3;
w_bobbin = 21.9e-3-2*0.9e-3;
w = 18e-3; % foil width


%%%%%%%%%%%%%%%%%%%%% Parameters %%%%%%%%%%%%%%%%%%%%%
N = ceil(sqrt(L/AL))
N = 6;
Pv = 16.5e3; % W/m^3 read at D = 0.25 N = 6
L = N^2*AL;
% Calculating currents again based on actual L
dIL = (Vin*n-Vo)/L*D*1/(2*fs)   % new dIL
IL_rms = sqrt(IL_avg^2 + ((dIL/2)/sqrt(3))^2)
IC_rms = 1/sqrt(3)*dIL/2
m = 1:N;

h_tape = 0.055e-3*2;
h = [0.15e-3 0.2e-3 0.3e-3 0.4e-3]'; % foil thickness
h_free_window = h_window - (N*h+N*h_tape);
l_creepage = h_free_window + (w_bobbin - w);

%%%%%%%%%%%%%%%%%%%%% R_DC & P_DC %%%%%%%%%%%%%%%%%%%%%
for i = 1:length(h)
    k = 0;
    for j = 1:length(m)
        lw(i,j) = la*2+lb*2 + k*8*(h(i)+h_tape);
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
R_DC
P_DC = R_DC*IL_avg^2

%%%%%%%%%%%%%%%%%%%%% R_AC & P_AC %%%%%%%%%%%%%%%%%%%%%
T = 50; % degrees C
rho_w = 1.68e-8*(1+0.003862*(T-20));
mu_0 = 4e-7*pi;
skindepth = sqrt(rho_w/(pi*mu_0*2*fs))

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
R_AC
P_AC = R_AC*IC_rms^2

figure(1)
plot(h*1e3,(R_DC*1e3)', h*1e3,FR_array, h*1e3,(R_AC*1e3)')
legend('R_{DC}', 'F_R', 'R_{AC}', 'Location', 'NorthWest')
xlabel('h_{foil} [mm]')
ylabel('F_R, R_{DC} [m\Omega], R_{AC} [m\Omega]')

%%%%%%%%%%%%%%%%%%%%% Intra-winding Capacitance %%%%%%%%%%%%%%%%%%%%%
V1 = Vin*n;
k = 0;
for i = 1:(length(m)+1)
    V(i) = Vin*n - k*(Vin*n-Vo)/length(m);
    k = k+1;
end

for i = 1:(length(m)-1)
    Vaj(i) = V(i+1)-V(i);
    Vbj(i) = V(i+2)-V(i+1);
end

epsi_0 = 8.85419e-12;
epsi_r = 3.4;
V_tot = Vin*n;

for i = 1:length(h)
    for j = 1:(length(m)-1)
        Cdmj(i,j) = w*lw(i,j+1)/h_tape*(Vaj(j)^2+Vaj(j)*Vbj(j)+Vbj(j)^2);
    end
end

for i = 1:length(h)
    Cdm(i,1) = epsi_0*epsi_r/(3*V_tot^2) * sum(Cdmj(i,:));
end

Cdm
P_Cdm = 0.5*Cdm*V_tot^2*2*fs

%%%%%%%%%%%%%%%%%%%%% Leakage Inductance %%%%%%%%%%%%%%%%%%%%%
Nrow = 1;
I_tot = IL_avg;

I_enclosed = m*IL_avg;
i = 1;
Lj = lw(i,1)*h./(3*Nrow*w) * (I_enclosed(1)^2);
for i = 1:length(h)
    for j = 2:length(m)
        Lj(i,j) = lw(i,j)*h(i)./(3*Nrow*w) * (I_enclosed(j)^2 + I_enclosed(j)*I_enclosed(j-1)+I_enclosed(j-1)^2);
    end
end

for i = 1:length(h)
    for j = 1:length(m)-1
        Lj_insul(i,j) = lw(i,j)*h(i)./w * (I_enclosed(j+1)-I_enclosed(j))^2;
    end
end

for i = 1:length(h)
    L_llk(i,1) = mu_0/I_tot^2*(sum(Lj(i,:)) + sum(Lj_insul(i,:)));
end
L_llk

%%%%%%%%%%%%%%%%%%%%% Core Loss %%%%%%%%%%%%%%%%%%%%%

dB = D*(Vin*n-Vo)/(N*Ae*2*fs)
Bpk = L*(IL_avg+dIL/2)/(N*Ae) % 127mT
% Kc = 1.766;
% alpha = 1.36;
% beta = 2.10;
% 
% Ki = Kc/(2^(beta-1)*pi^(alpha-1)*(1.1044+6.8244/(alpha+1.354)));
% 
% syms Ki
% eq = Pv == Ki*200e-3^beta*300e3^alpha*(D^(1-alpha)+(1-D)^(1-alpha));
% Ki = solve(eq,Ki)
% Pv = Ki*dB^beta*2*fs^alpha*(D^(1-alpha)+(1-D)^(1-alpha))
% Pv = double(Pv)

P_core_notstein = Pv*Ve;

%%%%%%%%%%%%%%%%%%%%% Total Losses %%%%%%%%%%%%%%%%%%%%%
P_Cdm
P_core_notstein
P_cu = P_AC + P_DC

P_tot = P_Cdm + P_DC + P_AC + P_core_notstein

%%%%%%%%%%%%%%%%%%%%% Temperature %%%%%%%%%%%%%%%%%%%%%
lh = 3.28;
ll = 3.2;
ld = 0.95;
A_su = lh*ll*2 + ll*ld*2 + lh*ld*2;
T_init = 25;
dT = (P_tot*1e3/A_su).^0.833
T = T_init + dT;

%%%%%%%%%%%%%%%%%%%% Measurements %%%%%%%%%%%%%%%%%%%%
% 7 stk paper in each outer leg

h = 0.4e-3;
A = w*h;
l_terminal = 40e-3;
l_terminal_tip = 8e-3;
w_terminal_tip = 7e-3;
l_wing = 15e-3;
w_wing = 7e-3;

R_DC_extra = (rho*l_terminal/A + rho*l_terminal_tip/(h*w_terminal_tip))*2 + ( rho*l_wing/(h*w_wing) )/2; % terminal*2 + 2 overgange i parallel
R_DC_tot = (R_DC(4) + R_DC_extra)
P_DC_tot = R_DC_tot.*IL_avg^2

C_extra = epsi_0*epsi_r*w*l_terminal/(h_tape)
C_tot = Cdm(4) + C_extra
P_C_tot = 0.5*C_tot*V_tot^2*2*fs