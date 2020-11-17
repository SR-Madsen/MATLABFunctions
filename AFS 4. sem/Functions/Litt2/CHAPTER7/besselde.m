function [poles,gain] = besselde(N,wp,Ap)
%
%
%   BESSELDE:  Determines the poles and the gain term
%              of a Bessel lowpass filter to have
%              a given corner frequency wp and 
%              passband corner attenuation Ap
%              for a given order N.
%
%   usage:
%   [poles,gain] = besselde(N,wp,Ap);
%
%   The function inputs are:
%       N   the filter order
%       wp  the desired passband corner frequency
%       Ap  the desired corresponding passband corner attenuation
%

%
%   written by L.D. Paarmann
%   August 20, 1997
%
%
%
%   This MATLAB function designs a Bessel lowpass filter
%   transfer function as discussed in Chapter 7 of
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

%
% STEP ONE:  Design the filter for a normalized delay of 1 second
%
  if(N==1)
    a(1) = 1;
    a(2) = 1;
    NUM = 1;
  end
%
  if(N==2)
    a(1) = 1;
    a(2) = 1;
    a(3) = 2/(3*2);
    NUM = 1/a(3);
    a = a*NUM;
    a = fliplr(a);
  end
%
  if(N==3)
    a(1) = 1;
    a(2) = 1;
    for k=1:2
      a(k+2) = 2*(N-k)*a(k+1)/((2*N-k)*(k+1));
    end
    NUM = 1/a(4);
    a = a*NUM;
    a = fliplr(a);
  end
%
  if(N==4)
    a(1) = 1;
    a(2) = 1;
    for k=1:3
      a(k+2) = 2*(N-k)*a(k+1)/((2*N-k)*(k+1));
    end
    NUM = 1/a(5);
    a = a*NUM;
    a = fliplr(a);
  end
%
  if(N==5)
    a(1) = 1;
    a(2) = 1;
    for k=1:4
      a(k+2) = 2*(N-k)*a(k+1)/((2*N-k)*(k+1));
    end
    NUM = 1/a(6);
    a = a*NUM;
    a = fliplr(a);
  end
%
  if(N==6)
    a(1) = 1;
    a(2) = 1;
    for k=1:5
      a(k+2) = 2*(N-k)*a(k+1)/((2*N-k)*(k+1));
    end
    NUM = 1/a(7);
    a = a*NUM;
    a = fliplr(a);
  end
%
  if(N==7)
    a(1) = 1;
    a(2) = 1;
    for k=1:6
      a(k+2) = 2*(N-k)*a(k+1)/((2*N-k)*(k+1));
    end
    NUM = 1/a(8);
    a = a*NUM;
    a = fliplr(a);
  end
%
  if(N==8)
    a(1) = 1;
    a(2) = 1;
    for k=1:7
      a(k+2) = 2*(N-k)*a(k+1)/((2*N-k)*(k+1));
    end
    NUM = 1/a(9);
    a = a*NUM;
    a = fliplr(a);
  end
%
  if(N==9)
    a(1) = 1;
    a(2) = 1;
    for k=1:8
      a(k+2) = 2*(N-k)*a(k+1)/((2*N-k)*(k+1));
    end
    NUM = 1/a(10);
    a = a*NUM;
    a = fliplr(a);
  end
%
  if(N==10)
    a(1) = 1;
    a(2) = 1;
    for k=1:9
      a(k+2) = 2*(N-k)*a(k+1)/((2*N-k)*(k+1));
    end
    NUM = 1/a(11);
    a = a*NUM;
    a = fliplr(a);
  end
%  
  if(N==30)
    a(1) = 1;
    a(2) = 1;
    for k=1:29
      a(k+2) = 2*(N-k)*a(k+1)/((2*N-k)*(k+1));
    end
    NUM = 1/a(31);
    a = a*NUM;
    a = fliplr(a);
  end
%
%
%
% STEP TWO:  Calculate the magnitude frequency response
%
  xx = 101:8100;
  w = xx/1000;
  FRM = abs(freqs(NUM,a,w));
%
%
%
% STEP THREE:  Calculate wpint
%
  mag = 10^(-Ap/20);
  dif = abs(FRM - mag);
  test = 1;
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
  pol = roots(a);
  poles = pol*fscale;
  gain = NUM*(fscale^N);
%
%
%
%
%  End of BESSELDE
%
