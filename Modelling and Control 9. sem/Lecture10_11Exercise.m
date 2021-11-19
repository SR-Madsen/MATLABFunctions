 clear, close all, clc;

%% In-Lecture Exercise: DC motor control
% Lecture 10 and 11

% The same DC machine as in the "optimal" design project is used.

Ra = 1;
La = 1;
Km = 0.1;
Ka = 0.1;
J = 0.1;
B = 0.05;

% Input is terminal voltage (Vi) and output is rotational speed (omega).

%% 1) Design an analog and a digital (T = 0.1 s) PI controller for the
% machine so the phase margin, PM = 50 degrees. Simulate in Simulink!
% What is the bandwidth of the system?

T = 0.1;

% State-space matrices for the DC motor
A = [-Ra/La -Ka/La; Ka/J -B/J];
B = [1/La;0];
C = [0 1]; 
D = 0;

% Transfer function of DC motor
[num, den] = ss2tf(A, B, C, D);
Gs = tf(num,den)
figure(1)
margin(Gs)

% Analog PI controller
Kp = 2.95;
Ki = 1;
omega_i = bandwidth(Gs)/10; % NOTE: SHOULD NOT BE FROM BANDWIDTH.
% INSTEAD PLOT PI AND FIND THE PHASE AT WHICH PI - INTEGRATOR - PM = 180
tau_i = 1/omega_i;
D_analog = tf(Kp*Ki*[tau_i 1], [tau_i 0]);
figure(2)
margin(D_analog*Gs)


% Digital PI controller
Gz = c2d(Gs, T);
Gw = d2c(Gz, 'Tustin');

Kp_z = 2.55;
Ki_z = 1;
omega_i_z = bandwidth(Gw)/10; % NOTE: SHOULD NOT BE FROM BANDWIDTH.
% INSTEAD PLOT PI AND FIND THE PHASE AT WHICH PI - INTEGRATOR - PM = 180
tau_i_z = 1/omega_i_z;
D_digital_w = tf(Kp_z*Ki_z*[tau_i_z 1], [tau_i_z 0]);
figure(3)
margin(D_digital_w*Gw)

D_digital_z = c2d(D_digital_w, T);


%% 2) Design a pole-placement PID, so the settling time is t_s = 2 s.
% Simulate in Simulink!
% What is the bandwidth of the system?
t_s = 2; % [s]

% The plant is a second order system. Adding a PID would make it a 3rd.
n = 3;

% The closed-loop transfer function for a PID + plant is
% y/yr = ((Kp + Kds + Ki/s) B(s)/A(s)) / (1 + (Kp + Kds + Ki/s) B(s)/A(s))

% From this, the characteristic equation is found as
% alpha_c(s) = A(s)s + (Kps + Kds^2 + Ki) B(s)

% Which is to be compared with
% alpha_c(s) = (s-sp)^4

% The poles are placed on top of each other, using the equation:
s_p = (-1.5 * (n + 1)) / t_s;

% Thus
syms s
alpha_c_general = expand((s-s_p)^3);
% = s^3 + 9s^2 + 27s + 27

syms Kp Kd Ki
alpha_c_system = expand((Gs.Denominator{1,1}(1)*s^2 + Gs.Denominator{1,1}(2)*s + Gs.Denominator{1,1}(3))*s + ... 
                 (Kp*s + Kd*s^2 + Ki)*Gs.Numerator{1,1}(3));
% = s^3 + (3/2 + Kd)*s^2 + (3/5 + Kp)*s + Ki

Ki = 27;
Kp = 27 - 3/5;
Kd = 9 - 3/2;


%% 3) Design an analog and digital LSF control for the system.
% Settling time must be ts = 2 sec. Simulate!
% What is the bandwidth for the system?
t_s = 2;
n = 2;

[Ad, Bd] = c2d(A, B, T);
Cd = C;
Dd = D;

s_p = (-1.5 * (n + 1)) / t_s;
z_p = exp(s_p*T);

K_s = acker(A, B, [s_p s_p])
K_z = acker(Ad, Bd, [z_p z_p])


%% 4) Design an analog and digital LSF control with integrator.
% Settling time must be ts = 2 sec. Simulate!
% What is the bandwidth for the system?
n = 3;

s_p = (-1.5 * (n + 1)) / t_s;
z_p = exp(s_p*T);

A_mark = [A, [0; 0]; -C, 0];
B_mark = [B; 0];
KKi_s = acker(A_mark, B_mark, [s_p, s_p, s_p])
K_s = KKi_s(1:n-1);
Ki_s = -KKi_s(n);

Ad_mark = [Ad, [0; 0]; -Cd, 1];
Bd_mark = [Bd; 0];
KKi_z = acker(Ad_mark, Bd_mark, [z_p, z_p, z_p])
K_z = KKi_z(1:n-1);
Ki_z = -KKi_z(n);


%% 5) Design a digital LSF control for the system with prediction observer.
% The observer must be twice as fast as the plant.
% The settling time must be ts = 2 sec. Simulate!
% What is the bandwidth for the system?
n = 2;

s_p_plant = (-1.5 * (n + 1)) / t_s;
z_p_plant = exp(s_p_plant*T);

s_p_obs = 2 * s_p_plant;
z_p_obs = exp(s_p_obs*T);

L = acker(Ad', Cd', [z_p_obs, z_p_obs])'
K_z = acker(Ad, Bd, [z_p_plant, z_p_plant])


%% 6) Design a digital LSF control for the system with reduced observer.
% The observer must be twice as fast as the plant.
% The settling time must be ts = 2 sec. Simulate!
% What is the bandwidth for the system?

% As C = [0 1], we must rearrange it to be C = [1 0].
% This also requires rearranging A and B.
C_adj = [Cd(2) Cd(1)];
B_adj = [Bd(2); Bd(1)];
A_adj = [Ad(2,2), Ad(2,1); Ad(1,2), Ad(1,1)];

A_aa = A_adj(1,1);
A_ab = A_adj(1,2);
A_ba = A_adj(2,1);
A_bb = A_adj(2,2);

B_a = B_adj(1);
B_b = B_adj(2);

L = acker(A_bb', A_ab', z_p_obs)'
K_z = acker(A_adj, B_adj, [z_p_plant, z_p_plant])