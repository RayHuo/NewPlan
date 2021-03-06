(define (domain cube)

    (:action sense_right
	 :parameters ()
	 :precondition (K (true))
     :observe (x p5)
    ) 	

    (:action sense_left
	 :parameters ()
	 :precondition (K (true))
     :observe (x p1)
    ) 	

    (:action sense_down
	 :parameters()
	 :precondition (K (true))
     :observe (y p5)
    ) 	

	(:action sense_up
	 :parameters()
	 :precondition (K (true))
     :observe (y p1) 
	) 	

	(:action sense_out
	 :parameters()
	 :precondition (K (true))
     :observe (z p5)
    ) 	

	(:action sense_in
	 :parameters()
	 :precondition(K (true))     
	 :observe (z p1) 
	) 	

	(:action right
	 :parameters()
     :precondition (K (not (x p5)))
     :effect (((x p1), (x p2), (x p1)),
			  ((x p2), (x p3), (x p2)),
			  ((x p3), (x p4), (x p3)),
			  ((x p4), (x p5), (x p4))
       )
    )
  
	(:action left
	 :parameters()
     :precondition (K (not (x p1)))
     :effect (((x p2), (x p1), (x p2)),
			  ((x p3), (x p2), (x p3)),
			  ((x p4), (x p3), (x p4)),
			  ((x p5), (x p4), (x p5))			 
        )
    )     
       

	(:action down
	 :parameters ()
     :precondition (K (not (y p5)))	
     :effect (((y p1), (y p2), (y p1)),
			  ((y p2), (y p3), (y p2)),
			  ((y p3), (y p4), (y p3)),
			  ((y p4), (y p5), (y p4))			 
       )
    )
       
  
	(:action up
	 :parameters()
     :precondition (K (not (y p1)))
     :effect (((y p2), (y p1), (y p2)),
			  ((y p3), (y p2), (y p3)),
			  ((y p4), (y p3), (y p4)),
			  ((y p5), (y p4), (y p5))
        )
    )     
      

	(:action out
	 :parameters()
     :precondition (K (not (z p5)))
     :effect (((z p1), (z p2), (z p1)),
			  ((z p2), (z p3), (z p2)),
			  ((z p3), (z p4), (z p3)),
			  ((z p4), (z p5), (z p4))
       )
    )
	 
  
	(:action in
	 :parameters()
     :precondition (K (not (z p1)))
     :effect (((z p2), (z p1), (z p2)),
			  ((z p3), (z p2), (z p3)),
			  ((z p4), (z p3), (z p4)),
			  ((z p5), (z p4), (z p5))
        )
    )      
)

