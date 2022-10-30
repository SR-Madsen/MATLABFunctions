clear, close all, clc;

%% Plant Continuous
% Components
Lc = 90.375*10^-6;
Lc = 33.15*10^-6; % Worst-case at maximum load (109.5 ARMS = 155 A peak)
Lg = 2*10^-6;
Cc = 30*10^-6;
Rlc = 5e-3;
Rlg = 3e-3;
Rcc = 1e-3;

% Timings
fsw = 24000;
fs = 2*fsw;
Ts = 1/(fs);
Td = 0.75*1/fsw;
%fres = 1/(2*pi)*sqrt((Lg+Lc)/(Lg*Lc*Cc)); % Apparently not though
fres = 1/(2*pi*sqrt((Lc+Lg)*Cc));

% Fundamental for three phases
fo = 50; % [Hz]
Vo = 230;
Po_max_3p = 50000;
Io_max_3p = Po_max_3p/(3*Vo);

% Fundamental for one phase
Po_max_1p = 50000/3;
Io_max_1p = Po_max_1p/Vo;

% Maximum load for current controller (150% of nominal load)
k_overcurr = 1.5;
%Zo = (Vo*sqrt(3))/(Io_max_3p*k_overcurr); % For three phases
Zo = Vo/(Io_max_1p*k_overcurr); % For one phase


% Transfer functions
Gil_num = [Cc*Lg Cc*(Rlg+Rcc+Zo) 1];
Gil_den = [Cc*Lg*Lc ...
           Cc*(Lg*(Rcc+Rlc)+Lc*(Rlg+Rcc+Zo)) ...
           Lg+Lc+Cc*Rcc*(Rlg+Zo)+Cc*Rlc*(Rlg+Rcc+Zo) ...
           Rlc + Rlg + Zo];
Gil = tf(Gil_num, Gil_den);

Gic_num = [Cc*Lg Cc*(Rlg+Zo) 0];
Gic_den = [Cc*Lg*Lc ...
           Cc*(Lc*(Rlg+Rcc+Zo)+Lg*(Rcc+Rlc)) ...
           Lc+Lg+Cc*Rlc*(Rlg+Rcc+Zo)+Cc*Rcc*(Rlg+Zo) ...
           Rlc + Rlg + Zo];
Gic = tf(Gic_num,Gic_den);

s = tf('s');
z = tf('z',Ts);
G1 = 1/(s*Lc+Rlc);
G2 = 1/(s*Cc) + Rcc;
G3 = 1/(s*Lg+Rlg);
G4 = Zo;
%G23_cl_s = feedback(G2,G3,-1);
%G23_cl_z = c2d(feedback(G2,G3,-1),Ts,'zoh');

G34_cl_s = feedback(G3,G4,-1);
G234_cl_s = feedback(G2,G34_cl_s,-1);
G2_z = c2d(G2,Ts,'zoh');
G234_cl_z = c2d(G234_cl_s,Ts,'zoh');
%Gil = feedback(G1,G234_cl_s,-1);
Gvc = feedback(G1*G234_cl_s,1,-1);
%Gic = series(Gvc,1/G2); % Inflates the order, do not use.


%% Proportional Current Controller Discrete Design
% FOR INDUCTOR CURRENT
omega_c_i = 0.175*fsw*2*pi;

% Differentiator
omega_max = omega_c_i;
phi_max = 30; % [degrees]
kf = (1-sind(phi_max))/(1+sind(phi_max));
tau_a = 1/(sqrt(kf)*omega_max);
tau_b = kf*tau_a;
G_diff_s = ((1+s*tau_a)/(1+s*tau_b));
opt = c2dOptions('Method','tustin','PrewarpFrequency',omega_max);
G_diff_z = c2d(G_diff_s,Ts,opt);

% Inner loop without control
Gi_nc_z = series(c2d(Gil,Ts,'zoh'),G_diff_z); % If lead-lag in series
%Gi_nc_z = feedback(feedback(c2d(Gil,Ts,'zoh'),1,-1)*G234_cl_z,G_diff_z,1); % If lead-lag in vc feedback
%Gi_nc_z = c2d(Gil,Ts,'zoh'); % If lead-lag is on PR controller
figure(1)
[mag, phase] = bode(Gi_nc_z,omega_c_i);
margin(Gi_nc_z)

% Inner loop with control, open loop
Kc = 1/mag;
Gi_z = series(Kc,Gi_nc_z);

