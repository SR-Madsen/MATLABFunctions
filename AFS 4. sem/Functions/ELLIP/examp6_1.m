%
%   File Name:  EXAMP6_1.m
%
%   written by L.D. Paarmann
%   June 5, 1997
%
%   This MATLAB m-file Demonstrates that a Chebyshev Filter is
%   a Special Case of an Elliptic Filter, and that in this Case,
%   the Elliptic Sine Form and the Elliptic Cosine Form of (6.2)
%   are Identical.  All Three Filter Responses, in this Example,
%   are Third-Order Chebyshev with 3 dB of Passband Ripple.
%
%
%
%   This is Example 6.1 in
%
%                     Design and Analysis of
%                         ANALOG FILTERS:
%                 A Signal Processing Perspective
%
%                       Larry D. Paarmann
%
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%

%
% Enter Parameters:
  kappa = 3;
  AC = 1000;
  tau1 = 0;
% Note that tau2 = 0 is not necessary, since sin and cos
% are used in place of sn and cn, respectively.
%
% Generate an array of radian frequency values going from
% 0 to 5 radians/second:
  nn = 0:1:500;
  w = nn/100;
%
% Produce the array of values for the upper limit of the
% elliptic integral of the first kind for the sn case and
% the cn case, respectively:
  asin1 = asin(w);
  acos1 = acos(w);
%
% Evaluate the elliptic integral of the first kind for the
% sn case and the cn case, respectively:
  invsn = ellipint(asin1,tau1,AC);
  invcn = ellipint(acos1,tau1,AC);
%
% Compute the argument for sn and cn, respectively:  
  argsn = invsn*kappa;
  argcn = invcn*kappa;
%
% Compute sn and cn, respectively:  
  sn = sin(argsn);
  cn = cos(argcn);
% 
% Compute the squares (real parts are used since sn and cn
% are, in general, complex, but it can be shown that the
% imaginary parts, ideally zero, are insignificantly small):  
  snr = real(sn);
  cnr = real(cn);
  snsq = snr.*snr;
  cnsq = cnr.*cnr;
%  
% Adjust values, prior to taking the logarithm, to prevent
% problems with the logarithm of zero (or near zero):
  N1 = 501;
  for ii=1:N1
    if(snsq(ii) > 10^30)
      snsq(ii) = 10^30;
    end
    if(cnsq(ii) > 10^30)
      cnsq(ii) = 10^30;
    end
  end
%
% Form the magnitude-squared frequency response denominators:  
  dens = 1 + snsq;
  denc = 1 + cnsq;
%
% Form the magnitude-squared frequency responses:
  HMmags = 1 ./ dens;
  HMmagc = 1 ./ denc;
%
% Form the magnitude-squared frequency responses in dB:  
  HMdBs = 10*log10(HMmags);
  HMdBc = 10*log10(HMmagc);
%
%
% Design a third-order Chebyshev filter:
  [zz,pp,kk] = cheb1ap(3,10*log10(2));
  NUM = kk*poly(zz);
  DEN = poly(pp);
%
% Form the magnitude-squared frequency response of the
% third-order Chebyshev filter in dB:
  freq = freqs(NUM,DEN,w);
  frem = abs(freq);
  HMdBf = 20*log10(frem);
%
% Plot and compare the three responses:
  plot(w,HMdBs,'g',w,HMdBc,'r',w,HMdBf,'b')
  grid
  xlabel('Radian Frequency')
  ylabel('Magnitude in dB')
  title('Example 6.1:  sn form in green, cn form in red, Chebyshev in blue')
  pause
  close
%
%
% End of Example 6.1
%