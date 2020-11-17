 	function [L, C, K] = BW_SINGLY_LADDER(Wc, Ws, Amax, Amin, N,  Rs, RL, Ladder)	%	%	Computes the element values for a SINGLY resistively 	%	terminated LC ladder of Butterworth type.	%	%	Ladder = 1 for T ladder and 0 for � ladder	%	Rs = source resistor and RL = load resistor	%	K is a vector used by LADDER_2_H that defines the two-port.	%	% 	Toolbox for ANALOG FILTERS USING MATLAB, Springer, 2009	%	% 	Author: 			Lars Wanhammar, 1983-08-18	% 	Modified by: 	 	LW 1987-01-19/1987-07-28/2005-11-21/2007-06-28	%	Copyright:			Divison of Electronics Systems	%	 					Dept. Electrical Engineering, Linkoping University, Sweden	% 	Version:			1 	% 	Known bugs:			None	% 	Report bugs to:		larsw@isy.liu.se	%		Print = 0;	% Set Print = 0 for no printing	if (Rs ~= 0 & RL ~= 0 & Rs ~= inf & RL ~= inf)		disp(['Use BW_LADDER instead']); return	end	n = 1:N;	A = sin((n-0.5)*pi/N); B = cos(n*pi/N/2).^2; G(1) = A(1);	for indx = 2:N		G(indx) = A(indx)*A(indx-1)/(B(indx-1)*G(indx-1));	end	L = zeros(1, N); C = zeros(1,N); Rnorm = Rs;	if Rs ~= 0 & Rs ~= inf		if  Ladder == 0			if (mod(N,2) == 0 & RL == inf) | (mod(N,2) == 1 & RL == 0)				disp(['This case do no exist']); return			end		end	end	if Rs == inf & RL ~= 0 & RL ~= inf		if Ladder == 0			G = fliplr(G); Rnorm = RL;		else			disp(['This case do no exist']); return		end	end	if Rs == 0 & RL ~= inf & RL ~= 0		if Ladder == 0			disp(['This case do no exist']); return		else			G = fliplr(G); Rnorm = RL;		end	end	if (Rs == 0 & (RL == 0| RL == inf)) | (Rs == inf & (RL == 0| RL == inf))		disp(['This case do no exist']); return	end 	r0p = Wc*(10^(0.1*Amax)-1)^(-1/(2*N));	G = G/r0p;		for indx = 1:2:N-1 % Define the two-ports		if Ladder == 1	% T Ladder 			L(indx) = G(indx); C(indx+1) = G(indx+1);			K(indx) = 2; K(indx+1) = 9; 		else 	% � Ladder 			C(indx) = G(indx); L(indx+1) = G(indx+1);			K(indx) = 9; K(indx+1) = 2;		end 	end	if mod(N,2) == 1		if Ladder == 1			L(N) = G(N); K(N) = 2; 		else 			C(N) = G(N); K(N) = 9; 		end	end	L = Rnorm*L; C = C/Rnorm;	if Print == 1	% Printing		disp(['Rs = ', num2str(Rs),' ohm'])			for indx = 1:2:N-1			if Ladder == 1	% T Ladder 				disp(['L', num2str(indx),' = ', num2str(L(indx)),' H'])					disp(['C', num2str(indx+1),' = ', num2str(C(indx+1)), ' F'])			else 	% � Ladder				disp(['C', num2str(indx),' = ', num2str(C(indx)), ' F'])				disp(['L', num2str(indx+1),' = ', num2str(L(indx+1)), ' H'])			end 		end		if mod(N,2) == 1			if Ladder == 1				disp(['L', num2str(N),' = ', num2str(L(N)),' H'])			else				disp(['C', num2str(N),' = ', num2str(C(N)), ' F'])			end		end 		disp(['RL = ', num2str(RL),' ohm'])	end																			