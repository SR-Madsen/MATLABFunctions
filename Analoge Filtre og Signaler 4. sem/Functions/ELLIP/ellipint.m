function xx = ellipint(phi,tau,AC)
%
%  ELLIPINT:  elliptic integral of the first kind.
%
%       ELLIPINT(phi,tau,AC) returns the value of the elliptic
%       integral of the first kind, evaluated at argument phi,
%       and modulus tau, using Accuracy Coefficient AC.  Note
%       that tau is used here, not the modulus m = tau^2.
%
%  usage (a) scalar phi:
%  EIF1 = ellipint(phi,tau,AC);
%  assigns the value of the elliptic integral to the scalar EIF1.
%
%  usage (b) array phi:
%  EIF2 = ellipint(phi,tau,AC);
%  assigns the values of the elliptic integral corresponding to each value
%  in phi to the array elements of EIF2.
%
%
%	Notes:
%		(1) This method will return the complete elliptic 
%		integral of the first kind if the argument is pi/2.
%		
%     (2) The argument phi is assumed to be either a scalar
%		or an array.
%
%		(3) This method is not restricted to a real argument.
%
%     (5) The Accuracy Coefficent AC is a positive integer that
%     determines how small the deltas are in the summation
%     approximation to the integral.  Generally, the larger AC
%     is the more accurate will be the approximation, but the
%     greater will be the computational burden.
%

%  L.D. Paarmann, May 31, 1997
%
%
%  This algorithm implements an approximation to equation (6.4) in
%
%                            Design and Analysis of
%                                ANALOG FILTERS:
%                       A Signal Processing Perspective
%
%                              Larry D. Paarmann
%
%
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%

%
[mm,nn] = size(phi);
N1 = max(mm,nn);
N2 = AC;
kk = 0:N2;
for ii=1:N1
   xi = phi(ii)/(N2+1);
   xxi = kk*xi;
   sine = sin(xxi);
   sin2 = sine.*sine;
   integ = 1 ./ sqrt(1-tau^2*sin2);
   xx(ii) = sum(integ)* xi;
end
%
