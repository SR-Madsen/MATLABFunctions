clear, close all, clc;

%% Plant Continuous
% Components
Lc = 90.375*10^-6;
%Lc = 26.989*10^-6; % Worst-case at maximum load (181 A peak)
Lg = 2*10^-6;
Cc = 30*10^-6;
Rlc = 5.6e-3;
Rlg = 5.6e-3;
Rcc = 9e-3;

% Timings
fsw = 24000;
fs = 4*fsw;
Ts = 1/fs;
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

% Maximum load for current controller (300% of nominal load for transients)
k_overcurr = 3;
%Zo = (Vo*sqrt(3))/(Io_max_3p*k_overcurr); % For three phases
Zo = (Vo*sqrt(2))/(Io_max_1p*k_overcurr); % For one phase
Zo_max = 1e9;

% Transfer functions
Gil_num = [Cc*Lg Cc*(Rlg+Rcc+Zo) 1];
Gil_den = [Cc*Lg*Lc ...
           Cc*(Lg*(Rcc+Rlc)+Lc*(Rlg+Rcc+Zo)) ...
           Lg+Lc+Cc*Rcc*(Rlg+Zo)+Cc*Rlc*(Rlg+Rcc+Zo) ...
           Rlc + Rlg + Zo];
Gil = tf(Gil_num, Gil_den);

Gil_num_max = [Cc*Lg Cc*(Rlg+Rcc+Zo_max) 1];
Gil_den_max = [Cc*Lg*Lc ...
           Cc*(Lg*(Rcc+Rlc)+Lc*(Rlg+Rcc+Zo_max)) ...
           Lg+Lc+Cc*Rcc*(Rlg+Zo_max)+Cc*Rlc*(Rlg+Rcc+Zo_max) ...
           Rlc + Rlg + Zo_max];
Gil_max = tf(Gil_num_max, Gil_den_max);

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
%Gil_t = feedback(G1,G234_cl_s,-1);
Gvc = feedback(G1*G234_cl_s,1,-1);
%Gic = series(Gvc,1/G2); % Inflates the order, do not use.


%% Proportional Current Controller Discrete Design
% FOR INDUCTOR CURRENT
omega_c_i = 3.35e4; %0.2*fsw*2*pi;

% Differentiator
omega_max = 3.35e4; %3.6e4;
phi_max = 40; % [degrees]
kf = (1-sind(phi_max))/(1+sind(phi_max));
tau_a = 1/(sqrt(kf)*omega_max);
tau_b = kf*tau_a;
G_diff_s = ((1+s*tau_a)/(1+s*tau_b));
opt = c2dOptions('Method','tustin','PrewarpFrequency',omega_max);
G_diff_z = c2d(G_diff_s,Ts,opt);

% Harmonic compensators
omega_p5 = fo*2*pi*5;
omega_w5 = 0.1*2*pi;
Kr5 = omega_c_i/(4*5*15);
omega_p7 = fo*2*pi*7;
omega_w7 = 0.1*2*pi;
Kr7 = omega_c_i/(4*7*10);

