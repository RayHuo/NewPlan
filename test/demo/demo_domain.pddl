(define (domain demo)

  (:action senseL
   :parameters ()
   :precondition (and (DK (lightOn)) (DK (not (lightOn))))
   :observe (lightOn)
  )
  
  (:action senseD
   :parameters ()
   :precondition (K (hasKnocked))
   :observe (doorOpen)
  )
  
  (:action knock
   :parameters ()
   :precondition (K (lightOn))
   :effect (((inRoom), (doorOpen, hasKnocked), ), 
            ((not (inRoom)), (hasKnocked), (doorOpen))
           )
  )
)
