function [poles,gain] = ultrade(N,wp,Ap,alpha)
%
%
%   ULTRADE: Determines the poles and the gain term of an Ultraspherical
%            lowpass filter to have a given corner frequency wp and 
%            passband corner attenuation Ap for a given order N and
%            parameter alpha.
%
%   usage:
%   [poles,gain] = ultrade(N,wp,Ap,alpha);
%
%   The function inputs are:
%        N  the filter order (no greater than 10)
%       wp  the desired passband corner frequency
%       Ap  the desired attenuation in dB at the passband corner frequency
%    alpha  the parameter that determines the character of the ultraspherical
%           filter:  if alpha = -0.5 the filter will be a Chebyshev Type I,
%           if alpha = m (m = 0, 1, 2, 3, ...) the filter will be a  
%           modified mth-associated Legendre, if alpha = infinity the
%           filter will be Butterworth, etc.
%

%
%   Written by L.D. Paarmann, June 29, 1998.
%
%
%   This MATLAB function designs an ultraspherical lowpass filter
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
%   D.E. Johnson and J.R. Johnson, "Low-Pass Filters Using Ultraspherical
%   Polynomials," IEEE Trans. Circuit Theory, vol. CT-13, no. 4,
%   pp. 364-369, December 1966.
%
%
  eps = 10^(Ap/10) - 1;
  NUM = 1;
%  
%
% STEP 1:  Design the ultraspherical filter for a normalized wp of unity
%
% STEP 1.1:  Specify the coefficient values for the 
%            denominator of H(s)H(-s)
% 
% The polynomial coefficient values for Fn^alpha(w), for orders 1
% through 6, are taken from Table I of Johnson and Johnson (1966)
%
  if(N==1)
     C1 = -eps; 
     PO = [C1 0 1];
  end  
%
  if(N==2)  
     gam1 = 2*alpha + 3;
     gam2 = -1;
     beta = 2*alpha + 2;
     C1 = eps*(gam1/beta)^2;
     C2 = -eps*(2*gam1*gam2/beta^2);
     C3 = eps*(gam2/beta)^2;
     PO = [C1 0 C2 0 (1 + C3)];       
  end
%
  if(N==3)
     gam1 = 2*alpha + 5;
     gam2 = -3;
     beta = 2*alpha + 2;
     C1 = -eps*(gam1/beta)^2;
     C2 = eps*2*gam1*gam2/beta^2;
     C3 = -eps*(gam2/beta)^2;
     PO = [C1 0 C2 0 C3 0 1];        
  end
%  
  if(N==4)   
     gam1 = 4*alpha^2 + 24*alpha + 35;
     gam2 = -(12*alpha + 30);
     gam3 = 3;
     beta = 4*alpha^2 + 12*alpha + 8;
     C1 = eps*(gam1/beta)^2;
     C2 = -eps*2*gam1*gam2/beta^2;
     C3 = eps*(2*gam1*gam3 + gam2^2)/beta^2;
     C4 = -eps*2*gam2*gam3/beta^2;
     C5 = eps*(gam3/beta)^2;
     PO = [C1 0 C2 0 C3 0 C4 0 (1 + C5)];
  end
%
  if(N==5)  
     gam1 = 8*alpha^3 + 84*alpha^2 + 286*alpha + 315;
     gam2 = -(40*alpha^2 + 240*alpha + 350);
     gam3 = 30*alpha + 75;
     beta = 8*alpha^3 + 44*alpha^2 + 76*alpha + 40;
     C1 = -eps*(gam1/beta)^2;
     C2 = eps*2*gam1*gam2/beta^2;
     C3 = -eps*(2*gam1*gam3 + gam2^2)/beta^2;
     C4 = eps*2*gam2*gam3/beta^2;
     C5 = -eps*(gam3/beta)^2;
     PO = [C1 0 C2 0 C3 0 C4 0 C5 0 1]; 
  end
