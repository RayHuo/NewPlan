(define (domain push-to) 
   (:types pos obj)
   (:predicates (adj ?i - pos ?j - pos) 
                (at ?i -pos) 
                (holding ?o -obj) 
                (obj-at ?o -obj ?i - pos)
                (pick-loc ?i - pos)
   )
   
   (:action senseObject
    :parameters (?p - pos ?o - obj)
    :precondition (K (at ?p))
    :observe (obj-at ?o ?p)
   ) 	

   (:action move
    :parameters (?i - pos ?j - pos )
    :precondition (K (and (adj ?i ?j) (at ?i)))
    :effect (( , (at ?j),(at ?i))) 
   )
      
   (:action pickup
    :parameters (?o - obj ?i - pos )
    :precondition (K (and (at ?i) (pick-loc ?i) (obj-at ?o ?i)))
    :effect (( ,(holding ?o),(obj-at ?o ?i)))
   )
     
   (:action push
    :parameters (?o - obj ?i - pos  ?j - pos )
    :precondition (K (and (adj ?i ?j) (at ?i) (obj-at ?o ?i)))
    :effect (( ,(obj-at ?o ?j),(obj-at ?o ?i)))
   )
)
