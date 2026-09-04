    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 5;
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
            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% rtP.Q
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.T_S
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 81;

                    ;% rtP.DetectChange_vinit
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 82;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.DetectChange1_vinit
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 36;
            section.data(36)  = dumData; %prealloc

                    ;% rtP.PulseGenerator_Amp
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.PulseGenerator_Period
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.PulseGenerator_Duty
                    section.data(3).logicalSrcIdx = 6;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.PulseGenerator_PhaseDelay
                    section.data(4).logicalSrcIdx = 7;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.Delay2_InitialCondition
                    section.data(5).logicalSrcIdx = 8;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.VariableIntegerDelay_InitialCondition
                    section.data(6).logicalSrcIdx = 9;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.Constant1_Value
                    section.data(7).logicalSrcIdx = 10;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.Step1_Time
                    section.data(8).logicalSrcIdx = 11;
                    section.data(8).dtTransOffset = 7;

                    ;% rtP.Step1_Y0
                    section.data(9).logicalSrcIdx = 12;
                    section.data(9).dtTransOffset = 8;

                    ;% rtP.Step1_YFinal
                    section.data(10).logicalSrcIdx = 13;
                    section.data(10).dtTransOffset = 9;

                    ;% rtP.Constant_Value
                    section.data(11).logicalSrcIdx = 14;
                    section.data(11).dtTransOffset = 10;

                    ;% rtP.Constant1_Value_c2vf1mlipc
                    section.data(12).logicalSrcIdx = 15;
                    section.data(12).dtTransOffset = 46;

                    ;% rtP.Constant2_Value
                    section.data(13).logicalSrcIdx = 16;
                    section.data(13).dtTransOffset = 47;

                    ;% rtP.Constant5_Value
                    section.data(14).logicalSrcIdx = 17;
                    section.data(14).dtTransOffset = 53;

                    ;% rtP.Step1_Time_ostrpcewxx
                    section.data(15).logicalSrcIdx = 18;
                    section.data(15).dtTransOffset = 54;

                    ;% rtP.Step1_Y0_bf5ui0nx2l
                    section.data(16).logicalSrcIdx = 19;
                    section.data(16).dtTransOffset = 55;

                    ;% rtP.Step1_YFinal_c35jqjcyg4
                    section.data(17).logicalSrcIdx = 20;
                    section.data(17).dtTransOffset = 56;

                    ;% rtP.Constant_Value_mproqzully
                    section.data(18).logicalSrcIdx = 21;
                    section.data(18).dtTransOffset = 57;

                    ;% rtP.fromWS_Signal1_Time0
                    section.data(19).logicalSrcIdx = 22;
                    section.data(19).dtTransOffset = 58;

                    ;% rtP.fromWS_Signal1_Data0
                    section.data(20).logicalSrcIdx = 23;
                    section.data(20).dtTransOffset = 65;

                    ;% rtP.UnitDelay_InitialCondition
                    section.data(21).logicalSrcIdx = 24;
                    section.data(21).dtTransOffset = 72;

                    ;% rtP.RT13_InitialCondition
                    section.data(22).logicalSrcIdx = 25;
                    section.data(22).dtTransOffset = 73;

                    ;% rtP.RT5_InitialCondition
                    section.data(23).logicalSrcIdx = 26;
                    section.data(23).dtTransOffset = 74;

                    ;% rtP.RT9_InitialCondition
                    section.data(24).logicalSrcIdx = 27;
                    section.data(24).dtTransOffset = 75;

                    ;% rtP.RT15_InitialCondition
                    section.data(25).logicalSrcIdx = 28;
                    section.data(25).dtTransOffset = 76;

                    ;% rtP.RT11_InitialCondition
                    section.data(26).logicalSrcIdx = 29;
                    section.data(26).dtTransOffset = 77;

                    ;% rtP.RT1_InitialCondition
                    section.data(27).logicalSrcIdx = 30;
                    section.data(27).dtTransOffset = 78;

                    ;% rtP.RT2_InitialCondition
                    section.data(28).logicalSrcIdx = 31;
                    section.data(28).dtTransOffset = 79;

                    ;% rtP.RT6_InitialCondition
                    section.data(29).logicalSrcIdx = 32;
                    section.data(29).dtTransOffset = 80;

                    ;% rtP.RT8_InitialCondition
                    section.data(30).logicalSrcIdx = 33;
                    section.data(30).dtTransOffset = 81;

                    ;% rtP.RT16_InitialCondition
                    section.data(31).logicalSrcIdx = 34;
                    section.data(31).dtTransOffset = 82;

                    ;% rtP.RT12_InitialCondition
                    section.data(32).logicalSrcIdx = 35;
                    section.data(32).dtTransOffset = 83;

                    ;% rtP.RT3_InitialCondition
                    section.data(33).logicalSrcIdx = 36;
                    section.data(33).dtTransOffset = 84;

                    ;% rtP.RT14_InitialCondition
                    section.data(34).logicalSrcIdx = 37;
                    section.data(34).dtTransOffset = 85;

                    ;% rtP.RT_InitialCondition
                    section.data(35).logicalSrcIdx = 38;
                    section.data(35).dtTransOffset = 86;

                    ;% rtP.RT4_InitialCondition
                    section.data(36).logicalSrcIdx = 39;
                    section.data(36).dtTransOffset = 87;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.RT7_InitialCondition
                    section.data(1).logicalSrcIdx = 40;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.VariableIntegerDelay_DiagnosticForDelayLength
                    section.data(1).logicalSrcIdx = 41;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
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
        nTotSects     = 2;
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
            section.nData     = 30;
            section.data(30)  = dumData; %prealloc

                    ;% rtB.cqzfaecv4m
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.bvjoabbgen
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.pvqul3j2kd
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.h33i3u05hi
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 8;

                    ;% rtB.pf1bcrl5dc
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 44;

                    ;% rtB.brgnx55w3z
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 50;

                    ;% rtB.gadvm22wd1
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 56;

                    ;% rtB.fefh0hhvrv
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 92;

                    ;% rtB.if5diqfxfu
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 93;

                    ;% rtB.patf3kg4ld
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 102;

                    ;% rtB.b3yhnwjth4
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 183;

                    ;% rtB.a4mpu0tcou
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 192;

                    ;% rtB.beqtta0fdy
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 228;

                    ;% rtB.lqpivh20ue
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 309;

                    ;% rtB.etvej00kls
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 315;

                    ;% rtB.g3dvnnpaww
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 324;

                    ;% rtB.bxo2fb1001
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 325;

                    ;% rtB.ahdogngpdy
                    section.data(18).logicalSrcIdx = 18;
                    section.data(18).dtTransOffset = 326;

                    ;% rtB.ddbaqxsz3c
                    section.data(19).logicalSrcIdx = 19;
                    section.data(19).dtTransOffset = 332;

                    ;% rtB.euw0jex01r
                    section.data(20).logicalSrcIdx = 20;
                    section.data(20).dtTransOffset = 368;

                    ;% rtB.lcdsgbjfwb
                    section.data(21).logicalSrcIdx = 23;
                    section.data(21).dtTransOffset = 369;

                    ;% rtB.fstyznqnc5
                    section.data(22).logicalSrcIdx = 24;
                    section.data(22).dtTransOffset = 378;

                    ;% rtB.otgdt14a05
                    section.data(23).logicalSrcIdx = 25;
                    section.data(23).dtTransOffset = 459;

                    ;% rtB.ll4syrh021
                    section.data(24).logicalSrcIdx = 26;
                    section.data(24).dtTransOffset = 460;

                    ;% rtB.i5dfrly4pb
                    section.data(25).logicalSrcIdx = 27;
                    section.data(25).dtTransOffset = 461;

                    ;% rtB.hqfbb0iret
                    section.data(26).logicalSrcIdx = 28;
                    section.data(26).dtTransOffset = 467;

                    ;% rtB.etbnu02wn1
                    section.data(27).logicalSrcIdx = 29;
                    section.data(27).dtTransOffset = 476;

                    ;% rtB.erku2k0xec
                    section.data(28).logicalSrcIdx = 30;
                    section.data(28).dtTransOffset = 512;

                    ;% rtB.hvbnpziw45
                    section.data(29).logicalSrcIdx = 31;
                    section.data(29).dtTransOffset = 593;

                    ;% rtB.j2ny3wc1th
                    section.data(30).logicalSrcIdx = 32;
                    section.data(30).dtTransOffset = 594;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtB.bxq1yx2osy
                    section.data(1).logicalSrcIdx = 34;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.psxllogfzm
                    section.data(2).logicalSrcIdx = 35;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
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
        nTotSects     = 12;
        sectIdxOffset = 2;

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
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.gocvwhon5y
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.mznmhfvmea
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.mhyvkdo2ux
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.mzifbxk1wn
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 45;
            section.data(45)  = dumData; %prealloc

                    ;% rtDW.lo3qyprm4b
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.beqcpe00sh
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.fcyc3lekf3
                    section.data(3).logicalSrcIdx = 6;
                    section.data(3).dtTransOffset = 7;

                    ;% rtDW.a0i41tv53p
                    section.data(4).logicalSrcIdx = 7;
                    section.data(4).dtTransOffset = 43;

                    ;% rtDW.jw1guf4gc4
                    section.data(5).logicalSrcIdx = 8;
                    section.data(5).dtTransOffset = 44;

                    ;% rtDW.de4tsmwird
                    section.data(6).logicalSrcIdx = 9;
                    section.data(6).dtTransOffset = 544;

                    ;% rtDW.h3pyo5aafm
                    section.data(7).logicalSrcIdx = 10;
                    section.data(7).dtTransOffset = 553;

                    ;% rtDW.iivzqnnafg
                    section.data(8).logicalSrcIdx = 11;
                    section.data(8).dtTransOffset = 634;

                    ;% rtDW.dfuabdacjg
                    section.data(9).logicalSrcIdx = 12;
                    section.data(9).dtTransOffset = 635;

                    ;% rtDW.dtytunz3lh
                    section.data(10).logicalSrcIdx = 13;
                    section.data(10).dtTransOffset = 638;

                    ;% rtDW.cfze1vz5si
                    section.data(11).logicalSrcIdx = 14;
                    section.data(11).dtTransOffset = 641;

                    ;% rtDW.cmrxwx2p1q
                    section.data(12).logicalSrcIdx = 15;
                    section.data(12).dtTransOffset = 659;

                    ;% rtDW.h4yjnfwxyj
                    section.data(13).logicalSrcIdx = 16;
                    section.data(13).dtTransOffset = 767;

                    ;% rtDW.bgcbhaqa0v
                    section.data(14).logicalSrcIdx = 17;
                    section.data(14).dtTransOffset = 773;

                    ;% rtDW.mgieiokwlg
                    section.data(15).logicalSrcIdx = 18;
                    section.data(15).dtTransOffset = 779;

                    ;% rtDW.ew4umcwnpz
                    section.data(16).logicalSrcIdx = 19;
                    section.data(16).dtTransOffset = 780;

                    ;% rtDW.ppuxszxz4r
                    section.data(17).logicalSrcIdx = 20;
                    section.data(17).dtTransOffset = 786;

                    ;% rtDW.lgvzz3uvac
                    section.data(18).logicalSrcIdx = 21;
                    section.data(18).dtTransOffset = 792;

                    ;% rtDW.dmeue2mdbu
                    section.data(19).logicalSrcIdx = 22;
                    section.data(19).dtTransOffset = 793;

                    ;% rtDW.admijup4h5
                    section.data(20).logicalSrcIdx = 23;
                    section.data(20).dtTransOffset = 829;

                    ;% rtDW.lnkw33l3jm
                    section.data(21).logicalSrcIdx = 24;
                    section.data(21).dtTransOffset = 865;

                    ;% rtDW.hvzeco2ore
                    section.data(22).logicalSrcIdx = 25;
                    section.data(22).dtTransOffset = 866;

                    ;% rtDW.mvtpbffmvi
                    section.data(23).logicalSrcIdx = 26;
                    section.data(23).dtTransOffset = 869;

                    ;% rtDW.fqe0q3cfrn
                    section.data(24).logicalSrcIdx = 27;
                    section.data(24).dtTransOffset = 896;

                    ;% rtDW.l2yr52gncr
                    section.data(25).logicalSrcIdx = 28;
                    section.data(25).dtTransOffset = 1139;

                    ;% rtDW.ezsyklwnq5
                    section.data(26).logicalSrcIdx = 29;
                    section.data(26).dtTransOffset = 1148;

                    ;% rtDW.kaofucg0ce
                    section.data(27).logicalSrcIdx = 30;
                    section.data(27).dtTransOffset = 1157;

                    ;% rtDW.id31qo414u
                    section.data(28).logicalSrcIdx = 31;
                    section.data(28).dtTransOffset = 1158;

                    ;% rtDW.jyvxuxxqjf
                    section.data(29).logicalSrcIdx = 32;
                    section.data(29).dtTransOffset = 1194;

                    ;% rtDW.i4vu5e54ap
                    section.data(30).logicalSrcIdx = 33;
                    section.data(30).dtTransOffset = 1230;

                    ;% rtDW.ihu2yalc0n
                    section.data(31).logicalSrcIdx = 34;
                    section.data(31).dtTransOffset = 1231;

                    ;% rtDW.pil0xca4t5
                    section.data(32).logicalSrcIdx = 35;
                    section.data(32).dtTransOffset = 1312;

                    ;% rtDW.iwm01ftkab
                    section.data(33).logicalSrcIdx = 36;
                    section.data(33).dtTransOffset = 1393;

                    ;% rtDW.kstza1wr21
                    section.data(34).logicalSrcIdx = 37;
                    section.data(34).dtTransOffset = 1394;

                    ;% rtDW.b2kfls1nvu
                    section.data(35).logicalSrcIdx = 38;
                    section.data(35).dtTransOffset = 1400;

                    ;% rtDW.jpaa1akovd
                    section.data(36).logicalSrcIdx = 39;
                    section.data(36).dtTransOffset = 1406;

                    ;% rtDW.halwmwe2x0
                    section.data(37).logicalSrcIdx = 40;
                    section.data(37).dtTransOffset = 1407;

                    ;% rtDW.c2dnexkmxf
                    section.data(38).logicalSrcIdx = 41;
                    section.data(38).dtTransOffset = 1416;

                    ;% rtDW.nlhsncexf0
                    section.data(39).logicalSrcIdx = 42;
                    section.data(39).dtTransOffset = 1425;

                    ;% rtDW.oraym15yy4
                    section.data(40).logicalSrcIdx = 43;
                    section.data(40).dtTransOffset = 1426;

                    ;% rtDW.ivwglyseg3
                    section.data(41).logicalSrcIdx = 44;
                    section.data(41).dtTransOffset = 1427;

                    ;% rtDW.dw2aqddkbu
                    section.data(42).logicalSrcIdx = 45;
                    section.data(42).dtTransOffset = 1428;

                    ;% rtDW.og10d1di0w
                    section.data(43).logicalSrcIdx = 46;
                    section.data(43).dtTransOffset = 1429;

                    ;% rtDW.ptgnvnkaax
                    section.data(44).logicalSrcIdx = 47;
                    section.data(44).dtTransOffset = 1430;

                    ;% rtDW.nl4qujfigc
                    section.data(45).logicalSrcIdx = 48;
                    section.data(45).dtTransOffset = 1431;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% rtDW.db0zscnkw5
                    section.data(1).logicalSrcIdx = 49;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.dnagvmiwyz
                    section.data(2).logicalSrcIdx = 50;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.l1qkwlxbe2
                    section.data(3).logicalSrcIdx = 51;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.nx3phiwl4b
                    section.data(4).logicalSrcIdx = 52;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.bivy2tgpmo
                    section.data(5).logicalSrcIdx = 53;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.ock4n01zv1
                    section.data(6).logicalSrcIdx = 54;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.nscvg2w1jd
                    section.data(7).logicalSrcIdx = 55;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.hltsxhc0yl.TimePtr
                    section.data(8).logicalSrcIdx = 56;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.cbz1zds3ha.LoggedData
                    section.data(9).logicalSrcIdx = 57;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.plm1yijlcr.LoggedData
                    section.data(10).logicalSrcIdx = 58;
                    section.data(10).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% rtDW.cel4kex0vf
                    section.data(1).logicalSrcIdx = 59;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.lnnkfakp5r
                    section.data(2).logicalSrcIdx = 60;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.dsacja1lso
                    section.data(3).logicalSrcIdx = 61;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.pob2ql2yji
                    section.data(4).logicalSrcIdx = 62;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.npbg2bjhaw
                    section.data(5).logicalSrcIdx = 63;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.abxfrplp1i
                    section.data(1).logicalSrcIdx = 64;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.oeoydvlwgx.PrevIndex
                    section.data(1).logicalSrcIdx = 65;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.npi2ladrba
                    section.data(1).logicalSrcIdx = 66;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section

            section.nData     = 16;
            section.data(16)  = dumData; %prealloc

                    ;% rtDW.ieyig5nl2r
                    section.data(1).logicalSrcIdx = 67;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.f3pfkie500
                    section.data(2).logicalSrcIdx = 68;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.eyofepozhc
                    section.data(3).logicalSrcIdx = 69;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.d3gd2okwfo
                    section.data(4).logicalSrcIdx = 70;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.nfs34xvx3j
                    section.data(5).logicalSrcIdx = 71;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.id2fpjvnxd
                    section.data(6).logicalSrcIdx = 72;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.a3irhgkhqf
                    section.data(7).logicalSrcIdx = 73;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.laoagnfzfl
                    section.data(8).logicalSrcIdx = 74;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.enpaf0a13a
                    section.data(9).logicalSrcIdx = 75;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.k53yka44us
                    section.data(10).logicalSrcIdx = 76;
                    section.data(10).dtTransOffset = 9;

                    ;% rtDW.iz2nl50abi
                    section.data(11).logicalSrcIdx = 77;
                    section.data(11).dtTransOffset = 10;

                    ;% rtDW.klxzw4td0l
                    section.data(12).logicalSrcIdx = 78;
                    section.data(12).dtTransOffset = 11;

                    ;% rtDW.hcrq1cfyt5
                    section.data(13).logicalSrcIdx = 79;
                    section.data(13).dtTransOffset = 12;

                    ;% rtDW.lbjnlc1mss
                    section.data(14).logicalSrcIdx = 80;
                    section.data(14).dtTransOffset = 13;

                    ;% rtDW.eypykigfe0
                    section.data(15).logicalSrcIdx = 81;
                    section.data(15).dtTransOffset = 14;

                    ;% rtDW.h51utyovca
                    section.data(16).logicalSrcIdx = 82;
                    section.data(16).dtTransOffset = 15;

            nTotData = nTotData + section.nData;
            dworkMap.sections(11) = section;
            clear section

            section.nData     = 23;
            section.data(23)  = dumData; %prealloc

                    ;% rtDW.elg2z4i5mu
                    section.data(1).logicalSrcIdx = 83;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.pfpu1lxyox
                    section.data(2).logicalSrcIdx = 84;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.cwyperzqwf
                    section.data(3).logicalSrcIdx = 85;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.pkugn2pznb
                    section.data(4).logicalSrcIdx = 86;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.l24bi33ydv
                    section.data(5).logicalSrcIdx = 87;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.kc0j20jyvv
                    section.data(6).logicalSrcIdx = 88;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.mghwgiy3zr
                    section.data(7).logicalSrcIdx = 89;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.mgqgi2ps1y
                    section.data(8).logicalSrcIdx = 90;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.h3x4gkt34l
                    section.data(9).logicalSrcIdx = 91;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.pbdxvs0spm
                    section.data(10).logicalSrcIdx = 92;
                    section.data(10).dtTransOffset = 9;

                    ;% rtDW.n2anugr1ay
                    section.data(11).logicalSrcIdx = 93;
                    section.data(11).dtTransOffset = 10;

                    ;% rtDW.en0iu21xjh
                    section.data(12).logicalSrcIdx = 94;
                    section.data(12).dtTransOffset = 11;

                    ;% rtDW.ex1idzngre
                    section.data(13).logicalSrcIdx = 95;
                    section.data(13).dtTransOffset = 12;

                    ;% rtDW.nsjaywhvfb
                    section.data(14).logicalSrcIdx = 96;
                    section.data(14).dtTransOffset = 13;

                    ;% rtDW.as24lkyvxh
                    section.data(15).logicalSrcIdx = 97;
                    section.data(15).dtTransOffset = 14;

                    ;% rtDW.nf2x5nb1ds
                    section.data(16).logicalSrcIdx = 98;
                    section.data(16).dtTransOffset = 15;

                    ;% rtDW.bl11n31i34
                    section.data(17).logicalSrcIdx = 99;
                    section.data(17).dtTransOffset = 16;

                    ;% rtDW.j5z0ymci3s
                    section.data(18).logicalSrcIdx = 100;
                    section.data(18).dtTransOffset = 17;

                    ;% rtDW.gciqwqedw2
                    section.data(19).logicalSrcIdx = 101;
                    section.data(19).dtTransOffset = 18;

                    ;% rtDW.kmhvvetfe2
                    section.data(20).logicalSrcIdx = 102;
                    section.data(20).dtTransOffset = 19;

                    ;% rtDW.lvyyr1smre
                    section.data(21).logicalSrcIdx = 103;
                    section.data(21).dtTransOffset = 20;

                    ;% rtDW.itimx2tbt5
                    section.data(22).logicalSrcIdx = 104;
                    section.data(22).dtTransOffset = 40;

                    ;% rtDW.hxoj3qbhn2
                    section.data(23).logicalSrcIdx = 105;
                    section.data(23).dtTransOffset = 41;

            nTotData = nTotData + section.nData;
            dworkMap.sections(12) = section;
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


    targMap.checksum0 = 928133372;
    targMap.checksum1 = 2120093012;
    targMap.checksum2 = 3764073844;
    targMap.checksum3 = 3331302897;

