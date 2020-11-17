function [poles,gain] = gausde(N,wp,Ap)
%
%
%   GAUSDE:  Determines the poles and the gain term of a Gaussian lowpass
%            filter to have a given corner frequency wp and passband 
%            corner attenuation Ap for a given order N.
%
%   usage:
%   [poles,gain] = gausde(N,wp,Ap);
%
%   The function inputs are:
%       N   the filter order (no greater than 10)
%       wp  the desired passband corner frequency
%       Ap  the desired corresponding passband corner attenuation
%

%
%   Written by L.D. Paarmann, June 26, 1998.
%
%
%   This MATLAB function designs a Gaussian lowpass filter
%   transfer function as discussed in Chapter 8 of
%
%
%                     Design and Analysis of
%                         ANALOG FILTERS:
%                 A Signal Processing Perspective
%
%                        Larry D. Paarmann
%
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%

% References:  
%   Milton Dishal, "Gaussian-Response Filter Design," Electrical
%   Communication, vol. 36, no. 1, pp. 3-26, January 1959.
%
%   Claude S. Lindquist, Active Network Design with Signal Filtering
%   Applications, Steward & Sons, Long Beach, CA, 1977, pp. 251-254.
%
%
% STEP ONE:  Design the filter for a normalized wc of unity
%
  wc = 1.0;
  gm = log(2)/(wc^2);
  NUM = 1;
%
  tem = [-gm 0 1];
  tem = [(gm^2)/2 0 tem];
  tem = [-(gm^3)/6 0 tem];
  tem = [(gm^4)/24 0 tem];
  tem = [-(gm^5)/120 0 tem];
  tem = [(gm^6)/720 0 tem];
  tem = [-(gm^7)/5040 0 tem];
  tem = [(gm^8)/40320 0 tem];
  tem = [-(gm^9)/362880 0 tem];
  tem = [(gm^10)/3628800 0 tem];
%
  PP2 = roots(tem(21-2*N:21));
  k1 = 1;
  for kk=1:2*N
     if(real(PP2(kk))<0)
        PP(k1) = PP2(kk);
        k1 = k1 + 1;
     end
  end
  DEN = poly(PP);
%
%
%
% STEP TWO:  Calculate the magnitude frequency response
%
  xx = 0:7999;
  w = xx/1000;
  FRM = abs(freqs(NUM,DEN,w));
  scc = max(FRM);
  FRM = FRM/scc;
  NUM = NUM/scc;
%
%
%
% STEP THREE:  Calculate wpint
%
  mag = 10^(-Ap/20);
  dif = abs(FRM - mag);
  test = 0.1;
  for k=1:8000
     if(dif(k)<test)
        test = dif(k);
        ko = k;
     end
  end
  wpint = w(ko);
%
%
%
% STEP FOUR:  Frequency scale
%
  fscale = wp/wpint;
  poles = PP.'*fscale;
  gain = NUM*fscale^N;
%
%
%
%
%  End of GAUSDE
%
