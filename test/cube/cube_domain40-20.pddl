(define (domain cube)
	
	(:types pos)
	(:predicates (x ?p - pos)
	             (y ?p - pos)
				 (z ?p - pos)  
	)

    (:action sense_right
	 :parameters ()
	 :precondition (True)
     :observe (x p40)
    ) 	

    (:action sense_left
	 :parameters ()
	 :precondition (True)
     :observe (x p1)
    ) 	

    (:action sense_down
	 :parameters()
	 :precondition (True)
     :observe (y p40)
    ) 	

	(:action sense_up
	 :parameters()
	 :precondition (True)
     :observe (y p1) 
	) 	

	(:action sense_out
	 :parameters()
	 :precondition (True)
     :observe (z p40)
    ) 	

	(:action sense_in
	 :parameters()
	 :precondition(True)
     :observe (z p1) 
	) 	

	(:action right
	 :parameters()
     :precondition (K (not (x p40)))
     :effect (((x p1), (x p2), (x p1)),
			  ((x p2), (x p3), (x p2)),
			  ((x p3), (x p4), (x p3)),
			  ((x p4), (x p5), (x p4)),
			  ((x p5), (x p6), (x p5)),
			  ((x p6), (x p7), (x p6)),
			  ((x p7), (x p8), (x p7)),
			  ((x p8), (x p9), (x p8)),
			  ((x p9), (x p10), (x p9)),
			  ((x p10), (x p11), (x p10)),
			  ((x p11), (x p12), (x p11)),
			  ((x p12), (x p13), (x p12)),
			  ((x p13), (x p14), (x p13)),
			  ((x p14), (x p15), (x p14)),
			  ((x p15), (x p16), (x p15)),
			  ((x p16), (x p17), (x p16)),
			  ((x p17), (x p18), (x p17)),
			  ((x p18), (x p19), (x p18)),
			  ((x p19), (x p20), (x p19)),
			  ((x p20), (x p21), (x p20)),
			  ((x p21), (x p22), (x p21)),
			  ((x p22), (x p23), (x p22)),
			  ((x p23), (x p24), (x p23)),
			  ((x p24), (x p25), (x p24)),
			  ((x p25), (x p26), (x p25)),
			  ((x p26), (x p27), (x p26)),
			  ((x p27), (x p28), (x p27)),
			  ((x p28), (x p29), (x p28)),
			  ((x p29), (x p30), (x p29)),
			  ((x p30), (x p31), (x p30)),
			  ((x p31), (x p32), (x p31)),
			  ((x p32), (x p33), (x p32)),
			  ((x p33), (x p34), (x p33)),
			  ((x p34), (x p35), (x p34)),
			  ((x p35), (x p36), (x p35)),
			  ((x p36), (x p37), (x p36)),
			  ((x p37), (x p38), (x p37)),
			  ((x p38), (x p39), (x p38)),
			  ((x p39), (x p40), (x p39))
       )
    )
  
	(:action left
	 :parameters()
     :precondition (K (not (x p1)))
     :effect (((x p2), (x p1), (x p2)),
			  ((x p3), (x p2), (x p3)),
			  ((x p4), (x p3), (x p4)),
			  ((x p5), (x p4), (x p5)),
			  ((x p6), (x p5), (x p6)),
			  ((x p7), (x p6), (x p7)),
			  ((x p8), (x p7), (x p8)),
			  ((x p9), (x p8), (x p9)),
			  ((x p10), (x p9), (x p10)),
			  ((x p11), (x p10), (x p11)),
			  ((x p12), (x p11), (x p12)),
			  ((x p13), (x p12), (x p13)),
			  ((x p14), (x p13), (x p14)),
			  ((x p15), (x p14), (x p15)),
			  ((x p16), (x p15), (x p16)),
			  ((x p17), (x p16), (x p17)),
			  ((x p18), (x p17), (x p18)),
			  ((x p19), (x p18), (x p19)),
			  ((x p20), (x p19), (x p20)),
			  ((x p21), (x p20), (x p21)),
			  ((x p22), (x p21), (x p22)),
			  ((x p23), (x p22), (x p23)),
			  ((x p24), (x p23), (x p24)),
			  ((x p25), (x p24), (x p25)),
			  ((x p26), (x p25), (x p26)),
			  ((x p27), (x p26), (x p27)),
			  ((x p28), (x p27), (x p28)),
			  ((x p29), (x p28), (x p29)),
			  ((x p30), (x p29), (x p30)),
			  ((x p31), (x p30), (x p31)),
			  ((x p32), (x p31), (x p32)),
			  ((x p33), (x p32), (x p33)),
			  ((x p34), (x p33), (x p34)),
			  ((x p35), (x p34), (x p35)),
			  ((x p36), (x p35), (x p36)),
			  ((x p37), (x p36), (x p37)),
			  ((x p38), (x p37), (x p38)),
			  ((x p39), (x p38), (x p39)),
			  ((x p40), (x p39), (x p40))
        )
    )     
       

	(:action down
	 :parameters ()
     :precondition (K (not (y p40)))	
     :effect (((y p1), (y p2), (y p1)),
			  ((y p2), (y p3), (y p2)),
			  ((y p3), (y p4), (y p3)),
			  ((y p4), (y p5), (y p4)),
			  ((y p5), (y p6), (y p5)),
			  ((y p6), (y p7), (y p6)),
			  ((y p7), (y p8), (y p7)),
			  ((y p8), (y p9), (y p8)),
			  ((y p9), (y p10), (y p9)),
			  ((y p10), (y p11), (y p10)),
			  ((y p11), (y p12), (y p11)),
			  ((y p12), (y p13), (y p12)),
			  ((y p13), (y p14), (y p13)),
			  ((y p14), (y p15), (y p14)),
			  ((y p15), (y p16), (y p15)),
			  ((y p16), (y p17), (y p16)),
			  ((y p17), (y p18), (y p17)),
			  ((y p18), (y p19), (y p18)),
			  ((y p19), (y p20), (y p19)),
			  ((y p20), (y p21), (y p20)),
			  ((y p21), (y p22), (y p21)),
			  ((y p22), (y p23), (y p22)),
			  ((y p23), (y p24), (y p23)),
			  ((y p24), (y p25), (y p24)),
			  ((y p25), (y p26), (y p25)),
			  ((y p26), (y p27), (y p26)),
			  ((y p27), (y p28), (y p27)),
			  ((y p28), (y p29), (y p28)),
			  ((y p29), (y p30), (y p29)),
			  ((y p30), (y p31), (y p30)),
			  ((y p31), (y p32), (y p31)),
			  ((y p32), (y p33), (y p32)),
			  ((y p33), (y p34), (y p33)),
			  ((y p34), (y p35), (y p34)),
			  ((y p35), (y p36), (y p35)),
			  ((y p36), (y p37), (y p36)),
			  ((y p37), (y p38), (y p37)),
			  ((y p38), (y p39), (y p38)),
			  ((y p39), (y p40), (y p39))
       )
    )
       
  
	(:action up
     :precondition (not (y p1))
     :effect (((y p2), (y p1), (y p2)),
			  ((y p3), (y p2), (y p3)),
			  ((y p4), (y p3), (y p4)),
			  ((y p5), (y p4), (y p5)),
			  ((y p6), (y p5), (y p6)),
			  ((y p7), (y p6), (y p7)),
			  ((y p8), (y p7), (y p8)),
			  ((y p9), (y p8), (y p9)),
			  ((y p10), (y p9), (y p10)),
			  ((y p11), (y p10), (y p11)),
			  ((y p12), (y p11), (y p12)),
			  ((y p13), (y p12), (y p13)),
			  ((y p14), (y p13), (y p14)),
			  ((y p15), (y p14), (y p15)),
			  ((y p16), (y p15), (y p16)),
			  ((y p17), (y p16), (y p17)),
			  ((y p18), (y p17), (y p18)),
			  ((y p19), (y p18), (y p19)),
			  ((y p20), (y p19), (y p20)),
			  ((y p21), (y p20), (y p21)),
			  ((y p22), (y p21), (y p22)),
			  ((y p23), (y p22), (y p23)),
			  ((y p24), (y p23), (y p24)),
			  ((y p25), (y p24), (y p25)),
			  ((y p26), (y p25), (y p26)),
			  ((y p27), (y p26), (y p27)),
			  ((y p28), (y p27), (y p28)),
			  ((y p29), (y p28), (y p29)),
			  ((y p30), (y p29), (y p30)),
			  ((y p31), (y p30), (y p31)),
			  ((y p32), (y p31), (y p32)),
			  ((y p33), (y p32), (y p33)),
			  ((y p34), (y p33), (y p34)),
			  ((y p35), (y p34), (y p35)),
			  ((y p36), (y p35), (y p36)),
			  ((y p37), (y p36), (y p37)),
			  ((y p38), (y p37), (y p38)),
			  ((y p39), (y p38), (y p39)),
			  ((y p40), (y p39), (y p40))
        )
    )     
      

	(:action out
	 :parameters()
     :precondition (K (not (z p40)))
     :effect (((z p1), (z p2), (z p1)),
			  ((z p2), (z p3), (z p2)),
			  ((z p3), (z p4), (z p3)),
			  ((z p4), (z p5), (z p4)),
			  ((z p5), (z p6), (z p5)),
			  ((z p6), (z p7), (z p6)),
			  ((z p7), (z p8), (z p7)),
			  ((z p8), (z p9), (z p8)),
			  ((z p9), (z p10), (z p9)),
			  ((z p10), (z p11), (z p10)),
			  ((z p11), (z p12), (z p11)),
			  ((z p12), (z p13), (z p12)),
			  ((z p13), (z p14), (z p13)),
			  ((z p14), (z p15), (z p14)),
			  ((z p15), (z p16), (z p15)),
			  ((z p16), (z p17), (z p16)),
			  ((z p17), (z p18), (z p17)),
			  ((z p18), (z p19), (z p18)),
			  ((z p19), (z p20), (z p19)),
			  ((z p20), (z p21), (z p20)),
			  ((z p21), (z p22), (z p21)),
			  ((z p22), (z p23), (z p22)),
			  ((z p23), (z p24), (z p23)),
			  ((z p24), (z p25), (z p24)),
			  ((z p25), (z p26), (z p25)),
			  ((z p26), (z p27), (z p26)),
			  ((z p27), (z p28), (z p27)),
			  ((z p28), (z p29), (z p28)),
			  ((z p29), (z p30), (z p29)),
			  ((z p30), (z p31), (z p30)),
			  ((z p31), (z p32), (z p31)),
			  ((z p32), (z p33), (z p32)),
			  ((z p33), (z p34), (z p33)),
			  ((z p34), (z p35), (z p34)),
			  ((z p35), (z p36), (z p35)),
			  ((z p36), (z p37), (z p36)),
			  ((z p37), (z p38), (z p37)),
			  ((z p38), (z p39), (z p38)),
			  ((z p39), (z p40), (z p39))
       )
    )
	 
  
	(:action in
	 :parameters()
     :precondition (K (not (z p1)))
     :effect (((z p2), (z p1), (z p2)),
			  ((z p3), (z p2), (z p3)),
			  ((z p4), (z p3), (z p4)),
			  ((z p5), (z p4), (z p5)),
			  ((z p6), (z p5), (z p6)),
			  ((z p7), (z p6), (z p7)),
			  ((z p8), (z p7), (z p8)),
			  ((z p9), (z p8), (z p9)),
			  ((z p10), (z p9), (z p10)),
			  ((z p11), (z p10), (z p11)),
			  ((z p12), (z p11), (z p12)),
			  ((z p13), (z p12), (z p13)),
			  ((z p14), (z p13), (z p14)),
			  ((z p15), (z p14), (z p15)),
			  ((z p16), (z p15), (z p16)),
			  ((z p17), (z p16), (z p17)),
			  ((z p18), (z p17), (z p18)),
			  ((z p19), (z p18), (z p19)),
			  ((z p20), (z p19), (z p20)),
			  ((z p21), (z p20), (z p21)),
			  ((z p22), (z p21), (z p22)),
			  ((z p23), (z p22), (z p23)),
			  ((z p24), (z p23), (z p24)),
			  ((z p25), (z p24), (z p25)),
			  ((z p26), (z p25), (z p26)),
			  ((z p27), (z p26), (z p27)),
			  ((z p28), (z p27), (z p28)),
			  ((z p29), (z p28), (z p29)),
			  ((z p30), (z p29), (z p30)),
			  ((z p31), (z p30), (z p31)),
			  ((z p32), (z p31), (z p32)),
			  ((z p33), (z p32), (z p33)),
			  ((z p34), (z p33), (z p34)),
			  ((z p35), (z p34), (z p35)),
			  ((z p36), (z p35), (z p36)),
			  ((z p37), (z p36), (z p37)),
			  ((z p38), (z p37), (z p38)),
			  ((z p39), (z p38), (z p39)),
			  ((z p40), (z p39), (z p40))
        )
    )      
)

