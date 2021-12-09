%% 

clc,clear,close all

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Determine Optimal Transformer Winding Ratio and Duty Cycle
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Vin = 130; Vo = 60; Io = 25; Po = Vo*Io; Iin = Po/Vin; 
L = 50e-6;
fs = 200e3;
Ts = 1/fs;

n = [0.5:0.05:1];
d = Vo./(Vin*2.*n);

deltaI_L = (n.*Vin-Vo).*1./L.*d.*Ts;
Ilmax = Io+deltaI_L./2;
Ilmin = Io-deltaI_L./2;
Iswmax = Ilmax.*n; Iswmin=Ilmin.*n;

% Primary
    u_1 = 1/3.*(Iswmin.^2+Iswmin.*Iswmax+Iswmax.^2);
    IpriRMS = sqrt(d.*u_1);
    
    I_D_turnon      = n.*Ilmin;
    I_D_turnoff     = n.*Ilmax;
    V_DS_turnon     = Vin/2;
    V_DS_turnoff    = Vin/2;
    V_DS            = Vin/2;

    V_GS = 5;
    R_gext = 4;
    
    % EPC2215
    %Q_Gtot  = 13.6e-9;  % typ: 13.6e-9 | max: 17.7e-9
    R_DSon  = 8e-3;     % typ: 6e-3 | max: 8e-3
    C_GD = 105.65e-12;
    V_TH = 1.1; % 2.5;
    C_iss_VDS = 1356e-12; % max: 1790e-12;
    R_g  = 0.4;
    R_G = R_g + R_gext;
    Q_GD = 2.1e-9;
    V_gp = 2.1;

    t_ir = R_G * C_iss_VDS*log((V_GS-V_TH)/(V_GS-V_gp));
    t_vf = R_G * C_GD * V_DS/(V_GS-V_gp);
    t_vr = R_G * C_GD * V_DS/V_gp;
    t_if = R_G * C_iss_VDS*log(V_gp/V_TH);
    P_sw_EPC2215  = 0.5*V_DS.*I_D_turnon*(t_ir+t_vf).*fs + 0.5*V_DS.*I_D_turnoff*(t_if+t_vr).*fs;
    P_con_EPC2215 = R_DSon * IpriRMS.^2;

    P_tot_EPC2215 = P_con_EPC2215 + P_sw_EPC2215;


