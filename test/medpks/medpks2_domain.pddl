(define (domain medpks2)
	(:types ILLNESS STAIN)
	(:predicates (dead)
	             (stain ?i - STAIN)
				 (ill ?i - ILLNESS)
	)
	
	(:action inspect-stain
	 :parameters (?i -STAIN)
	 :precondition (K (not (dead)))
	 :effect (( ,(stain ?i), (dead))
	         )
	)
	 
	(:action medicate
	 :parameters (?i - ILLNESS)
	 :preondition (K (and (not (dead)) (not (ill i0))))
	 :effect (((ill ?i), (ill i0), ),
	          ((not (ill ?i)), (dead), )
			 )
	)
	
	(:action stain
	 :parameters()
	 :precondition (K (not (dead)))
	 :effect (((ill i1), (stain s1), ),
	          ((ill i2), (stain s2), )
			 )
	)
)