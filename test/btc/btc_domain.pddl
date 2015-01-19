(define (domain btc)
  
  (:predicates
   (disarmed ?p - package)
   (clogged)
  )

  (:action dunk
   :parameters (?p - package)
   :precondition (and (K (not(clogged))) (DK (not (disarmed ?p))))
   :effect ((,(disarmed ?p),), (,(clogged),))
   )
   
  (:action flush	
   :parameters ()
   :precondition(DK (clogged))
   :effect ((,,(clogged)))
  )
  
)
