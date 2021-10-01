%
%   File Name:  FI8_1dat.m
%
%   written by L.D. Paarmann
%   June 27, 1998
%
%
%
%   This MATLAB m-file generates the data for the magnitude frequency
%   response plots for transitional filters, as shown in Figure 8.1 in
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
% STEP FIVE:  Compute the magnitude frequency responses
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
  xx = (1:1000)/200;
  w = 0.01 * 10 .^ xx;  
  FRnBU = abs(freqs(NUM,DENBU,w));
  FRnBE = abs(freqs(NUM,DENBE,w));
  FRnTR = abs(freqs(NUM,DENTR,w));
%
  scBU = max(FRnBU);
  scBE = max(FRnBE);
  scTR = max(FRnTR);
%
  FRBU = FRnBU/scBU;
  FRBE = FRnBE/scBE;
  FRTR = FRnTR/scTR;
%  
  DbBU = 20*log10(FRBU);
  DbBE = 20*log10(FRBE);
  DbTR = 20*log10(FRTR);
%
%
%
% STEP SIX:  Plot the results
%
  semilogx(w,DbBU,w,DbBE,w,DbTR)
  axis([0 1000 -100 5])
  xlabel('Radian Frequency (Logarithmic Scale)')
  ylabel('Magnitude in dB')
  grid
  title('The Data for Figure 8.1 (Transitional Filters)')   
%
%
%  End of FI8_1dat.m
%
  
  