% Secondary
    u_2 = 1/3.*(Ilmin.^2+Ilmin.*Ilmax+Ilmax.^2); %on time: d
    u_3 = 1/3.*((Ilmax/2).^2+(Ilmax/2).*(Ilmin/2)+(Ilmin/2).^2);
    IsecRMS = sqrt(u_2.*d+u_3.*(0.5-d)+u_3.*(0.5-d));

    I_D_turnon      = Ilmin/2;
    I_D_turnoff     = Ilmax/2;
    V_DS_turnon     = n.*Vin;
    V_DS_turnoff    = n.*Vin;
    V_DS            = n.*Vin;
    
    V_GS = 5;
    R_gext = 4;
    
    % EPC2001C
    %Q_Gtot  = 7.5e-9;   % typ: 7.5e-9 | max: 9e-9
    R_DSon  = 7e-3;     % typ: 5.6e-3 | max: 7e-3 
    C_GD = 0.1161e-9;
    V_TH = 1.4; % 2.5;
    C_iss_VDS = 770e-12;
    R_g  = 0.3;
    R_G = R_g + R_gext;
    Q_GD = 1.2e-9; % 2e-9;
    V_gp = 2.35;

    t_ir = R_G * C_iss_VDS*log((V_GS-V_TH)/(V_GS-V_gp));
    t_vf = R_G * C_GD * V_DS/(V_GS-V_gp);
    t_vr = R_G * C_GD * V_DS/V_gp;
    t_if = R_G .* C_iss_VDS.*log(V_gp/V_TH);
    P_sw_EPC2001C    = 0.5.*V_DS.*I_D_turnon.*(t_ir+t_vf).*fs + 0.5.*V_DS.*I_D_turnoff.*(t_if+t_vr).*fs;
    P_con_EPC2001C   = R_DSon * IsecRMS.^2;

    P_tot_EPC2001C   = P_con_EPC2001C + P_sw_EPC2001C;
    
    % EPC2218
    %Q_Gtot  = 10.5e-9;  % typ: 10.5e-9 | max: 13.6e-9
    R_DSon  = 3.2e-3;   % typ: 2.4e-3  | max: 3.2e-3
    C_GD = 108.27e-12;
    V_TH = 1.1; % 2.5;
    C_iss_VDS = 1189e-12; 
    R_g  = 0.4;
    R_G = R_g + R_gext;
    Q_GD = 1.5e-9;
    V_gp = 2;

    t_ir = R_G * C_iss_VDS*log((V_GS-V_TH)/(V_GS-V_gp));
    t_vf = R_G * C_GD * V_DS/(V_GS-V_gp);
    t_vr = R_G * C_GD * V_DS/V_gp;
    t_if = R_G * C_iss_VDS*log(V_gp/V_TH);
    P_sw_EPC2218    = 0.5.*V_DS.*I_D_turnon.*(t_ir+t_vf).*fs + 0.5.*V_DS.*I_D_turnoff.*(t_if+t_vr).*fs;
    P_con_EPC2218   = R_DSon * IsecRMS.^2;

    P_tot_EPC2218   = P_con_EPC2218 + P_sw_EPC2218;

    % GaN Systems: GS61004B
    %Q_Gtot  = 3.3e-9;   % typ: 3.3e-9 | max: ?
    R_DSon  = 22e-3;    % typ: 16e-3  | max: 22e-3
    C_GD = 33.67e-12;
    V_TH = 1.7; % 2.6;
    C_iss_VDS = 260e-12;
    R_g  = 0.9;
    R_G = R_g + R_gext;
    Q_GD = 0.7e-9;
    V_gp = 3.5;

    t_ir = R_G * C_iss_VDS*log((V_GS-V_TH)/(V_GS-V_gp));
    t_vf = R_G * C_GD * V_DS/(V_GS-V_gp);
    t_vr = R_G * C_GD * V_DS/V_gp;
    t_if = R_G * C_iss_VDS*log(V_gp/V_TH);
    P_sw_GS61004B    = 0.5.*V_DS.*I_D_turnon.*(t_ir+t_vf).*fs + 0.5.*V_DS.*I_D_turnoff.*(t_if+t_vr).*fs;
    P_con_GS61004B   = R_DSon * IsecRMS.^2;

    P_tot_GS61004B   = P_con_GS61004B + P_sw_GS61004B;
    
    % GaN Systems: GS61008P
    %Q_Gtot  = 8e-9;     % typ: 8e-9 | max: ?
    R_DSon  = 9.5e-3;   % typ: 7e-3 | max: 9.5e-3
    C_GD = 84.965e-12;
    V_TH = 1.7; % 2.6;
    C_iss_VDS = 600e-12; 
    R_g  = 0.8;
    R_G = R_g + R_gext;
    Q_GD = 1.7e-9;
    V_gp = 3.5;

    t_ir = R_G * C_iss_VDS*log((V_GS-V_TH)/(V_GS-V_gp));
    t_vf = R_G * C_GD * V_DS/(V_GS-V_gp);
    t_vr = R_G * C_GD * V_DS/V_gp;
    t_if = R_G * C_iss_VDS*log(V_gp/V_TH);
    P_sw_GS61008P    = 0.5.*V_DS.*I_D_turnon.*(t_ir+t_vf).*fs + 0.5.*V_DS.*I_D_turnoff.*(t_if+t_vr).*fs;
    P_con_GS61008P   = R_DSon * IsecRMS.^2;

    P_tot_GS61008P   = P_con_GS61008P + P_sw_GS61008P;
    
    % GaN Systems: GS61008T
    %Q_Gtot  = 8e-9;     % typ: 8e-9 | max: ?
    R_DSon  = 9.5e-3;   % typ: 7e-3 | max: 9.5e-3
    C_GD = 84.965e-12;
    V_TH = 1.7; % 2.6;
    C_iss_VDS = 600e-12;
    R_g  = 0.6;
    R_G = R_g + R_gext;
    Q_GD = 1.7e-9;
    V_gp = 3.5;

    t_ir = R_G * C_iss_VDS*log((V_GS-V_TH)/(V_GS-V_gp));
    t_vf = R_G * C_GD * V_DS/(V_GS-V_gp);
    t_vr = R_G * C_GD * V_DS/V_gp;
    t_if = R_G * C_iss_VDS*log(V_gp/V_TH);
    P_sw_GS61008T    = 0.5.*V_DS.*I_D_turnon.*(t_ir+t_vf).*fs + 0.5.*V_DS.*I_D_turnoff.*(t_if+t_vr).*fs;
    P_con_GS61008T   = R_DSon * IsecRMS.^2;

    P_tot_GS61008T   = P_con_GS61008T + P_sw_GS61008T;
    
