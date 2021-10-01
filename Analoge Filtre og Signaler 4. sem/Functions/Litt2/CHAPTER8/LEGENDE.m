function [poles,gain] = legende(N,wp,Ap,m)
%
%
%   LEGENDE: Determines the poles and the gain term of a Legendre, or
%            first or second associated Legendre, lowpass filter to have
%            a given corner frequency wp and passband corner attenuation
%            Ap for a given order N.
%
%   usage:
%   [poles,gain] = legende(N,wp,Ap,m);
%
%   The function inputs are:
%       N   the filter order (no greater than 10)
%       wp  the desired passband corner frequency
%       Ap  the desired attenuation in dB at the passband corner frequency
%       m   the order of the associated Legendre polynomial (m = 0 is
%           for standard Legendre, m = 1 first associated, m = 2 second
%           associated)
%

%
%
%   Written by L.D. Paarmann, June 26, 1998.
%
%
%   This MATLAB function designs a Legendre lowpass filter
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
%   Y.H. Ku and Meir Drubin, "Network Synthesis using Legendre and
%   Hermite Polynomials," J. Franklin Inst., vol. 273, no. 2,
%   pp. 138-157, February 1962.
%
%
  eps = 10^(Ap/10) - 1;
  NUM = 1;
%  
%
% STEP 1:  Design for the standard Legendre filter
%
  if(m==0)
%
% STEP 1.1:  Obtain the Legendre polynomial coefficient values
%            and the denominator of H(s)H(-s) coefficient values
%
  if(N==1)
     P1 = 1;
     C1 = -eps*P1^2;
     PO = [C1 0 1];
  end
%
  if(N==2)  
     P1 = 3/2;
     P2 = -1/2;
     C1 = eps*P1^2;
     C2 = -2*P1*P2*eps;
     C3 = eps*P2^2;
     PO = [C1 0 C2 0 (1 + C3)];
  end
%
  if(N==3)
     P1 = 5/2;
     P2 = -3/2;
     C1 = -eps*P1^2;
     C2 = 2*P1*P2*eps;
     C3 = -eps*P2^2;
     PO = [C1 0 C2 0 C3 0 1];
  end
%  
  if(N==4)   
     P1 = 35/8;
     P2 = -30/8;
     P3 = 3/8;
     C1 = eps*P1^2;
     C2 = -2*P1*P2*eps;
     C3 = eps*(P2^2 + 2*P1*P3);
     C4 = -2*P2*P3*eps;
     C5 = eps*P3^2;
     PO = [C1 0 C2 0 C3 0 C4 0 (1 + C5)];
  end
%
  if(N==5)  
     P1 = 63/8;
     P2 = -70/8;
     P3 = 15/8;
     C1 = -eps*P1^2;
     C2 = 2*P1*P2*eps;
     C3 = -eps*(P2^2 + 2*P1*P3);
     C4 = 2*P2*P3*eps;
     C5 = -eps*P3^2;
     PO = [C1 0 C2 0 C3 0 C4 0 C5 0 1];
  end
%
  if(N==6)
     P1 = 231/16;
     P2 = -315/16;
     P3 = 105/16;
     P4 = -5/16;
     C1 = eps*P1^2;
     C2 = -2*P1*P2*eps;
     C3 = eps*(P2^2 + 2*P1*P3);
     C4 = -2*(P1*P4 + P2*P3)*eps;
     C5 = eps*(2*P2*P4 + P3^2);
     C6 = -eps*2*P3*P4;
     C7 = P4^2*eps;
     PO = [C1 0 C2 0 C3 0 C4 0 C5 0 C6 0 (1 + C7)];
  end
%
  if(N==7)
     P1 = 429/16;
     P2 = -693/16;
     P3 = 315/16;
     P4 = -35/16;
     C1 = -eps*P1^2;
     C2 = 2*P1*P2*eps;
     C3 = -eps*(P2^2 + 2*P1*P3);
     C4 = 2*(P1*P4 + P2*P3)*eps;
     C5 = -eps*(2*P2*P4 + P3^2);
     C6 = eps*2*P3*P4;
     C7 = -P4^2*eps;
     PO = [C1 0 C2 0 C3 0 C4 0 C5 0 C6 0 C7 0 1];
  end
