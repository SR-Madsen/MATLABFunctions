%
%   File Name:  EXAMP6_6.m
%
%   written by L.D. Paarmann
%   April 27, 1999
%
%   This MATLAB m-file computes Filter Selectivity and 
%   Shaping Factor for an elliptic lowpass filter for the
%   following parameters:
%      N = 3, 4, ..., 10
%      a = 3 dB
%      b = 80 dB
%      Ap = 1 dB
%      As = 80 dB
%      wc = 1
%
%
%
%   This algorithm computes the data for Example 6.6 in
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
a = -10*log10(0.5);
b = 80;
Ap = 1;
As = 80;
epsp = sqrt(10^(Ap/10) - 1);
epss = 1/sqrt(10^(As/10) - 1);
tau1 = epsp*epss;
mod1 = tau1^2;
[X1,E] = ellipke(mod1);
%
%  The main processing loop:
for N=3:10
   %  Initially assume a normalized wp:
   ws = ellipws(N,Ap,As,1);
   wc = ellipwc(N,Ap,As,1,ws);
   tau2 = 1/ws;
   [X2,E] = ellipke(tau2^2);
   q = 0;
   if(2*round(N/2)==N)
      q = 1;
   end
   %  Scale for wc = 1:
   wp = 1/wc;
   ws = ws/wc;
   wc = 1;
   %  Compute Filter Selectivity:
   FS(N-2) = ellipfs(N,Ap,As,wp,wc,ws);
   %  Compute the Shaping Factor:
   SF(N-2) = ellipsf(N,a,b,Ap,As,wp,ws);
end
%
%
% End of Example 6.6
%