function NN = ellipor(Ap,As,wp,ws)
%
%  ELLIPOR:  Determines the minimum required order of an elliptic
%            lowpass prototype filter to meet input specifications.
%
%  usage:
%	ELLIPOR(Ap,As,wp,ws) returns the scalar minimum required order
%  of an elliptic filter.
%
%  The function inputs are:
%     Ap  (the passband ripple in dB)
%     As  (the stopband minimum attenuation in dB)
%     wp  (the frequency of the passband edge in radians per second)
%     ws  (the frequency of the stopband edge in radians per second)
%

%
%     Written by L.D. Paarmann, October 24, 1997
%
%
%  This function determines the minimum required order of an elliptic
%  filter, according to equation (6.40) of
%  
%                     Design and Analysis of
%                         ANALOG FILTERS:
%                 A Signal Processing Perspective
%
%                        Larry D. Paarmann
%
%
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%

%
%
%  Compute the complete elliptic integrals:
%
   epsp = sqrt(10^(Ap/10) - 1);
   epss = 1/sqrt(10^(As/10) - 1);
   tau1 = epsp*epss;
   mod1 = tau1^2;
   mod1p = 1 - mod1;
   tau2 = wp/ws;
   mod2 = tau2^2;
   mod2p = 1 - mod2;
   [X1,E] = ellipke(mod1);
   [X1p,E] = ellipke(mod1p);
   [X2,E] = ellipke(mod2);
   [X2p,E] = ellipke(mod2p);
%
%
%
%  Compute the minimum required order:
%
   eta = (X1p*X2)/(X1*X2p);
   NN = ceil(eta);
%
