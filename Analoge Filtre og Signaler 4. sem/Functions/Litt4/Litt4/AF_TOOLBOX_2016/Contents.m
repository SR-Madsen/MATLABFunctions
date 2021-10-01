% Contents of the Toolbox for
%
% ANALOG FILTERS USING MATLAB, Springer, 2009
%
% Version 1.1, 2009-10-13 : Corrected some Mac vs PC vs Linux issues
% Version 1.2, 2009-10-20 : Added two missing functions: POLYSUB/POLYADD
% Version 1.3, 2009-11-04 : Corrected broken links to subdirectories.
% Version 2,   2016-04-29
%
% This file
%
% Contents.m
%
% Functions to calculate the required order of a filter
% BESSEL_ORDER -- Bessel 
% BW_ORDER     -- Butterworth 
% CA_ORDER     -- Cauer 
% CH_ORDER     -- Chebychev 
%
% Functions to find the poles and zeros
% BESSEL_POLES  --
% BW_POLES      --
% CA_POLES      --
% CA_B_POLES    --
% CA_C_POLES    --
% CH_I_POLES    --
% CH_I_C_POLES  --
% CH_II_POLES   --
% CH_II_B_POLES --
CT_TREE_WDF_BP --
CT_TREE_WDF_H_LP --
%
% Functions to compute the element values, etc. in a ladder or lattice realization
% BW_LADDER        --
% BW_SINGLY_LADDER --
% CA_LADDER        --
% CH_II_LADDER     --
% CH_I_LADDER      --
% CH_I_SINGLY_LADDER --
% LADDER_2_H     --
% LATTICE_S      --
% LP_2_BP_LADDER --
% LP_2_BS_LADDER --
% LP_2_HP_LADDER --
% LP_LADDER      --
% T_LADDER_2_PI  --
% X_CAUER_I      --
% X_CAUER_II      --
% X_FOSTER_I      --
% X_FOSTER_II      --
% ZIN_LADDER     --
%
% Plot functions
% PLOT_A_TG_S --
% PLOT_ATTENUATION_S --
% PLOT_HP_SPEC_S --
% PLOT_h_s_S -- Plots impulse and step responses
% PLOT_IMPULSE_RESPONSE_S --
% PLOT_LP_SPEC_S --
% PLOT_MAG_PHASE_S --
% PLOT_PHASE_S --
% PLOT_PZ_S --
% PLOT_STEP_RESPONSE_S --
% PLOT_TG_S --
% xtick --
% ytick --
% ytick_right --
% BP_2_LP_SPEC --
% BS_2_LP_SPEC --
%
% Miscellaneous functions
% DELTA_ATTENUATION --
% EQAPLP --
% EQ_TG_LP_S --
% EQUALRIPPLE_LP --
% H_2_ATT --
% H_2_MAG --
% MAG_2_ATT --
%
% Poleplacer programs
% PART_FRACT_EXPANSION --
% POLE_PLACER_BP_EQ_S --
% POLE_PLACER_BP_MF_S --
% POLE_PLACER_HP_EQ_S --
% POLE_PLACER_HP_MF_S --
% POLE_PLACER_LP_EQ_S --
% POLE_PLACER_LP_MF_S --
%
% Functions on polynomials
% POLYADD   -- sum of two polynoms
% POLYSUB   -- difference between two polynoms
% POLYMULT  -- product of two polynoms, c.f., conv
% POLY_AT_X -- returns value of polynom at x
% POLY_PRIM --
%
% Functions on poles and zeros
% HURWITZ_POLY --
% HURWITZ_ROOTS --
% PZ_2_ATT_S --
% PZ_2_FREQ_S --
% PZ_2_G_SYM_BP_S --
% PZ_2_G_SYM_BS_S --
% PZ_2_HP_S --
% PZ_2_IMPULSE_RESPONSE_S --
% PZ_2_MAG_PHASE_S --
% PZ_2_MAG_S --
% PZ_2_PHASE_S --
% PZ_2_STEP_RESPONSE_S --
% PZ_2_TG_S --
% PZ_CANCEL --
% REFLECTION_ZEROS --
% ROOTS_2_POLY --
% UNIQUE_ROOTS --
%
% Distributed element structures
% RICHARDS_EQ --
% RICHARDS_MF --
% RICHARDS_REACTANCE --
% S_2_X --
%
% Math functions
% COMPLETE_ELLIPTIC_INTEGRAL --
% FACTORIAL --
% FACTORIZE --
% LONG_DIV --
% PRAXIS --
