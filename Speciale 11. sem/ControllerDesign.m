clear, close all, clc;

%% Plant Continuous
% Components
Lc = 90.375*10^-6;
Lc = 5.21618129598826e-06; % Worst-case at high current
Lg = 12*10^-6;
Cc = 30*10^-6;
Rcc = 1e-3;
Rlc = 5e-3;
Rlg = 3e-3;

% Timings
fsw = 24000;
Ts = 1/(2*fsw);
Td = 0.75*1/fsw;
fres = 1/(2*pi)*sqrt((Lg+Lc)/(Lg*Lc*Cc));

% Fundamental
fo = 50; % [Hz]

% Maximum load for current controller (150% of nominal load)
Zo = 0.9136;

% Transfer functions
Gil_num = [Cc*Lg Cc*(Rlg+Rcc+Zo) 1];
Gil_den = [Cc*Lg*Lc ...
           Cc*(Lg*(Rcc+Rlc)+Lc*(Rlg+Rcc+Zo)) ...
           Lg+Lc+Cc*Rcc*(Rlg+Zo)+Cc*Rlc*(Rlg+Rcc+Zo) ...
           Rlc + Rlg + Zo];
Gil = tf(Gil_num, Gil_den);

% For testing of MATLAB accuracy
s = tf('s');
z = tf('z', Ts);
G1 = 1/(s*Lc+Rlc);
G2 = 1/(s*Cc) + Rcc;
G3 = 1/(s*Lg+Rlg+Zo);
G23 = feedback(G2,G3,-1);
G23_cl_z = c2d(feedback(G2,G3,-1),Ts,'zoh');


%% Proportional Current Controller Discrete Design
omega_c_i = 0.125*fsw*2*pi;

% Inner loop without control
Gic_no_control_z = c2d(Gil,Ts,'zoh');
figure(1)
[mag, phase] = bode(Gic_no_control_z,omega_c_i);
margin(Gic_no_control_z)

% Inner loop with control, open loop
Kc = 1/mag;
Gic_z = series(Kc,Gic_no_control_z);

figure(2)
[mag, phase] = bode(Gic_z,omega_c_i);
PM_i_z = 180+phase-omega_c_i*Td*180/pi
margin(Gic_z)

% Inner loop with control, closed-loop
Gic_cl_z = feedback(Gic_z,1);
figure(3)
margin(Gic_cl_z)
omega_i_cl_z = bandwidth(Gic_cl_z)

% x = 1;
% for Kc = 0.1:0.1:5
%     Gic_z = series(Kc,Gic_no_control_z);
%     Gic_cl_z = feedback(Gic_z,1);
%     omega_i_cl_z(x) = bandwidth(Gic_cl_z);
%     x = x + 1;
% end
%Kc = [0.1:0.1:5];
%plot(Kc,omega_i_cl_z)
Kc = 0.2;

%% Proportional-Integrator Current Controller Discrete Design
omega_c_i = 0.15*fsw*2*pi;

% Inner loop without control
Gic_no_control_z = c2d(Gil,Ts,'zoh');
figure(1)
[mag, phase] = bode(Gic_no_control_z,omega_c_i);
margin(Gic_no_control_z)

% Inner loop with P control, open loop
Kc = 1/mag;
Gic_p_control_z = series(Kc,Gic_no_control_z);
%figure(20)
%margin(Gic_p_control_z)

% Inner loop with PI control, open loop
Ki = omega_c_i/4;
G_pi_z = Kc + Ki*Ts/(1-z^-1)
Gic_z = series(G_pi_z,Gic_no_control_z);

[mag, phase] = bode(Gic_z,omega_c_i);
Kc = Kc/mag;
G_pi_z = Kc + Ki*Ts/(1-z^-1)
Gic_z = series(G_pi_z,Gic_no_control_z);

figure(2)
[mag, phase] = bode(Gic_z,omega_c_i);
PM_i_z = 180+phase-omega_c_i*Td*180/pi
margin(Gic_z)

% Inner loop with control, closed-loop
Gic_cl_z = feedback(Gic_z,1);
figure(3)
margin(Gic_cl_z)
omega_i_cl_z = bandwidth(Gic_cl_z)

%% Proportional-Resonant Voltage Controller Discrete Design
omega_c_o = fo*20*2*pi;

% Outer loop without control
Go_no_control_z = series(Gic_cl_z,G23_cl_z);

figure(4)
[mag, phase] = bode(Go_no_control_z,omega_c_o);
margin(Go_no_control_z)

% Determining Kp
Kp = 1/mag;
Gov_p_control_z = Go_no_control_z*Kp;
figure(5)
[Gm_temp, Pm_temp] = margin(Gov_p_control_z);

Kp = Kp*Gm_temp;
Gov_p_control_z = Go_no_control_z*Kp;
margin(Gov_p_control_z)

