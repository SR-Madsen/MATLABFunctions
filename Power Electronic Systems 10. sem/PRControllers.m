close all, clear, clc;

omega_ci = 8;
omega_0  = 100*pi;

% Ideal resonant
k_pI = 1;
k_k = [1 3 5 7];
k_rIk = [1 1 1 1];

G_f = tf([k_rIk(1) 0], [1 0 (k_k(1)*omega_0)^2]);
G_3 = tf([k_rIk(2) 0], [1 0 (k_k(2)*omega_0)^2]);
G_5 = tf([k_rIk(3) 0], [1 0 (k_k(3)*omega_0)^2]);
G_7 = tf([k_rIk(4) 0], [1 0 (k_k(4)*omega_0)^2]);

G_PR_id = k_pI + G_f + G_3 + G_5 + G_7;

figure(1)
bode(G_PR_id)


% Non-ideal resonant
k_pI = 1;
k_k = [1 3 5 7];
k_rIk = [1 1 1 1];

G_f = tf([2*k_rIk(1)*omega_ci 0], [1 2*omega_ci (k_k(1)*omega_0)^2]);
G_3 = tf([2*k_rIk(2)*omega_ci 0], [1 2*omega_ci (k_k(2)*omega_0)^2]);
G_5 = tf([2*k_rIk(3)*omega_ci 0], [1 2*omega_ci (k_k(3)*omega_0)^2]);
G_7 = tf([2*k_rIk(4)*omega_ci 0], [1 2*omega_ci (k_k(4)*omega_0)^2]);

G_PR_ni = k_pI + G_f + G_3 + G_5 + G_7;

figure(2)
bode(G_PR_ni)