% Total Converter Power Loss
    % Primary Switch:     EPC2215
    % Secondary Switches: EPC2001C, EPC2218, GS61004B, GS61008P, GS61008T
    
    P_loss_EPC2215_EPC2001C = P_tot_EPC2215*4 + P_tot_EPC2001C*4;
    P_loss_EPC2215_EPC2218  = P_tot_EPC2215*4 + P_tot_EPC2218*4;
    P_loss_EPC2215_GS61004B = P_tot_EPC2215*4 + P_tot_GS61004B*4;
    P_loss_EPC2215_GS61008P = P_tot_EPC2215*4 + P_tot_GS61008P*4;
    P_loss_EPC2215_GS61008T = P_tot_EPC2215*4 + P_tot_GS61008T*4;
    
    figure(1)
    subplot(1,2,1)
    plot(n,P_loss_EPC2215_EPC2001C, n,P_loss_EPC2215_EPC2218, n,P_loss_EPC2215_GS61004B, n,P_loss_EPC2215_GS61008P, n,P_loss_EPC2215_GS61008T)
    legend('Ploss EPC2215 + EPC2001C','Ploss EPC2215 + EPC2218','Ploss EPC2215 + GS61004B','Ploss EPC2215 + GS61008P','Ploss EPC2215 + GS61008T')
    ylabel('Ploss Primary + Secondary [W]')
    xlabel('Transformer Winding Ratio [ ]')
    
    subplot(1,2,2)
    plot(d,P_loss_EPC2215_EPC2001C, d,P_loss_EPC2215_EPC2218, d,P_loss_EPC2215_GS61004B, d,P_loss_EPC2215_GS61008P, d,P_loss_EPC2215_GS61008T)
    legend('Ploss EPC2215 + EPC2001C','Ploss EPC2215 + EPC2218','Ploss EPC2215 + GS61004B','Ploss EPC2215 + GS61008P','Ploss EPC2215 + GS61008T')
    ylabel('Ploss Primary + Secondary [W]')
    xlabel('Duty cycle [ ]')
    
    figure(2)
    plot(n,P_tot_EPC2215, n,P_tot_EPC2001C, n,P_tot_EPC2218, n,P_tot_GS61004B, n,P_tot_GS61008P, n,P_tot_GS61008T)
    legend('EPC2215','EPC2001C','EPC2218','GS61004B','GS61008P','GS61008T')
    ylabel('Total Device Power Loss [W]')
    xlabel('Switch Frequency [Hz]')
    
%%

clc,clear,close all

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% FET losses vs frequency
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Vin = 130; Vo = 60; Io = 25; Po = Vo*Io; Iin = Po/Vin; 
fs = [50e3 100e3 150e3 200e3 250e3 300e3 350e3 400e3];
fs = 50e3:5e3:400e3;
Ts = 1./fs; 
L = 4e-6;
n = 0.5;
d = Vo/(Vin*2*n);   % Vo/Vin = 2nD

%fs = 200e3;
%d = 0.01:0.01:0.5;

deltaI_L = (n.*Vin-Vo).*1./L.*d.*Ts;
%deltaI_L = 0.2*Io*[1 1 1 1 1 1 1 1];
Ilmax = Io+deltaI_L./2;
Ilmin = Io-deltaI_L./2;
Iswmax = Ilmax.*n; Iswmin=Ilmin.*n;

