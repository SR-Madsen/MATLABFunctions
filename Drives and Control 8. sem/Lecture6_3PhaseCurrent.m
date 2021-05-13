clear, close all, clc

%% In-Lecture Exercise for Lecture 6: 3-Phase Symmetrical Current
% Design a 3-phase current array (2 seconds) and plot.
% The frequency is 2 Hz
% The amplitude is 20 A
% i1(t) = A * cos(wt + 0)
% i2(t) = A * cos(wt + 120)
% i3(t) = A * cos(wt - 120)

A = 20; % Amps
f = 2; % Hz
w = f * 2 * pi; % rad/s

for k = 1:2000
    t(k) = 0.001 * k;
    i1(k) = A * cos(w*t(k));
    i2(k) = A * cos(w*t(k) + deg2rad(120));
    i3(k) = A * cos(w*t(k) - deg2rad(120));
end

figure(1)
plot(t,i1,t,i2,t,i3, 'LineWidth', 2)
legend('Phase A', 'Phase B', 'Phase C')
grid on
title('3-Phase Symmetrical Current')
xlabel('Time [s]')
ylabel('Current [A]')

% Do a Clarke transformation of the 3 currents and plot them in the
% alpha/beta plane
Clarke = 2/3*[1 -1/2 -1/2; 0 sqrt(3)/2 -sqrt(3)/2];
phases = [i1; i2; i3];
alpha_beta = Clarke * phases;
alpha = i1;
beta = 1/(sqrt(3)) * (i2  - i3);

figure(2)
%plot(alpha_beta(1,:),alpha_beta(2,:))
plot(t,alpha_beta(1,:),t,alpha_beta(2,:),t,alpha,t,beta)
grid on
title('Clarke-transformed 3 Phase Symmetrical Current')
xlabel('Alpha [A]')
ylabel('Beta [A]')

% Do a Park transformation
%Park = [-sin(w*t(k)) cos(w*t(k)); cos(w*t(k)) sin(w*t(k))];
%i_qd = Park * alpha_beta;

%figure(3)
%plot(i_qd(1,:),i_qd(2,:))