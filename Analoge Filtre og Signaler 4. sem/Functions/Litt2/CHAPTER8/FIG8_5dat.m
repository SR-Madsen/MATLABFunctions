%
%   File Name:  FI8_5dat.m
%
%   written by L.D. Paarmann
%   June 27, 1998
%
%
%
%   This MATLAB m-file generates the data for the group delay plots
%   for transitional filters (Figure 8.5) in
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
% STEP ONE:  Specifiy the transitional parameter
%
  m = 0.4;
%
%
%
% STEP TWO:  Obtain the Butterworth and Bessel poles
%
  [zBU,pBUi,kBU] = buttap(10); 
  [pBE,kBE] = besselde(10,1,10*log10(2));
%  
%
%
% STEP THREE:  Rearrange Butterworth poles
%
  pBU(1) = pBUi(1);
  pBU(2) = pBUi(10);
  pBU(3) = pBUi(2);
  pBU(4) = pBUi(9);
  pBU(5) = pBUi(3);
  pBU(6) = pBUi(8);
  pBU(7) = pBUi(4);
  pBU(8) = pBUi(7);
  pBU(9) = pBUi(5);
  pBU(10) = pBUi(6);
%
%
%
% STEP FOUR:  Modifiy the poles
% 
  for kk=1:10
     pmodmag = (abs(pBE(kk))^m) * abs(pBU(kk))^(1-m);
     pmodarg = angle(pBU(kk)) - m*(angle(pBU(kk)) - angle(pBE(kk)));     
     pTR(kk) = pmodmag*exp(sqrt(-1)*pmodarg);
  end
%  
%
%
% STEP FIVE:  Scale the poles for an wc of unity
%
  NUM = 1;
  DENBU = poly(pBU);
  DENBE = poly(pBE);
  DENTR = poly(pTR);
%
  w = (1:1000)/400;
  FRBU = abs(freqs(NUM,DENBU,w));
  FRBE = abs(freqs(NUM,DENBE,w));
  FRTR = abs(freqs(NUM,DENTR,w));
%  
  scBU = max(FRBU);
  scBE = max(FRBE);
  scTR = max(FRTR);
%  
  FRBU = FRBU/scBU;
  FRBE = FRBE/scBE;
  FRTR = FRTR/scTR;
%  
  mag = 1/sqrt(2);
  mg = mag;
  for kk=1:1000
     if(FRBU(kk)<mg)
        wBU = w(kk);
        mg = 0;
     end
  end
  mg = mag;
  for kk=1:1000
     if(FRBE(kk)<mg)
        wBE = w(kk);
        mg = 0;
     end
  end
  mg = mag;
  for kk=1:1000
     if(FRTR(kk)<mg)
        wTR = w(kk);
        mg = 0;
     end
  end
%  
  pBU = pBU/wBU;
  pBE = pBE/wBE;
  pTR = pTR/wTR;
%  
  DENBU = poly(pBU);
  DENBE = poly(pBE);
  DENTR = poly(pTR);
%    
%
%
% STEP SIX:  Compute the group delay responses
%
   w = 0.005:0.005:2.0;
  PHR1 = unwrap(angle(freqs(NUM,DENBU,w)));
  PHR2 = unwrap(angle(freqs(NUM,DENBE,w)));
  PHR3 = unwrap(angle(freqs(NUM,DENTR,w)));
%
  PR1A = [PHR1 0];
  PR1B = [0 PHR1];
  PR2A = [PHR2 0];
  PR2B = [0 PHR2];
  PR3A = [PHR3 0];
  PR3B = [0 PHR3];
%
  GD1 = (PR1B - PR1A)*200;
  GD1 = GD1(1:400);
  GD2 = (PR2B - PR2A)*200;
  GD2 = GD2(1:400);
  GD3 = (PR3B - PR3A)*200;
  GD3 = GD3(1:400);
%
%
%
% STEP SEVEN:  Plot the results
%
  plot(w,GD1,w,GD2,w,GD3)
  axis([0 2 0 15])  
  xlabel('Radian Frequency')
  ylabel('Group Delay in Seconds')
  grid
  title('The Data for Figure 8.5 (Transitional Filters)')
%
%
%
%  End of FI8_5dat.m
%
  
  
