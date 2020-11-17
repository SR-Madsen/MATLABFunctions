function sfeval = besselsf(N,a,b)
%
%  BESSELSF:  Determines the Shaping Factor for a lowpass
%             Bessel filter.
%
%  usage:
%  sfeval = besselsf(N,a,b);
%
%  The function inputs are:
%     N   (the order of the Bessel filter)
%     a   (the attenuation in dB at the narrower bandwidth)
%     b   (the attenuation in dB at the wider bandwidth)
%

%
%       L.D. Paarmann, August 23, 1997
%
%
%  This function determines the Shaping Factor of a Bessel lowpass
%  prototype filter using a direct method.  See Section 7.3 of
%  
%                     Design and Analysis of
%                         ANALOG FILTERS:
%                 A Signal Processing Perspective
%
%                        Larry D. Paarmann
%
%
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%

%
%  Determine the normalized Bessel filter coefficients:
%
   wcn = 1;
   Ap = 10*log10(2);
   [ppn,kkn] = besselde(N,wcn,Ap);
   NUM = kkn;
   DEN = poly(ppn);
%
%
%
%  Determine the bandwidth at attenuation a:
%
   xx = 1:8000;
   w = xx/4700;
   test = 10^(-a/20);
   FRmag = abs(freqs(NUM,DEN,w));
   FR = abs(FRmag - test);
   mag1 = 1;
   for k=1:8000
     if(FR(k)<mag1)
       k1 = k;
       mag1 = FR(k);
     end
   end
   BW1 = w(k1);
%     
   xx = 6001:14000;
   w = xx/4000;
   FRmag = abs(freqs(NUM,DEN,w));
   FR = abs(FRmag - test);
   mag2 = 1;
   for k=1:8000
     if(FR(k)<mag2)
       k2 = k;
       mag2 = FR(k);
     end
   end
   BW2 = w(k2);
%  
   xx = 12401:20400;
   w = xx/4000;
   FRmag = abs(freqs(NUM,DEN,w));
   FR = abs(FRmag - test);
   mag3 = 1;
   for k=1:8000
     if(FR(k)<mag3)
       k3 = k;
       mag3 = FR(k);
     end
   end
   BW3 = w(k3);
%  
   BWa = BW2;
   if(mag1<mag2)
      BWa = BW1;
   end
%
   if(mag3<mag2)
      if(mag3<mag1)
         BWa = BW3;
      end
   end
%
%
%
%  Determine the bandwidth at attenuation b:
%
   xx = 81:8080;
   w = xx/24;
   test = 10^(-b/20);
   FRmag = abs(freqs(NUM,DEN,w));
   FR = abs(FRmag - test);
   mag1 = 1;
   for k=1:8000
     if(FR(k)<mag1)
       k1 = k;
       mag1 = FR(k);
     end
   end
   BW1 = w(k1);
%
   xx = 8033:16032;
   w = xx/24;
   FRmag = abs(freqs(NUM,DEN,w));
   FR = abs(FRmag - test);
   mag2 = 1;
   for k=1:8000
     if(FR(k)<mag2)
       k2 = k;
       mag2 = FR(k);
     end
   end
   BW2 = w(k2);
%
   xx = 15291:23290;
   w = xx/23;
   FRmag = abs(freqs(NUM,DEN,w));
   FR = abs(FRmag - test);
   mag3 = 1;
   for k=1:8000
     if(FR(k)<mag3)
       k3 = k;
       mag3 = FR(k);
     end
   end
   BW3 = w(k3);
%
   BWb = BW2;
   if(mag1<mag2)
      BWb = BW1;
   end
%
   if(mag3<mag2)
      if(mag3<mag1)
         BWb = BW3;
      end
   end
%
%
%
%  Calculate the Shaping Factor:
%
   sfeval = BWb/BWa;
%
%
%
%  End of BESSELSF
%