% G_pr_r_5_z = (2*exp(Ts*omega_w5)^2*(omega_w5^2-omega_p5^2)^(1/2)*Kr5*Ts*omega_w5 - ...
%     z^-1*2*Kr5*Ts*omega_w5*exp(Ts*omega_w5)*(omega_w5*sinh(Ts*(omega_w5^2-omega_p5^2)^(1/2))+...
%     cosh(Ts*(omega_w5^2-omega_p5^2)^(1/2))*(omega_w5^2-omega_p5^2)^(1/2)))/...
%     (exp(2*Ts*omega_w5)*(omega_w5^2-omega_p5^2)^(1/2) - ...
%     z^-1*((omega_w5^2-omega_p5^2)^(1/2)*2*exp(Ts*omega_w5)*...
%     cosh(Ts*(omega_w5^2-omega_p5^2)^(1/2)))+z^-2*(omega_w5^2-omega_p5^2)^(1/2));
% G_pr_r_7_z = (2*exp(Ts*omega_w7)^2*(omega_w7^2-omega_p7^2)^(1/2)*Kr7*Ts*omega_w7 - ...
%     z^-1*2*Kr7*Ts*omega_w7*exp(Ts*omega_w7)*(omega_w7*sinh(Ts*(omega_w7^2-omega_p7^2)^(1/2))+...
%     cosh(Ts*(omega_w7^2-omega_p7^2)^(1/2))*(omega_w7^2-omega_p7^2)^(1/2)))/...
%     (exp(2*Ts*omega_w7)*(omega_w7^2-omega_p7^2)^(1/2) - ...
%     z^-1*((omega_w7^2-omega_p7^2)^(1/2)*2*exp(Ts*omega_w7)*...
%     cosh(Ts*(omega_w7^2-omega_p7^2)^(1/2)))+z^-2*(omega_w7^2-omega_p7^2)^(1/2));
G_pr_r_5_z = -(2*Kr5*Ts*omega_w5*z*exp(Ts*omega_w5)*(omega_w5*sinh(Ts*(omega_w5^2 - omega_p5^2)^(1/2)) ...
             + cosh(Ts*(omega_w5^2 - omega_p5^2)^(1/2))*(omega_w5^2 - omega_p5^2)^(1/2) ... 
             - z*exp(Ts*omega_w5)*(omega_w5^2 - omega_p5^2)^(1/2)))/((omega_w5^2 - omega_p5^2)^(1/2) ...
             *(exp(2*Ts*omega_w5)*z^2 - 2*exp(Ts*omega_w5)*cosh(Ts*(omega_w5^2 - omega_p5^2)^(1/2))*z + 1));
G_pr_r_7_z = -(2*Kr7*Ts*omega_w7*z*exp(Ts*omega_w7)*(omega_w7*sinh(Ts*(omega_w7^2 - omega_p7^2)^(1/2)) ...
             + cosh(Ts*(omega_w7^2 - omega_p7^2)^(1/2))*(omega_w7^2 - omega_p7^2)^(1/2) ... 
             - z*exp(Ts*omega_w7)*(omega_w7^2 - omega_p7^2)^(1/2)))/((omega_w7^2 - omega_p7^2)^(1/2) ...
             *(exp(2*Ts*omega_w7)*z^2 - 2*exp(Ts*omega_w7)*cosh(Ts*(omega_w7^2 - omega_p7^2)^(1/2))*z + 1));

% Inner loop without control
Gi_nc_z = series(c2d(Gil,Ts,'zoh'),G_diff_z+G_pr_r_5_z+G_pr_r_7_z); % If lead-lag in series
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
% % FOR CAPACITOR CURRENT
% omega_c_i = 0.2*fsw*2*pi;
% 
% % Differentiator
% omega_max = omega_c_i;
% phi_max = 30; % [degrees]
% kf = (1-sind(phi_max))/(1+sind(phi_max));
% tau_a = 1/(sqrt(kf)*omega_max);
% tau_b = kf*tau_a;
% G_diff_s = ((1+s*tau_a)/(1+s*tau_b));
% opt = c2dOptions('Method','tustin','PrewarpFrequency',omega_max);
% G_diff_z = c2d(G_diff_s,Ts,opt);
% 
% % Inner loop without control
% Gi_nc_z = series(c2d(Gic,Ts,'zoh'),G_diff_z); % If lead-lag in series
% %Gi_nc_z = feedback(feedback(c2d(Gil,Ts,'zoh'),1,-1)*G234_cl_z,G_diff_z,1); % If lead-lag in vc feedback
% %Gi_nc_z = c2d(Gil,Ts,'zoh'); % If lead-lag is on PR controller
% figure(1)
% [mag, phase] = bode(Gi_nc_z,omega_c_i);
% margin(Gi_nc_z)
% 
% % Inner loop with control, open loop
% Kc = 1/mag;
% Gi_z = series(Kc,Gi_nc_z);
% 
% figure(2)
% [Gm,Pm,omega_i_gm,omega_i_pm] = margin(Gi_z);
% PM_i_z = Pm-omega_i_pm*Td*180/pi
% margin(Gi_z)
% 
% % Inner loop with control, closed-loop
% Gi_cl_z = feedback(Gi_z,1,-1);
% figure(3)
% margin(Gi_cl_z)
% omega_i_cl_z = bandwidth(Gi_cl_z)

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
omega_c_o = fo*20*2*pi;

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
Kp = 1/mag/(10^(1.14/20));
Gov_p_control_z = Go_nc_z*Kp;
figure(5)
[Gm, Pm] = margin(Gov_p_control_z);

