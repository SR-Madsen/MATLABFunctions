	function[MAG, PHASE] = PZ_2_MAG_PHASE_S(G, Z, P, W)	%	% 	Computes the magnitude and phase responses given the poles and zeros and 	% 	gain constant for an analog transfer function at the frequencies specified by W.	%	% 	Toolbox for ANALOG FILTERS USING MATLAB, Springer, 2009		% 	Author: 		Oscar Gustafsson, oscarg@isy.liu.se	% 	Modified by: 	LW 2003-09-19, 2004-09-22, 2005-11-15	% 	Copyright:		Divison of Electronics Systems	% 					Dept. Electrical Engineering, Linkoping University, Sweden	% 	Version: 		1	% 	Known bugs:		None	% 	Report bugs to:	larsw@isy.liu.se	%		MAG = PZ_2_MAG_S(G, Z, P, W);	PHASE = PZ_2_PHASE_S(G, Z, P, W);	