clear, close all, clc;

mu = 4*pi*10^-7; % For copper
sigma = 58.7e6; % For copper
f = 200e3; % [Hz]
I_amp = 1; % [A]
r_0 = 0.3e-3; % [m]

delta = 1/sqrt(mu*pi*f*sigma); % Skin depth
Jm = I_amp/(2*pi*delta*(r_0-delta*(1-exp(-r_0/delta))));
J_DC = I_amp/(pi*r_0^2); % Current density at DC

r = linspace(0, 0.3e-3, 20);
J = Jm*exp(-(r_0-r)/delta);

r = [flip(-r),r];
J = [flip(J),J];

% Figure
figure(1)
set(gca, 'FontSize', 22)
hold on
plot(r,J, 'LineWidth', 4)
grid on
xlabel('Conductor Position', 'FontSize', 26)
ylabel('Current Density', 'FontSize', 26)



% Higher frequency calculation
f = 400e3;
delta = 1/sqrt(mu*pi*f*sigma); % Skin depth
Jm = I_amp/(2*pi*delta*(r_0-delta*(1-exp(-r_0/delta))));
J_DC = I_amp/(pi*r_0^2); % Current density at DC

r = linspace(0, 0.3e-3, 20);
J = Jm*exp(-(r_0-r)/delta);

r = [flip(-r),r];
J = [flip(J),J];

% Figure update
plot(r,J, 'LineWidth', 4)
y1 = yline(J_DC, '--g', '\fontsize{16} DC', 'LineWidth', 4);
y1.LabelHorizontalAlignment = 'center';
legend({'200 kHz', '400 kHz', 'DC'})