%
  if(N==6)
     gam1 = 16*alpha^4 + 256*alpha^3 + 1496*alpha^2 + 3776*alpha + 3465;
     gam2 = -(120*alpha^3 + 1260*alpha^2 + 4290*alpha + 4725);
     gam3 = 180*alpha^2 + 1080*alpha + 1575;
     gam4 = -30*alpha - 75;
     beta = 16*alpha^4 + 136*alpha^3 + 416*alpha^2 + 536*alpha + 240;
     C1 = eps*(gam1/beta)^2;
     C2 = -eps*2*gam1*gam2/beta^2;
     C3 = eps*(2*gam1*gam3 + gam2^2)/beta^2;
     C4 = -eps*2*(gam1*gam4 + gam2*gam3)/beta^2;
     C5 = eps*(2*gam2*gam4 + gam3^2)/beta^2;
     C6 = -eps*2*gam3*gam4/beta^2;
     C7 = eps*(gam4/beta)^2;
     PO = [C1 0 C2 0 C3 0 C4 0 C5 0 C6 0 (1 + C7)];
  end
%
% The polynomial coefficient values for Fn^alpha(w), for orders 7
% through 10, are from equation (3) of Johnson and Johnson (1966)
% 
  if(N==7)
%    Summation values 
     Nk1 = -7;
     al2k1 = 2*alpha + 8;
     k1fact = 1;
     alk1 = 1 + alpha;
     twop1 = 2;
     KK1 = Nk1*al2k1/(k1fact*alk1*twop1);
%  
     Nk2 = -6*Nk1;
     al2k2 = al2k1*(2*alpha + 9);
     k2fact = 2*k1fact;
     alk2 = alk1*(2 + alpha);
     twop2 = 2^2;
     KK2 = Nk2*al2k2/(k2fact*alk2*twop2);
%  
     Nk3 = -5*Nk2;
     al2k3 = al2k2*(2*alpha + 10);
     k3fact = 3*k2fact;
     alk3 = alk2*(3 + alpha);
     twop3 = 2^3;
     KK3 = Nk3*al2k3/(k3fact*alk3*twop3);
%  
     Nk4 = -4*Nk3;
     al2k4 = al2k3*(2*alpha + 11);
     k4fact = 4*k3fact;
     alk4 = alk3*(4 + alpha);
     twop4 = 2^4;
     KK4 = Nk4*al2k4/(k4fact*alk4*twop4);
%  
     Nk5 = -3*Nk4;
     al2k5 = al2k4*(2*alpha + 12);
     k5fact = 5*k4fact;
     alk5 = alk4*(5 + alpha);
     twop5 = 2^5;
     KK5 = Nk5*al2k5/(k5fact*alk5*twop5);
%  
     Nk6 = -2*Nk5;
     al2k6 = al2k5*(2*alpha + 13);
     k6fact = 6*k5fact;
     alk6 = alk5*(6 + alpha);
     twop6 = 2^6;
     KK6 = Nk6*al2k6/(k6fact*alk6*twop6);
%
     Nk7 = -1*Nk6;
     al2k7 = al2k6*(2*alpha + 14);
     k7fact = 7*k6fact;
     alk7 = alk6*(7 + alpha);
     twop7 = 2^7;
     KK7 = Nk7*al2k7/(k7fact*alk7*twop7);
%
%    The Fn^alpha(w) polynomial coefficients
     P1 = -KK7;
     P2 = -21*KK7 - 6*KK6 - KK5;
     P3 = -35*KK7 - 20*KK6 - 10*KK5 - 4*KK4 - KK3;
     P4 = -7*KK7 - 6*KK6 - 5*KK5 - 4*KK4 - 3*KK3 - 2*KK2 - KK1;
%
%    H(s)H(-s) denominator coefficients  
     C1 = -eps*P1^2;
     C2 = eps*2*P1*P2;
     C3 = -eps*(2*P1*P3 + P2^2);
     C4 = eps*2*(P1*P4 + P2*P3);
     C5 = -eps*(2*P2*P4 + P3^2);
     C6 = eps*2*P3*P4;
     C7 = -eps*P4^2;
     PO = [C1 0 C2 0 C3 0 C4 0 C5 0 C6 0 C7 0 1];
  end
%
  if(N==8)
