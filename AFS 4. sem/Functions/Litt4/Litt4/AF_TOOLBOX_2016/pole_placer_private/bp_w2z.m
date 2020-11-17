	function z = bp_w2z(w,wa,wb)	%  	% Converts for the bandpass case from the jw plane to the 	% transformed variable plane.	% The pass band cut off frequencies wa and wb is needed.		% Author: 			Per Loewenborg    % Modified by:		LW 	% Copyright:		Divison of Electronics Systems	%					Dept. Electrical Engineering, Linkoping University, Sweden	% Version: 			1		% Known bugs:		None	% Report bugs to:	larsw@isy.liu.se		z = sqrt( (wb^2-w.^2)./(wa^2-w.^2) );