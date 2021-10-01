function fseval = besselfs(N,wc)
%
%  BESSELFS:  Determines the Filter Selectivity for a lowpass
%             Bessel filter.
%
%  usage:
%  fseval = besselfs(N,wc);
%
%  The function inputs are:
%     N   (the order of the Bessel filter)
%     wc  (the 3 dB corner frequency in radians per second)
%

%
%       L.D. Paarmann, August 21, 1997
%
%
%  This function determines the Filter Selectivity of a Bessel lowpass
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
wcn = 1;
Ap = 10*log10(2);
[ppn,kkn] = besselde(N,wcn,Ap);
scale = wc/wcn;
NUM = kkn;
DEN = poly(ppn);
%
%  Determine two frequency points for evaluation:
deltaw = 0.000001;
wc1 = wcn - deltaw;
wc2 = wcn + deltaw;
w = [wc1 wc2];
%
%  Determine the magnitude response at the two frequency points:
FRmag = abs(freqs(NUM,DEN,w));
%
%  Determine the negative of the difference at the normalized wc:
deltamag = FRmag(1) - FRmag(2);
%
%  Denormalize the slope for the Filter Selectivity:
fseval = deltamag/(2*deltaw*scale);
%
%
%  End of BESSELFS
%