%    Summation values 
     KK0 = 1;
%
     Nk1 = -8;
     al2k1 = 2*alpha + 9;
     k1fact = 1;
     alk1 = 1 + alpha;
     twop1 = 2;
     KK1 = Nk1*al2k1/(k1fact*alk1*twop1);
%  
     Nk2 = -7*Nk1;
     al2k2 = al2k1*(2*alpha + 10);
     k2fact = 2*k1fact;
     alk2 = alk1*(2 + alpha);
     twop2 = 2^2;
     KK2 = Nk2*al2k2/(k2fact*alk2*twop2);
%  
     Nk3 = -6*Nk2;
     al2k3 = al2k2*(2*alpha + 11);
     k3fact = 3*k2fact;
     alk3 = alk2*(3 + alpha);
     twop3 = 2^3;
     KK3 = Nk3*al2k3/(k3fact*alk3*twop3);
%  
     Nk4 = -5*Nk3;
     al2k4 = al2k3*(2*alpha + 12);
     k4fact = 4*k3fact;
     alk4 = alk3*(4 + alpha);
     twop4 = 2^4;
     KK4 = Nk4*al2k4/(k4fact*alk4*twop4);
%  
     Nk5 = -4*Nk4;
     al2k5 = al2k4*(2*alpha + 13);
     k5fact = 5*k4fact;
     alk5 = alk4*(5 + alpha);
     twop5 = 2^5;
     KK5 = Nk5*al2k5/(k5fact*alk5*twop5);
%  
     Nk6 = -3*Nk5;
     al2k6 = al2k5*(2*alpha + 14);
     k6fact = 6*k5fact;
     alk6 = alk5*(6 + alpha);
     twop6 = 2^6;
     KK6 = Nk6*al2k6/(k6fact*alk6*twop6);
%
     Nk7 = -2*Nk6;
     al2k7 = al2k6*(2*alpha + 15);
     k7fact = 7*k6fact;
     alk7 = alk6*(7 + alpha);
     twop7 = 2^7;
     KK7 = Nk7*al2k7/(k7fact*alk7*twop7);
%
     Nk8 = -1*Nk7;
     al2k8 = al2k7*(2*alpha + 16);
     k8fact = 8*k7fact;
     alk8 = alk7*(8 + alpha);
     twop8 = 2^8;
     KK8 = Nk8*al2k8/(k8fact*alk8*twop8);
%
%    The Fn^alpha(w) polynomial coefficients
     P1 = KK8;
     P2 = 28*KK8 + 7*KK7 + KK6;
     P3 = 70*KK8 + 35*KK7 + 15*KK6 + 5*KK5 + KK4;
     P4 = 28*KK8 + 21*KK7 + 15*KK6 + 10*KK5 + 6*KK4 + 3*KK3 + KK2;
     P5 = KK8 + KK7 + KK6 + KK5 + KK4 + KK3 + KK2 + KK1 + KK0;
%
%    H(s)H(-s) denominator coefficients  
     C1 = eps*P1^2;
     C2 = -eps*2*P1*P2;
     C3 = eps*(2*P1*P3 + P2^2);
     C4 = -eps*2*(P1*P4 + P2*P3);
     C5 = eps*(2*P1*P5 + 2*P2*P4 + P3^2);
     C6 = -eps*2*(P2*P5 + P3*P4);
     C7 = eps*(2*P3*P5 + P4^2);
     C8 = -eps*2*P4*P5;
     C9 = eps*P5^2;
     PO = [C1 0 C2 0 C3 0 C4 0 C5 0 C6 0 C7 0 C8 0 (1 + C9)];
  end
%
  if(N==9)
%    Summation values 
     Nk1 = -9;
     al2k1 = 2*alpha + 10;
     k1fact = 1;
     alk1 = 1 + alpha;
     twop1 = 2;
     KK1 = Nk1*al2k1/(k1fact*alk1*twop1);
%  
     Nk2 = -8*Nk1;
     al2k2 = al2k1*(2*alpha + 11);
     k2fact = 2*k1fact;
     alk2 = alk1*(2 + alpha);
     twop2 = 2^2;
     KK2 = Nk2*al2k2/(k2fact*alk2*twop2);
