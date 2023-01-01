clear, close all, clc;

%% Characteristics
% Core (KS250-026A-E20-HF)
n_cores = 2;
N = 26;
Nw = N;
Ae = 2.940*10^-4; % [m^2]
le = 14.370e-2; % [m]
mu_r = 26;
mu_0 = 4*pi*10^-7;
mu = mu_r * mu_0;

% Inverter characteristics
V_ph = 230;
V_ll = 230*sqrt(3); % For star connection
P_o = 50000;
I_ph = P_o/(V_ll*sqrt(3));
IL_avg = I_ph;

% Nominal value
L_nom = n_cores*N^2*mu*Ae/le;


%% BH-curve according to figure in datasheet
% Magnetizing force (H, Oersted)
graph_x = [1, 2.0040346541427647, 3.0045009784357193, 4.002624920399505, 5.001172246143714, 6.0008395886725205, 7.008543091687776, ...
           7.967443701819634, 9.027026129421197, 10.02252249260898, 19.950378888390272, 30.011232404429457, 39.84655831425289, ...
           49.78720352485547, 59.940932890331865, 70.00663905611724, 80.39465238093258, 90.47357242349284, 100.1125491265153, ...
           199.95312114496275, 300.7882518043099, 399.36302695765556, 502.37253882137367, 600.759348121316, 699.2793577521177, ...
           803.042706257887, 900.6740704326758, 1003.3802754129212];

% Relative permeability (percent)
graph_y = [100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 99.47604790419162, 98.65269461077844, 97.60479041916167, 96.33233532934132, ...
          94.68562874251496, 92.96407185628743, 91.01796407185628, 88.84730538922156, 86.75149700598803, 63.398203592814355, 44.08682634730539, ...
          31.437125748503007, 22.979041916167574, 17.365269461077858, 13.622754491017986, 10.778443113772425, 8.832335329341348, 7.3353293413173475];

% Magnetizing field strength [A/m]
H_Am_graph = graph_x./0.0125663706;

% Relative permeabilty (absolute value)
mu_graph = mu_r.*(graph_y./100); % Unused due to KDM equation later


%% BH-curve according to MATLAB Simulink calculation
% https://se.mathworks.com/help/sps/ug/nonlinear-inductor-characteristics.html;jsessionid=154128d76f89d6095368281edb2b
B_sat_begin = (20/0.0125663706)*mu_0*mu_r; % See datasheet figure
B_sat = 1.2; % See: https://www.kdm-mag.com/products/super-sendust-cores-390.html

H_sat_begin = (B_sat_begin)/(mu_0*mu_r);
a = atanh(B_sat_begin/B_sat)/H_sat_begin;

H_linear = [-50000 50000];
B_linear = mu_0*mu_r*H_linear;

H_nonlinear = -110*H_sat_begin:H_sat_begin/4:110*H_sat_begin;
B_nonlinear = B_sat*tanh(a*H_nonlinear);

figure(1)
plot(H_linear,B_linear,H_nonlinear,B_nonlinear)
grid('on');
title('BH-curve of powdered iron core KS250-026A-E20-HF');
xlabel('Magnetic field strength, H (A/m)');
ylabel('Magnetic flux density, B (T)');
legend('B=\mu_0 \mu_r H', 'B-H curve', 'Location', 'NorthWest')

%% I-Wb curve according to MATLAB Simulink calculation
L_linear = n_cores*mu_0*mu_r*Ae*N^2/le;
I_linear = [-250 250];
phi_linear = I_linear.*L_linear/N;

I_nonlinear = le.*H_nonlinear./N;
phi_nonlinear = n_cores.*B_nonlinear.*Ae;

figure(2)
plot(I_linear, phi_linear, I_nonlinear, phi_nonlinear, 'LineWidth', 4)
set(gca, 'FontSize', 18)
grid('on');
ax = gca;
ax.GridAlpha = 0.8;
title('Magnetic flux versus current for converter-side inductor','FontSize', 26);
xlabel('Current, I (A)','FontSize',22);
ylabel('Magnetic flux, \phi (Wb)','FontSize',22);
legend('Linear', 'Nonlinear', 'Location', 'NorthWest');

%% Non-linear inductance curve
% Calculation based on equation from KDM:
% (https://www.kdm-mag.com/products/details-characteristics-curves-1374.html)
percent_permeability = 100./(1+2.27e-05.*(H_Am_graph*0.0125663706).^1.9167);
L_KDM = n_cores*N^2*(mu.*percent_permeability/100*Ae)/le;
I_graph = le.*(graph_x./0.0125663706)./N;

figure(3)
%semilogx(I_graph,L_KDM*1000000, 'LineWidth', 1)
%hold on

syms x
l_c = 26^2*(4*pi*10^-7*26*2*2.94e-04)/(0.1437*(1+2.27e-05*(0.0125663706*(x*26)/(0.1437))^1.9167));
l_c = 3.9813/((2.2736648267223381421480600353473*x)^(1.9167) + 44052.863436123348947148770093918);
fplot(l_c*1000000, [0 225], 'LineWidth', 4)

% Linearization
%linear_l_c = 90.375 - 90.375*x*1/218;
%hold on
%fplot(linear_l_c, [0 225], 'LineWidth', 4)

set(gca, 'FontSize', 18)
xlim([0 225])
ylim([0 100])
grid('on');
title('Current versus inductance for converter-side inductor', 'FontSize', 26);
xlabel('Current [A]', 'FontSize', 22);
ylabel('Inductance [\muH]', 'FontSize', 22);

% Command graveyard
%L_graph = n_cores*N^2*(mu.*graph_y./100*Ae)/le;
%phi_graph = B_T_graph.*Ae;
%phi_graph = I_graph.*L_graph./N;
%L_nonlinear = n_cores*N^2*(phi_nonlinear)./I_nonlinear

% figure(2)
% %plot(I_graph,phi_graph)
% plot(I_graph,phi_graph,I_nonlinear,phi_nonlinear)
% grid( 'on' );
% title( 'Magnetic flux, \phi, versus current, I' );
% xlabel( 'Current, I (A)' );
% ylabel( 'Magnetic flux, \phi (Wb)' );
% legend('Graph','Nonlinear')