% Determining Kr
Kr = omega_c_o/10;

% Outer loop with control, open loop
% PR controller values
omega_o = fo*2*pi; % Resonant frequency
omega_w = 0.1*2*pi; % Bandpass filter width (lower mostly better)
G_pr_r_z = (4*Kr*Ts*omega_w*(1-z^-2))/(Ts^2*omega_o^2+4*Ts*omega_w+ ...
            4+z^-1*(2*Ts^2*omega_o^2-8)+z^-2*(Ts^2*omega_o^2-4*Ts*omega_w+4));
G_ov_control_z = series(Go_no_control_z,(Kp+G_pr_r_z));
[mag, phase] = bode(G_ov_control_z,omega_c_o);
PM_o_z = 180+phase-omega_c_o*Td*180/pi;
figure(6)
margin(G_ov_control_z)

% Outer loop with control, closed-loop
G_ov_cl_z = feedback(G_ov_control_z,1);
figure(7)
margin(G_ov_cl_z)
omega_o_cl_z = bandwidth(G_ov_cl_z)

% PR + HC test
%G_pr = Kp + (4*Kr*Ts*omega_w*(1-z^-2))/(Ts^2*omega_o^2+4*Ts*omega_w+4+z^-1*(2*Ts^2*omega_o^2-8)+z^-2*(Ts^2*omega_o^2-4*Ts*omega_w+4));
%figure(8)
%bodeplot(G_pr)

% x = 1;
% for Kp = 0.01:0.01:0.5
%     G_ov_control_z = series(Go_no_control_z,(Kp+(4*Kr*Ts*omega_w*(1-z^-2))/(Ts^2*omega_o^2+4*Ts*omega_w+ ...
%                                   4+z^-1*(2*Ts^2*omega_o^2-8)+z^-2*(Ts^2*omega_o^2-4*Ts*omega_w+4))));
%     G_ov_cl_z = feedback(G_ov_control_z,1);
%     omega_o_cl_z(x) = bandwidth(G_ov_cl_z);
%     x = x + 1;
% end
% Kp = [0.01:0.01:0.5];
% plot(Kp,omega_o_cl_z)
% Kp = 0.03; % (For 20fo) % Kp = 0.08; % (For 10fo)

%% Stability test when using non-linear inductor

x = 1;
for iL = 0:5:500
    Lc_nonlin(x) = 26^2*(4*pi*10^-7*26*2*2.94e-04)/(0.1437*(1+2.27e-05*(0.0125663706*(iL*26)/(0.1437))^1.9167));
    
    % Inner loop
    Gil_num = [Cc*Lg Cc*(Rlg+Rcc+Zo) 1];
    Gil_den = [Cc*Lg*Lc_nonlin(x) ...
               Cc*(Lg*(Rcc+Rlc)+Lc_nonlin(x)*(Rlg+Rcc+Zo)) ...
               Lg+Lc_nonlin(x)+Cc*Rcc*(Rlg+Zo)+Cc*Rlc*(Rlg+Rcc+Zo) ...
               Rlc + Rlg + Zo];
    Gil = tf(Gil_num, Gil_den);

    Gic_no_control_z = c2d(Gil,Ts,'zoh');
    Gic_z = series(Kc,Gic_no_control_z);
    [Gm_c(x), Pm_c(x), omega_cg_c, omega_cp_c] = margin(Gic_z);
    Pm_c(x) = Pm_c(x) - omega_c_i*Td*180/pi;

    % Outer loop
    Gic_cl_z = feedback(Gic_z,1);
    Go_no_control_z = Gic_cl_z*G23_cl_z;
    G_ov_control_z = series(Go_no_control_z,(Kp+(4*Kr*Ts*omega_w*(1-z^-2))/(Ts^2*omega_o^2+4*Ts*omega_w+ ...
                                  4+z^-1*(2*Ts^2*omega_o^2-8)+z^-2*(Ts^2*omega_o^2-4*Ts*omega_w+4))));
    [Gm_v(x), Pm_v(x), omega_cg_v, omega_cp_v] = margin(G_ov_control_z);
    Pm_v(x) = Pm_v(x) - omega_c_o*Td*180/pi;

    %fres_vec(x) = 1/(2*pi)*sqrt((Lg+Lc_nonlin(x))/(Lg*Lc_nonlin(x)*Cc));

    x = x+1;

    if mod(x,20) == 0
        figure(12)
        hold on
        bode(Gic_z)
        figure(13)
        hold on
        bode(G_ov_control_z)
        figure(14)
        hold on
        bode(Gil)
    end
end
iL = [0:5:500];
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
% Gic_cl_s = feedback(Gic_s,1);
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
% G_ov_cl_s = feedback(G_ov_control_s,1);
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