%  
     Nk3 = -7*Nk2;
     al2k3 = al2k2*(2*alpha + 12);
     k3fact = 3*k2fact;
     alk3 = alk2*(3 + alpha);
     twop3 = 2^3;
     KK3 = Nk3*al2k3/(k3fact*alk3*twop3);
%  
     Nk4 = -6*Nk3;
     al2k4 = al2k3*(2*alpha + 13);
     k4fact = 4*k3fact;
     alk4 = alk3*(4 + alpha);
     twop4 = 2^4;
     KK4 = Nk4*al2k4/(k4fact*alk4*twop4);
%  
     Nk5 = -5*Nk4;
     al2k5 = al2k4*(2*alpha + 14);
     k5fact = 5*k4fact;
     alk5 = alk4*(5 + alpha);
     twop5 = 2^5;
     KK5 = Nk5*al2k5/(k5fact*alk5*twop5);
%  
     Nk6 = -4*Nk5;
     al2k6 = al2k5*(2*alpha + 15);
     k6fact = 6*k5fact;
     alk6 = alk5*(6 + alpha);
     twop6 = 2^6;
     KK6 = Nk6*al2k6/(k6fact*alk6*twop6);
%
     Nk7 = -3*Nk6;
     al2k7 = al2k6*(2*alpha + 16);
     k7fact = 7*k6fact;
     alk7 = alk6*(7 + alpha);
     twop7 = 2^7;
     KK7 = Nk7*al2k7/(k7fact*alk7*twop7);
%
     Nk8 = -2*Nk7;
     al2k8 = al2k7*(2*alpha + 17);
     k8fact = 8*k7fact;
     alk8 = alk7*(8 + alpha);
     twop8 = 2^8;
     KK8 = Nk8*al2k8/(k8fact*alk8*twop8);
%
     Nk9 = -1*Nk8;
     al2k9 = al2k8*(2*alpha + 18);
     k9fact = 9*k8fact;
     alk9 = alk8*(9 + alpha);
     twop9 = 2^9;
     KK9 = Nk9*al2k9/(k9fact*alk9*twop9);
%
%    The Fn^alpha(w) polynomial coefficients
     P1 = -KK9;
     P2 = -36*KK9 - 8*KK8 - KK7;
     P3 = -126*KK9 - 56*KK8 - 21*KK7 - 6*KK6 - KK5;
     P4 = -84*KK9 - 56*KK8 - 35*KK7 - 20*KK6 - 10*KK5 - 4*KK4 - KK3;
     P5 = -9*KK9 - 8*KK8 - 7*KK7 - 6*KK6 - 5*KK5 - 4*KK4 - 3*KK3 ...
           - 2*KK2 - KK1;
%
%    H(s)H(-s) denominator coefficients  
     C1 = -eps*P1^2;
     C2 = eps*2*P1*P2;
     C3 = -eps*(2*P1*P3 + P2^2);
     C4 = eps*2*(P1*P4 + P2*P3);
     C5 = -eps*(2*P1*P5 + 2*P2*P4 + P3^2);
     C6 = eps*2*(P2*P5 + P3*P4);
     C7 = -eps*(2*P3*P5 + P4^2);
     C8 = eps*2*P4*P5;
     C9 = -eps*P5^2;
     PO = [C1 0 C2 0 C3 0 C4 0 C5 0 C6 0 C7 0 C8 0 C9 0 1]; 
  end
%
  if(N==10)
%    Summation values 
     KK0 = 1;
%
     Nk1 = -10;
     al2k1 = 2*alpha + 11;
     k1fact = 1;
     alk1 = 1 + alpha;
     twop1 = 2;
     KK1 = Nk1*al2k1/(k1fact*alk1*twop1);
%  
     Nk2 = -9*Nk1;
     al2k2 = al2k1*(2*alpha + 12);
     k2fact = 2*k1fact;
     alk2 = alk1*(2 + alpha);
     twop2 = 2^2;
     KK2 = Nk2*al2k2/(k2fact*alk2*twop2);
