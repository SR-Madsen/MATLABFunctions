    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 6;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (rtP)
        ;%
            section.nData     = 202;
            section.data(202)  = dumData; %prealloc

                    ;% rtP.KipP
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.KipQ
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.KppP
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.KppQ
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.ki
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.kp
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.AlphaBetaZerotodq0_Alignment
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.AlphaBetaZerotodq0_Alignment_hohufqrubs
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% rtP.dq0toAlphaBetaZero_Alignment
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% rtP.Vdc_Amplitude
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% rtP.ThreePhaseSource_Frequency
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% rtP.ThreePhaseProgrammableVoltageSource_HarmonicGeneration
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% rtP.Continuous_Init
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% rtP.Continuous_Kd
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% rtP.Continuous_Ki
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

                    ;% rtP.Continuous_Kp
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 15;

                    ;% rtP.PWMGenerator2Level_MinMax
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 16;

                    ;% rtP.VariationSubSystem_Toff_Variation
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 18;

                    ;% rtP.VariationSubSystem_Ton_Variation
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 19;

                    ;% rtP.ThreePhaseProgrammableVoltageSource_VariationEntity
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 20;

                    ;% rtP.VariationSubSystem_VariationFreq
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 21;

                    ;% rtP.VariationSubSystem_VariationMag
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 22;

                    ;% rtP.VariationSubSystem_VariationRate
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 23;

                    ;% rtP.VariationSubSystem_VariationStep
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 24;

                    ;% rtP.ThreePhaseProgrammableVoltageSource_VariationType
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 25;

                    ;% rtP.CompareToConstant_const
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 26;

                    ;% rtP.CompareToConstant1_const
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 27;

                    ;% rtP.CompareToConstant_const_c3zde2cbi4
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 28;

                    ;% rtP.CompareToConstant1_const_efjr5x0wsv
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 29;

                    ;% rtP.CompareToConstant_const_gsz3trqyjp
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 30;

                    ;% rtP.CompareToConstant1_const_hw4vovlkze
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 31;

                    ;% rtP.Gain_Y0
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 32;

                    ;% rtP.VariableTransportDelay_MaxDelay
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 33;

                    ;% rtP.VariableTransportDelay_InitOutput
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 34;

                    ;% rtP.integrator_IC
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 35;

                    ;% rtP.Memory_InitialCondition
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 36;

                    ;% rtP.VariableTransportDelay_MaxDelay_evwrynr4yh
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 37;

                    ;% rtP.VariableTransportDelay_InitOutput_d5upbocuak
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 38;

                    ;% rtP.integrator_IC_g14ialcirz
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 39;

                    ;% rtP.Memory_InitialCondition_bz4nohehtu
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 40;

                    ;% rtP.Saturation_UpperSat
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 41;

                    ;% rtP.Saturation_LowerSat
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 42;

                    ;% rtP.Toavoiddivisionbyzero_UpperSat
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 43;

                    ;% rtP.Toavoiddivisionbyzero_LowerSat
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 44;

                    ;% rtP.Toavoiddivisionbyzero_UpperSat_amv5dob4gd
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 45;

                    ;% rtP.Toavoiddivisionbyzero_LowerSat_dsvy2fn0ag
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 46;

                    ;% rtP.Gain3_Gain
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 47;

                    ;% rtP.Gain1_Gain
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 56;

                    ;% rtP.Constant_Value
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 57;

                    ;% rtP.Constant_Value_n0qkhh1fth
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 58;

                    ;% rtP.alpha_beta_Y0
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 59;

                    ;% rtP.alpha_beta_Y0_pg4urrpzbu
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 61;

                    ;% rtP.Out1_Y0
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 63;

                    ;% rtP.Out2_Y0
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 64;

                    ;% rtP.timer_Y0
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 65;

                    ;% rtP.magnitude_Y0
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 66;

                    ;% rtP.frequency_Y0
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 67;

                    ;% rtP.phase_Y0
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 68;

                    ;% rtP.DiscreteTimeIntegrator_gainval
                    section.data(59).logicalSrcIdx = 58;
                    section.data(59).dtTransOffset = 69;

                    ;% rtP.DiscreteTimeIntegrator_IC
                    section.data(60).logicalSrcIdx = 59;
                    section.data(60).dtTransOffset = 70;

                    ;% rtP.Step1_Y0
                    section.data(61).logicalSrcIdx = 60;
                    section.data(61).dtTransOffset = 71;

                    ;% rtP.Step1_YFinal
                    section.data(62).logicalSrcIdx = 61;
                    section.data(62).dtTransOffset = 72;

                    ;% rtP.Step_Y0
                    section.data(63).logicalSrcIdx = 62;
                    section.data(63).dtTransOffset = 73;

                    ;% rtP.Step_YFinal
                    section.data(64).logicalSrcIdx = 63;
                    section.data(64).dtTransOffset = 74;

                    ;% rtP.DiscreteTimeIntegrator1_gainval
                    section.data(65).logicalSrcIdx = 64;
                    section.data(65).dtTransOffset = 75;

                    ;% rtP.DiscreteTimeIntegrator1_IC
                    section.data(66).logicalSrcIdx = 65;
                    section.data(66).dtTransOffset = 76;

                    ;% rtP.UnitDelay_InitialCondition
                    section.data(67).logicalSrcIdx = 66;
                    section.data(67).dtTransOffset = 77;

                    ;% rtP.Switch2_Threshold
                    section.data(68).logicalSrcIdx = 67;
                    section.data(68).dtTransOffset = 78;

                    ;% rtP.Gain2_Gain
                    section.data(69).logicalSrcIdx = 68;
                    section.data(69).dtTransOffset = 79;

                    ;% rtP.Switch_Threshold
                    section.data(70).logicalSrcIdx = 69;
                    section.data(70).dtTransOffset = 80;

                    ;% rtP.Constant3_Value
                    section.data(71).logicalSrcIdx = 70;
                    section.data(71).dtTransOffset = 81;

                    ;% rtP.Constant5_Value
                    section.data(72).logicalSrcIdx = 71;
                    section.data(72).dtTransOffset = 82;

                    ;% rtP.Constant_Value_dvamm1lycs
                    section.data(73).logicalSrcIdx = 72;
                    section.data(73).dtTransOffset = 83;

                    ;% rtP.Constant1_Value
                    section.data(74).logicalSrcIdx = 73;
                    section.data(74).dtTransOffset = 84;

                    ;% rtP.Constant2_Value
                    section.data(75).logicalSrcIdx = 74;
                    section.data(75).dtTransOffset = 85;

                    ;% rtP.Constant3_Value_jeehzqq2f5
                    section.data(76).logicalSrcIdx = 75;
                    section.data(76).dtTransOffset = 86;

                    ;% rtP.Constant4_Value
                    section.data(77).logicalSrcIdx = 76;
                    section.data(77).dtTransOffset = 87;

                    ;% rtP.Constant5_Value_bojg2v1nr1
                    section.data(78).logicalSrcIdx = 77;
                    section.data(78).dtTransOffset = 88;

                    ;% rtP.Gain1_Gain_onz34q5f5w
                    section.data(79).logicalSrcIdx = 78;
                    section.data(79).dtTransOffset = 89;

                    ;% rtP.SineWaveA_Amp
                    section.data(80).logicalSrcIdx = 79;
                    section.data(80).dtTransOffset = 90;

                    ;% rtP.SineWaveA_Bias
                    section.data(81).logicalSrcIdx = 80;
                    section.data(81).dtTransOffset = 91;

                    ;% rtP.SineWaveA_Hsin
                    section.data(82).logicalSrcIdx = 81;
                    section.data(82).dtTransOffset = 92;

                    ;% rtP.SineWaveA_HCos
                    section.data(83).logicalSrcIdx = 82;
                    section.data(83).dtTransOffset = 93;

                    ;% rtP.SineWaveA_PSin
                    section.data(84).logicalSrcIdx = 83;
                    section.data(84).dtTransOffset = 94;

                    ;% rtP.SineWaveA_PCos
                    section.data(85).logicalSrcIdx = 84;
                    section.data(85).dtTransOffset = 95;

                    ;% rtP.SineWaveB_Amp
                    section.data(86).logicalSrcIdx = 85;
                    section.data(86).dtTransOffset = 96;

                    ;% rtP.SineWaveB_Bias
                    section.data(87).logicalSrcIdx = 86;
                    section.data(87).dtTransOffset = 97;

                    ;% rtP.SineWaveB_Hsin
                    section.data(88).logicalSrcIdx = 87;
                    section.data(88).dtTransOffset = 98;

                    ;% rtP.SineWaveB_HCos
                    section.data(89).logicalSrcIdx = 88;
                    section.data(89).dtTransOffset = 99;

                    ;% rtP.SineWaveB_PSin
                    section.data(90).logicalSrcIdx = 89;
                    section.data(90).dtTransOffset = 100;

                    ;% rtP.SineWaveB_PCos
                    section.data(91).logicalSrcIdx = 90;
                    section.data(91).dtTransOffset = 101;

                    ;% rtP.SineWaveC_Amp
                    section.data(92).logicalSrcIdx = 91;
                    section.data(92).dtTransOffset = 102;

                    ;% rtP.SineWaveC_Bias
                    section.data(93).logicalSrcIdx = 92;
                    section.data(93).dtTransOffset = 103;

                    ;% rtP.SineWaveC_Hsin
                    section.data(94).logicalSrcIdx = 93;
                    section.data(94).dtTransOffset = 104;

                    ;% rtP.SineWaveC_HCos
                    section.data(95).logicalSrcIdx = 94;
                    section.data(95).dtTransOffset = 105;

                    ;% rtP.SineWaveC_PSin
                    section.data(96).logicalSrcIdx = 95;
                    section.data(96).dtTransOffset = 106;

                    ;% rtP.SineWaveC_PCos
                    section.data(97).logicalSrcIdx = 96;
                    section.data(97).dtTransOffset = 107;

                    ;% rtP.StateSpace_AS_param
                    section.data(98).logicalSrcIdx = 97;
                    section.data(98).dtTransOffset = 108;

                    ;% rtP.StateSpace_BS_param
                    section.data(99).logicalSrcIdx = 98;
                    section.data(99).dtTransOffset = 112;

                    ;% rtP.StateSpace_CS_param
                    section.data(100).logicalSrcIdx = 99;
                    section.data(100).dtTransOffset = 132;

                    ;% rtP.StateSpace_DS_param
                    section.data(101).logicalSrcIdx = 100;
                    section.data(101).dtTransOffset = 156;

                    ;% rtP.StateSpace_X0_param
                    section.data(102).logicalSrcIdx = 101;
                    section.data(102).dtTransOffset = 276;

                    ;% rtP.u4_Value
                    section.data(103).logicalSrcIdx = 102;
                    section.data(103).dtTransOffset = 278;

                    ;% rtP.uRon_Gain
                    section.data(104).logicalSrcIdx = 103;
                    section.data(104).dtTransOffset = 279;

                    ;% rtP.Switch_Threshold_h0h0hrbrds
                    section.data(105).logicalSrcIdx = 104;
                    section.data(105).dtTransOffset = 280;

                    ;% rtP.Saturation_UpperSat_lphrbvohc0
                    section.data(106).logicalSrcIdx = 105;
                    section.data(106).dtTransOffset = 281;

                    ;% rtP.Saturation_LowerSat_gyzt3s021b
                    section.data(107).logicalSrcIdx = 106;
                    section.data(107).dtTransOffset = 282;

                    ;% rtP.UnitDelay_InitialCondition_hnsfjn5hxn
                    section.data(108).logicalSrcIdx = 107;
                    section.data(108).dtTransOffset = 283;

                    ;% rtP.P10kW_Time
                    section.data(109).logicalSrcIdx = 108;
                    section.data(109).dtTransOffset = 284;

                    ;% rtP.P10kW_Y0
                    section.data(110).logicalSrcIdx = 109;
                    section.data(110).dtTransOffset = 285;

                    ;% rtP.P10kW_YFinal
                    section.data(111).logicalSrcIdx = 110;
                    section.data(111).dtTransOffset = 286;

                    ;% rtP.donotdeletethisgain_Gain
                    section.data(112).logicalSrcIdx = 111;
                    section.data(112).dtTransOffset = 287;

                    ;% rtP.donotdeletethisgain_Gain_cjkn1fmmwf
                    section.data(113).logicalSrcIdx = 112;
                    section.data(113).dtTransOffset = 288;

                    ;% rtP.donotdeletethisgain_Gain_p4xdjo1x0c
                    section.data(114).logicalSrcIdx = 113;
                    section.data(114).dtTransOffset = 289;

                    ;% rtP.Kv1_Gain
                    section.data(115).logicalSrcIdx = 114;
                    section.data(115).dtTransOffset = 290;

                    ;% rtP.donotdeletethisgain_Gain_f05p010jfj
                    section.data(116).logicalSrcIdx = 115;
                    section.data(116).dtTransOffset = 291;

                    ;% rtP.donotdeletethisgain_Gain_om0hzrwmvi
                    section.data(117).logicalSrcIdx = 116;
                    section.data(117).dtTransOffset = 292;

                    ;% rtP.donotdeletethisgain_Gain_pj4emxjkfc
                    section.data(118).logicalSrcIdx = 117;
                    section.data(118).dtTransOffset = 293;

                    ;% rtP.Kv_Gain
                    section.data(119).logicalSrcIdx = 118;
                    section.data(119).dtTransOffset = 294;

                    ;% rtP.s1_Gain
                    section.data(120).logicalSrcIdx = 119;
                    section.data(120).dtTransOffset = 295;

                    ;% rtP.Delay11_InitialCondition
                    section.data(121).logicalSrcIdx = 120;
                    section.data(121).dtTransOffset = 296;

                    ;% rtP.a21_Gain
                    section.data(122).logicalSrcIdx = 121;
                    section.data(122).dtTransOffset = 297;

                    ;% rtP.FFInt_gainval
                    section.data(123).logicalSrcIdx = 122;
                    section.data(123).dtTransOffset = 298;

                    ;% rtP.FFInt_IC
                    section.data(124).logicalSrcIdx = 123;
                    section.data(124).dtTransOffset = 299;

                    ;% rtP.s1_Gain_hko4bmcnti
                    section.data(125).logicalSrcIdx = 124;
                    section.data(125).dtTransOffset = 300;

                    ;% rtP.Delay11_InitialCondition_dkcmnnrtrg
                    section.data(126).logicalSrcIdx = 125;
                    section.data(126).dtTransOffset = 301;

                    ;% rtP.a21_Gain_igtn11js15
                    section.data(127).logicalSrcIdx = 126;
                    section.data(127).dtTransOffset = 302;

                    ;% rtP.FFInt_gainval_ajjzcdjezz
                    section.data(128).logicalSrcIdx = 127;
                    section.data(128).dtTransOffset = 303;

                    ;% rtP.FFInt_IC_dnt3xnjdp2
                    section.data(129).logicalSrcIdx = 128;
                    section.data(129).dtTransOffset = 304;

                    ;% rtP.Gain1_Gain_mmba2zpssf
                    section.data(130).logicalSrcIdx = 129;
                    section.data(130).dtTransOffset = 305;

                    ;% rtP.Initial_Value
                    section.data(131).logicalSrcIdx = 130;
                    section.data(131).dtTransOffset = 306;

                    ;% rtP.Integrator_UpperSat
                    section.data(132).logicalSrcIdx = 131;
                    section.data(132).dtTransOffset = 307;

                    ;% rtP.Integrator_LowerSat
                    section.data(133).logicalSrcIdx = 132;
                    section.data(133).dtTransOffset = 308;

                    ;% rtP.HitCrossing_Offset
                    section.data(134).logicalSrcIdx = 133;
                    section.data(134).dtTransOffset = 309;

                    ;% rtP.Memory_InitialCondition_cmy5m3zyx0
                    section.data(135).logicalSrcIdx = 134;
                    section.data(135).dtTransOffset = 310;

                    ;% rtP.Integrator_UpperSat_pm1zhfhqin
                    section.data(136).logicalSrcIdx = 135;
                    section.data(136).dtTransOffset = 311;

                    ;% rtP.Integrator_LowerSat_nkt4rnjn03
                    section.data(137).logicalSrcIdx = 136;
                    section.data(137).dtTransOffset = 312;

                    ;% rtP.VariableTransportDelay_MaxDelay_gjh2uwsyu4
                    section.data(138).logicalSrcIdx = 137;
                    section.data(138).dtTransOffset = 313;

                    ;% rtP.VariableTransportDelay_InitOutput_ly4stoovo0
                    section.data(139).logicalSrcIdx = 138;
                    section.data(139).dtTransOffset = 314;

                    ;% rtP.integrator_IC_fa2zkozxvn
                    section.data(140).logicalSrcIdx = 139;
                    section.data(140).dtTransOffset = 315;

                    ;% rtP.Memory_InitialCondition_mxilddonen
                    section.data(141).logicalSrcIdx = 140;
                    section.data(141).dtTransOffset = 316;

                    ;% rtP.TransferFcn_A
                    section.data(142).logicalSrcIdx = 141;
                    section.data(142).dtTransOffset = 317;

                    ;% rtP.TransferFcn_C
                    section.data(143).logicalSrcIdx = 142;
                    section.data(143).dtTransOffset = 318;

                    ;% rtP.TransferFcn_D
                    section.data(144).logicalSrcIdx = 143;
                    section.data(144).dtTransOffset = 319;

                    ;% rtP.Saturation2_UpperSat
                    section.data(145).logicalSrcIdx = 144;
                    section.data(145).dtTransOffset = 320;

                    ;% rtP.Saturation2_LowerSat
                    section.data(146).logicalSrcIdx = 145;
                    section.data(146).dtTransOffset = 321;

                    ;% rtP.Gain10_Gain
                    section.data(147).logicalSrcIdx = 146;
                    section.data(147).dtTransOffset = 322;

                    ;% rtP.RateLimiter_RisingLim
                    section.data(148).logicalSrcIdx = 147;
                    section.data(148).dtTransOffset = 323;

                    ;% rtP.RateLimiter_FallingLim
                    section.data(149).logicalSrcIdx = 148;
                    section.data(149).dtTransOffset = 324;

                    ;% rtP.Integrator_x1_IC
                    section.data(150).logicalSrcIdx = 149;
                    section.data(150).dtTransOffset = 325;

                    ;% rtP.A11_Gain
                    section.data(151).logicalSrcIdx = 150;
                    section.data(151).dtTransOffset = 326;

                    ;% rtP.Integrator_x2_IC
                    section.data(152).logicalSrcIdx = 151;
                    section.data(152).dtTransOffset = 327;

                    ;% rtP.A12_Gain
                    section.data(153).logicalSrcIdx = 152;
                    section.data(153).dtTransOffset = 328;

                    ;% rtP.A21_Gain
                    section.data(154).logicalSrcIdx = 153;
                    section.data(154).dtTransOffset = 329;

                    ;% rtP.A22_Gain
                    section.data(155).logicalSrcIdx = 154;
                    section.data(155).dtTransOffset = 330;

                    ;% rtP.B11_Gain
                    section.data(156).logicalSrcIdx = 155;
                    section.data(156).dtTransOffset = 331;

                    ;% rtP.B21_Gain
                    section.data(157).logicalSrcIdx = 156;
                    section.data(157).dtTransOffset = 332;

                    ;% rtP.C11_Gain
                    section.data(158).logicalSrcIdx = 157;
                    section.data(158).dtTransOffset = 333;

                    ;% rtP.C12_Gain
                    section.data(159).logicalSrcIdx = 158;
                    section.data(159).dtTransOffset = 334;

                    ;% rtP.Du_Gain
                    section.data(160).logicalSrcIdx = 159;
                    section.data(160).dtTransOffset = 335;

                    ;% rtP.Toavoiddivisionbyzero_UpperSat_ipy2dfjdyr
                    section.data(161).logicalSrcIdx = 160;
                    section.data(161).dtTransOffset = 336;

                    ;% rtP.Toavoiddivisionbyzero_LowerSat_ipo4dvmiva
                    section.data(162).logicalSrcIdx = 161;
                    section.data(162).dtTransOffset = 337;

                    ;% rtP.Gain3_Gain_jp2ndmjqu5
                    section.data(163).logicalSrcIdx = 162;
                    section.data(163).dtTransOffset = 338;

                    ;% rtP.Gain1_Gain_nhidfscigt
                    section.data(164).logicalSrcIdx = 163;
                    section.data(164).dtTransOffset = 347;

                    ;% rtP.Gain3_Gain_mvygasyxhr
                    section.data(165).logicalSrcIdx = 164;
                    section.data(165).dtTransOffset = 348;

                    ;% rtP.TransferFcn1_A
                    section.data(166).logicalSrcIdx = 165;
                    section.data(166).dtTransOffset = 357;

                    ;% rtP.TransferFcn1_C
                    section.data(167).logicalSrcIdx = 166;
                    section.data(167).dtTransOffset = 359;

                    ;% rtP.Gain2_Gain_asqeevkcou
                    section.data(168).logicalSrcIdx = 167;
                    section.data(168).dtTransOffset = 361;

                    ;% rtP.TransferFcn2_A
                    section.data(169).logicalSrcIdx = 168;
                    section.data(169).dtTransOffset = 362;

                    ;% rtP.TransferFcn2_C
                    section.data(170).logicalSrcIdx = 169;
                    section.data(170).dtTransOffset = 364;

                    ;% rtP.Gain3_Gain_gnz4vn3ehd
                    section.data(171).logicalSrcIdx = 170;
                    section.data(171).dtTransOffset = 366;

                    ;% rtP.TransferFcn_A_dt3anvvvjk
                    section.data(172).logicalSrcIdx = 171;
                    section.data(172).dtTransOffset = 367;

                    ;% rtP.TransferFcn_C_ebeqd4pm5a
                    section.data(173).logicalSrcIdx = 172;
                    section.data(173).dtTransOffset = 369;

                    ;% rtP.Constant3_Value_nxfd0r3vwv
                    section.data(174).logicalSrcIdx = 173;
                    section.data(174).dtTransOffset = 371;

                    ;% rtP.Constant4_Value_pzmijoxky1
                    section.data(175).logicalSrcIdx = 174;
                    section.data(175).dtTransOffset = 372;

                    ;% rtP.uib1_Gain
                    section.data(176).logicalSrcIdx = 175;
                    section.data(176).dtTransOffset = 373;

                    ;% rtP.uDLookupTable_tableData
                    section.data(177).logicalSrcIdx = 176;
                    section.data(177).dtTransOffset = 374;

                    ;% rtP.uDLookupTable_bp01Data
                    section.data(178).logicalSrcIdx = 177;
                    section.data(178).dtTransOffset = 377;

                    ;% rtP.Constant2_Value_imsydp4sjx
                    section.data(179).logicalSrcIdx = 178;
                    section.data(179).dtTransOffset = 380;

                    ;% rtP.TransferFcn_A_nzocbi1yil
                    section.data(180).logicalSrcIdx = 179;
                    section.data(180).dtTransOffset = 381;

                    ;% rtP.TransferFcn_C_gvrgkkm0gy
                    section.data(181).logicalSrcIdx = 180;
                    section.data(181).dtTransOffset = 383;

                    ;% rtP.TransferFcn1_A_oq1eexzdia
                    section.data(182).logicalSrcIdx = 181;
                    section.data(182).dtTransOffset = 385;

                    ;% rtP.TransferFcn1_C_kgy1sslmk0
                    section.data(183).logicalSrcIdx = 182;
                    section.data(183).dtTransOffset = 387;

                    ;% rtP.Gain2_Gain_nzx0saocj4
                    section.data(184).logicalSrcIdx = 183;
                    section.data(184).dtTransOffset = 389;

                    ;% rtP.TransferFcn2_A_ls5rzge3gu
                    section.data(185).logicalSrcIdx = 184;
                    section.data(185).dtTransOffset = 390;

                    ;% rtP.TransferFcn2_C_hvsgpr5esg
                    section.data(186).logicalSrcIdx = 185;
                    section.data(186).dtTransOffset = 392;

                    ;% rtP.Gain3_Gain_hmwjolcezb
                    section.data(187).logicalSrcIdx = 186;
                    section.data(187).dtTransOffset = 394;

                    ;% rtP.TransferFcn_A_ctlxcv4srh
                    section.data(188).logicalSrcIdx = 187;
                    section.data(188).dtTransOffset = 395;

                    ;% rtP.TransferFcn_C_ieerxo0rjq
                    section.data(189).logicalSrcIdx = 188;
                    section.data(189).dtTransOffset = 397;

                    ;% rtP.TransferFcn1_A_dxdwz5zlll
                    section.data(190).logicalSrcIdx = 189;
                    section.data(190).dtTransOffset = 399;

                    ;% rtP.TransferFcn1_C_lx3veeshxb
                    section.data(191).logicalSrcIdx = 190;
                    section.data(191).dtTransOffset = 401;

                    ;% rtP.Gain2_Gain_n2c2zc5fut
                    section.data(192).logicalSrcIdx = 191;
                    section.data(192).dtTransOffset = 403;

                    ;% rtP.TransferFcn2_A_pejgnp0mdw
                    section.data(193).logicalSrcIdx = 192;
                    section.data(193).dtTransOffset = 404;

                    ;% rtP.TransferFcn2_C_kjbo4vmtza
                    section.data(194).logicalSrcIdx = 193;
                    section.data(194).dtTransOffset = 406;

                    ;% rtP.Gain3_Gain_gzq4wqubv2
                    section.data(195).logicalSrcIdx = 194;
                    section.data(195).dtTransOffset = 408;

                    ;% rtP.UnitDelay_InitialCondition_kjuilmwono
                    section.data(196).logicalSrcIdx = 195;
                    section.data(196).dtTransOffset = 409;

                    ;% rtP.Constant_Value_faygct0s2b
                    section.data(197).logicalSrcIdx = 196;
                    section.data(197).dtTransOffset = 410;

                    ;% rtP.Constant1_Value_bnn31ave1a
                    section.data(198).logicalSrcIdx = 197;
                    section.data(198).dtTransOffset = 411;

                    ;% rtP.Constant2_Value_awyv320bt3
                    section.data(199).logicalSrcIdx = 198;
                    section.data(199).dtTransOffset = 412;

                    ;% rtP.Constant_Value_amasrcypll
                    section.data(200).logicalSrcIdx = 199;
                    section.data(200).dtTransOffset = 413;

                    ;% rtP.Gain1_Gain_bxyi0qtgnl
                    section.data(201).logicalSrcIdx = 200;
                    section.data(201).dtTransOffset = 414;

                    ;% rtP.Q_Value
                    section.data(202).logicalSrcIdx = 201;
                    section.data(202).dtTransOffset = 415;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.selector_Y0
                    section.data(1).logicalSrcIdx = 202;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.hl5zrirewt.dq_Y0
                    section.data(1).logicalSrcIdx = 203;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.gbv0nikqj2.dq_Y0
                    section.data(1).logicalSrcIdx = 204;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.aa2j2wnloo2.dq_Y0
                    section.data(1).logicalSrcIdx = 205;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.gpv2q2mna0v.dq_Y0
                    section.data(1).logicalSrcIdx = 206;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 8;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (rtB)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.gap4mluorh
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 120;
            section.data(120)  = dumData; %prealloc

                    ;% rtB.gktfzcs3fd
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.dbmx3g5hpc
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.dm5evipofq
                    section.data(3).logicalSrcIdx = 3;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.bpposa5psj
                    section.data(4).logicalSrcIdx = 4;
                    section.data(4).dtTransOffset = 3;

                    ;% rtB.a03vq2btj3
                    section.data(5).logicalSrcIdx = 5;
                    section.data(5).dtTransOffset = 15;

                    ;% rtB.bgjph5tzti
                    section.data(6).logicalSrcIdx = 6;
                    section.data(6).dtTransOffset = 21;

                    ;% rtB.kqg04a251b
                    section.data(7).logicalSrcIdx = 7;
                    section.data(7).dtTransOffset = 27;

                    ;% rtB.djau2g1olc
                    section.data(8).logicalSrcIdx = 8;
                    section.data(8).dtTransOffset = 28;

                    ;% rtB.paaqohv05q
                    section.data(9).logicalSrcIdx = 9;
                    section.data(9).dtTransOffset = 31;

                    ;% rtB.k2t2anegon
                    section.data(10).logicalSrcIdx = 10;
                    section.data(10).dtTransOffset = 34;

                    ;% rtB.fo12qitrhm
                    section.data(11).logicalSrcIdx = 11;
                    section.data(11).dtTransOffset = 35;

                    ;% rtB.kkx3bsha4q
                    section.data(12).logicalSrcIdx = 12;
                    section.data(12).dtTransOffset = 36;

                    ;% rtB.prxgf4reyt
                    section.data(13).logicalSrcIdx = 13;
                    section.data(13).dtTransOffset = 37;

                    ;% rtB.dtyrdyfgxc
                    section.data(14).logicalSrcIdx = 14;
                    section.data(14).dtTransOffset = 38;

                    ;% rtB.lhih2qrjjs
                    section.data(15).logicalSrcIdx = 15;
                    section.data(15).dtTransOffset = 39;

                    ;% rtB.j2eixrpwyy
                    section.data(16).logicalSrcIdx = 16;
                    section.data(16).dtTransOffset = 40;

                    ;% rtB.m5uukj3ycd
                    section.data(17).logicalSrcIdx = 17;
                    section.data(17).dtTransOffset = 41;

                    ;% rtB.kq0uqgcvcf
                    section.data(18).logicalSrcIdx = 18;
                    section.data(18).dtTransOffset = 42;

                    ;% rtB.k5kueqchg5
                    section.data(19).logicalSrcIdx = 19;
                    section.data(19).dtTransOffset = 43;

                    ;% rtB.m5bsg3jkvc
                    section.data(20).logicalSrcIdx = 20;
                    section.data(20).dtTransOffset = 44;

                    ;% rtB.exoldmyxco
                    section.data(21).logicalSrcIdx = 21;
                    section.data(21).dtTransOffset = 45;

                    ;% rtB.ffvcceoghv
                    section.data(22).logicalSrcIdx = 22;
                    section.data(22).dtTransOffset = 46;

                    ;% rtB.dgq4jw1zua
                    section.data(23).logicalSrcIdx = 23;
                    section.data(23).dtTransOffset = 49;

                    ;% rtB.k01onl4g5t
                    section.data(24).logicalSrcIdx = 24;
                    section.data(24).dtTransOffset = 50;

                    ;% rtB.llqrd441m5
                    section.data(25).logicalSrcIdx = 25;
                    section.data(25).dtTransOffset = 51;

                    ;% rtB.exj242slie
                    section.data(26).logicalSrcIdx = 26;
                    section.data(26).dtTransOffset = 52;

                    ;% rtB.ckayt42vf3
                    section.data(27).logicalSrcIdx = 27;
                    section.data(27).dtTransOffset = 53;

                    ;% rtB.oijk30i103
                    section.data(28).logicalSrcIdx = 28;
                    section.data(28).dtTransOffset = 54;

                    ;% rtB.jkth2sfciv
                    section.data(29).logicalSrcIdx = 29;
                    section.data(29).dtTransOffset = 55;

                    ;% rtB.psgxvcmjhn
                    section.data(30).logicalSrcIdx = 30;
                    section.data(30).dtTransOffset = 56;

                    ;% rtB.mqhymewypv
                    section.data(31).logicalSrcIdx = 31;
                    section.data(31).dtTransOffset = 57;

                    ;% rtB.hhnk2g0wfl
                    section.data(32).logicalSrcIdx = 32;
                    section.data(32).dtTransOffset = 58;

                    ;% rtB.gphcjhvv1a
                    section.data(33).logicalSrcIdx = 33;
                    section.data(33).dtTransOffset = 59;

                    ;% rtB.jvo1ddk5yj
                    section.data(34).logicalSrcIdx = 34;
                    section.data(34).dtTransOffset = 60;

                    ;% rtB.gbqdu1hcwl
                    section.data(35).logicalSrcIdx = 35;
                    section.data(35).dtTransOffset = 61;

                    ;% rtB.k0pwj4jxiq
                    section.data(36).logicalSrcIdx = 36;
                    section.data(36).dtTransOffset = 62;

                    ;% rtB.dijcpphi4p
                    section.data(37).logicalSrcIdx = 37;
                    section.data(37).dtTransOffset = 63;

                    ;% rtB.amr33vumq0
                    section.data(38).logicalSrcIdx = 38;
                    section.data(38).dtTransOffset = 64;

                    ;% rtB.gc2xht4yqo
                    section.data(39).logicalSrcIdx = 39;
                    section.data(39).dtTransOffset = 65;

                    ;% rtB.iosedcm1tf
                    section.data(40).logicalSrcIdx = 40;
                    section.data(40).dtTransOffset = 66;

                    ;% rtB.oll4rfkmhz
                    section.data(41).logicalSrcIdx = 41;
                    section.data(41).dtTransOffset = 67;

                    ;% rtB.cnh4llzau0
                    section.data(42).logicalSrcIdx = 42;
                    section.data(42).dtTransOffset = 68;

                    ;% rtB.aebuj4jliw
                    section.data(43).logicalSrcIdx = 43;
                    section.data(43).dtTransOffset = 69;

                    ;% rtB.f2yfeiz4wx
                    section.data(44).logicalSrcIdx = 44;
                    section.data(44).dtTransOffset = 70;

                    ;% rtB.mm4x5kerfj
                    section.data(45).logicalSrcIdx = 45;
                    section.data(45).dtTransOffset = 71;

                    ;% rtB.ejg1ybzhgl
                    section.data(46).logicalSrcIdx = 46;
                    section.data(46).dtTransOffset = 72;

                    ;% rtB.k1rxqwgc5o
                    section.data(47).logicalSrcIdx = 47;
                    section.data(47).dtTransOffset = 73;

                    ;% rtB.n4ots5cknz
                    section.data(48).logicalSrcIdx = 48;
                    section.data(48).dtTransOffset = 74;

                    ;% rtB.brzgt5o0ly
                    section.data(49).logicalSrcIdx = 49;
                    section.data(49).dtTransOffset = 75;

                    ;% rtB.fbrwvcuz2e
                    section.data(50).logicalSrcIdx = 50;
                    section.data(50).dtTransOffset = 76;

                    ;% rtB.lrkvpii4gh
                    section.data(51).logicalSrcIdx = 51;
                    section.data(51).dtTransOffset = 77;

                    ;% rtB.orccexijhq
                    section.data(52).logicalSrcIdx = 52;
                    section.data(52).dtTransOffset = 78;

                    ;% rtB.erof3sa2ef
                    section.data(53).logicalSrcIdx = 53;
                    section.data(53).dtTransOffset = 79;

                    ;% rtB.kyvouqb0no
                    section.data(54).logicalSrcIdx = 54;
                    section.data(54).dtTransOffset = 80;

                    ;% rtB.gungbq04sb
                    section.data(55).logicalSrcIdx = 55;
                    section.data(55).dtTransOffset = 81;

                    ;% rtB.b4jfht23g2
                    section.data(56).logicalSrcIdx = 56;
                    section.data(56).dtTransOffset = 82;

                    ;% rtB.f0vgkk3bhk
                    section.data(57).logicalSrcIdx = 57;
                    section.data(57).dtTransOffset = 83;

                    ;% rtB.dvkqumepgk
                    section.data(58).logicalSrcIdx = 58;
                    section.data(58).dtTransOffset = 86;

                    ;% rtB.fvbww5mjui
                    section.data(59).logicalSrcIdx = 59;
                    section.data(59).dtTransOffset = 89;

                    ;% rtB.gimxw5025n
                    section.data(60).logicalSrcIdx = 60;
                    section.data(60).dtTransOffset = 91;

                    ;% rtB.j2ygziwuza
                    section.data(61).logicalSrcIdx = 61;
                    section.data(61).dtTransOffset = 93;

                    ;% rtB.i3co5cpqer
                    section.data(62).logicalSrcIdx = 62;
                    section.data(62).dtTransOffset = 96;

                    ;% rtB.pusmndwhp4
                    section.data(63).logicalSrcIdx = 63;
                    section.data(63).dtTransOffset = 99;

                    ;% rtB.li0okspf41
                    section.data(64).logicalSrcIdx = 64;
                    section.data(64).dtTransOffset = 102;

                    ;% rtB.eqrscq4msa
                    section.data(65).logicalSrcIdx = 65;
                    section.data(65).dtTransOffset = 103;

                    ;% rtB.mv0i5cphjf
                    section.data(66).logicalSrcIdx = 66;
                    section.data(66).dtTransOffset = 104;

                    ;% rtB.bt2aomm4y4
                    section.data(67).logicalSrcIdx = 67;
                    section.data(67).dtTransOffset = 105;

                    ;% rtB.bj5uxavhae
                    section.data(68).logicalSrcIdx = 68;
                    section.data(68).dtTransOffset = 106;

                    ;% rtB.a4ynar3r0p
                    section.data(69).logicalSrcIdx = 69;
                    section.data(69).dtTransOffset = 107;

                    ;% rtB.kd4hozccoi
                    section.data(70).logicalSrcIdx = 70;
                    section.data(70).dtTransOffset = 108;

                    ;% rtB.itzulpyuw2
                    section.data(71).logicalSrcIdx = 71;
                    section.data(71).dtTransOffset = 109;

                    ;% rtB.otuvlsx5ys
                    section.data(72).logicalSrcIdx = 72;
                    section.data(72).dtTransOffset = 110;

                    ;% rtB.j0n1jzgntq
                    section.data(73).logicalSrcIdx = 73;
                    section.data(73).dtTransOffset = 111;

                    ;% rtB.jmwusjiov1
                    section.data(74).logicalSrcIdx = 74;
                    section.data(74).dtTransOffset = 112;

                    ;% rtB.jb4fsta5my
                    section.data(75).logicalSrcIdx = 75;
                    section.data(75).dtTransOffset = 113;

                    ;% rtB.hm5ofsqtib
                    section.data(76).logicalSrcIdx = 76;
                    section.data(76).dtTransOffset = 114;

                    ;% rtB.amhtuysrig
                    section.data(77).logicalSrcIdx = 77;
                    section.data(77).dtTransOffset = 115;

                    ;% rtB.aylp23sizt
                    section.data(78).logicalSrcIdx = 78;
                    section.data(78).dtTransOffset = 116;

                    ;% rtB.fdwocsfez5
                    section.data(79).logicalSrcIdx = 79;
                    section.data(79).dtTransOffset = 117;

                    ;% rtB.cdgmcxdgxx
                    section.data(80).logicalSrcIdx = 80;
                    section.data(80).dtTransOffset = 118;

                    ;% rtB.it4rtc1qod
                    section.data(81).logicalSrcIdx = 81;
                    section.data(81).dtTransOffset = 124;

                    ;% rtB.dsjsfniaum
                    section.data(82).logicalSrcIdx = 82;
                    section.data(82).dtTransOffset = 125;

                    ;% rtB.dcuhhc42lm
                    section.data(83).logicalSrcIdx = 83;
                    section.data(83).dtTransOffset = 126;

                    ;% rtB.osecmroasz
                    section.data(84).logicalSrcIdx = 84;
                    section.data(84).dtTransOffset = 127;

                    ;% rtB.gei3qlbkau
                    section.data(85).logicalSrcIdx = 85;
                    section.data(85).dtTransOffset = 128;

                    ;% rtB.k2r2gd5thc
                    section.data(86).logicalSrcIdx = 86;
                    section.data(86).dtTransOffset = 129;

                    ;% rtB.hxgcychvxe
                    section.data(87).logicalSrcIdx = 87;
                    section.data(87).dtTransOffset = 130;

                    ;% rtB.ojpmhqp3hb
                    section.data(88).logicalSrcIdx = 88;
                    section.data(88).dtTransOffset = 131;

                    ;% rtB.dfsza0jb3r
                    section.data(89).logicalSrcIdx = 89;
                    section.data(89).dtTransOffset = 132;

                    ;% rtB.aydt5pakqc
                    section.data(90).logicalSrcIdx = 90;
                    section.data(90).dtTransOffset = 133;

                    ;% rtB.gahdo2523m
                    section.data(91).logicalSrcIdx = 91;
                    section.data(91).dtTransOffset = 134;

                    ;% rtB.brq4reciat
                    section.data(92).logicalSrcIdx = 92;
                    section.data(92).dtTransOffset = 135;

                    ;% rtB.mv2ve5xuao
                    section.data(93).logicalSrcIdx = 93;
                    section.data(93).dtTransOffset = 136;

                    ;% rtB.lzxedsxie0
                    section.data(94).logicalSrcIdx = 94;
                    section.data(94).dtTransOffset = 137;

                    ;% rtB.f2eidvmh01
                    section.data(95).logicalSrcIdx = 95;
                    section.data(95).dtTransOffset = 138;

                    ;% rtB.ermyprlyya
                    section.data(96).logicalSrcIdx = 96;
                    section.data(96).dtTransOffset = 139;

                    ;% rtB.jqerscg1zt
                    section.data(97).logicalSrcIdx = 97;
                    section.data(97).dtTransOffset = 140;

                    ;% rtB.pqq2mzl5yy
                    section.data(98).logicalSrcIdx = 98;
                    section.data(98).dtTransOffset = 141;

                    ;% rtB.emtuteg24p
                    section.data(99).logicalSrcIdx = 99;
                    section.data(99).dtTransOffset = 142;

                    ;% rtB.gfw00daf11
                    section.data(100).logicalSrcIdx = 100;
                    section.data(100).dtTransOffset = 143;

                    ;% rtB.klqpdibj32
                    section.data(101).logicalSrcIdx = 101;
                    section.data(101).dtTransOffset = 144;

                    ;% rtB.jdm55m0vau
                    section.data(102).logicalSrcIdx = 102;
                    section.data(102).dtTransOffset = 145;

                    ;% rtB.hohn5tgzlv
                    section.data(103).logicalSrcIdx = 103;
                    section.data(103).dtTransOffset = 146;

                    ;% rtB.asbptj5zaz
                    section.data(104).logicalSrcIdx = 104;
                    section.data(104).dtTransOffset = 147;

                    ;% rtB.nred03mov5
                    section.data(105).logicalSrcIdx = 105;
                    section.data(105).dtTransOffset = 148;

                    ;% rtB.onjteuktwt
                    section.data(106).logicalSrcIdx = 106;
                    section.data(106).dtTransOffset = 149;

                    ;% rtB.jfashjspdq
                    section.data(107).logicalSrcIdx = 107;
                    section.data(107).dtTransOffset = 150;

                    ;% rtB.hujgllbkhe
                    section.data(108).logicalSrcIdx = 108;
                    section.data(108).dtTransOffset = 151;

                    ;% rtB.pe3tnbqbgy
                    section.data(109).logicalSrcIdx = 109;
                    section.data(109).dtTransOffset = 152;

                    ;% rtB.emd031udec
                    section.data(110).logicalSrcIdx = 110;
                    section.data(110).dtTransOffset = 153;

                    ;% rtB.hs004dp4hy
                    section.data(111).logicalSrcIdx = 111;
                    section.data(111).dtTransOffset = 154;

                    ;% rtB.lejcvssl30
                    section.data(112).logicalSrcIdx = 112;
                    section.data(112).dtTransOffset = 155;

                    ;% rtB.omw4a1utb1
                    section.data(113).logicalSrcIdx = 113;
                    section.data(113).dtTransOffset = 156;

                    ;% rtB.aiseatx5p4
                    section.data(114).logicalSrcIdx = 114;
                    section.data(114).dtTransOffset = 157;

                    ;% rtB.lsxposbkab
                    section.data(115).logicalSrcIdx = 115;
                    section.data(115).dtTransOffset = 160;

                    ;% rtB.p52yfpva5l
                    section.data(116).logicalSrcIdx = 116;
                    section.data(116).dtTransOffset = 163;

                    ;% rtB.fdljtyo4lz
                    section.data(117).logicalSrcIdx = 117;
                    section.data(117).dtTransOffset = 165;

                    ;% rtB.jwdiimvvl4
                    section.data(118).logicalSrcIdx = 118;
                    section.data(118).dtTransOffset = 166;

                    ;% rtB.e3pcbwyj3i
                    section.data(119).logicalSrcIdx = 119;
                    section.data(119).dtTransOffset = 167;

                    ;% rtB.aah0x3cxyl
                    section.data(120).logicalSrcIdx = 120;
                    section.data(120).dtTransOffset = 168;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% rtB.ejjuk1fwje
                    section.data(1).logicalSrcIdx = 121;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.bjycl5wbcz
                    section.data(2).logicalSrcIdx = 122;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.ogehm3eyx3
                    section.data(3).logicalSrcIdx = 123;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.oakfin4jis
                    section.data(4).logicalSrcIdx = 124;
                    section.data(4).dtTransOffset = 3;

                    ;% rtB.eo33rm2kiy
                    section.data(5).logicalSrcIdx = 125;
                    section.data(5).dtTransOffset = 4;

                    ;% rtB.jr2eclq22h
                    section.data(6).logicalSrcIdx = 126;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% rtB.hzmul4slgt
                    section.data(1).logicalSrcIdx = 127;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.lbe40ygcva
                    section.data(2).logicalSrcIdx = 128;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.ejejjrbn43
                    section.data(3).logicalSrcIdx = 129;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.g524d0rboe
                    section.data(4).logicalSrcIdx = 130;
                    section.data(4).dtTransOffset = 5;

                    ;% rtB.k0zgmoo03i
                    section.data(5).logicalSrcIdx = 131;
                    section.data(5).dtTransOffset = 6;

                    ;% rtB.kiunlxs5sx
                    section.data(6).logicalSrcIdx = 132;
                    section.data(6).dtTransOffset = 7;

                    ;% rtB.bx3i1gippc
                    section.data(7).logicalSrcIdx = 133;
                    section.data(7).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtB.hl5zrirewt.otn2ta4rye
                    section.data(1).logicalSrcIdx = 134;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.hl5zrirewt.ow32b43xgs
                    section.data(2).logicalSrcIdx = 135;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            sigMap.sections(5) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtB.gbv0nikqj2.j2nl0k3bjo
                    section.data(1).logicalSrcIdx = 136;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.gbv0nikqj2.dxu5h4veqy
                    section.data(2).logicalSrcIdx = 137;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            sigMap.sections(6) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtB.aa2j2wnloo2.otn2ta4rye
                    section.data(1).logicalSrcIdx = 138;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.aa2j2wnloo2.ow32b43xgs
                    section.data(2).logicalSrcIdx = 139;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            sigMap.sections(7) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtB.gpv2q2mna0v.j2nl0k3bjo
                    section.data(1).logicalSrcIdx = 140;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.gpv2q2mna0v.dxu5h4veqy
                    section.data(2).logicalSrcIdx = 141;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            sigMap.sections(8) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 16;
        sectIdxOffset = 8;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (rtDW)
        ;%
            section.nData     = 28;
            section.data(28)  = dumData; %prealloc

                    ;% rtDW.naju1uwbkg
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.iz4mjb3fpi
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% rtDW.kanrys502u
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 8;

                    ;% rtDW.il2g04n2zg
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 9;

                    ;% rtDW.lc4skbr0sd
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 10;

                    ;% rtDW.kmcobpcqvr
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 11;

                    ;% rtDW.dcvx0x0nhj
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 12;

                    ;% rtDW.jonetifjdl
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 13;

                    ;% rtDW.k5octspggf
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 14;

                    ;% rtDW.kurtqaimb2
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 15;

                    ;% rtDW.m3xa5qdlgu
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 16;

                    ;% rtDW.g4a2feilda
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 17;

                    ;% rtDW.ati3zogtqu
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 18;

                    ;% rtDW.n5yzxageiq
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 19;

                    ;% rtDW.hxzxqy2ytd
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 20;

                    ;% rtDW.lpdpgewspm
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 21;

                    ;% rtDW.bwt1hrltpz
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 22;

                    ;% rtDW.o4yzgxidzo
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 23;

                    ;% rtDW.puptsnuvic
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 24;

                    ;% rtDW.do51saudm1
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 25;

                    ;% rtDW.ejvm3rk4rw
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 26;

                    ;% rtDW.hrtqjrd53x
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 27;

                    ;% rtDW.pvzxgas2b3
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 28;

                    ;% rtDW.edvu1xljbk
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 29;

                    ;% rtDW.d3leen4kcy
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 30;

                    ;% rtDW.jycqzsqlqh.modelTStart
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 31;

                    ;% rtDW.omzfzlvkmy.modelTStart
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 32;

                    ;% rtDW.hrjhnmw2gy.modelTStart
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 33;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% rtDW.empra3chml.AS
                    section.data(1).logicalSrcIdx = 28;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.f4qjpvtvia.LoggedData
                    section.data(2).logicalSrcIdx = 29;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.nr4hpz0s5b.TUbufferPtrs
                    section.data(3).logicalSrcIdx = 30;
                    section.data(3).dtTransOffset = 3;

                    ;% rtDW.nowwneuenp.LoggedData
                    section.data(4).logicalSrcIdx = 31;
                    section.data(4).dtTransOffset = 6;

                    ;% rtDW.iske0ojumf.LoggedData
                    section.data(5).logicalSrcIdx = 32;
                    section.data(5).dtTransOffset = 8;

                    ;% rtDW.mlq3s0zii4.TUbufferPtrs
                    section.data(6).logicalSrcIdx = 33;
                    section.data(6).dtTransOffset = 10;

                    ;% rtDW.n2b5jg51yt.TUbufferPtrs
                    section.data(7).logicalSrcIdx = 34;
                    section.data(7).dtTransOffset = 13;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% rtDW.cbxygsrulg
                    section.data(1).logicalSrcIdx = 35;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.oehqsdtju1
                    section.data(2).logicalSrcIdx = 36;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.ebrnrfebzf
                    section.data(3).logicalSrcIdx = 37;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.mr1ke3zacb
                    section.data(1).logicalSrcIdx = 38;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% rtDW.crtkqsbmaj
                    section.data(1).logicalSrcIdx = 39;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.kuxuhbis4w
                    section.data(2).logicalSrcIdx = 40;
                    section.data(2).dtTransOffset = 11;

                    ;% rtDW.e3u5ld2y51.Tail
                    section.data(3).logicalSrcIdx = 41;
                    section.data(3).dtTransOffset = 12;

                    ;% rtDW.itw05pv4q1.Tail
                    section.data(4).logicalSrcIdx = 42;
                    section.data(4).dtTransOffset = 13;

                    ;% rtDW.oyd0zxlfez.Tail
                    section.data(5).logicalSrcIdx = 43;
                    section.data(5).dtTransOffset = 14;

                    ;% rtDW.dg3sdnhfhz
                    section.data(6).logicalSrcIdx = 44;
                    section.data(6).dtTransOffset = 15;

                    ;% rtDW.chgudtwki5
                    section.data(7).logicalSrcIdx = 45;
                    section.data(7).dtTransOffset = 16;

                    ;% rtDW.cxei33jqmq
                    section.data(8).logicalSrcIdx = 46;
                    section.data(8).dtTransOffset = 17;

                    ;% rtDW.bisetz5iuz
                    section.data(9).logicalSrcIdx = 47;
                    section.data(9).dtTransOffset = 18;

                    ;% rtDW.lguevo5cl5
                    section.data(10).logicalSrcIdx = 48;
                    section.data(10).dtTransOffset = 19;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% rtDW.ee4ok4zlel
                    section.data(1).logicalSrcIdx = 49;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.mvk1crirkl
                    section.data(2).logicalSrcIdx = 50;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.c2l3p2qtjf
                    section.data(3).logicalSrcIdx = 51;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.kza5ow0kr4
                    section.data(4).logicalSrcIdx = 52;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.oxvhzb4uhf
                    section.data(5).logicalSrcIdx = 53;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% rtDW.aw1t1zwgas
                    section.data(1).logicalSrcIdx = 54;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.aisofpnorv
                    section.data(2).logicalSrcIdx = 55;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.hsca3knam3
                    section.data(3).logicalSrcIdx = 56;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.loledzy1qu
                    section.data(4).logicalSrcIdx = 57;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% rtDW.oacr45potf
                    section.data(1).logicalSrcIdx = 58;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.lp022slzwu
                    section.data(2).logicalSrcIdx = 59;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.ls1rbfacqf
                    section.data(3).logicalSrcIdx = 60;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.navvsf1ufo
                    section.data(4).logicalSrcIdx = 61;
                    section.data(4).dtTransOffset = 5;

                    ;% rtDW.fbyhlicb5e
                    section.data(5).logicalSrcIdx = 62;
                    section.data(5).dtTransOffset = 6;

                    ;% rtDW.nf2gbckq3n
                    section.data(6).logicalSrcIdx = 63;
                    section.data(6).dtTransOffset = 7;

                    ;% rtDW.o2b5vrjagl
                    section.data(7).logicalSrcIdx = 64;
                    section.data(7).dtTransOffset = 8;

                    ;% rtDW.bv4jm4qenv
                    section.data(8).logicalSrcIdx = 65;
                    section.data(8).dtTransOffset = 9;

                    ;% rtDW.fbzp2gawrm
                    section.data(9).logicalSrcIdx = 66;
                    section.data(9).dtTransOffset = 10;

                    ;% rtDW.ovo53pq3zf
                    section.data(10).logicalSrcIdx = 67;
                    section.data(10).dtTransOffset = 11;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.hl5zrirewt.fqy4beoqau
                    section.data(1).logicalSrcIdx = 68;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.hl5zrirewt.mvk4qyxu0n
                    section.data(1).logicalSrcIdx = 69;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.gbv0nikqj2.ofjd3uadhp
                    section.data(1).logicalSrcIdx = 70;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(11) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.gbv0nikqj2.eya5d5vx55
                    section.data(1).logicalSrcIdx = 71;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(12) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.aa2j2wnloo2.fqy4beoqau
                    section.data(1).logicalSrcIdx = 72;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(13) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.aa2j2wnloo2.mvk4qyxu0n
                    section.data(1).logicalSrcIdx = 73;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(14) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.gpv2q2mna0v.ofjd3uadhp
                    section.data(1).logicalSrcIdx = 74;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(15) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.gpv2q2mna0v.eya5d5vx55
                    section.data(1).logicalSrcIdx = 75;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(16) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 1263269511;
    targMap.checksum1 = 3066790768;
    targMap.checksum2 = 1316343474;
    targMap.checksum3 = 2761255352;