%Kp = Kp*Gm_temp;
%Gov_p_control_z = Go_no_control_z*Kp;
margin(Gov_p_control_z)

% Outer loop with control, open-loop
omega_p = fo*2*pi;
Kr = omega_c_o/2;
omega_o = fo*2*pi;
omega_w = 0.1*2*pi;

%KT = omega_p/(tan(omega_p*Ts/2));
% G_pr_r_z = (2*KT(1)*Kr(1)*omega_w(1)*(1-z^-2))/ ...
%            (KT(1)^2 + 2*omega_w(1)*KT(1) + omega_o^2 - (2*KT(1)^2 - 2*omega_o^2)*z^-1 ...
%             + (KT(1)^2-2*omega_w(1)*KT(1)+omega_o^2)*z^-2);
% 
% G_pr_r_3_z = (2*KT(2)*Kr(2)*omega_w(2)*(1-z^-2))/ ...
%            (KT(2)^2 + 2*omega_w(2)*KT(2) + (3*omega_o)^2 - (2*KT(2)^2 - 2*(3*omega_o)^2)*z^-1 ...
%             + (KT(2)^2-2*omega_w(2)*KT(2)+(3*omega_o)^2)*z^-2);
% 
% G_pr_r_5_z = (2*KT(3)*Kr(3)*omega_w(3)*(1-z^-2))/ ...
%            (KT(3)^2 + 2*omega_w(3)*KT(3) + (5*omega_o)^2 - (2*KT(3)^2 - 2*(5*omega_o)^2)*z^-1 ...
%             + (KT(3)^2-2*omega_w(3)*KT(3)+(5*omega_o)^2)*z^-2);
% 
% G_pr_r_7_z = (2*KT(4)*Kr(4)*omega_w(4)*(1-z^-2))/ ...
%            (KT(4)^2 + 2*omega_w(4)*KT(4) + (7*omega_o)^2 - (2*KT(4)^2 - 2*(7*omega_o)^2)*z^-1 ...
%             + (KT(4)^2-2*omega_w(4)*KT(4)+(7*omega_o)^2)*z^-2);
%
% G_pr_r_z = -(2*Kr(1)*omega_w(1)*z*exp(Ts*omega_w(1))* ...
%            (omega_w(1)*sinh(Ts*(omega_w(1)^2 - omega_p(1)^2)^(1/2)) + ...
%            cosh(Ts*(omega_w(1)^2 - omega_p(1)^2)^(1/2))* ...
%            (omega_w(1)^2 - omega_p(1)^2)^(1/2) - z*exp(Ts*omega_w(1))* ...
%            (omega_w(1)^2 - omega_p(1)^2)^(1/2)))/ ...
%            ((omega_w(1)^2 - omega_p(1)^2)^(1/2)* ...
%            (exp(2*Ts*omega_w(1))*z^2 - 2*exp(Ts*omega_w(1))* ...
%            cosh(Ts*(omega_w(1)^2 - omega_p(1)^2)^(1/2))*z + 1));
%
%G_pr_r_z = Ts*(1-z^-1*cos(omega_p(1)*Ts))/(1-2*z^-1*cos(omega_p(1)*Ts)+z^-2);
%
%G_pr_s = (2*Kr(1)*omega_w(1)*s)/(s^2+2*omega_w(1)*s+omega_p(1)^2);
%G_pr_z = c2d(G_pr_s,Ts,'impulse')
%
% G_pr_r_z = (2*exp(Ts*omega_w)^2*(omega_w^2-omega_p^2)^(1/2)*Kr*Ts*omega_w - ...
%     z^-1*2*Kr*Ts*omega_w*exp(Ts*omega_w)*(omega_w*sinh(Ts*(omega_w^2-omega_p^2)^(1/2))+...
%     cosh(Ts*(omega_w^2-omega_p^2)^(1/2))*(omega_w^2-omega_p^2)^(1/2)))/...
%     (exp(2*Ts*omega_w)*(omega_w^2-omega_p^2)^(1/2) - ...
%     z^-1*((omega_w^2-omega_p^2)^(1/2)*2*exp(Ts*omega_w)*...
%     cosh(Ts*(omega_w^2-omega_p^2)^(1/2)))+z^-2*(omega_w^2-omega_p^2)^(1/2));

