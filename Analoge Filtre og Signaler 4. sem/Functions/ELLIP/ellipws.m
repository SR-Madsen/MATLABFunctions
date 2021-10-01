function wseval = ellipws(N,Ap,As,wp)
%
%  ELLIPWS:  Determines ws such as to satisfy equation (6.23).
%
%  usage:
%	wseval = ellipws(N,Ap,As,wp);
%  returns the value of ws, the frequency
%	of an elliptic filter stopband edge, such as to satisfy
%	equation (6.23):
%              kappa = (N*X1)/X2 = X1p/X2p
%  where N is the filter order, X1 is the complete elliptic
%  integral of tau1 = epsilonp*epsilons, X2 is the complete
%  elliptic integral of tau2 = omegap/omegas, and X1p and X2p
%  are the complete elliptic integrals of the complementary
%  moduli.
%
%  The function inputs are:
%     N   (the order of the elliptic filter)
%     Ap  (the passband ripple in dB)
%     As  (the stopband minimum attenuation in dB)
%     wp  (the frequency of the passband edge in radians per second)
%

%
%       L.D. Paarmann, June 20, 1997
%
%
%  This function determines ws such as to satisfy equation (6.23)
%  in
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
%  Compute some necessary values:
delta1 = 10^(-6);
delta2 = 5*10^(-3)/(N^4);
epsilonp = sqrt(10^(Ap/10) - 1);
epsilons = 1/sqrt(10^(As/10) - 1);
tau1 = epsilonp*epsilons;
mod1 = tau1^2;
mod1p = 1 - mod1;
[X1eval,E] = ellipke(mod1);
[X1peval,E] = ellipke(mod1p);
ratio1 = N*X1eval/X1peval;
%
%  Compute the ratio2 curve for coarse evaluation of ws:
mod2a = (1:8000)/(7.2*10^(8));
mod2b = (1:8000)/(1.28*10^(5));
mod2c = (401:8400)/8402;
mod2ap = 1 - mod2a;
mod2bp = 1 - mod2b;
mod2cp = 1 - mod2c;
[X2aeval,E] = ellipke(mod2a);
[X2apeval,E] = ellipke(mod2ap);
ratio2a = X2aeval ./ X2apeval;
[X2beval,E] = ellipke(mod2b);
[X2bpeval,E] = ellipke(mod2bp);
ratio2b = X2beval ./ X2bpeval;
[X2ceval,E] = ellipke(mod2c);
[X2cpeval,E] = ellipke(mod2cp);
ratio2c = X2ceval ./ X2cpeval;
%
%  Find the ratio2 value closest to ratio1 for coarse evaluation
%  of ws:
differa = ratio1 - ratio2a;
differb = ratio1 - ratio2b;
differc = ratio1 - ratio2c;
minniea = min(abs(differa));
minnieb = min(abs(differb));
minniec = min(abs(differc));
if(minniea < minnieb & minniea < minniec)
   minnie = minniea;
   ratio2 = ratio2a;
   mod2 = mod2a;
   X2eval = X2aeval;
   X2peval = X2apeval;
end
if(minnieb < minniea & minnieb < minniec)
   minnie = minnieb;
   ratio2 = ratio2b;
   mod2 = mod2b;
   X2eval = X2beval;
   X2peval = X2bpeval;
end
if(minniec < minniea & minniec < minnieb)
   minnie = minniec;
   ratio2 = ratio2c;
   mod2 = mod2c;
   X2eval = X2ceval;
   X2peval = X2cpeval;
end
mm = 0;
for kk=1:8000
   if(ratio1 - ratio2(kk) == minnie)
      mm = kk;
   end
   if(ratio1 - ratio2(kk) == -minnie)
      mm = kk;
   end
end
mod2sel = mod2(mm);
wseval = 1/sqrt(mod2sel);
%
%  Perform fine evaluation of ws:
rat2 = ratio2(mm);
magtest = abs(ratio1 - rat2);
while(magtest > delta1)
   if(rat2 > ratio1)
      wseval = wseval + delta2;
   else
      wseval = wseval - delta2;
   end
   tau2 = 1/wseval;
   mod2s = tau2^2;
   mod2ps = 1 - mod2s;
   [X2ev,E] = ellipke(mod2s);
   [X2pev,E] = ellipke(mod2ps);
   rat2 = X2ev/X2pev;
   magtemp = abs(ratio1 - rat2);
   if(abs(magtemp-magtest)<delta1)
      delta2 = delta2*1.25;
   end
   if(magtemp>=magtest)
      delta2 = delta2*0.8;
   end
   magtest = magtemp;
end
wseval = wp*wseval;
%

