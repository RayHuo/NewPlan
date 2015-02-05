(define (domain wumpus-contingent) 

   (:predicates (adj ?i ?j - pos) 
                (at ?i - pos)
				(safe ?i - pos) 
                (wumpus-at ?x - pos)
				(alive) 
				(stench ?i - pos)
				(gold-at ?i - pos)
				(got-the-treasure)
                (breeze ?i - pos) 
				(pit-at ?p - pos)
	)
               
    (:action sense_smell-wumpus
     :parameters (?pos - pos )
     :precondition (K (and (alive) (at ?pos)))
     :observe (and (alive) (stench ?pos))
	)

	(:action sense_feel-breeze
     :parameters (?pos - pos )
     :precondition (K (and (alive) (at ?pos)))
     :observe (and (alive) (breeze ?pos))
	)
 
	(:action grab
     :parameters (?i - pos)
     :precondition (K (and (at ?i) (gold-at ?i) (alive)))
     :effect (( , (got-the-treasure), (gold-at ?i)))
	)

    (:action move
     :parameters (?i - pos ?j - pos )
     :precondition (K (and (adj ?i ?j) (at ?i) (alive) (safe ?j)))
     :effect (( , (at ?j), (at ?i)))
    )
)