G_pr_r_z = -(2*Kr*Ts*omega_w*z*exp(Ts*omega_w)*(omega_w*sinh(Ts*(omega_w^2 - omega_p^2)^(1/2)) ...
        + cosh(Ts*(omega_w^2 - omega_p^2)^(1/2))*(omega_w^2 - omega_p^2)^(1/2) ... 
        - z*exp(Ts*omega_w)*(omega_w^2 - omega_p^2)^(1/2)))/((omega_w^2 - omega_p^2)^(1/2) ...
        *(exp(2*Ts*omega_w)*z^2 - 2*exp(Ts*omega_w)*cosh(Ts*(omega_w^2 - omega_p^2)^(1/2))*z + 1));

Gov_ol_z = series(Go_nc_z,Kp+G_pr_r_z);
[Gm,Pm,omega_o_g,omega_o_p] = margin(Gov_ol_z);
Pm_o_z = Pm-omega_o_p*Td*180/pi
figure(6)
margin(Gov_ol_z)

% Outer loop with control, closed-loop
G_ov_cl_z = feedback(Gov_ol_z,1,-1);
figure(7)
margin(G_ov_cl_z)

% figure(15)
% opt = bodeoptions;
% opt.Grid = 'on';
% opt.Title.String = 'Bode plot of discretized non-ideal Resonant Controller';
% opt.FreqUnits = 'Hz';
% opt.Title.FontSize = 26;
% opt.XLabel.FontSize = 22;
% opt.YLabel.FontSize = 22;
% 
% bodeplot(G_pr_r_z, opt)
% Fh = gcf;                                                   % Handle To Current Figure
% Kids = Fh.Children;                                         % Children
% AxAll = findobj(Kids,'Type','Axes');                        % Handles To Axes
% Ax1 = AxAll(1);                                             % First Set Of Axes
% LinesAx1 = findobj(Ax1,'Type','Line');                      % Handle To Lines
% LinesAx1(2).LineWidth = 4;                                  % Set 4LineWidth’
% Ax2 = AxAll(2);                                             % Second Set Of Axes
% LinesAx2 = findobj(Ax2,'Type','Line');                      % Handle To Lines
% LinesAx2(2).LineWidth = 4;

%% Proportional Current Controller Root Locus Discrete Design
% FOR INDUCTOR CURRENT
omega_c_i = 0.2*fsw*2*pi;
%omega_c_i = 3.35e4;

% Differentiator
%omega_max = omega_c_i;
%phi_max = 40; % [degrees]
%kf = (1-sind(phi_max))/(1+sind(phi_max));
%tau_a = 1/(sqrt(kf)*omega_max);
%tau_b = kf*tau_a;
%G_diff_s = ((1+s*tau_a)/(1+s*tau_b));
%opt = c2dOptions('Method','tustin','PrewarpFrequency',omega_max);
%G_diff_z = c2d(G_diff_s,Ts,opt);

% Harmonic compensators
omega_p5 = fo*2*pi*5;
omega_w5 = 0.1*2*pi;
Kr5 = omega_c_i/(4*5*15);
omega_p7 = fo*2*pi*7;
omega_w7 = 0.1*2*pi;
Kr7 = omega_c_i/(4*7*10);

