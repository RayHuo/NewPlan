(define (problem dispose_2_1)
(:domain dispose)

 (:objects     
    o1 - obj 
    p11
    p12
    p21
    p22 - pos 
  )
   
  (:init(K (and
     (at p11)
     (trashat p11)     
     (adj p11 p21)
     (adj p21 p11)

     (adj p12 p22)
     (adj p22 p12)
     
     (adj p11 p12)
     (adj p12 p11)

     (adj p21 p22)
     (adj p22 p21)

        (objat o1 p11)

     )
    )
    )
    
    (:goal (K(disposed o1)))
)
