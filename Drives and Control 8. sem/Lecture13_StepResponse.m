clear, close all, clc;

%% In-Lecture Exercise: Analyze a plant step response in analog, digital, and for different sample times.
% The plant is G(s) = 10 / (s^2 + 2*s + 1)
% The sampling frequencies to use are 25 * w_3dB and 2.5 * w_3dB.

Gs_num = [10];
Gs_den = [1 2 1];
Gs = tf(Gs_num, Gs_den);
%bode(Gs)

w_3dB = bandwidth(Gs); % rad/s
f_samp = [2.5 * (w_3dB) 25*(w_3dB)];
T_samp = 1./(f_samp);

Gz_slow = c2d(Gs, T_samp(1));
Gz_num = Gz_slow.Numerator{1,1};
Gz_den = Gz_slow.Denominator{1,1};

Gz_fast = c2d(Gs, T_samp(2));

% Results are pretty much as expected, a low sampling frequency results in
% a very abrupt change in discretized output voltage.

%% In-Lecture Exercise: Find the open loop phase margin for analog and digital with different sample times.
% Re-use the plant from above.
figure(1)
margin(Gs)

figure(2)
margin(Gz_slow)

figure(3)
margin(Gz_fast)


% Close the loop with unity feedback and no controller.
% Use analog and digital with different sample times.
Gs_closed = feedback(Gs, 1);
Gz_slow_closed = feedback(Gz_slow, 1);
Gz_fast_closed = feedback(Gz_fast, 1);

figure(4)
subplot(2,2,1)
bode(Gs_closed)
subplot(2,2,2)
bode(Gz_slow_closed)
subplot(2,2,3)
bode(Gz_fast_closed)