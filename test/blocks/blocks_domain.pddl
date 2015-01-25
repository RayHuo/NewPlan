(define (domain blocksworld)
  (:predicates (clear ?x)
               (on-table ?x)
               (on ?x ?y)
  )

  (:action senseON
   :parameters (?b1 - BLOCK ?b2 - BLOCK)
   :precondition (True)
   :observe (on ?b1 ?b2)
  )

  (:action senseCLEAR
   :parameters (?b1 - BLOCK)
   :precondition (True)
   :observe (clear ?b1)
  )

  (:action senseONTABLE	
   :parameters (?b1 - BLOCK)
   :precondition (True)
   :observe (on-table ?b1)
  )

 (:action move-b-to-b
  :parameters (?bm - BLOCK ?bf - BLOCK ?bt - BLOCK)
  :precondition (K (and (clear ?bm) (clear ?bt) (on ?bm ?bf)))
  :effect (( ,(on ?bm ?bt, clear ?bf),(clear ?bt, on ?bm ?bf)))
  )

 (:action move-to-t
  :parameters (?b - BLOCK ?bf - BLOCK)
  :precondition (K (and (clear ?b) (on ?b ?bf)))
  :effect (( ,(on-table ?b, clear ?bf), (on ?b ?bf) ))
  )

 (:action move-t-to-b
  :parameters (?bm - BLOCK ?bt - BLOCK)
  :precondition (K (and (clear ?bm) (clear ?bt) (on-table ?bm)))
  :effect (( ,(on ?bm ?bt), (clear ?bt, on-table ?bm)))
  )
)

