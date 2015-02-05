(define (problem medicalPKS150)
	(:domain medicalPKS150)
    (:objects i0 i1 i2 i3 i4 i5 i6 i7 i8 i9 i10 
	          i11 i12 i13 i14 i15 i16 i17 i18 i19 i20 
			  i21 i22 i23 i24 i25 i26 i27 i28 i29 i30 
			  i31 i32 i33 i34 i35 i36 i37 i38 i39 i40 
			  i41 i42 i43 i44 i45 i46 i47 i48 i49 i50 
			  i51 i52 i53 i54 i55 i56 i57 i58 i59 i60 
			  i61 i62 i63 i64 i65 i66 i67 i68 i69 i70 
			  i71 i72 i73 i74 i75 i76 i77 i78 i79 i80 
			  i81 i82 i83 i84 i85 i86 i87 i88 i89 i90 
			  i91 i92 i93 i94 i95 i96 i97 i98 i99 i100 
			  i101 i102 i103 i104 i105 i106 i107 i108 i109 i110 
			  i111 i112 i113 i114 i115 i116 i117 i118 i119 i120 
			  i121 i122 i123 i124 i125 i126 i127 i128 i129 i130 
			  i131 i132 i133 i134 i135 i136 i137 i138 i139 i140 
			  i141 i142 i143 i144 i145 i146 i147 i148 i149 - ILLNESS
			  s0 s1 s2 s3 s4 s5 s6 s7 s8 s9 s10 
			  s11 s12 s13 s14 s15 s16 s17 s18 s19 s20
			  s21 s22 s23 s24 s25 s26 s27 s28 s29 s30
			  s31 s32 s33 s34 s35 s36 s37 s38 s39 s40
			  s41 s42 s43 s44 s45 s46 s47 s48 s49 s50 
			  s51 s52 s53 s54 s55 s56 s57 s58 s59 s60 
			  s61 s62 s63 s64 s65 s66 s67 s68 s69 s70 
			  s71 s72 s73 s74 s75 s76 s77 s78 s79 s80
			  s81 s82 s83 s84 s85 s86 s87 s88 s89 s90
			  s91 s92 s93 s94 s95 s96 s97 s98 s99 s100
			  s101 s102 s103 s104 s105 s106 s107 s108 s109 s110
			  s111 s112 s113 s114 s115 s116 s117 s118 s119 s120
			  s121 s122 s123 s124 s125 s126 s127 s128 s129 s130
			  s131 s132 s133 s134 s135 s136 s137 s138 s139 s140
			  s141 s142 s143 s144 s145 s146 s147 s148 s149 - STAIN
	)
	
	(:init (K (and
				  (stain s0)
                  (ndead)
                  (oneof (ill i1)  
				         (ill i0)
						 (ill i2) 
						 (ill i3)
						 (ill i4) 
						 (ill i5) 
						 (ill i6) 
						 (ill i7)
						 (ill i8) 
						 (ill i9) 
						 (ill i10)
						 (ill i11) 
						 (ill i12) 
						 (ill i13) 
						 (ill i14)
						 (ill i15) 
						 (ill i16) 
						 (ill i17) 
						 (ill i18) 
						 (ill i19) 
						 (ill i20)
						 (ill i21) 
						 (ill i22) 
						 (ill i23) 
						 (ill i24) 
						 (ill i25) 
						 (ill i26) 
						 (ill i27) 
						 (ill i28) 
						 (ill i29) 
						 (ill i30) 
						 (ill i31)
						 (ill i32)
						 (ill i33)
						 (ill i34)
						 (ill i35)
						 (ill i36)
						 (ill i37)
						 (ill i38)
						 (ill i39)
						 (ill i40)
						 (ill i41)
						 (ill i42)
						 (ill i43)
						 (ill i44)
						 (ill i45) 
						 (ill i46) 
						 (ill i47)
						 (ill i48) 
						 (ill i49)
						 (ill i50)
						 (ill i51)
						 (ill i52) 
						 (ill i53) 
						 (ill i54)
						 (ill i55)
						 (ill i56)
						 (ill i57)
						 (ill i58)
						 (ill i59) 
						 (ill i60) 
						 (ill i61)
						 (ill i62)
						 (ill i63)
						 (ill i64)
						 (ill i65) 
						 (ill i66) 
						 (ill i67) 
						 (ill i68) 
						 (ill i69)
						 (ill i70) 
						 (ill i71) 
						 (ill i72) 
						 (ill i73)
						 (ill i74)
						 (ill i75)
						 (ill i76) 
						 (ill i77) 
						 (ill i78) 
						 (ill i79) 
						 (ill i80)
						 (ill i81)
						 (ill i82) 
						 (ill i83) 
						 (ill i84) 
						 (ill i85) 
						 (ill i86) 
						 (ill i87) 
						 (ill i88) 
						 (ill i89) 
						 (ill i90) 
						 (ill i91) 
						 (ill i92) 
						 (ill i93) 
						 (ill i94) 
						 (ill i95) 
						 (ill i96) 
						 (ill i97) 
						 (ill i98) 
						 (ill i99) 
						 (ill i100)
						 (ill i101)
						 (ill i102)
						 (ill i103)
						 (ill i104)
						 (ill i105)
						 (ill i106)
						 (ill i107)
						 (ill i108) 
						 (ill i109) 
						 (ill i110)
						 (ill i111)
						 (ill i112) 
						 (ill i113) 
						 (ill i114)
						 (ill i115)
						 (ill i116) 
						 (ill i117)
						 (ill i118)
						 (ill i119)
						 (ill i120)
						 (ill i121) 
						 (ill i122) 
						 (ill i123) 
						 (ill i124) 
						 (ill i125)
						 (ill i126) 
						 (ill i127) 
						 (ill i128) 
						 (ill i129)
						 (ill i130) 
						 (ill i131) 
						 (ill i132) 
						 (ill i133)
						 (ill i134)
						 (ill i135)
						 (ill i136) 
						 (ill i137)
						 (ill i138)
						 (ill i139) 
						 (ill i140)
						 (ill i141)
						 (ill i142)
						 (ill i143)
						 (ill i144) 
						 (ill i145) 
						 (ill i146) 
						 (ill i147) 
						 (ill i148)
						 (ill i149)
					)
				)
			)
	)

	(:goal (K (and (ill i0) (ndead))))
)