figure(2)
[Gm,Pm,omega_i_gm,omega_i_pm] = margin(Gi_z);
PM_i_z = Pm-omega_i_pm*Td*180/pi
margin(Gi_z)

% Inner loop with control, closed-loop
Gi_cl_z = feedback(Gi_z,1,-1);
figure(3)
margin(Gi_cl_z)
omega_i_cl_z = bandwidth(Gi_cl_z)

% x = 1;
% for Kc = 0.01:0.01:5
%     Gic_z = series(Kc,Gic_no_control_z);
%     Gic_cl_z = feedback(Gic_z,1,-1);
%     omega_i_cl_z(x) = bandwidth(Gic_cl_z);
%     x = x + 1;
% end
% Kc = [0.01:0.01:5];
% plot(Kc,omega_i_cl_z)

%% Proportional Current Controller Discrete Design
% FOR CAPACITOR CURRENT
omega_c_i = 0.2*fsw*2*pi;

% Differentiator
omega_max = omega_c_i;
phi_max = 30; % [degrees]
kf = (1-sind(phi_max))/(1+sind(phi_max));
tau_a = 1/(sqrt(kf)*omega_max);
tau_b = kf*tau_a;
G_diff_s = ((1+s*tau_a)/(1+s*tau_b));
opt = c2dOptions('Method','tustin','PrewarpFrequency',omega_max);
G_diff_z = c2d(G_diff_s,Ts,opt);

% Inner loop without control
Gi_nc_z = series(c2d(Gic,Ts,'zoh'),G_diff_z); % If lead-lag in series
%Gi_nc_z = feedback(feedback(c2d(Gil,Ts,'zoh'),1,-1)*G234_cl_z,G_diff_z,1); % If lead-lag in vc feedback
%Gi_nc_z = c2d(Gil,Ts,'zoh'); % If lead-lag is on PR controller
figure(1)
[mag, phase] = bode(Gi_nc_z,omega_c_i);
margin(Gi_nc_z)

% Inner loop with control, open loop
Kc = 1/mag;
Gi_z = series(Kc,Gi_nc_z);

figure(2)
[Gm,Pm,omega_i_gm,omega_i_pm] = margin(Gi_z);
PM_i_z = Pm-omega_i_pm*Td*180/pi
margin(Gi_z)

% Inner loop with control, closed-loop
Gi_cl_z = feedback(Gi_z,1,-1);
figure(3)
margin(Gi_cl_z)
omega_i_cl_z = bandwidth(Gi_cl_z)

%% Proportional-Integrator Current Controller Discrete Design
%omega_c_i = 0.2*fsw*2*pi;
% Inner loop without control
%Gic_nc_z = c2d(Gil,Ts,'zoh');
%figure(1)
%[mag, phase] = bode(Gic_nc_z,omega_c_i);
%margin(Gic_nc_z)
% Inner loop with P control, open loop
%Kc = 1/mag;
%Gic_p_control_z = series(Kc,Gic_no_control_z);
%figure(20)
%margin(Gic_p_control_z)
% Inner loop with PI control, open loop
%Ki = omega_c_i/4;
%G_pi_z = Ki*Ts/(1-z^-1);
%Gic_z = series(G_pi_z,Gic_nc_z);
%[mag, phase] = bode(Gic_z,omega_c_i);
%[Gm,Pm] = margin(Gic_z);
%Kc = 1/mag;
%Kc = 1/Gm;
%G_pi_z = Kc + Ki*Ts/(1-z^-1);
%Gic_z = series(G_pi_z,Gic_nc_z);
% [Gm,Pm] = margin(Gic_z);
% Kc = Kc*Gm;
% G_pi_z = Kc + Ki*Ts/(1-z^-1);
% Gic_z = series(G_pi_z,Gic_no_control_z);
%figure(2)
%[mag, phase] = bode(Gic_z,omega_c_i);
%PM_i_z = 180+phase-omega_c_i*Td*180/pi
%margin(Gic_z)
% Inner loop with control, closed-loop
%Gic_cl_z = feedback(Gic_z,1,-1);
%figure(3)
%margin(Gic_cl_z)
%omega_i_cl_z = bandwidth(Gic_cl_z)
% x = 1;
% for Kc = 0.1:0.1:5
%     Gic_z = series((Kc+Ki*Ts/(1-z^-1)),Gic_no_control_z);
%     Gic_cl_z = feedback(Gic_z,1,-1);
%     omega_i_cl_z(x) = bandwidth(Gic_cl_z);
%     x = x + 1;
% end
% Kc = [0.1:0.1:5];
% plot(Kc,omega_i_cl_z)

