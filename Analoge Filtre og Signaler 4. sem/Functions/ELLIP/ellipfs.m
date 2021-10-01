function fseval = ellipfs(N,Ap,As,wp,wc,ws)
%
%  ELLIPFS:  Determines the Filter Selectivity
%            for a lowpass elliptic filter.
%
%  usage:
%  FS1 = ellipfs(N,Ap,As,wp,wc,ws);
%  assigns the value of the Filter Selectivity to FS1.
%
%  The function inputs are:
%     N   (the order of the elliptic filter)
%     Ap  (the passband ripple in dB)
%     As  (the stopband minimum attenuation in dB)
%     wp  (the frequency of the passband edge in radians per second)
%     wc  (the 3 dB corner frequency in radians per second)
%     ws  (the frequency of the stopband edge in radians per second)
%

%
%       L.D. Paarmann, July 1, 1997
%
%
%  This function determines the Filter Selectivity of an elliptic lowpass
%  prototype filter, and is an implementation of equation (6.36) in
%  
%                     Design and Analysis of
%                         ANALOG FILTERS:
%                 A Signal Processing Perspective
%
%                        Larry D. Paarmann
%
%
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%

%
%  Compute a few necessary values;
epsp = sqrt(10^(Ap/10) - 1);
epss = 1/sqrt(10^(As/10) - 1);
tau1 = epsp*epss;
tau2 = wp/ws;
mod1 = tau1^2;
mod2 = tau2^2;
[X1,E] = ellipke(mod1);
[X2,E] = ellipke(mod2);
kappa = N*X1/X2;
q = 0;
if(2*round(N/2) == N)
   q = 1;
end
%
%  Determine the argument x:
x = kappa * ellipint(asin(wc/wp),tau2,10000) + q * X1;
%
%  Compute the elliptic sine and cosine functions:
sn = ellipsn(x,tau1);
cn = abs(imag(ellipcn(x,tau1)));
%
%  Evaluate Filter Selectivity:
NUM = kappa*epsp*cn*sqrt(1 - mod1*sn^2);
den1 = sqrt(1-mod2*(cosh(imag(asin(wc/wp)))^2));
den2 = sqrt(wc^2 - wp^2);
DEN = 2*sqrt(2)*den1*den2;
fseval = real(NUM/DEN);
%
