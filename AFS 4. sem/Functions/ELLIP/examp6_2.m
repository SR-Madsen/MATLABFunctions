%
%   File Name:  EXAMP6_2.m
%
%   written by L.D. Paarmann
%   June 5, 1997
%
%
%   This MATLAB m-file Demonstrates that Setting up the
%   Parameters of
%            sn(kappa*sn^(-1)(w/wp,wp/ws),epsp*epss)
%   Yielding a Real Result is Critical, and that Arbitrarily
%   Chosen Values will Yield, in General, a Complex Result,
%   and Therefore not Realizable.  When Set up Properly, the
%   Result in this Example is a Third-Order Elliptic Magnitude-
%   Squared Response with 3 dB of Passband Ripple, a Stopband
%   Minimum Attenuation of 40 dB, and a Stopband Frequency Edge
%   of 1.9789 radians/sec.
%
%
%
%   This is Example 6.2 in
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
% STEP ONE:  Setup Proper Parameters and Compute Results
%
% Enter parameters:
  ws = 1.9789;
  epss = 0.0100005;
  kappa = 2.7906;
  AC = 10000;
  tau1 = epss;
  tau2 = 1 / ws;
%
% Generate an array of radian frequency values going from
% 0 to 5 radians/second:
  nn = 0:1:500;
  w = nn/100;
%
% Produce the array of values for the upper limit of the
% elliptic integral of the first kind:
  asin1 = asin(w);
%
% Evaluate the elliptic integral of the first kind:
  invsn = ellipint(asin1,tau2,AC);
%
% Compute the argument for sn:  
  argsn = invsn*kappa;
%
% Compute sn:  
  sn = ellipsn(argsn,tau1);
% 
% Compute the squares of the magnitudes (real and imaginary parts
% are computed also for analysis):  
  snr = real(sn);
  sni = imag(sn);
  snm = abs(sn);
  snsq = snm.*snm;
%  
% Adjust values, prior to taking the logarithm, to prevent
% problems with the logarithm of zero (or near zero):
  N1 = 501;
  for ii=1:N1
    if(snsq(ii) > 10^30)
      snsq(ii) = 10^30;
    end
  end
%
% Form the magnitude-squared frequency response denominator:  
  den = 1 + snsq;
%
% Form the magnitude-squared frequency response:
  HMmag = 1 ./ den;
%
% Form the magnitude-squared frequency response in dB:  
  HMdB = 10*log10(HMmag);
%
%
%
% STEP TWO:  Setup Arbitrary Parameters 1 and Compute Results
%
% Enter parameters:
  ws2 = 2.5;
  epss2 = 0.01;
  kappa2 = 3;
  AC2 = 1000;
  tau1 = epss2;
  tau2 = 1 / ws2;
%
% Evaluate the elliptic integral of the first kind:
  invsn2 = ellipint(asin1,tau2,AC2);
%
% Compute the argument for sn:  
  argsn2 = invsn2*kappa2;
%
% Compute sn:  
  sn2 = ellipsn(argsn2,tau1);
% 
% Compute the squares(real and imaginary parts
% are computed also for analysis):  
  snr2 = real(sn2);
  sni2 = imag(sn2);
  snsq2 = sn2.*sn2;
% 
% Form the squared frequency response denominator:  
  den2 = 1 + snsq2;
%
% Form the magnitude-squared frequency response:
  HMmag2 = abs(1 ./ den2);
%   
% Adjust values, prior to taking the logarithm, to prevent
% problems with the logarithm of zero (or near zero):
  N1 = 501;
  for ii=1:N1
    if(HMmag2(ii) < 10^(-30))
      HMmag2(ii) = 10^(-30);
    end
  end
% Form the magnitude-squared frequency response in dB:  
  HMdB2 = 10*log10(HMmag2);
%
%
%
% STEP THREE:  Setup Arbitrary Parameters 2 and Compute Results
%
% Enter parameters:
  ws3 = 1.5;
  epss3 = 0.008;
  kappa3 = 3;
  tau1 = epss3;
  tau2 = 1 / ws3;
%
% Evaluate the elliptic integral of the first kind:
  invsn3 = ellipint(asin1,tau2,AC2);
%
% Compute the argument for sn:  
  argsn3 = invsn3*kappa3;
%
% Compute sn:  
  sn3 = ellipsn(argsn3,tau1);
% 
% Compute the squares(real and imaginary parts
% are computed also for analysis):  
  snr3 = real(sn3);
  sni3 = imag(sn3);
  snsq3 = sn3.*sn3;
% 
% Form the squared frequency response denominator:  
  den3 = 1 + snsq3;
%
% Form the magnitude-squared frequency response:
  HMmag3 = abs(1 ./ den3);
%   
% Adjust values, prior to taking the logarithm, to prevent
% problems with the logarithm of zero (or near zero):
  N1 = 501;
  for ii=1:N1
    if(HMmag3(ii) < 10^(-30))
      HMmag3(ii) = 10^(-30);
    end
  end
% Form the magnitude-squared frequency response in dB:  
  HMdB3 = 10*log10(HMmag3);
%
%
%
% STEP FOUR:  Design a Third-Order Elliptic Filter:
%
  [zz,pp,kk] = ellipap(3,10*log10(2),40);
  NUM = kk*poly(zz);
  DEN = poly(pp);
%
% Form the magnitude-squared frequency response of the
% third-order elliptic filter in dB:
  freq = freqs(NUM,DEN,w);
  frem = abs(freq);
  HMdBf = 20*log10(frem);
%
% Plot and compare the four magnitude responses:
  plot(w,HMdB,'g',w,HMdB2,'r',w,HMdB3,'y',w,HMdBf,'b')
  grid
  xlabel('Radian Frequency')
  ylabel('Magnitude in dB')
  title('proper sn in green, arbitrary 1 in red, arbitrary 2 in yellow, elliptic in blue')
  pause
  close
%
% Scale snr and sni for plotting purposes:
  snr40 = snr/40;
  sni40 = sni/40;
%  
% Plot and compare the real and imaginary responses:
  plot(w,snr40,'m',w,sni40,'c',w,snr2,'g',w,sni2,'r',w,snr3,'y',w,sni3,'b')
  grid
  xlabel('Radian Frequency')
  ylabel('Amplitude')
  title('Prop/40: magenta (r), cyan (i). Arb1: green (r), red (i). Arb2: yellow (r), blue (i)')
  pause
  close
%  
%
% End of Example 6.2
%








