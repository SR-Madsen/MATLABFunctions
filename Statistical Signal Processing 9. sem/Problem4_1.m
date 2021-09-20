clear, close all, clc;

%% Problem 4.1
% Signal estimation with discrete-time Wiener-filter (FIR/IIR)
% The problem uses the same model as in lecture 4, with a WSS signal Y(n)
% with added noise W(n) resulting in an observed signal X(n) to be
% filtered. The Y(n) will be generated in MATLAB by using white noise Z(n)
% through a generator filter H_gen(z).
% In practical applications, Y(n) is not known, although its stochastic
% characteristics may be known.

% The problem is split into 8 parts, all containing theoretical and MATLAB
% calculations for optimal understanding.

%% Part A: Generation and analysis of the WSS signal Y(n)

% The stochastic WSS signal Y(n) is given by
% Autocorrelation: Ryy(k) = h^|k|  ,  h = 0.8
% PSD in z-domain: Syy(z) = (1 - h^2)/((1-hz^-1)(1-hz))
% PSD in frequency: Syy(omega) = (1 - h^2)/((1+h^2)-2hcos(omega*Ts))
% fs = 1/Ts = 10 kHz

h = 0.8;
fs = 10000;
Ts = 1/fs;

% 1) Outline Ryy(k) and Syy(omega)
k = -25:1:25;
Ryy = h.^abs(k);
figure(1)
stem(k, Ryy, '.')

omega = -10000:1:10000;
Syy = (1-h^2)./((1+h^2)-2.*h.*cos(omega.*Ts));
figure(2)
stem(omega, Syy, '.')


% 2) Demonstrate that Y(n) can be produced by means of the differential
% equation: Y(n) = hY(n-1) + Z(n)
% where Z(n) ("driving noise") is white, additive, zero-mean gaussic noise.
% Help: Compute Ryy(k) based on the differential equation.

% Ryy(k) = E[x(n)x(n-k)]
% Ryy(k) = E[Y(n)(hY(n-k-1) + Z(n-k))]
%        The noise term is zero-mean and random and thus does not matter
%        = E[Y(n)(hY(n-k-1))]
%        h is a constant and can be moved outside the calculation
%        = h E[Y(n)Y(n-k-1)]
%        We then get the autocorrelation function again:
%        = h Ryy(k-1)


% 3) Find the required noise effect of driving noise sigma_z^2 = E[Z^2(n)]
% which ensures that Ryy(0) = 1 as required in the specification.

% With zero lack, the total power is calculated as
% Ryy(0) = E[X^2(t)] = E[(hY(n-1) + Z(n))^2]
%        Terms can be split, as E[Z^2(n)] = sigma_z^2
%        = E[hY(n-1)^2] + sigma_z^2
%        h can be pulled out, as it is a constant  
%        = h^2 E[Y(n-1)^2] + sigma_z^2
%        The expected value of Y(n-1)Y(n-1) is the autocorrelation function
%        with no lack, that is Ryy(0)
%        = h^2 Ryy(0) + sigma_z^2

% That is, 1 = h^2 + sigma_z^2
% Thus, sigma_z^2 = 1 - h^2 = 1 - 0.8^2 = 0.36
sigma_sq = 0.36
sigma = sqrt(0.36)


% 4) State the transfer function H_gen(z) = Y(z)/Z(z) for the signal
% generator filter.

% The difference equation is moved to the z-domain, resulting in
% Y(z) = h*Y(z)*z^-1 + Z(z)
% Y(z)/Z(z) = 1/(1 - h*z^-1)


% 5) MATLAB realisation:
% Generate N = 1000 samples of driving noise Z(n)
N = 1000;
Zn = sigma * randn(1,N);

% Filter Z(n) with signal generator H_gen
H_gen = tf([1 0], [1 -h], Ts)
Yn = filter(H_gen.Numerator{1,1}, H_gen.Denominator{1,1}, Zn);

figure(3)
psdplot(Yn, 'biased', fs)


%% Part B: Generation and analysis of the WSS noise W(n)
% The additive, zero-mean, gaussic noise W(n) is given by
% W(n) = N(0,sigma_w^2)
sigma_w_sq = 4;
sigma_w = sqrt(sigma_w_sq);

% Sww(z) = sigma_w^2
% Furthermore, the noise is uncorrelated with the signal Y(n)

% 6) Outline Rww(k) and Sww(omega)
% This will be performed in the next step. A dirac delta with peak = 4
% is expected for the Rww(k), while a somewhat
% uniform shape is expected for Sww(omega).

% 7) MATLAB realisation:
% Generate N = 1000 samples of the noise W(n)
N = 1000;
Wn = sigma_w * randn(1,N);

% Plot the noise W(n) and its autocorrelation and PSD
figure(4)
psdplot(Wn, 'biased', fs)


%% Part C: Generation and analysis of the observed signal X(n)
% The observed, noise-riddled signal is given by X(n) = Y(n) + W(n).

% 8) and 9) through mathematical hoops, show that autocorrelation and PSDs
% are as expected.

% 10) Demonstrate the estimation error by means of using X(n) for the
% estimation of Y(n), i.e. state MSEx = E[(Y(n) - X(n))^2]

% 11) MATLAB realisation:
% Generate the observed signal
Xn = Yn + Wn;

% Plot Xn, its autocorrelation function, and PSD
figure(5)
psdplot(Xn, 'biased', fs)

% Calculate the estimation error MSEx
MSE = mean((Yn-Xn).^2)