% Primary
    u_1 = 1/3.*(Iswmin.^2+Iswmin.*Iswmax+Iswmax.^2);
    IpriRMS = sqrt(d.*u_1);
    
    I_D_turnon      = n.*Ilmin;
    I_D_turnoff     = n.*Ilmax;
    V_DS_turnon     = Vin/2;
    V_DS_turnoff    = Vin/2;
    V_DS            = Vin/2;    
    
    V_GS = 5;
    R_gext = 4;
    
    % EPC2215
    %Q_Gtot  = 13.6e-9;  % typ: 13.6e-9 | max: 17.7e-9
    R_DSon  = 8e-3;     % typ: 6e-3 | max: 8e-3
%     R_DSon = 8e-3*1.24; % at 63.8 degrees
%     R_DSon = 8e-3*1.25; % at 65.5 degrees
    C_GD = 105.65e-12;
    V_TH = 1.1; % 2.5;
    C_iss_VDS = 1356e-12; % max: 1790e-12;
    R_g  = 0.4;
    R_G = R_g + R_gext;
    R_G = 3;
    Q_GD = 2.1e-9;
    V_gp = 2.1;

    t_ir = R_G * C_iss_VDS*log((V_GS-V_TH)/(V_GS-V_gp));
    t_vf = R_G * C_GD * V_DS/(V_GS-V_gp);
    t_vr = R_G * C_GD * V_DS/V_gp;
    t_if = R_G * C_iss_VDS*log(V_gp/V_TH);
%     tir = t_ir
%     rg = R_G
%     cgd = C_GD
%     vgs = V_GS
%     vgp = V_gp
%     tif = t_if 
    P_sw_EPC2215  = 0.5*V_DS.*I_D_turnon*(t_ir+t_vf).*fs + 0.5*V_DS.*I_D_turnoff*(t_if+t_vr).*fs;
    P_con_EPC2215 = R_DSon * IpriRMS.^2;

    P_tot_EPC2215 = P_con_EPC2215 + P_sw_EPC2215;
    P_tot_EPC2215(4);

    
% Secondary
    u_2 = 1/3.*(Ilmin.^2+Ilmin.*Ilmax+Ilmax.^2); %on time: d
    u_3 = 1/3.*((Ilmax/2).^2+(Ilmax/2).*(Ilmin/2)+(Ilmin/2).^2);
    IsecRMS = sqrt(u_2.*d+u_3.*(0.5-d)+u_3.*(0.5-d));

    I_D_turnon      = Ilmin/2;
    I_D_turnoff     = Ilmax/2;
    V_DS_turnon     = n.*Vin;
    V_DS_turnoff    = n.*Vin;
    V_DS            = n.*Vin;
    
    V_GS = 5;
    R_gext = 4;
    
    % EPC2001C
    %Q_Gtot  = 7.5e-9;   % typ: 7.5e-9 | max: 9e-9
    R_DSon  = 7e-3;     % typ: 5.6e-3 | max: 7e-3 
    C_GD = 0.1161e-9;
    V_TH = 1.4; % 2.5;
    C_iss_VDS = 770e-12;
    R_g  = 0.3;
    R_G = R_g + R_gext;
    R_G = 3;
    Q_GD = 1.2e-9; % 2e-9;
    V_gp = 2.35;

    t_ir = R_G * C_iss_VDS*log((V_GS-V_TH)/(V_GS-V_gp));
    t_vf = R_G * C_GD * V_DS/(V_GS-V_gp);
    t_vr = R_G * C_GD * V_DS/V_gp;
    t_if = R_G .* C_iss_VDS.*log(V_gp/V_TH);
    P_sw_EPC2001C    = 0.5.*V_DS.*I_D_turnon.*(t_ir+t_vf).*fs + 0.5.*V_DS.*I_D_turnoff.*(t_if+t_vr).*fs;
    P_con_EPC2001C   = R_DSon * IsecRMS.^2;

    P_tot_EPC2001C   = P_con_EPC2001C + P_sw_EPC2001C;
    
    % EPC2218
    %Q_Gtot  = 10.5e-9;  % typ: 10.5e-9 | max: 13.6e-9
    R_DSon  = 3.2e-3;   % typ: 2.4e-3  | max: 3.2e-3