%% Proportional-Resonant Voltage Controller Discrete Design
omega_c_o = fo*60*2*pi; % Capacitor current control
omega_c_o = 3e4; % Inductor current control

% Outer loop without control

% Differentiator
%omega_max = 2.1e3;
%phi_max = 60; % [degrees]
%kf = (1-sind(phi_max))/(1+sind(phi_max));
%tau_a = 1/(sqrt(kf)*omega_max);
%tau_b = kf*tau_a;
%G_diff_s = ((1+s*tau_a)/(1+s*tau_b));
%opt = c2dOptions('Method','tustin','PrewarpFrequency',omega_max);
%G_diff_z = c2d(G_diff_s,Ts,opt);

Go_nc_z = series(Gi_cl_z,G234_cl_z); % For inductor current control
%Go_nc_z = series(Gi_cl_z,G2_z); % For capacitor current control
%Go_nc_z = series(Gi_cl_z*G_diff_z,G234_cl_z); % For use with lead-lag
figure(4)
[mag, phase] = bode(Go_nc_z,omega_c_o);
margin(Go_nc_z)

% Determining Kp
Kp = 1/mag;
Gov_p_control_z = Go_nc_z*Kp;
figure(5)
[Gm, Pm] = margin(Gov_p_control_z);

%Kp = Kp*Gm_temp;
%Gov_p_control_z = Go_no_control_z*Kp;
margin(Gov_p_control_z)

% Outer loop with control, open-loop
omega_p = [];
Kr = [];
KT = [];
omega_w = [];
omega_o = fo*2*pi;

for h = 1:2:7
    omega_p(end+1) = fo*2*pi*h;
    Kr(end+1) = (omega_c_o/(4*h));
    KT(end+1) = omega_p(end)/(tan(omega_p(end)*Ts/2));
    omega_w(end+1) = 0.1*2*pi;
end
G_pr_r_z = (2*KT(1)*Kr(1)*omega_w(1)*(1-z^-2))/ ...
           (KT(1)^2 + 2*omega_w(1)*KT(1) + omega_o^2 - (2*KT(1)^2 - 2*omega_o^2)*z^-1 ...
            + (KT(1)^2-2*omega_w(1)*KT(1)+omega_o^2)*z^-2);

G_pr_r_3_z = (2*KT(2)*Kr(2)*omega_w(2)*(1-z^-2))/ ...
           (KT(2)^2 + 2*omega_w(2)*KT(2) + (3*omega_o)^2 - (2*KT(2)^2 - 2*(3*omega_o)^2)*z^-1 ...
            + (KT(2)^2-2*omega_w(2)*KT(2)+(3*omega_o)^2)*z^-2);

G_pr_r_5_z = (2*KT(3)*Kr(3)*omega_w(3)*(1-z^-2))/ ...
           (KT(3)^2 + 2*omega_w(3)*KT(3) + (5*omega_o)^2 - (2*KT(3)^2 - 2*(5*omega_o)^2)*z^-1 ...
            + (KT(3)^2-2*omega_w(3)*KT(3)+(5*omega_o)^2)*z^-2);

G_pr_r_7_z = (2*KT(4)*Kr(4)*omega_w(4)*(1-z^-2))/ ...
           (KT(4)^2 + 2*omega_w(4)*KT(4) + (7*omega_o)^2 - (2*KT(4)^2 - 2*(7*omega_o)^2)*z^-1 ...
            + (KT(4)^2-2*omega_w(4)*KT(4)+(7*omega_o)^2)*z^-2);

Gov_ol_z = series(Go_nc_z,Kp+G_pr_r_z+G_pr_r_5_z+G_pr_r_7_z);
[Gm,Pm,omega_o_g,omega_o_p] = margin(Gov_ol_z);
Pm_o_z = Pm-omega_o_p*Td*180/pi
figure(6)
margin(Gov_ol_z)

%hold on
%Go_nc_z = series(Gi_cl_z*G_diff_z,G234_cl_z);
%Gov_ol_z = series(Go_nc_z,Kp+G_pr_r_z+G_pr_r_5_z+G_pr_r_7_z);
%margin(Gov_ol_z)

% Outer loop with control, closed-loop
G_ov_cl_z = feedback(Gov_ol_z,1,-1);
figure(7)
margin(G_ov_cl_z)

%% Proportional Current Controller Root Locus Discrete Design
% FOR INDUCTOR CURRENT
omega_c_i = 0.175*fsw*2*pi;

