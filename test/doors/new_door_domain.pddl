(define (domain doors) 
   (:types pos)
   (:predicates (adj ?i ?j) 
                (at ?i)  
                (opened ?i) 
   )
                
   (:action openDoor
    :parameters (?i - pos ?j - pos)
    :precondition(K (true))
    :effect ((((at ?i), (adj ?i ?j)), (opened ?j), ))  
   )

   (:action move
    :parameters (?i - pos ?j - pos )
    :precondition (K (true))
    :effect ((((adj ?i ?j), (at ?i), (opened ?j)) ,(at ?j), (at ?i))) 
   )
)
