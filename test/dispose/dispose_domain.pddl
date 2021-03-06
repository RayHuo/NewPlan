(define (domain dispose) 

   (:predicates (adj ?i ?j - pos) 
                (at ?i - pos) 
                (holding ?o - obj) 
                (objat ?o - obj ?i - pos)
                (trashat ?x - pos) 
                (disposed ?o - obj)
    )

   (:action sense_object
      :parameters (?p - pos ?o - obj)
      :precondition (K (at ?p))
      :observe (objat ?o ?p)
   ) 	

   (:action move
      :parameters (?i - pos ?j - pos )
      :precondition (K (and (adj ?i ?j) (at ?i)))
      :effect (( ,(at ?j), (at ?i)))
   )
      
   (:action pickup
      :parameters (?o - obj ?i - pos)
      :precondition (K (and (at ?i) (objat ?o ?i)))
      :effect (( ,(holding ?o), (objat ?o ?i)))
   )
   
   (:action drop
      :parameters (?o - obj ?i - pos )
      :precondition (K (and (at ?i) (trashat ?i)))
      :effect (((holding ?o), (disposed ?o), (holding ?o)))
    )
)
