function [poles,gain] = papoulde(N,wp,Ap)
%
%
%   PAPOULDE: Determines the poles and the gain term of a Papoulis
%             lowpass filter to have a given corner frequency wp and 
%             passband corner attenuation Ap for a given order N.
%
%   usage:
%   [poles,gain] = papoulde(N,wp,Ap);
%
%   The function inputs are:
%        N  the filter order (no greater than 10)
%       wp  the desired passband corner frequency
%       Ap  the desired attenuation in dB at the passband corner frequency
%

%
%   Written by L.D. Paarmann, June 29, 1998.
%
%
%   This MATLAB function designs a Papoulis lowpass filter
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
%   A. Papoulis, "Optimum Filters with Monotonic Response,"
%   Proceed. IRE, vol. 46, no. 3, pp. 606-609, March 1958.
%   
%   A. Papoulis, "On Monotonic Response Filters," Proceed. IRE,
%   vol. 47, pp. 332-333, February 1959.
%
%
  eps = 10^(Ap/10) - 1;
  NUM = 1;
%  
%
% STEP 1:  Design the Papoulis filter for a normalized wp of unity
%
% STEP 1.1:  Specify the coefficient values for the 
%            denominator of H(s)H(-s)
% 
%
  if(N==1)
     C1 = -eps; 
     PO = [C1 0 1];
  end  
%  
  if(N==2)   
     C1 = eps;
     PO = [C1 0 0 0 1];       
  end
%
  if(N==3)
     C1 = -eps*3;
     C2 = -eps*3;
     C3 = -eps;
     PO = [C1 0 C2 0 C3 0 1];        
  end
%  
  if(N==4)     
     C1 = eps*6;
     C2 = eps*8;
     C3 = eps*3;     
     PO = [C1 0 C2 0 C3 0 0 0 1];
  end
%
  if(N==5)   
     C1 = -eps*20;
     C2 = -eps*40;
     C3 = -eps*28;
     C4 = -eps*8;
     C5 = -eps;
     PO = [C1 0 C2 0 C3 0 C4 0 C5 0 1];  
  end
%
  if(N==6)
     C1 = eps*50;
     C2 = eps*120;
     C3 = eps*105;
     C4 = eps*40;
     C5 = eps*6;
     PO = [C1 0 C2 0 C3 0 C4 0 C5 0 0 0 1];
  end
% 
  if(N==7)
     C1 = -eps*175;
     C2 = -eps*525;
     C3 = -eps*615;
     C4 = -eps*355;
     C5 = -eps*105;
     C6 = -eps*15;
     C7 = -eps;
     PO = [C1 0 C2 0 C3 0 C4 0 C5 0 C6 0 C7 0 1]; 
  end
%
  if(N==8)
     C1 = eps*490;
     C2 = eps*1680;
     C3 = eps*2310;
     C4 = eps*1624;
     C5 = eps*615;
     C6 = eps*120;
     C7 = eps*10;
     PO = [C1 0 C2 0 C3 0 C4 0 C5 0 C6 0 C7 0 0 0 1];
  end
%
  if(N==9)
     C1 = -eps*1764;
     C2 = -eps*7056;
     C3 = -eps*11704;
     C4 = -eps*10416;
     C5 = -eps*5376;
     C6 = -eps*1624;
     C7 = -eps*276;
     C8 = -eps*24;
     C9 = -eps;
     PO = [C1 0 C2 0 C3 0 C4 0 C5 0 C6 0 C7 0 C8 0 C9 0 1]; 
  end
%
  if(N==10)
     C1 = eps*5292;
     C2 = eps*23520;
     C3 = eps*44100;
     C4 = eps*45360;
     C5 = eps*27860;
     C6 = eps*10416;
     C7 = eps*2310;
     C8 = eps*280;
     C9 = eps*15;
     PO = [C1 0 C2 0 C3 0 C4 0 C5 0 C6 0 C7 0 C8 0 C9 0 0 0 1];
  end
%
%
%
% STEP 1.2:  Compute the poles of H(s)H(-s) and assign those with
%            negative real parts to H(s)
%
  pr = roots(PO);
  k1 = 1;
  for kk=1:2*N
     if(real(pr(kk))<0)
        PP(k1) = pr(kk);
        k1 = k1 + 1;
     end
  end
%
%
%
% STEP TWO:  Frequency scale for desired wp and obtain denominator
%            polynomial coefficient values
%
  fscale = wp;
  PP = PP*fscale;
  DEN = poly(PP);
%
%
%
% STEP THREE:  Normalize the transfer function gain 
%
  w = (1:1000)/400;
  FR = abs(freqs(NUM,DEN,w));
%  
  sc = max(FR);
  NUM = NUM/sc;
%  
  poles = PP.';
  gain = NUM; 
%
%
%  End of PAPOULDE.m
%
