function [poles,gain] = besseldd(N)
%
%
%   BESSELDD:  Determines the poles and the gain term
%              of a Bessel normalized time delay lowpass
%              filter for a given order N.  
%             
%   usage:
%   [poles,gain] = besseldd(N);
%   returns the poles and the gain term for a given order N. 
%

%
%
%   written by L.D. Paarmann
%   July 5, 1999
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
%
%
% STEP TWO:  Produce output variables
%
  poles = roots(a);
  gain = a(N+1);
%
%
%
%
%  End of BESSELDD
%
