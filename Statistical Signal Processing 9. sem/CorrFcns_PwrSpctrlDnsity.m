clear, close all, clc;

% MATLAB Exercise: Correlation functions and power spectral density

%% The autocorrelation function, rxx(tau)
% Autocorrelation and crosscorrelation uses xcorr in MATLAB.
help xcorr; % Preferred way of using is [Rxx, tau] = xcorr(x)

% Example 1: Gauss-distributed white noise
N = 1024;
x1 = randn(1,N);
n = 0:N-1;

figure(1)
subplot(2,1,1)
stem(n,x1, '.')

subplot(2,1,2)
[rxx, tau] = xcorr(x1);
stem(tau, rxx, '.')

% Random noise generated in time domain.
% In lag domain, the zero lag value is 1043.
% All non-zero lag values are random and reasonably near 0.


% Example 2: Low-pass filtered white noise
fs = 8000;
help fir1;
firlpf = fir1(50, 1000/(fs/2));
%figure(2)
%freqz(firlpf, 1, 1024, fs) % Transfer function of digital filter
% The filter has a cutoff frequency just below 1000 Hz
x2 = filter(firlpf, 1, x1);
figure(3)
autocorrplot(x2, 'none')

% As expected, the signal in time domain has removed high frequencies.
% In lag domain, the zero lag value is now only 250.
% This is because the Nyquist frequency is 4000 Hz, which is just above
% four times the filter cutoff-frequency (1043/250 ~ 4). If
% cutoff-frequency is further adjusted, so will zero-lag value.
% Additionally, some higher values are observed.


% Example 3: Sinusoidal signal
f1 = 400;
Ts = 1/fs;
x3 = sin(2*pi*f1*n*Ts);
figure(4)
autocorrplot(x3, 'none')

% The result in the lag domain is a sinusoidal signal of identical
% frequency, but with varying values depending on lag. At low lag, the
% values are higher due to larger overlap.


% Example 4: Sinusoidal signal with white noise
sigma = 1;
x4 = x3 + sigma*randn(1,N);
figure(5)
autocorrplot(x4, 'none')

% The time domain signal is must less obvious, however from the lag domain
% values it can be seen that the total power is significantly higher, and
% the sinusoidal signal is still clearly present.
% When the sigma value is increased, the time domain signal becomes ever
% more difficult to describe, however the sine is still somewhat present in
% the lag domain, although it too becomes more difficult to see.


% Example 5: White noise with DC value
DC = 1;
x5 = x1 + DC;
figure(6)
autocorrplot(x5, 'none')


% Characteristics of the autocorrelation function:
% r_xx(0) is equal to the total signal energy. This is seen as it is the
% only consistently positive value, which energy would always be.
% 
% r_xx(-tau) = r_xx(tau). This is seen in every case. Referring to the
% "sliding blocks", which the signals values can be seen as, the overlap is
% identical whether you slide one or the other direction.
%
% r_xx(tau) <= r_xx(0). The maximum value is always at 0. This is because
% it is the total signal energy. In no way could you observe a time
% difference resulting in more energy than the total energy of the signal.
%
% r_xx(infinity) is equal to the DC value of the signal. As the lag moves
% the "blocks" out of the scope of eachother, only a DC value will remain.


% All examples above can be performed with different options for the
% autocorrelation method. With 'none', no adjustments are made.
% With 'biased', a value is multiplied with the summation equal to 1/N.
% With 'unbiased', the multiplied value is 1 / (N - tau)
% Finally with 'coeff', the value ensures that R_xx(0) = 1.

% Generally, these methods result in the values only being trustworthy for
% values of tau up to around 10-20% of N


% Connection between autocorrelation and convolution:
% Convolution and correlation are almost identical.
% Convolution is "flip-and-slide", while correlation is "slide-but-no-flip"
% Thus r_xx(tau) = x(tau)*x(-tau)
% This can be seen from
figure(7)
subplot(2,1,1)
[rxx, tau] = xcorr(x2, 'none');
stem(tau, rxx, '.')
subplot(2,1,2)
x2mirror = fliplr(x2);
rxx2 = conv(x2, x2mirror);
stem(tau, rxx2, '.')

% These are identical.


% Calculation of autocorrelation with own algorithm, corresponding to
% real-time implementation:
% A selfdefined xcorr algorithm is created, as MATLAB hides the O(N^2)
% calculation. This is tested with
figure(8)
subplot(2,1,1)
[rxx, tau] = xcorr(x2, 'biased');
stem(tau, rxx, '.')
subplot(2,1,2)
[rxx_own, tau_own] = own_xcorr(x2);
stem(tau_own, rxx_own, '.')

% These are identical.

% When studying stochastic signals with an average value different from 0,
% the auto-covariance function xcov can be used instead.


%% The cross correlation function, rxy(tau)
% Autocorrelation compares a signal with a time lagged version of itself.
% The cross correlation function compares two signals with each other, in
% which one is time lagged.
% The crosscorrplot.m function has been created to plot signals.


% Example 1: x1 is gauss-distributed white noise, y1 is variants of x1
N = 1024;
x1 = randn(1,N);
y1a = x1;
figure(1)
crosscorrplot(x1, y1a, 'none')

% As the signals are identical, this works similar to an autocorrelation.
% In the lag domain, the values are thus symmetric and as expected.

% y1 is now set to a time delayed version of x1
delay = 300;
y1b = [randn(1,delay), x1(1:N-delay)];
crosscorrplot(x1, y1b, 'none')

% As expected, the values in the lag domain have been shifted 300 samples.

% y1 is set to a low-pass filtered version of x1
fs = 8000;
fir_lpf = fir1(50, 1000/(fs/2));
y1c = filter(fir_lpf, 1, x1);
crosscorrplot(x1, y1c, 'none')

% The maximum is not found in tau = 0, but rather tau = -25.
% Increasing the filter order also increases the lag (tau becomes more
% negative). This may be due to the inherent delay in the digital filter.
% Changing the cutoff-frequency does not impact lag, but rather the look of
% the signal.

% y1 is set to a time-delayed and low-pass filtered version of x1
y1d = filter(fir_lpf, 1, y1b);
crosscorrplot(x1, y1d, 'none')

% A combination of the two previous, as expected.


% Example 2: 