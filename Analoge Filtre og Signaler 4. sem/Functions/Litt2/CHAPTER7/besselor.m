function order = besselor(Ap,wp,As,ws)
%
%  BESSELOR:  Determines the minimum required order for a lowpass
%             Bessel filter to meet given specifications.
%
%  usage:
%  order = besselor(Ap,wp,As,ws);
%
%  The function inputs are:
%     Ap  (the maximum attenuation in the passband in dB)
%     wp  (the passband corner frequency in radians per second)
%     As  (the minimum attenuation in the stopband in dB)
%     ws  (the maximum value for the stopband edge frequency) 
%

%
%       L.D. Paarmann, August 30, 1997
%
%
%  This function determines the minimum required filter order
%  for a lowpass prototype Bessel filter.  See Section 7.4 of
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
%  Determine the required Shaping Factor:
%
   SF = ws/wp;
%
%
%
%  Test for the minimum required order:
%
   N = 0;
   SF1 = 10^6;
   dum = 0;
   while SF1>SF
      N = N + 1;
      if(N>10)
         disp('   ')
         disp('Required order greater than 10')
         dum = 1;
      end
      if(dum==0)
         order = N;
         SF1 = besselsf(N,Ap,As);
      else
         order = [];
         SF1 = 0;
      end
   end   
%
%
%
%  End of BESSELOR
%