%     R_DSon  = 3.2e-3*1.3327; % at 74 degrees
%     R_DSon  = 3.2e-3*1.3567; % at 77 degrees
    C_GD = 108.27e-12;
    V_TH = 1.1; % 2.5;
    C_iss_VDS = 1189e-12; 
    R_g  = 0.4;
    R_G = R_g + R_gext;
    R_G = 3;
    Q_GD = 1.5e-9;
    V_gp = 2;

    t_ir = R_G * C_iss_VDS*log((V_GS-V_TH)/(V_GS-V_gp));
    t_vf = R_G * C_GD * V_DS/(V_GS-V_gp);
    t_vr = R_G * C_GD * V_DS/V_gp;
    t_if = R_G * C_iss_VDS*log(V_gp/V_TH);
    P_sw_EPC2218    = 0.5.*V_DS.*I_D_turnon.*(t_ir+t_vf).*fs + 0.5.*V_DS.*I_D_turnoff.*(t_if+t_vr).*fs;
    P_con_EPC2218   = R_DSon * IsecRMS.^2;

    P_tot_EPC2218   = P_con_EPC2218 + P_sw_EPC2218;
    P_tot_EPC2218(4);
    
    % GaN Systems: GS61004B
    V_GS = 6;

    %Q_Gtot  = 3.3e-9;   % typ: 3.3e-9 | max: ?
    R_DSon  = 22e-3;    % typ: 16e-3  | max: 22e-3
%     R_DSon  = 22e-3*1.4367; % at 75 degrees
%     R_DSon  = 22e-3*1.6; % at 92 degrees
%     R_DSon  = 22e-3*1.668; % at 99 degrees
%     R_DSon  = 22e-3*1.7; % at 102 degrees
    C_GD = 33.67e-12;
    V_TH = 1.7; % 2.6;
    C_iss_VDS = 260e-12;
    R_g  = 0.9;
    R_G = R_g + R_gext;
    R_G = 3;
    Q_GD = 0.7e-9;
    V_gp = 3.5;

    t_ir = R_G * C_iss_VDS*log((V_GS-V_TH)/(V_GS-V_gp));
    t_vf = R_G * C_GD * V_DS/(V_GS-V_gp);
    t_vr = R_G * C_GD * V_DS/V_gp;
    t_if = R_G * C_iss_VDS*log(V_gp/V_TH);
    P_sw_GS61004B    = 0.5.*V_DS.*I_D_turnon.*(t_ir+t_vf).*fs + 0.5.*V_DS.*I_D_turnoff.*(t_if+t_vr).*fs;
    P_con_GS61004B   = R_DSon * IsecRMS.^2;

    P_tot_GS61004B   = P_con_GS61004B + P_sw_GS61004B;
    P_tot_GS61004B(4);
    
    % GaN Systems: GS61008P
    %Q_Gtot  = 8e-9;     % typ: 8e-9 | max: ?
    R_DSon  = 9.5e-3;   % typ: 7e-3 | max: 9.5e-3
    C_GD = 84.965e-12;
    V_TH = 1.7; % 2.6;
    C_iss_VDS = 600e-12;
    R_g  = 0.8;
    R_G = R_g + R_gext;
    R_G = 3;
    Q_GD = 1.7e-9;
    V_gp = 3.5;

    t_ir = R_G * C_iss_VDS*log((V_GS-V_TH)/(V_GS-V_gp));
    t_vf = R_G * C_GD * V_DS/(V_GS-V_gp);
    t_vr = R_G * C_GD * V_DS/V_gp;
    t_if = R_G * C_iss_VDS*log(V_gp/V_TH);
    P_sw_GS61008P    = 0.5.*V_DS.*I_D_turnon.*(t_ir+t_vf).*fs + 0.5.*V_DS.*I_D_turnoff.*(t_if+t_vr).*fs;
    P_con_GS61008P   = R_DSon * IsecRMS.^2;

    P_tot_GS61008P   = P_con_GS61008P + P_sw_GS61008P;
    
    % GaN Systems: GS61008T
    %Q_Gtot  = 8e-9;     % typ: 8e-9 | max: ?
    R_DSon  = 9.5e-3;   % typ: 7e-3 | max: 9.5e-3
