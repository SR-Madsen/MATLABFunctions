function [wpeak,wvalley] = ellippv(N,wp,ws)
%
%  ELLIPPV:  Determines the frequencies of the passband 
%            peaks and valleys in the magnitude frequency 
%            response of an elliptic lowpass filter.
%
%  usage:
%	[wps,wvs] = ellippv(N,wp,ws);
%  returns the arrays of frequencies of the passband peaks, wps,
%  and valleys, wvs, of an elliptic lowpass filter.
%
%  The function inputs are:
%     N   (the order of the elliptic filter)
%     wp  (the frequency of the passband edge in radians per second)
%     ws  (the frequency of the stopband edge in radians per second)
%

%
%	L.D. Paarmann, August 4, 1997
%
%
%  This function determines the frequencies of the passband peaks
%  and valleys of the magnitude frequency response of an elliptic
%  lowpass prototype filter, as in (6.25) and (6.27) of
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
[X2eval,E] = ellipke(mod2);
q = 0;
Maxp = (N-1)/2;
Maxv = (N-3)/2;
if(2*round(N/2)-N==0)
   q = 1;
   Maxp = N/2;
   Maxv = (N-2)/2;
end
%
%  Compute the frequencies of the passband peaks:
wpev(1) = 0;
for m=1:Maxp
   arg = (2*m - q)*X2eval/N;
   wpe = wp*ellipsn(arg,tau2);
   wpev = [wpev wpe];
end
if(q==0)
   wpeak = real(wpev);
else
   wpeak = real(wpev(2:Maxp+1));
end
%
%  Compute the frequencies of the passband valleys:
wval(1) = 0;
for m=0:Maxv+1
   arg = (2*m + 1 - q)*X2eval/N;
   wve = wp*ellipsn(arg,tau2);
   wval = [wval wve];
end
if(q==1)
   wvalley = real(wval(2:Maxv+2));
else
   wvalley = real(wval(2:Maxv+2));
end
%
%
%  End of Ellippv