%  
     Nk3 = -8*Nk2;
     al2k3 = al2k2*(2*alpha + 13);
     k3fact = 3*k2fact;
     alk3 = alk2*(3 + alpha);
     twop3 = 2^3;
     KK3 = Nk3*al2k3/(k3fact*alk3*twop3);
%  
     Nk4 = -7*Nk3;
     al2k4 = al2k3*(2*alpha + 14);
     k4fact = 4*k3fact;
     alk4 = alk3*(4 + alpha);
     twop4 = 2^4;
     KK4 = Nk4*al2k4/(k4fact*alk4*twop4);
%  
     Nk5 = -6*Nk4;
     al2k5 = al2k4*(2*alpha + 15);
     k5fact = 5*k4fact;
     alk5 = alk4*(5 + alpha);
     twop5 = 2^5;
     KK5 = Nk5*al2k5/(k5fact*alk5*twop5);
%  
     Nk6 = -5*Nk5;
     al2k6 = al2k5*(2*alpha + 16);
     k6fact = 6*k5fact;
     alk6 = alk5*(6 + alpha);
     twop6 = 2^6;
     KK6 = Nk6*al2k6/(k6fact*alk6*twop6);
%
     Nk7 = -4*Nk6;
     al2k7 = al2k6*(2*alpha + 17);
     k7fact = 7*k6fact;
     alk7 = alk6*(7 + alpha);
     twop7 = 2^7;
     KK7 = Nk7*al2k7/(k7fact*alk7*twop7);
%
     Nk8 = -3*Nk7;
     al2k8 = al2k7*(2*alpha + 18);
     k8fact = 8*k7fact;
     alk8 = alk7*(8 + alpha);
     twop8 = 2^8;
     KK8 = Nk8*al2k8/(k8fact*alk8*twop8);
%
     Nk9 = -2*Nk8;
     al2k9 = al2k8*(2*alpha + 19);
     k9fact = 9*k8fact;
     alk9 = alk8*(9 + alpha);
     twop9 = 2^9;
     KK9 = Nk9*al2k9/(k9fact*alk9*twop9);
%
     Nk10 = -1*Nk9;
     al2k10 = al2k9*(2*alpha + 20);
     k10fact = 10*k9fact;
     alk10 = alk9*(10 + alpha);
     twop10 = 2^10;
     KK10 = Nk10*al2k10/(k10fact*alk10*twop10);
%
%    The Fn^alpha(w) polynomial coefficients
     P1 = KK10;
     P2 = 45*KK10 + 9*KK9 + KK8;
     P3 = 210*KK10 + 84*KK9 + 28*KK8 + 7*KK7 + KK6;
     P4 = 210*KK10 + 126*KK9 + 70*KK8 + 35*KK7 + 15*KK6 + 5*KK5 + KK4;
     P5 = 45*KK10 + 36*KK9 + 28*KK8 + 21*KK7 + 15*KK6 + 10*KK5 + 6*KK4 ...
          + 3*KK3 + KK2;
     P6 = KK10 + KK9 + KK8 + KK7 + KK6 + KK5 + KK4 + KK3 + KK2 + KK1 + KK0;
%
%    H(s)H(-s) denominator coefficients  
     C1 = eps*P1^2;
     C2 = -eps*2*P1*P2;
     C3 = eps*(2*P1*P3 + P2^2);
     C4 = -eps*2*(P1*P4 + P2*P3);
     C5 = eps*(2*P1*P5 + 2*P2*P4 + P3^2);
     C6 = -eps*2*(P1*P6 + P2*P5 + P3*P4);
     C7 = eps*(2*P2*P6 + 2*P3*P5 + P4^2);
     C8 = -eps*2*(P3*P6 + P4*P5);
     C9 = eps*(2*P4*P6 + P5^2);;
     C10 = -eps*2*P5*P6;
     C11 = eps*P6^2;
     PO = [C1 0 C2 0 C3 0 C4 0 C5 0 C6 0 C7 0 C8 0 C9 0 C10 0 (1 + C11)];
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
%  End of ULTRADE.m
%
  
  