%
  if(N==8)
     P1 = 6435/128;
     P2 = -12012/128;
     P3 = 6930/128;
     P4 = -1260/128;
     P5 = 35/128;
     C1 = eps*P1^2;
     C2 = -2*P1*P2*eps;
     C3 = eps*(P2^2 + 2*P1*P3);
     C4 = -2*(P1*P4 + P2*P3)*eps;
     C5 = eps*(2*P1*P5 + 2*P2*P4 + P3^2);
     C6 = -eps*2*(P2*P5 + P3*P4);
     C7 = (2*P3*P5 + P4^2)*eps;
     C8 = -eps*2*(P4*P5);
     C9 = P5^2*eps;
     PO = [C1 0 C2 0 C3 0 C4 0 C5 0 C6 0 C7 0 C8 0 (1 + C9)];
  end
%
  if(N==9)
     P1 = 109395/1152;
     P2 = -231660/1152;
     P3 = 162162/1152;
     P4 = -41580/1152;
     P5 = 2835/1152;
     C1 = -eps*P1^2;
     C2 = 2*P1*P2*eps;
     C3 = -eps*(P2^2 + 2*P1*P3);
     C4 = 2*(P1*P4 + P2*P3)*eps;
     C5 = -eps*(2*P1*P5 + 2*P2*P4 + P3^2);
     C6 = eps*2*(P2*P5 + P3*P4);
     C7 = -(2*P3*P5 + P4^2)*eps;
     C8 = eps*2*(P4*P5);
     C9 = -(P5^2)*eps;
     PO = [C1 0 C2 0 C3 0 C4 0 C5 0 C6 0 C7 0 C8 0 C9 0 1];
  end
%
  if(N==10)
     P1 = 46189/256;
     P2 = -109395/256;
     P3 = 90090/256;
     P4 = -30030/256;
     P5 = 3465/256;
     P6 = -63/256;
     C1 = eps*P1^2;
     C2 = -2*P1*P2*eps;
     C3 = eps*(P2^2 + 2*P1*P3);
     C4 = -2*(P1*P4 + P2*P3)*eps;
     C5 = eps*(2*P1*P5 + 2*P2*P4 + P3^2);
     C6 = -eps*2*(P1*P6 + P2*P5 + P3*P4);
     C7 = (2*P2*P6 + 2*P3*P5 + P4^2)*eps;
     C8 = -eps*2*(P3*P6 + P4*P5);
     C9 = (2*P4*P6 + P5^2)*eps;
     C10 = -2*P5*P6*eps;
     C11 = P6^2;
     PO = [C1 0 C2 0 C3 0 C4 0 C5 0 C6 0 C7 0 C8 0 C9 0 C10 0 (1 + C11)];
  end
%
%
%
% STEP 1.2:  Compute the poles of H(s)H(-s) and assign those with
%            negative real parts to H(s), and compute transfer function
%            polynomial values
%
  pr = roots(PO);
  k1 = 1;
  for kk=1:2*N
     if(real(pr(kk))<0)
        PP(k1) = pr(kk);
        k1 = k1 + 1;
     end
  end
  DEN = poly(PP);
%
  end
%
%
%
% STEP 2:  Design for the modified first-associated Legendre filter
%
  if(m==1)
%
% STEP 2.1:  Obtain the modified first-associated Legendre polynomial
%            coefficient values and the denominator of H(s)H(-s)
%            coefficient values
%
  if(N==1)
     P1 = 1;
     C1 = -eps*P1^2;
     PO = [C1 0 1];
  end
%
  if(N==2)  
     P1 = 5/4;
     P2 = -1/4;
     C1 = eps*P1^2;
     C2 = -2*P1*P2*eps;
     C3 = eps*P2^2;
     PO = [C1 0 C2 0 (1 + C3)];
  end