% G_pr_r_5_z = (2*exp(Ts*omega_w5)^2*(omega_w5^2-omega_p5^2)^(1/2)*Kr5*Ts*omega_w5 - ...
%     z^-1*2*Kr5*Ts*omega_w5*exp(Ts*omega_w5)*(omega_w5*sinh(Ts*(omega_w5^2-omega_p5^2)^(1/2))+...
%     cosh(Ts*(omega_w5^2-omega_p5^2)^(1/2))*(omega_w5^2-omega_p5^2)^(1/2)))/...
%     (exp(2*Ts*omega_w5)*(omega_w5^2-omega_p5^2)^(1/2) - ...
%     z^-1*((omega_w5^2-omega_p5^2)^(1/2)*2*exp(Ts*omega_w5)*...
%     cosh(Ts*(omega_w5^2-omega_p5^2)^(1/2)))+z^-2*(omega_w5^2-omega_p5^2)^(1/2));
% G_pr_r_7_z = (2*exp(Ts*omega_w7)^2*(omega_w7^2-omega_p7^2)^(1/2)*Kr7*Ts*omega_w7 - ...
%     z^-1*2*Kr7*Ts*omega_w7*exp(Ts*omega_w7)*(omega_w7*sinh(Ts*(omega_w7^2-omega_p7^2)^(1/2))+...
%     cosh(Ts*(omega_w7^2-omega_p7^2)^(1/2))*(omega_w7^2-omega_p7^2)^(1/2)))/...
%     (exp(2*Ts*omega_w7)*(omega_w7^2-omega_p7^2)^(1/2) - ...
%     z^-1*((omega_w7^2-omega_p7^2)^(1/2)*2*exp(Ts*omega_w7)*...
%     cosh(Ts*(omega_w7^2-omega_p7^2)^(1/2)))+z^-2*(omega_w7^2-omega_p7^2)^(1/2));
G_pr_r_5_z = -(2*Kr5*Ts*omega_w5*z*exp(Ts*omega_w5)*(omega_w5*sinh(Ts*(omega_w5^2 - omega_p5^2)^(1/2)) ...
             + cosh(Ts*(omega_w5^2 - omega_p5^2)^(1/2))*(omega_w5^2 - omega_p5^2)^(1/2) ... 
             - z*exp(Ts*omega_w5)*(omega_w5^2 - omega_p5^2)^(1/2)))/((omega_w5^2 - omega_p5^2)^(1/2) ...
             *(exp(2*Ts*omega_w5)*z^2 - 2*exp(Ts*omega_w5)*cosh(Ts*(omega_w5^2 - omega_p5^2)^(1/2))*z + 1));
G_pr_r_7_z = -(2*Kr7*Ts*omega_w7*z*exp(Ts*omega_w7)*(omega_w7*sinh(Ts*(omega_w7^2 - omega_p7^2)^(1/2)) ...
             + cosh(Ts*(omega_w7^2 - omega_p7^2)^(1/2))*(omega_w7^2 - omega_p7^2)^(1/2) ... 
             - z*exp(Ts*omega_w7)*(omega_w7^2 - omega_p7^2)^(1/2)))/((omega_w7^2 - omega_p7^2)^(1/2) ...
             *(exp(2*Ts*omega_w7)*z^2 - 2*exp(Ts*omega_w7)*cosh(Ts*(omega_w7^2 - omega_p7^2)^(1/2))*z + 1));

% Inner loop without control
Gi_nc_z = c2d(Gil,Ts,'zoh');
%Gi_nc_z = series(c2d(Gil,Ts,'zoh'),G_diff_z); % If lead-lag in series
%Gi_nc_z = feedback(feedback(c2d(Gil,Ts,'zoh'),1,-1)*G234_cl_z,G_diff_z,1); % If lead-lag in vc feedback
%Gi_nc_z = c2d(Gil,Ts,'zoh'); % If lead-lag is on PR controller
figure(1)
rlocus(Gi_nc_z)

% Found from root locus. Results in omega_c_i =  and
% damping =
Kc = 2.5;

% Inner loop with control, open-loop
Gi_z = series(c2d(Gil,Ts,'zoh'),Kc+G_pr_r_5_z+G_pr_r_7_z); % With P controller
%Gi_z = feedback(feedback(c2d(Gil,Ts,'zoh'),1,-1)*G234_cl_z,Kc*G_diff_z,1); % With lead-lag

figure(2)
[Gm,Pm,omega_i_gm,omega_i_pm] = margin(Gi_z);
PM_i_z = Pm-omega_i_pm*Td*180/pi
margin(Gi_z)

% Inner loop with control, closed-loop
Gi_cl_z = feedback(Gi_z,1,-1);
figure(3)
margin(Gi_cl_z)

% Inner loop with control, closed-loop, high output impedance
% Used because the outer loop is least stable with high impedance.
%Gi_max_z = series(c2d(Gil_max,Ts,'zoh'),Kc+G_pr_r_5_z+G_pr_r_7_z);
%Gi_cl_z = feedback(Gi_max_z,1,-1);
%hold on
%margin(Gi_cl_z)

