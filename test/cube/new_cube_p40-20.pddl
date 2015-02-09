(define (problem cube-cube-d40-g20-corners)
	(:domain cube)
	(:objects   p1  
				p2  
				p3  
				p4 
				p5
				p6
				p7
				p8
				p9
				p10  
				p11
				p12
				p13
				p14
				p15 
				p16  
				p17
				p18
				p19
				p20
				p21
				p22
				p23
				p24
				p25
				p26
				p27
				p28
				p29 
				p30
				p31
				p32
				p33
				p34
				p35
				p36
				p37
				p38
				p39
				p40 - pos
				gold - gold
	)
	
	(:init(or (K (and (x p1) (y p1) (z p1)))
	          (K (and (x p40) (y p40) (z p40)))
		)
    )
	
	(:goal (or (K (and (x p1) (y p1) (z p1) (gold)))
	           (K (and (x p1) (y p1) (z p1) (not (gold))))
		   )
	)
)
