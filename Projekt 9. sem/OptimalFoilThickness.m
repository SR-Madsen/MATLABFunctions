%% Test: Finding best foil thickness
clear, close all, clc;
t_foil_p = 0.15*10^-3;
w_foil_p = 18*10^-3;
t_foil_s = 0.3*10^-3;
w_foil_s = 18*10^-3;

% Stackup
syms S P
stackup = [P, t_foil_p, 1, w_foil_p;
           S, t_foil_s, 0.5, w_foil_s;
           P, t_foil_p, 1, w_foil_p;
           P, t_foil_p, 1, w_foil_p;
           S, t_foil_s, 0.5, w_foil_s;
           P, t_foil_p, 1, w_foil_p;
           P, t_foil_p, 1, w_foil_p;
           S, t_foil_s, 0.5, w_foil_s;
           P, t_foil_p, 1, w_foil_p;
           P, t_foil_p, 1, w_foil_p;
           S, t_foil_s, 0.5, w_foil_s;
           P, t_foil_p, 1, w_foil_p;
           P, t_foil_p, 1, w_foil_p;
           S, t_foil_s, 0.5, w_foil_s;
           P, t_foil_p, 1, w_foil_p;];
       
% Find isolation thickness between each layer
t_kapton = 0.055*10^-3;
for i = 1:1:length(stackup)
    if (stackup(i) == P && stackup(i+1) == S) || (stackup(i) == S && stackup(i+1) == P)
        t_iso(i) = 3*t_kapton;
    else
        t_iso(i) = t_kapton;
    end
end

% Converter characteristics
fs = 200000; % [Hz]
Vin = 130; % [V]
Vout = 60; % [V]
n_trafo = 0.5;
D = (Vout/Vin)/(2*n_trafo);

% Physical properties
T = 70; % [C]
mu_r_cu = 0.999994;
rho_cu = 1.68*10^-8*(1+0.003862*(T-20)); % [Ohm/m]
mu_0 = 1.25663706*10^-6;


% Best thickness for foil
%t_foil_test_p = 10^-3*[0.15 0.2 0.3 0.4];
t_foil_test_p = 0.15*10^-3:0.01*10^-3:0.4*10^-3;

% Bobbin for EPCOS TDK E42/21/15
w_bobbin_wind = 0.0174; % [m]
h_bobbin_wind = 0.0151; % [m]

for j = 1:1:length(t_foil_test_p)
    ln(j,1) = 2*w_bobbin_wind + 2*h_bobbin_wind;
end

for j = 1:1:length(t_foil_test_p)
    for i = 2:1:length(stackup)
        ln(j,i) = ln(j,i-1) + ((t_iso(i-1) + t_foil_test_p(j)) * 8);
    end
end

% Total length
for j = 1:1:length(t_foil_test_p)
    k_p = 1;
    k_s = 1;
    for i = 1:1:length(stackup)
        if stackup(i) == P
            ln_p(j,k_p) = ln(j,i);
            k_p = k_p + 1;
        elseif stackup(i) == S
            ln_s(j,k_s) = ln(j,i);
            k_s = k_s + 1;
        end
    end
end

% Penetration depth
delta_w = sqrt(rho_cu/(pi*fs*mu_0*mu_r_cu)); % [m]

phi_j = t_foil_test_p/delta_w % Calculate phi from copper thickness


% DC resistances
for j = 1:1:length(t_foil_test_p)
    for i = 1:1:k_p-1
        R_DC_jp(j,i) = rho_cu * ln_p(j,i) / (w_foil_p*t_foil_test_p(j));
    end
end
for j = 1:1:length(t_foil_test_p)
    for i = 1:1:k_s-1
        R_DC_js(j,i) = rho_cu * ln_s(j,i) / (w_foil_p*t_foil_test_p(j));
    end
end
for j = 1:1:length(t_foil_test_p)
    R_DC_p(j) = sum(R_DC_jp(j,:));
    R_DC_s(j) = sum(R_DC_js(j,:));
end
R_DC_p
R_DC_s

% AC-to-DC resistance factor
for j = 1:1:length(phi_j)
    for i = 1:1:length(stackup)
        Fr_j(j,i) = phi_j(j)/2 * (( sinh(phi_j(j)) + sin(phi_j(j)) ) / ( cosh(phi_j(j)) - cos(phi_j(j)) )) ...
                + phi_j(j)/2 * (2 * w_foil_p - 1)^2 ...
                * (( sinh(phi_j(j)) - sin(phi_j(j)) ) / ( cosh(phi_j(j)) + cos(phi_j(j)) ))
    end
end

% Total AC resistance
for j = 1:1:length(t_foil_test_p)
    k_p = 1;
    k_s = 1;
    for i = 1:1:length(stackup)
        if stackup(i) == P
            R_AC_jp(j,k_p) = R_DC_jp(j,k_p) * Fr_j(j,i);
            k_p = k_p + 1;
        elseif stackup(i) == S
            R_AC_js(j,k_s) = R_DC_js(j,k_s) * Fr_j(j,i);
            k_s = k_s + 1;
        end
    end
end
for j = 1:1:length(t_foil_test_p)
    R_AC_p(j) = sum(R_AC_jp(j,:));
    R_AC_s(j) = sum(R_AC_js(j,:));
end
R_AC_p
R_AC_s

R_tot_p = R_AC_p + R_DC_p
R_tot_s = R_AC_s + R_DC_s

figure(1)
hold on
grid on
plot(t_foil_test_p*1000, R_DC_p*1000, t_foil_test_p*1000, R_AC_p*1000, 'LineWidth', 4)
set(gca, 'FontSize', 18)
title('Winding resistance as a function of thickness', 'FontSize', 26)
ylabel('Winding Resistance [m\Omega]', 'FontSize', 22)
xlabel('Winding Thickness [mm]', 'FontSize', 22)
legend('DC resistance [m\Omega]', 'AC resistance [m\Omega]')


figure(2)
hold on
grid on
plot(t_foil_test_p, Fr_j, t_foil_test_p, R_DC_s*1000, t_foil_test_p, R_AC_s*1000, t_foil_test_p, R_tot_s*1000, 'LineWidth', 4)
title('Secondary side resistance versus foil thickness')
legend('F_R', 'DC resistance [m\Omega]', 'AC resistance [m\Omega]', 'Total resistance [m\Omega]')