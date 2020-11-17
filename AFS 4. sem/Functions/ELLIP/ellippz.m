function [zz,pp] = ellippz(N,Ap,As,wp)
%
%  ELLIPPZ:  Determines the poles and zeros of an elliptic
%            lowpass prototype filter.
%
%  usage:
%	[zz,pp] = ellippz(N,Ap,As,wp);
%  returns the arrays zz, containing the zeros, and pp
%  containing the poles, of an elliptic filter.
%
%  The function inputs are:
%     N   (the order of the elliptic filter)
%     Ap  (the passband ripple in dB)
%     As  (the stopband minimum attenuation in dB)
%     wp  (the frequency of the passband edge in radians per second)
%

%
%     Written by L.D. Paarmann, July 23, 1997
%
%
%  This function determines the poles and zeros of an elliptic
%  filter, as discussed in Section 6.8 of
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
%  Compute ws:
ws = ellipws(N,Ap,As,wp);
%
%
%  Compute the transfer function zeros:
q = 0;
MM = (N-1)/2;
if(2*round(N/2)-N==0)
   q = 1;
   MM = N/2;
end
zeros = ellipwz(N,wp,ws);
zz = [];
for m=1:MM
   zero = sqrt(-1)*zeros(m);
   zeroc = -zero;
   zz = [zz zero zeroc];
end
zz = zz';
%
%
%  Compute a few things necessary for finding the poles:
epsp = sqrt(10^(Ap/10) - 1);
epss = 1/sqrt(10^(As/10) - 1);
tau1 = epsp*epss;
mod1 = tau1^2;
mod1p = 1 - mod1;
tau2 = wp/ws;
mod2 = tau2^2;
[X1,E] = ellipke(mod1);
[X1p,E] = ellipke(mod1p);
[X2,E] = ellipke(mod2);
kappa = N*X1/X2;
%
%
%  Compute the transfer function poles:
sninv = ellipint(asin(sqrt(-1)/epsp),tau1,10000);
pp = [];
for m=1:MM
   arg = (sninv - q*X1 - 4*m*X1)/kappa;
   pole = sqrt(-1)*wp*ellipsn(arg,tau2);
   if(real(pole)>0)
      pole = -pole;
   end
   polec = conj(pole);
   pp = [pp pole polec];
end
if(q==0)
   m = 0;
   arg = (sninv - q*X1 - 4*m*X1)/kappa;
   pole = sqrt(-1)*wp*ellipsn(arg,tau2);
   pole = real(pole);
   if(pole>0)
      pole = -pole;
   end
   pp = [pp pole];
end
pp = pp';
%