% Differentiator
omega_max = 2.1e3;
phi_max = 60; % [degrees]
kf = (1-sind(phi_max))/(1+sind(phi_max));
tau_a = 1/(sqrt(kf)*omega_max);
tau_b = kf*tau_a;
G_diff_s = ((1+s*tau_a)/(1+s*tau_b));
opt = c2dOptions('Method','tustin','PrewarpFrequency',omega_max);
G_diff_z = c2d(G_diff_s,Ts,opt);

Gi_nc_z = series(c2d(Gil,Ts,'zoh'),G_diff_z); % If lead-lag in series
%Gi_nc_z = feedback(feedback(c2d(Gil,Ts,'zoh'),1,-1)*G234_cl_z,G_diff_z,1); % If lead-lag in vc feedback
%Gi_nc_z = c2d(Gil,Ts,'zoh'); % If lead-lag is on PR controller
figure(1)
rlocus(Gi_nc_z)

% Found from root locus. Results in omega_c_i =  and
% damping =
Kc = 0.158;

% Inner loop with control, open-loop
Gi_z = series(Kc,Gi_nc_z); % With P controller
%Gi_z = feedback(feedback(c2d(Gil,Ts,'zoh'),1,-1)*G234_cl_z,Kc*G_diff_z,1); % With lead-lag

figure(2)
[Gm,Pm,omega_i_gm,omega_i_pm] = margin(Gi_z);
PM_i_z = Pm-omega_i_pm*Td*180/pi
margin(Gi_z)

% Inner loop with control, closed-loop
Gi_cl_z = feedback(Gi_z,1,-1);
figure(3)
margin(Gi_cl_z)

%% Proportional Current Controller Root Locus Discrete Design
% FOR CAPACITOR CURRENT
omega_c_i = 0.2*fsw*2*pi;

Gi_nc_z = c2d(Gic,Ts,'zoh');
figure(1)
rlocus(Gi_nc_z)

% Found from root locus. Results in omega_c_i =  and
% damping =
Kc = 0.35;

% Inner loop with control, open-loop
Gi_z = series(Kc,Gi_nc_z);

figure(2)
[Gm,Pm,omega_i_gm,omega_i_pm] = margin(Gi_z);
PM_i_z = Pm-omega_i_pm*Td*180/pi
margin(Gi_z)

% Inner loop with control, closed-loop
Gi_cl_z = feedback(Gi_z,1,-1);
figure(3)
margin(Gi_cl_z)

%% Proportional-Resonant Voltage Controller Root Locus Discrete Design
%Root locus is not viable for the outer loop
% omega_c_o = fo*20*2*pi;
% 
% % Outer loop without control
% %Go_nc_z = series(Gi_cl_z,G234_cl_z); % For inductor current control
% Go_nc_z = series(Gi_cl_z,G2_z); % For capacitor current control
% figure(4)
% rlocus(Go_nc_z)
% 
% % Found from root locus. Results in omega_c_i =  and
% % damping = .
% Kp = 0.06;
% 
% % Outer loop with control, open-loop
% %omega_o = fo*2*pi; % Resonant frequency
% %omega_w = 0.5*2*pi; % Bandpass filter width (lower mostly better)
% %omega_p = fo*2*pi; % Pre-warp frequency
% %Kr = omega_c_o/4; % Resonant (integral) gain determined by PI rule of thumb
% 
% %G_pr_r_z = (4*Kr*Ts*omega_w*(1-z^-2))/(Ts^2*omega_o^2+4*Ts*omega_w+ ...
% %            4+z^-1*(2*Ts^2*omega_o^2-8)+z^-2*(Ts^2*omega_o^2-4*Ts*omega_w+4));
% 
% omega_p = [];
% Kr = [];
% KT = [];
% omega_w = [];
% omega_o = fo*2*pi;
% 
% for h = 1:2:7
%     omega_p(end+1) = fo*2*pi*h;
%     Kr(end+1) = (omega_c_o/(4*h));
%     KT(end+1) = omega_p(end)/(tan(omega_p(end)*Ts/2));
%     omega_w(end+1) = 0.5*2*pi;
% end
% G_pr_r_z = (2*KT(1)*Kr(1)*omega_w(1)*(1-z^-2))/ ...
%            (KT(1)^2 + 2*omega_w(1)*KT(1) + omega_o^2 - (2*KT(1)^2 - 2*omega_o^2)*z^-1 ...
%             + (KT(1)^2-2*omega_w(1)*KT(1)+omega_o^2)*z^-2);
% 
% G_pr_r_3_z = (2*KT(2)*Kr(2)*omega_w(2)*(1-z^-2))/ ...
%            (KT(2)^2 + 2*omega_w(2)*KT(2) + (3*omega_o)^2 - (2*KT(2)^2 - 2*(3*omega_o)^2)*z^-1 ...
%             + (KT(2)^2-2*omega_w(2)*KT(2)+(3*omega_o)^2)*z^-2);
% 
% G_pr_r_5_z = (2*KT(3)*Kr(3)*omega_w(3)*(z^-1-z^-2))/ ...
%            (KT(3)^2 + 2*omega_w(3)*KT(3) + (5*omega_o)^2 - (2*KT(3)^2 - 2*(5*omega_o)^2)*z^-1 ...
%             + (KT(3)^2-2*omega_w(3)*KT(3)+(5*omega_o)^2)*z^-2);
% 
% G_pr_r_7_z = (2*KT(4)*Kr(4)*omega_w(4)*(1-z^-2))/ ...
%            (KT(4)^2 + 2*omega_w(4)*KT(4) + (7*omega_o)^2 - (2*KT(4)^2 - 2*(7*omega_o)^2)*z^-1 ...
%             + (KT(4)^2-2*omega_w(4)*KT(4)+(7*omega_o)^2)*z^-2);
% 
% Gov_ol_z = series(Go_nc_z,Kp+G_pr_r_z+G_pr_r_5_z+G_pr_r_7_z);
% [Gm,Pm,omega_o_g,omega_o_p] = margin(Gov_ol_z);
% Pm_o_z = Pm-omega_o_p*Td*180/pi
% figure(6)
% margin(Gov_ol_z)
% 
% % Outer loop with control, closed-loop
% G_ov_cl_z = feedback(Gov_ol_z,1,-1);
% figure(7)
% margin(G_ov_cl_z)

