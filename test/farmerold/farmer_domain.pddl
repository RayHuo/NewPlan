(define (domain farmer)
    
	(:action 
	 :parameters()
	 :precondition (True)
	 :observe (d)
	)
	
	(:action left
	 :parameters ()
	 :precondition (K (not (fl)))
	 :effect (( ,(fl), )
	         )
	)
	
	(:action wleft
	 :parameters()
	 :precondition (and (K (not (fl))) (DK (not (d))))
	 :effect (( , (fl), ),
	          ((wa, (not (wl))), (wl), ),
			  ((sa, re, sl, rl), ,(re)),
			  ((sa, re, (not (sl)), (not (rl))), ,(re))
			  )
	)
	
	(:action sleft
	 :parameters()
	 :precondition (and (K (not (fl))) (DK (not (d))))
	 :effect (( ,(fl), ),
	          ((sa, (not (sl))), (sl), )
			  )	
	)
	
	(:action rleft
	 :parameters()
	 :precondition (and (K (not (fl))) (DK (not (d))))
	 :effect (( , (fl), ),
	          ((re, (not (rl))), (rl), ),
			  ((wa, sa, wl, sl), , (sa)),
			  ((wa, sa, (not (wl)), (not (sl))), , (sa))
	         )
	)
	
	(:action wsleft
	 :parameters()
	 :precondition (K (and (not (fl)) (d)))
	 :effect (( , (fl), ),
	          ((wa, (not (wl))), (wl), ),
			  ((sa, (not (sl))), (sl), )
			 )
	 )
	 
	(:action rsleft
	 :parameters()
	 :precondition (K (and (not (fl)) (d)))
	 :effect (( , (fl), ),
	          ((sa, (not (sl))), (sl), ),
			  ((re, (not (rl))), (rl), )
	         ) 
	 )
	 
	(:action rwleft
	 :parameters()
	 :precondition (K (and (not (fl)) (d)))
	 :effect (( , (fl), ),
	          ((wa, (not (wl))), (wl), ),
			  ((re, (not (rl))), (rl), )
	         )
	)
	
	(:action right
	 :parameters()
	 :precondition (K (fl))
	 :effect (( , ,(fl))
	         )
	)
	
	(:action wright
	 :parameters()
	 :precondition (and (K (fl)) (DK (not (d))))
	 :effect (( , ,(fl)),
	          ((wa, wl), ,(wl)),
			  ((sa, re, (not (sl)), (not (rl))), ,(re)),
			  ((sa, re, sl, rl), ,(re))
			 )
	)
	
	(:action sright
	 :parameters()
	 :precondition (and (K (fl)) (DK (not (d))))
	 :effect (( , , (fl)),
	          ((sa, sl), ,(sl))
			 )
	)
	
	(:action rright
	 :parameters()
	 :precondition (and (K (fl)) (DK (not (d))))
	 :effect (( , , (fl)),
	          ((re, rl), , (rl)),
			  ((wa, sa, wl, sl), ,(sa)),
			  ((wa, sa, (not (wl)), (not (sl))), , (sa))
			 )
	)
	
	(:action wsright
	 :parameters()
	 :precondition (K (and (fl) (d)))
	 :effect (( , , (fl)),
	          ((wa, wl), , (wl)),
			  ((sa, sl), , (sl))
			 ) 
	)
	
	(:action rsright
	 :parameters()
	 :precondition (K (and (fl) (d)))
	 :effect (( , , (fl)),
	          ((sa, sl), , (sl)),
			  ((re, rl), , (rl))
			 )
	)
	
	(:action rwright
	 :parameters()
	 :precondition (K (and (fl) (d)))
	 :effect (( , , (fl)),
	          ((wa, wl), , (wl)),
			  ((re, rl), , (rl))
			 )
	)
)