%
  if(N==3)
     P1 = 7/4;
     P2 = -3/4;
     C1 = -eps*P1^2;
     C2 = 2*P1*P2*eps;
     C3 = -eps*P2^2;
     PO = [C1 0 C2 0 C3 0 1];
  end
%  
  if(N==4)   
     P1 = 21/8;
     P2 = -14/8;
     P3 = 1/8;
     C1 = eps*P1^2;
     C2 = -2*P1*P2*eps;
     C3 = eps*(P2^2 + 2*P1*P3);
     C4 = -2*P2*P3*eps;
     C5 = eps*P3^2;
     PO = [C1 0 C2 0 C3 0 C4 0 (1 + C5)];
  end
%
  if(N==5)  
     P1 = 33/8;
     P2 = -30/8;
     P3 = 5/8;
     C1 = -eps*P1^2;
     C2 = 2*P1*P2*eps;
     C3 = -eps*(P2^2 + 2*P1*P3);
     C4 = 2*P2*P3*eps;
     C5 = -eps*P3^2;
     PO = [C1 0 C2 0 C3 0 C4 0 C5 0 1];
  end
%
  if(N==6)
     P1 = 429/64;
     P2 = -495/64;
     P3 = 135/64;
     P4 = -5/64;
     C1 = eps*P1^2;
     C2 = -2*P1*P2*eps;
     C3 = eps*(P2^2 + 2*P1*P3);
     C4 = -2*(P1*P4 + P2*P3)*eps;
     C5 = eps*(2*P2*P4 + P3^2);
     C6 = -eps*2*P3*P4;
     C7 = P4^2*eps;
     PO = [C1 0 C2 0 C3 0 C4 0 C5 0 C6 0 (1 + C7)];
  end
%
  if(N==7)
     P1 = 715/64;
     P2 = -1001/64;
     P3 = 385/64;
     P4 = -35/64;
     C1 = -eps*P1^2;
     C2 = 2*P1*P2*eps;
     C3 = -eps*(P2^2 + 2*P1*P3);
     C4 = 2*(P1*P4 + P2*P3)*eps;
     C5 = -eps*(2*P2*P4 + P3^2);
     C6 = eps*2*P3*P4;
     C7 = -P4^2*eps;
     PO = [C1 0 C2 0 C3 0 C4 0 C5 0 C6 0 C7 0 1];
  end
%
  if(N==8)
     P1 = 196911/9368;
     P2 = -324324/9368;
     P3 = 161162/9368;
     P4 = -24948/9368;
     P5 = 567/9368;
     C1 = eps*P1^2;
     C2 = -2*P1*P2*eps;
     C3 = eps*(P2^2 + 2*P1*P3);
     C4 = -2*(P1*P4 + P2*P3)*eps;
     C5 = eps*(2*P1*P5 + 2*P2*P4 + P3^2);
     C6 = -eps*2*(P2*P5 + P3*P4);
     C7 = (2*P3*P5 + P4^2)*eps;
     C8 = -eps*2*(P4*P5);
     C9 = P5^2*eps;
     PO = [C1 0 C2 0 C3 0 C4 0 C5 0 C6 0 C7 0 C8 0 (1 + C9)];
  end
%
  if(N==9)
     P1 = 46189/1408;
     P2 = -87516/1408;
     P3 = 54054/1408;
     P4 = -12012/1408;
     P5 = 693/1408;
     C1 = -eps*P1^2;
     C2 = 2*P1*P2*eps;
     C3 = -eps*(P2^2 + 2*P1*P3);
     C4 = 2*(P1*P4 + P2*P3)*eps;
     C5 = -eps*(2*P1*P5 + 2*P2*P4 + P3^2);
     C6 = eps*2*(P2*P5 + P3*P4);
     C7 = -(2*P3*P5 + P4^2)*eps;
     C8 = eps*2*(P4*P5);
     C9 = -(P5^2)*eps;
     PO = [C1 0 C2 0 C3 0 C4 0 C5 0 C6 0 C7 0 C8 0 C9 0 1];
  end