%% Stability test when using non-linear inductor

x = 1;
for iL = 0:5:125
    Lc_nonlin(x) = 26^2*(4*pi*10^-7*26*2*2.94e-04)/(0.1437*(1+2.27e-05*(0.0125663706*(iL*26)/(0.1437))^1.9167));
    
    % Inner loop
    Gil_num = [Cc*Lg Cc*(Rlg+Rcc+Zo) 1];
    Gil_den = [Cc*Lg*Lc_nonlin(x) ...
           Cc*(Lg*(Rcc+Rlc)+Lc_nonlin(x)*(Rlg+Rcc+Zo)) ...
           Lg+Lc_nonlin(x)+Cc*Rcc*(Rlg+Zo)+Cc*Rlc*(Rlg+Rcc+Zo) ...
           Rlc + Rlg + Zo];
    Gil = tf(Gil_num, Gil_den);

    Gi_nc_z = series(c2d(Gil,Ts,'zoh'),G_diff_z); % If lead-lag in series
    %Gi_nc_z = c2d(Gil,Ts,'zoh'); % If P controller
    Gi_z = series(Kc,Gi_nc_z);

    [Gm_c(x), Pm_c(x), omega_cg_c, omega_cp_c] = margin(Gi_z);
    Pm_c(x) = Pm_c(x) - omega_c_i*Td*180/pi;

    % Outer loop
    Gi_cl_z = feedback(Gi_z,1,-1);
    Go_nc_z = Gi_cl_z*G234_cl_z;
    Gov_ol_z = series(Go_nc_z,(Kp+G_pr_r_z+G_pr_r_3_z+G_pr_r_5_z+G_pr_r_7_z));
    [Gm_v(x), Pm_v(x), omega_cg_v, omega_cp_v] = margin(Gov_ol_z);
    Pm_v(x) = Pm_v(x) - omega_c_o*Td*180/pi;

    %fres_vec(x) = 1/(2*pi)*sqrt((Lg+Lc_nonlin(x))/(Lg*Lc_nonlin(x)*Cc));

    x = x+1;

%     if mod(x,20) == 0
%         figure(12)
%         hold on
%         bode(Gic_z)
%         figure(13)
%         hold on
%         bode(G_ov_control_z)
%         figure(14)
%         hold on
%         bode(Gil)
%     end
end
iL = [0:5:125];
figure(10)
plot(iL,Pm_c,'LineWidth',4)
set(gca, 'FontSize', 18)
grid('on');
title('Current versus phase margin for current controller', 'FontSize', 26);
xlabel('Current [A]', 'FontSize', 22);
ylabel('Phase Margin [\circ]', 'FontSize', 22);