%% Proportional Current Controller Root Locus Discrete Design
% % FOR CAPACITOR CURRENT
% omega_c_i = 0.2*fsw*2*pi;
% 
% Gi_nc_z = c2d(Gic,Ts,'zoh');
% figure(1)
% rlocus(Gi_nc_z)
% 
% % Found from root locus. Results in omega_c_i =  and
% % damping =
% Kc = 0.35;
% 
% % Inner loop with control, open-loop
% Gi_z = series(Kc,Gi_nc_z);
% 
% figure(2)
% [Gm,Pm,omega_i_gm,omega_i_pm] = margin(Gi_z);
% PM_i_z = Pm-omega_i_pm*Td*180/pi
% margin(Gi_z)
% 
% % Inner loop with control, closed-loop
% Gi_cl_z = feedback(Gi_z,1,-1);
% figure(3)
% margin(Gi_cl_z)

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
for iL = 0:5:225
    Lc_nonlin(x) = 26^2*(4*pi*10^-7*26*2*2.94e-04)/(0.1437*(1+2.27e-05*(0.0125663706*(iL*26)/(0.1437))^1.9167));
    
    % Inner loop
    Gil_num = [Cc*Lg Cc*(Rlg+Rcc+Zo) 1];
    Gil_den = [Cc*Lg*Lc_nonlin(x) ...
           Cc*(Lg*(Rcc+Rlc)+Lc_nonlin(x)*(Rlg+Rcc+Zo)) ...
           Lg+Lc_nonlin(x)+Cc*Rcc*(Rlg+Zo)+Cc*Rlc*(Rlg+Rcc+Zo) ...
           Rlc + Rlg + Zo];
    Gil = tf(Gil_num, Gil_den);

    if abs(iL)<=218
        k_var = abs(iL)*1/218;
    else
        k_var = 0;
    end

    %Gi_nc_z = series(c2d(Gil,Ts,'zoh'),G_diff_z); % If lead-lag in series
    Gi_nc_z = c2d(Gil,Ts,'zoh'); % If P controller
    Gi_z = series(k_var*(Kc+G_pr_r_5_z+G_pr_r_7_z),Gi_nc_z);

    [Gm_c(x), Pm_c(x), omega_cg_c, omega_cp_c] = margin(Gi_z);
    Pm_c(x) = Pm_c(x) - omega_cp_c*Td*180/pi;

    % Outer loop
    Gi_cl_z = feedback(Gi_z,1,-1);
    Go_nc_z = Gi_cl_z*G234_cl_z;
    Gov_ol_z = series(Go_nc_z,(Kp+G_pr_r_z));
    [Gm_v(x), Pm_v(x), omega_cg_v, omega_cp_v] = margin(Gov_ol_z);
    Pm_v(x) = Pm_v(x) - omega_cp_v*Td*180/pi;

    %fres_vec(x) = 1/(2*pi)*sqrt((Lg+Lc_nonlin(x))/(Lg*Lc_nonlin(x)*Cc));

    if mod((x-1),10) == 0
        figure(12)
        hold on
        bode(Gi_z)
        %figure(13)
        %hold on
        %bode(G_ov_control_z)

        opt = bodeoptions;
        opt.Grid = 'on';
        opt.Title.String = 'Plant transfer function at various currents';
        opt.FreqUnits = 'Hz';
        opt.Title.FontSize = 26;
        opt.XLabel.FontSize = 22;
        opt.YLabel.FontSize = 22;
        figure(14)
        hold on
        bodeplot(c2d(Gil,Ts,'zoh'),opt)
        if iL == 200
            legend({'0 A', '50 A', '100 A', '150 A', '200 A'},'location','northeast','FontSize',18)
        end
        Fh = gcf;                                                   % Handle To Current Figure
        Kids = Fh.Children;                                         % Children
        AxAll = findobj(Kids,'Type','Axes');                        % Handles To Axes
        Ax1 = AxAll(1);                                             % First Set Of Axes
        LinesAx1 = findobj(Ax1,'Type','Line');                      % Handle To Lines
        LinesAx1(2).LineWidth = 3;                                  % Set 4LineWidth3
        Ax2 = AxAll(2);                                             % Second Set Of Axes
        LinesAx2 = findobj(Ax2,'Type','Line');                      % Handle To Lines
        LinesAx2(2).LineWidth = 3;
    end

    x = x+1;
end
iL = [0:5:225];
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