%
  if(N==10)
     P1 = 29393/512;
     P2 = -62985/512;
     P3 = 46410/512;
     P4 = -13650/512;
     P5 = 1365/512;
     P6 = -21/512;
     C1 = eps*P1^2;
     C2 = -2*P1*P2*eps;
     C3 = eps*(P2^2 + 2*P1*P3);
     C4 = -2*(P1*P4 + P2*P3)*eps;
     C5 = eps*(2*P1*P5 + 2*P2*P4 + P3^2);
     C6 = -eps*2*(P1*P6 + P2*P5 + P3*P4);
     C7 = (2*P2*P6 + 2*P3*P5 + P4^2)*eps;
     C8 = -eps*2*(P3*P6 + P4*P5);
     C9 = (2*P4*P6 + P5^2)*eps;
     C10 = -2*P5*P6*eps;
     C11 = P6^2;
     PO = [C1 0 C2 0 C3 0 C4 0 C5 0 C6 0 C7 0 C8 0 C9 0 C10 0 (1 + C11)];
  end
% 
%
%
% STEP 2.2:  Compute the poles of H(s)H(-s) and assign those with
%            negative real parts to H(s), and compute transfer function
%            polynomial values
%
  pr = roots(PO);
  k1 = 1;
  for kk=1:2*N
     if(real(pr(kk))<0)
        PP(k1) = pr(kk);
        k1 = k1 + 1;
     end
  end
  DEN = poly(PP);
%   
  end
%
%
%
% STEP 3:  Design for the modified second-associated Legendre filter
%
  if(m==2)
%
% STEP 3.1:  Obtain the modified second-associated Legendre polynomial
%            coefficient values and the denominator of H(s)H(-s)
%            coefficient values
%
  if(N==1)
     P1 = 1;
     C1 = -eps*P1^2;
     PO = [C1 0 1];
  end
%
  if(N==2)  
     P1 = 21/18;
     P2 = -3/18;
     C1 = eps*P1^2;
     C2 = -2*P1*P2*eps;
     C3 = eps*P2^2;
     PO = [C1 0 C2 0 (1 + C3)];
  end
%
  if(N==3)
     P1 = 3/2;
     P2 = -1/2;
     C1 = -eps*P1^2;
     C2 = 2*P1*P2*eps;
     C3 = -eps*P2^2;
     PO = [C1 0 C2 0 C3 0 1];
  end
%  
  if(N==4)   
     P1 = 33/16;
     P2 = -18/16;
     P3 = 1/16;
     C1 = eps*P1^2;
     C2 = -2*P1*P2*eps;
     C3 = eps*(P2^2 + 2*P1*P3);
     C4 = -2*P2*P3*eps;
     C5 = eps*P3^2;
     PO = [C1 0 C2 0 C3 0 C4 0 (1 + C5)];
  end
%
  if(N==5)  
     P1 = 143/48;
     P2 = -110/48;
     P3 = 15/48;
     C1 = -eps*P1^2;
     C2 = 2*P1*P2*eps;
     C3 = -eps*(P2^2 + 2*P1*P3);
     C4 = 2*P2*P3*eps;
     C5 = -eps*P3^2;
     PO = [C1 0 C2 0 C3 0 C4 0 C5 0 1];
  end
%
  if(N==6)
     P1 = 143/32;
     P2 = -143/32;
     P3 = 33/32;
     P4 = -1/32;
     C1 = eps*P1^2;
     C2 = -2*P1*P2*eps;
     C3 = eps*(P2^2 + 2*P1*P3);
     C4 = -2*(P1*P4 + P2*P3)*eps;
     C5 = eps*(2*P2*P4 + P3^2);
     C6 = -eps*2*P3*P4;
     C7 = P4^2*eps;
     PO = [C1 0 C2 0 C3 0 C4 0 C5 0 C6 0 (1 + C7)];
  end