figure(11)
plot(iL,Pm_v,'LineWidth',4)
set(gca, 'FontSize', 18)
grid('on');
title('Current versus phase margin for voltage controller', 'FontSize', 26);
xlabel('Current [A]', 'FontSize', 22);
ylabel('Phase Margin [\circ]', 'FontSize', 22);

%figure(17)
%plot(iL,fres_vec)


% for x = 1:100
%     Lc(x) = (90.375*10^-6)-(90.375*10^-6)*(x-1)/100;
% 
%     Gil_num = [Cc*Lg Cc*(Rlg+Rcc+Zo) 1];
%     Gil_den = [Cc*Lg*Lc(x) ...
%                Cc*(Lg*(Rcc+Rlc)+Lc(x)*(Rlg+Rcc+Zo)) ...
%                Lg+Lc(x)+Cc*Rcc*(Rlg+Zo)+Cc*Rlc*(Rlg+Rcc+Zo) ...
%                Rlc + Rlg + Zo];
%     Gil = tf(Gil_num, Gil_den);
% 
%     Gic_no_control_z = c2d(Gil,Ts,'zoh');
%     Gic_z = series(Kc,Gic_no_control_z);
%     [Gm_c(x), Pm_c(x)] = margin(Gic_z);
%     Pm_c(x) = Pm_c(x) - 0.2*fsw*2*pi*Td*180/pi;
% 
%     %hold on
%     %figure(10)
%     %margin(Gic_z)
% end

%plot(Lc,Pm_c)
%set(gca,'xdir','reverse')


%% Current Controller Continuous Design
% omega_c_i = 0.2*fsw*2*pi;
% 
% % Inner loop without control
% Gic_no_control_s = Gil;
% figure(1)
% [mag, phase] = bode(Gic_no_control_s,omega_c_i);
% bode(Gic_no_control_s)
% 
% % Inner loop with control, open loop
% Kc = 1/mag;
% Gic_s = series(Kc,Gic_no_control_s);
% 
% figure(2)
% %[mag, phase] = bode(Gic_s,omega_c_i)
% %PM_i_s = 180+phase-omega_c_i*Td*180/pi
% margin(Gic_s)
% 
% % Inner loop with control, closed-loop
% Gic_cl_s = feedback(Gic_s,1,-1);
% figure(3)
% bodeplot(Gic_cl_s)
% omega_i_cl_s = bandwidth(Gic_cl_s)
% 
% %% Voltage Controller Discrete Design
% omega_c_o = fo*10*2*pi;
% 
% Go_num = [Kc*Cc*Rcc Kc];
% Go_den = [Cc*Lc Cc*(Kc+Rlc+Rcc) 1];
% Go = tf(Go_num, Go_den);
% 
% % Outer loop without control
% Go_no_control_s = Go;
% 
% figure(4)
% [mag, phase] = bode(Go_no_control_s,omega_c_o)
% bode(Go_no_control_s)
% 
% % Determining Kp
% Kp = 1/mag;
% Gov_p_control_s = Go_no_control_s*Kp;
% figure(5)
% margin(Gov_p_control_s)
% 
% % Determining Kr
% Kr = omega_c_o/10;
% 
% % Outer loop with control, open loop
% % PR controller values
% omega_o = fo*2*pi; % Resonant frequency
% omega_w = 0.1*2*pi; % Bandpass filter width (lower mostly better)
% G_ov_control_s = Go_no_control_s*(Kp+(2*Kr*omega_w*s)/(s^2+2*omega_w*s+omega_o^2))
% 
% [mag, phase] = bode(G_ov_control_s,omega_c_o);
% PM_o_s = 180+phase-omega_c_o*Td*180/pi
% figure(6)
% margin(G_ov_control_s)
% 
% % Outer loop with control, closed-loop
% G_ov_cl_s = feedback(G_ov_control_s,1,-1);
% figure(7)
% bodeplot(G_ov_cl_s)
% omega_o_cl_s = bandwidth(G_ov_cl_s)

% PR + HC test
%G_pr = Kp + (2*Kr*omega_w*s)/(s^2+2*omega_w*s+omega_o^2) + (2*Kr*omega_w*s)/(s^2+2*omega_w*s+(3*omega_o)^2)
%G_ov = Go_no_control*G_pr;
%figure(8)
%margin(G_ov)
%figure(8)
%bodeplot(G_pr)