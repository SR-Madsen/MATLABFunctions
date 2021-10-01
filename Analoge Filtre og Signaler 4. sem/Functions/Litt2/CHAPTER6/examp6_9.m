%
%   File Name:  EXAMP6_9.m
%
%   written by L.D. Paarmann
%   July 23, 1997
%
%   This Example demonstrates the Chebyshev Rational Function
%   form of a 4th-order elliptic lowpass filter.
%  
%
%
%   This is Example 6.9 in
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

%
% STEP ONE:  Enter the design parameters
%
  N = 4;
  wp = 1;
  Ap = 10*log10(2);
  As = 40;
%  
%
% STEP TWO:  Calculate ws:
%
  ws = ellipws(N,Ap,As,wp);
%
%
% STEP THREE:  Calculate the peak frequencies:
%
  peaks = ellipeak(N,wp,ws);
%
%
% STEP FOUR:  Calculate the zero-transmission frequencies:
%
  zeros = ellipwz(N,wp,ws);
%
%
% STEP FIVE:  Calculate the scaling coefficient K:
%
  K = (zeros(1)^2 * zeros(2)^2)/(peaks(1)^2 * peaks(2)^2);
%
%
% STEP SIX:  Compute the Chebyshev Rational Function response:
%
  nn = 0:1:1000;
  w = nn/200;
  RNN = K .* ( w.^2 - peaks(1)^2 ) .* ( w.^2 - peaks(2)^2 );
  RND = ( w.^2 - zeros(1)^2 ) .* ( w.^2 - zeros(2)^2 );
  RN = RNN ./ RND;
  FRrf = 1 ./ (1 + RN.^2);
  RFdB = 10*log10(FRrf);
%
%
% STEP SEVEN:  Design a conventional 4th-order elliptic filter
%              and compute the frequency response:
%
  [zz,pp,kk] = ellipap(N,Ap,As);
  NUM = kk*poly(zz);
  DEN = poly(pp);
  FRmag = abs(freqs(NUM,DEN,w));
  FRdB = 20*log10(FRmag);
%  
%
% STEP EIGHT:  Plot the results:
%
  plot(w,FRdB,w,RFdB)
  xlabel('Radian Frequency')
  ylabel('Magnitude in dB')
  grid
  title('Results of Example 6.9:  Rational Function and Conventional')
%
%
%  End of Example 6.9.
%
  
  