%
  if(N==7)
     P1 = 196911/28012;
     P2 = -243243/28012;
     P3 = 80581/28012;
     P4 = -6237/28012;
     C1 = -eps*P1^2;
     C2 = 2*P1*P2*eps;
     C3 = -eps*(P2^2 + 2*P1*P3);
     C4 = 2*(P1*P4 + P2*P3)*eps;
     C5 = -eps*(2*P2*P4 + P3^2);
     C6 = eps*2*P3*P4;
     C7 = -P4^2*eps;
     PO = [C1 0 C2 0 C3 0 C4 0 C5 0 C6 0 C7 0 1];
  end
%
  if(N==8)
     P1 = 4199/384;
     P2 = -6188/384;
     P3 = 2730/384;
     P4 = -364/384;
     P5 = 7/384;
     C1 = eps*P1^2;
     C2 = -2*P1*P2*eps;
     C3 = eps*(P2^2 + 2*P1*P3);
     C4 = -2*(P1*P4 + P2*P3)*eps;
     C5 = eps*(2*P1*P5 + 2*P2*P4 + P3^2);
     C6 = -eps*2*(P2*P5 + P3*P4);
     C7 = (2*P3*P5 + P4^2)*eps;
     C8 = -eps*2*(P4*P5);
     C9 = P5^2*eps;
     PO = [C1 0 C2 0 C3 0 C4 0 C5 0 C6 0 C7 0 C8 0 (1 + C9)];
  end
%
  if(N==9)
     P1 = 2261/128;
     P2 = -3876/128;
     P3 = 2142/128;
     P4 = -420/128;
     P5 = 21/128;
     C1 = -eps*P1^2;
     C2 = 2*P1*P2*eps;
     C3 = -eps*(P2^2 + 2*P1*P3);
     C4 = 2*(P1*P4 + P2*P3)*eps;
     C5 = -eps*(2*P1*P5 + 2*P2*P4 + P3^2);
     C6 = eps*2*(P2*P5 + P3*P4);
     C7 = -(2*P3*P5 + P4^2)*eps;
     C8 = eps*2*(P4*P5);
     C9 = -(P5^2)*eps;
     PO = [C1 0 C2 0 C3 0 C4 0 C5 0 C6 0 C7 0 C8 0 C9 0 1];
  end
%
  if(N==10)
     P1 = 7429/256;
     P2 = -14535/256;
     P3 = 9690/256;
     P4 = -2550/256;
     P5 = 225/256;
     P6 = -3/256;
     C1 = eps*P1^2;
     C2 = -2*P1*P2*eps;
     C3 = eps*(P2^2 + 2*P1*P3);
     C4 = -2*(P1*P4 + P2*P3)*eps;
     C5 = eps*(2*P1*P5 + 2*P2*P4 + P3^2);
     C6 = -eps*2*(P1*P6 + P2*P5 + P3*P4);
     C7 = (2*P2*P6 + 2*P3*P5 + P4^2)*eps;
     C8 = -eps*2*(P3*P6 + P4*P5);
     C9 = (2*P4*P6 + P5^2)*eps;
     C10 = -2*P5*P6*eps;
     C11 = P6^2;
     PO = [C1 0 C2 0 C3 0 C4 0 C5 0 C6 0 C7 0 C8 0 C9 0 C10 0 (1 + C11)];
  end
%
%
%
% STEP 3.2:  Compute the poles of H(s)H(-s) and assign those with
%            negative real parts to H(s), and compute transfer function
%            polynomial values
%
  pr = roots(PO);
  k1 = 1;
  for kk=1:2*N
     if(real(pr(kk))<0)
        PP(k1) = pr(kk);
        k1 = k1 + 1;
     end
  end
  DEN = poly(PP);
%
  end
%
%
%
% STEP 4:  Calculate the magnitude frequency response
%
  xx = 0:7999;
  w = xx/1000;
  FRM = abs(freqs(NUM,DEN,w));
  scc = max(FRM);
  NUM = NUM/scc;
%
%
%
% STEP 5:  Frequency scale
%
  fscale = wp;
  poles = PP.'*fscale;
  gain = NUM*fscale^N;
%
%
%
%
%  End of LEGENDE
%


  
  


