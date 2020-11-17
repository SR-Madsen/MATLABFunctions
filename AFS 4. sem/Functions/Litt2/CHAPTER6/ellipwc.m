function wceval = ellipwc(N,Ap,As,wp,ws)
%
%  ELLIPWC:  Determines wc, the 3 dB cutoff frequency,
%            of a lowpass elliptic filter.
%
%  usage:
%	omegac = ellipwc(N,Ap,As,wp,ws);
%  returns the value of wc, the 3 dB corner frequency of an
%  elliptic lowpass filter.
%
%  The function inputs are:
%     N   (the order of the elliptic filter)
%     Ap  (the passband ripple in dB)
%     As  (the stopband minimum attenuation in dB)
%     wp  (the frequency of the passband edge in radians per second)
%     ws  (the frequency of the stopband edge in radians per second)
%

%
%	L.D. Paarmann, June 19, 1997
%
%
%  This function determines wc, the 3 dB corner frequency, of an
%  elliptic lowpass prototype filter.  It evaluates (6.29) in
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
%  Compute some necessary values:
epsilonp = sqrt(10^(Ap/10) - 1);
epsilons = 1/sqrt(10^(As/10) - 1);
tau1 = epsilonp*epsilons;
tau2 = wp/ws;
mod1 = tau1^2;
mod2 = tau2^2;
[X1eval,E] = ellipke(mod1);
[X2eval,E] = ellipke(mod2);
q = 0;
if(2*round(N/2)-N==0)
   q = 1;
end
%
%  Compute the elliptic sine function argument:
invsn = ellipint(asin(1/epsilonp),tau1,10000);
iinv = imag((invsn - q*X1eval)*X2eval/(N*X1eval));
argu = X2eval + sqrt(-1)*iinv;
%
%  Compute the 3 dB corner frequency:
wceval = wp*real(ellipsn(argu,tau2));
%
