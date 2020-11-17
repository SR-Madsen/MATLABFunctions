function wzeval = ellipwz(N,wp,ws)
%
%  ELLIPWZ:  Determines the finite-value zero-transmission
%            frequencies of an elliptic lowpass filter.
%
%  usage:
%	wzeval = ellipwz(N,wp,ws);
%  returns the array of zero-transmission
%	frequencies of an elliptic lowpass filter.
%
%  The function inputs are:
%     N   (the order of the elliptic filter)
%     wp  (the frequency of the passband edge in radians per second)
%     ws  (the frequency of the stopband edge in radians per second)
%

%
%	L.D. Paarmann, June 21, 1997
%
%
%  This function determines the zero-transmission frequencies of an
%  elliptic lowpass prototype filter, as used in
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
tau2 = wp/ws;
mod2 = tau2^2;
mod2p = 1 - mod2;
[X2eval,E] = ellipke(mod2);
[X2peval,E] = ellipke(mod2p);
q = 0;
Max = (N-1)/2;
if(2*round(N/2)-N==0)
   q = 1;
   Max = N/2;
end
%
%  Compute the zero-transmission frequencies:
argi = -X2peval;
wzeval(1) = 0;
for m=1:Max
   mr = Max-m+1;
   argr = (2*mr - q)*X2eval/N;
   arg = argr + sqrt(-1)*argi;
   wz = wp*ellipsn(arg,tau2);
   wzeval = [wzeval wz];
end
wzeval = real(wzeval(2:Max+1));
%