%    R_DSon  = 9.5e-3*1.339; % at 66 degrees
    R_DSon  = 9.5e-3*1.3969; % at 71 degrees
    C_GD = 84.965e-12;
    V_TH = 1.7; % 2.6;
    C_iss_VDS = 600e-12;
    R_g  = 0.6;
    R_G = R_g + R_gext;
    R_G = 3;
    Q_GD = 1.7e-9;
    V_gp = 3.5;

    t_ir = R_G * C_iss_VDS*log((V_GS-V_TH)/(V_GS-V_gp));
    t_vf = R_G * C_GD * V_DS/(V_GS-V_gp);
    t_vr = R_G * C_GD * V_DS/V_gp;
    t_if = R_G * C_iss_VDS*log(V_gp/V_TH);

    P_sw_GS61008T    = 0.5.*V_DS.*I_D_turnon.*(t_ir+t_vf).*fs + 0.5.*V_DS.*I_D_turnoff.*(t_if+t_vr).*fs;
    P_con_GS61008T   = R_DSon * IsecRMS.^2;

    P_tot_GS61008T   = P_con_GS61008T + P_sw_GS61008T;
    
%     P_con_GS61008T(4)
%     P_sw_GS61008T(4)
%     P_tot_GS61008T(4)
    
% Total Converter Power Loss
    % Primary Switch:     EPC2215
    % Secondary Switches: EPC2001C, EPC2218, GS61004B, GS61008P, GS61008T
    
    P_loss_EPC2215_EPC2001C = P_tot_EPC2215*4 + P_tot_EPC2001C*4;
    P_loss_EPC2215_EPC2218  = P_tot_EPC2215*4 + P_tot_EPC2218*4;
    P_loss_EPC2215_GS61004B = P_tot_EPC2215*4 + P_tot_GS61004B*4;
    P_loss_EPC2215_GS61008P = P_tot_EPC2215*4 + P_tot_GS61008P*4;
    P_loss_EPC2215_GS61008T = P_tot_EPC2215*4 + P_tot_GS61008T*4;
    
figure(1)
plot(fs*1e-3,P_tot_EPC2215, fs*1e-3,P_tot_EPC2001C, fs*1e-3,P_tot_EPC2218, fs*1e-3,P_tot_GS61004B, fs*1e-3,P_tot_GS61008P, fs*1e-3,P_tot_GS61008T,'LineWidth',2)
legend('EPC2215','EPC2001C','EPC2218','GS61004B','GS61008P','GS61008T')
ylabel('Conduction Loss + Switching Loss [W]','FontSize',18)
xlabel('Switching Frequency [kHz]','FontSize',18)
set(gca, 'FontSize', 18)
    
figure(2)
plot(fs,P_loss_EPC2215_EPC2001C, fs,P_loss_EPC2215_EPC2218, fs,P_loss_EPC2215_GS61004B, fs,P_loss_EPC2215_GS61008P, fs,P_loss_EPC2215_GS61008T)
legend('Ploss EPC2215 + EPC2001C','Ploss EPC2215 + EPC2218','Ploss EPC2215 + GS61004B','Ploss EPC2215 + GS61008P','Ploss EPC2215 + GS61008T')
ylabel('Total Converter Power Loss [W]')
xlabel('Switch Frequency [Hz]')

figure(3)
plot(d,P_tot_EPC2215, d,P_tot_EPC2001C, d,P_tot_EPC2218, d,P_tot_GS61004B, d,P_tot_GS61008P, d,P_tot_GS61008T)
legend('EPC2215','EPC2001C','EPC2218','GS61004B','GS61008P','GS61008T')
ylabel('Total Device Power Loss [W]')
xlabel('Duty Cycle [ ]')
