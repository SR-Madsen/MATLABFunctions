function sfeval = ellipsf(N,a,b,Ap,As,wp,ws)
%
%  ELLIPSF:  Determines the Shaping Factor
%            for a lowpass elliptic filter.
%
%  usage:
%  SF1 = ellipsf(N,a,b,Ap,As,wp,ws);
%  returns the Shaping Factor, SF1, for an elliptic lowpass filter.
%
%  The function inputs are:
%     N   (the order of the elliptic filter)
%     a   (the attenuation specification in dB at the narrower bandwidth)
%     b   (the attenuation specification in dB at the wider bandwidth)
%     Ap  (the passband ripple in dB)
%     As  (the stopband minimum attenuation in dB)
%     wp  (the frequency of the passband edge in radians per second)
%     ws  (the frequency of the stopband edge in radians per second)
%

%
%       L.D. Paarmann, July 2, 1997
%
%
%  This function determines the Shaping Factor of an elliptic lowpass
%  prototype filter, and is an implementation of equation (6.39) in
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
%
%  Determine the arguments for the inverse elliptic sine function:
arga = sqrt(10^(a/10) - 1)/sqrt(10^(Ap/10) - 1);
argb = sqrt(10^(b/10) - 1)/sqrt(10^(Ap/10) - 1);
%
%  Compute the inverse elliptic sines:
sninva = ellipint(asin(arga),tau1,10000);
sninvb = ellipint(asin(argb),tau1,10000);
%
%  Determine the arguments for the elliptic sine function:
arga = (N*X1 + sqrt(-1)*imag(sninva))*X2/(N*X1);
argb = (N*X1 + sqrt(-1)*imag(sninvb))*X2/(N*X1);
%
%  Compute the two bandwidths:
BWa = wp*ellipsn(arga,tau2);
BWb = wp*ellipsn(argb,tau2);
%
%  Compute the Shaping Factor:
sfeval = real(BWb/BWa);
%
