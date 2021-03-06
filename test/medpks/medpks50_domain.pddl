(define (domain medicalPKS50)
	(:types ILLNESS STAIN)
	(:predicates 
			(dead)
			(stain ?i - STAIN) 
            (ill ?i - ILLNESS)
	)
 
	(:action sense-stain
	 :parameters (?i - STAIN)
	 :precondition (K (not (dead)))
	 :observe (stain ?i)
	)
	   
	(:action medicate
	 :parameters (?i - ILLNESS)
	 :precondition (K (and (not (dead)) (not (ill i0))))
	 :effect (((ill ?i), (ill i0), ),
			  ((not (ill ?i)), (dead), )
			 )
	)
		
	(:action stain
     :parameters ()
     :precondition (K (not (dead)))
     :effect (((ill i1), (stain s1), ),
			  ((ill i2), (stain s2), ),
			  ((ill i3), (stain s3), ),
			  ((ill i4), (stain s4), ),
			  ((ill i5), (stain s5), ),
			  ((ill i6), (stain s6), ),
			  ((ill i7), (stain s7), ),
			  ((ill i8), (stain s8), ),
			  ((ill i9), (stain s9), ),
			  ((ill i10), (stain s10), ),
			  ((ill i11), (stain s11), ),
			  ((ill i12), (stain s12), ),
			  ((ill i13), (stain s13), ),
			  ((ill i14), (stain s14), ),
			  ((ill i15), (stain s15), ),
			  ((ill i16), (stain s16), ),
			  ((ill i17), (stain s17), ),
			  ((ill i18), (stain s18), ),
			  ((ill i19), (stain s19), ),
			  ((ill i20), (stain s20), ),
			  ((ill i21), (stain s21), ),
			  ((ill i22), (stain s22), ),
			  ((ill i23), (stain s23), ),
			  ((ill i24), (stain s24), ),
			  ((ill i25), (stain s25), ),
			  ((ill i26), (stain s26), ),
			  ((ill i27), (stain s27), ),
			  ((ill i28), (stain s28), ),
			  ((ill i29), (stain s29), ),
			  ((ill i30), (stain s30), ),
			  ((ill i31), (stain s31), ),
			  ((ill i32), (stain s32), ),
			  ((ill i33), (stain s33), ),
			  ((ill i34), (stain s34), ),
			  ((ill i35), (stain s35), ),
			  ((ill i36), (stain s36), ),
			  ((ill i37), (stain s37), ),
			  ((ill i38), (stain s38), ),
			  ((ill i39), (stain s39), ),
			  ((ill i40), (stain s40), ),
			  ((ill i41), (stain s41), ),
			  ((ill i42), (stain s42), ),
			  ((ill i43), (stain s43), ),
			  ((ill i44), (stain s44), ),
			  ((ill i45), (stain s45), ),
			  ((ill i46), (stain s46), ),
			  ((ill i47), (stain s47), ),
			  ((ill i48), (stain s48), ),
			  ((ill i49), (stain s49), ),
			  ((ill i50), (stain s50), )
			)
	)
)
