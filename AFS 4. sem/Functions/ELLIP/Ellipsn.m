function xx = ellipsn(u,k)
%
%  ELLIPSN:  Jacobi elliptic sine function.
%
%  usage:
%	JES1 = ellipsn(u,k);
%  returns the value (scalar or array) of the Jacobi elliptic
%	sine function, evaluated at argument u (scalar or array),
%  and modulus k.	Note that modulus k is used here, as opposed to
%  modulus m = k^2.
%
%	Notes:
%		(1) The argument u is assumed to be either a scalar
%		or an array.
%
%		(2) This method is not restricted to a real argument.
%

%
%	L.D. Paarmann, May 31, 1997
%
%
%
%	Reference:  Paul F. Byrd and Morris D. Friedman, "Handbook of
%	  	     Elliptic Integrals for Engineers and Physicists,"
%		     Springer-Verlag, 1954, p. 24.
%
%          The following algorithm implements 125.01 for the
%          elliptic sine function with a complex argument.
%
%
[mnn,mnp] = size(u);
NN = max(mnn,mnp);
%
ur = real(u);
ui = imag(u);
%
m = k*k;
mp = 1 - m;
%
[snr,cnr,dnr] = ellipj(ur,m);
[snrp,cnrp,dnrp] = ellipj(ur,mp);
%
[sni,cni,dni] = ellipj(ui,m);
[snip,cnip,dnip] = ellipj(ui,mp);
%
den = 1 - snip.*snip .* dnr.*dnr;
denr = real(den);
deni = imag(den);
%
for kk=1:NN
   if(denr(kk) == 0)
      denr(kk) = 10^(-30);
      den(kk) = denr(kk) + sqrt(-1)*deni(kk);
   end
   if(deni(kk) == 0)
      deni(kk) = 10^(-30);
      den(kk) = denr(kk) + sqrt(-1)*deni(kk);
   end
end
xxrn = snr.*dnip;
xxin = cnr.*dnr.*snip.*cnip;
xxr = xxrn ./ den;
xxi = xxin ./ den;
%
xx = xxr + sqrt(-1)*xxi;
%
