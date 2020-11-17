function wmeval = ellipwm(N,wp,ws)
%
%  ELLIPWM:  Determines the finite-value frequencies in the
%            stopband of an elliptic lowpass filter where the
%            attenuation is minimum.
%
%  usage:
%	wmeval = ellipwm(N,wp,ws);
%  returns the array of frequencies where the
%	attenuation is minimum for an elliptic lowpass filter.
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
%  This function determines an array of frequencies in the
%  stopband of an elliptic lowpass prototype filter, where the
%  attenuation is minimum, as used in
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
   Max = (N/2) - 1;
end
%
%  Compute the minimum-attenuation frequencies:
argi = -X2peval;
wmeval(1) = 0;
for m=1:Max
   mr = Max + 1 - m;
   argr = (2*mr - 1 + q)*X2eval/N;   
   arg = argr + sqrt(-1)*argi;
   wm = wp*ellipsn(arg,tau2);
   wmeval = [wmeval wm];
end
wmeval = wmeval(2:Max+1);
%
