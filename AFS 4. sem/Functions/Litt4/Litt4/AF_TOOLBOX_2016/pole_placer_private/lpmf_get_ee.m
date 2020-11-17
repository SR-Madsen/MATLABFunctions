	function EE = lpmf_get_ee(Z,NIN,Amax)	% 	% Returns the E*conj(E) given an  attenuation pole 	% vector, the number of attenuation poles at infinity and 	% the passband attenuation Amax.		% Author: 			Per Loewenborg    % Modified by:		LW	% Copyright:		Divison of Electronics Systems	%					Dept. Electrical Engineering, Linkoping University, Sweden	% Version: 			1		% Known bugs:		None	% Report bugs to:	larsw@isy.liu.se		ep_sqred = (10^(0.1*Amax))-1;	% Find F^2 and Q^2	N = length(Z);	if N > 0	  Q2 = [1 0 -2*(Z(1)^2) 0 Z(1)^4];	  for k = 2:N	   Q2 = conv(Q2,[1 0 -2*(Z(k)^2) 0 Z(k)^4]);	  end	  if NIN > 0	    for k = 1:NIN	      Q2 = conv(Q2,[1 0 -1]);	    end    	  end	   Q2 = Q2*((-1)^NIN);	else % No attenuation poles  	 Q2 = [1];	  if NIN > 0	    for k = 1:NIN	      Q2 = conv(Q2,[1 0 -1]);	    end    	  end  	 Q2 = Q2*((-1)^NIN);	end	F2 = prod(Z.^4);	F2 = F2*ep_sqred;	dif = length(Q2) - length(F2);	if dif > 0	  z = zeros(1,dif);	  F2 = [z F2];	else	  z = zeros(1,dif);	  Q2 = [z Q2];	end	EE = F2+Q2;