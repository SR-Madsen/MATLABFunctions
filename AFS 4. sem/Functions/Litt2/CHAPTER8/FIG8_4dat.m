%
%   File Name:  FI8_4dat.m
%
%   written by L.D. Paarmann
%   June 27, 1998
%
%
%
%   This MATLAB m-file generates the data for the phase delay plots
%   for transitional filters (Figure 8.4) in
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
% STEP SIX:  Compute the phase delay responses
%
  w = (1:1:999)/200;  
  PDBU = -unwrap(angle(freqs(NUM,DENBU,w)))./w;
  PDBE = -unwrap(angle(freqs(NUM,DENBE,w)))./w;
  PDTR = -unwrap(angle(freqs(NUM,DENTR,w)))./w;
%
%
%
% STEP SEVEN:  Plot the results
%
  plot(w,PDBU,w,PDBE,w,PDTR)
  xlabel('Radian Frequency')
  ylabel('Phase Delay in Seconds')
  grid
  title('The Data for Figure 8.4 (Transitional Filters)')   
%
%
%
%  End of FI8_4dat.m
%
  
  
