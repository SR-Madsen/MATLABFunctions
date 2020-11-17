function [poles,gain] = halpde(N,wp,Ap)
%
%
%   HALPDE:  Determines the poles and the gain term of a Halpern lowpass
%            filter to have a given corner frequency wp and passband 
%            corner attenuation Ap for a given order N.
%
%   usage:
%   [poles,gain] = halpde(N,wp,Ap);
%
%   The function inputs are:
%       N   the filter order (no greater than 10)
%       wp  the desired passband corner frequency
%       Ap  the desired attenuation at the passband corner frequency
%

%
%   Written by L.D. Paarmann, June 26, 1998.
%
%
%   This MATLAB function designs a Halpern lowpass filter
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

% Reference:  
%   Peter H. Halpern, "Optimum Monotonic Low-Pass Filters," IEEE
%   Trans. Circuit Theory, vol. CT-16, no. 2, pp. 240-242, May 1969.
%
%
% STEP ONE:  Design the filter for a normalized wc of unity
%
  eps = 10^(Ap/10) - 1;
%  
%  
%  Obtain the Halpern polynomial coefficient values and the denominator
%  of H(s)H(-s) coefficient values
%
  if(N==1)
     C11 = -eps;
     P1 = [C11 0 1];
  end
%
  if(N==2)  
     C21 = eps;
     P2 = [C21 0 0 0 1];
  end
%
  if(N==3)
     C31 = -eps*4;
     C32 = -eps*6;
     C33 = -eps*3;
     P3 = [C31 0 C32 0 C33 0 1];
  end
%  
  if(N==4)   
     C41 = eps*9;
     C42 = eps*16;
     C43 = eps*8;
     P4 = [C41 0 C42 0 C43 0 0 0 1];
  end
%
  if(N==5)  
     C51 = -eps*36;
     C52 = -eps*90;
     C53 = -eps*80;
     C54 = -eps*30;
     C55 = -eps*5;
     P5 = [C51 0 C52 0 C53 0 C54 0 C55 0 1];
  end
%
  if(N==6)
     C61 = eps*100;
     C62 = eps*288;
     C63 = eps*306;
     C64 = eps*144;
     C65 = eps*27;
     P6 = [C61 0 C62 0 C63 0 C64 0 C65 0 0 0 1];
  end
%
  if(N==7)
     C71 = -eps*400;
     C72 = -eps*1400;
     C73 = -eps*1932;
     C74 = -eps*1330;
     C75 = -eps*476;
     C76 = -eps*84;
     C77 = -eps*7;
     P7 = [C71 0 C72 0 C73 0 C74 0 C75 0 C76 0 C77 0 1]; 
  end
%
  if(N==8)
     C81 = eps*1225;
     C82 = eps*4800;
     C83 = eps*7600;
     C84 = eps*6208;
     C85 = eps*2760;
     C86 = eps*640;
     C87 = eps*64;
     P8 = [C81 0 C82 0 C83 0 C84 0 C85 0 C86 0 C87 0 0 0 1];
  end
%
  if(N==9)
     C91 = -eps*4900;
     C92 = -eps*22050;
     C93 = -eps*41400;
     C94 = -eps*42000;
     C95 = -eps*24912;
     C96 = -eps*8730;
     C97 = -eps*1740;
     C98 = -eps*180;
     C99 = -eps*9;
     P9 = [C91 0 C92 0 C93 0 C94 0 C95 0 C96 0 C97 0 C98 0 C99 0 1]; 
  end
%
  if(N==10)
     C101 = eps*15876;
     C102 = eps*78400;
     C103 = eps*164150;
     C104 = eps*189600;
     C105 = eps*131600;
     C106 = eps*56000;
     C107 = eps*14250;
     C108 = eps*2000;
     C109 = eps*125;
     P10 = [C101 0 C102 0 C103 0 C104 0 C105 0 C106 0 C107 0 C108 0 ...
           C109 0 0 0 1];
  end
%
%
% Compute the poles of H(s)H(-s) and assign those with negative real
% parts to H(s), and compute transfer function polynomial values
%
  NUM = 1;
% 
  if(N==1)  
     pr = roots(P1);
     k1 = 1;
     for kk=1:2
        if(real(pr(kk))<0)
           PP(k1) = pr(kk);
           k1 = k1 + 1;
        end
     end
     DEN = poly(PP);
  end
%
   if(N==2) 
     pr = roots(P2);
     k1 = 1;
     for kk=1:4
        if(real(pr(kk))<0)
           PP(k1) = pr(kk);
           k1 = k1 + 1;
        end
     end
     DEN = poly(PP);
  end
%
  if(N==3)
     pr = roots(P3);
     k1 = 1;
     for kk=1:6
        if(real(pr(kk))<0)
           PP(k1) = pr(kk);
           k1 = k1 + 1;
        end
     end
     DEN = poly(PP);
  end
%
  if(N==4)
     pr = roots(P4);
     k1 = 1;
     for kk=1:8
        if(real(pr(kk))<0)
           PP(k1) = pr(kk);
           k1 = k1 + 1;
        end
     end
     DEN = poly(PP);
  end
%
  if(N==5)
     pr = roots(P5);
     k1 = 1;
     for kk=1:10
        if(real(pr(kk))<0)
           PP(k1) = pr(kk);
           k1 = k1 + 1;
        end
     end
     DEN = poly(PP);
  end
%
  if(N==6)
     pr = roots(P6);
     k1 = 1;
     for kk=1:12
        if(real(pr(kk))<0)
           PP(k1) = pr(kk);
           k1 = k1 + 1;
        end
     end
     DEN = poly(PP);
  end
%
  if(N==7)
     pr = roots(P7);
     k1 = 1;
     for kk=1:14
        if(real(pr(kk))<0)
           PP(k1) = pr(kk);
           k1 = k1 + 1;
        end
     end
     DEN = poly(PP);
  end
%
  if(N==8)
     pr = roots(P8);
     k1 = 1;
     for kk=1:16
        if(real(pr(kk))<0)
           PP(k1) = pr(kk);
           k1 = k1 + 1;
        end
     end
     DEN = poly(PP);
  end
%
  if(N==9)
     pr = roots(P9);
     k1 = 1;
     for kk=1:18
        if(real(pr(kk))<0)
           PP(k1) = pr(kk);
           k1 = k1 + 1;
        end
     end
     DEN = poly(PP);
  end
%
  if(N==10)
     pr = roots(P10);
     k1 = 1;
     for kk=1:20
        if(real(pr(kk))<0)
           PP(k1) = pr(kk);
           k1 = k1 + 1;
        end
     end
     DEN = poly(PP);
  end
%
%
%
% STEP TWO:  Calculate the magnitude frequency response
%
  xx = 0:7999;
  w = xx/1000;
  FRM = abs(freqs(NUM,DEN,w));
  scc = max(FRM);
  NUM = NUM/scc;
%
%
%
% STEP THREE:  Frequency scale
%
  fscale = wp;
  poles = PP.'*fscale;
  gain = NUM*fscale^N;
%
%
%
%
%  End of HALPDE
%


