(define (problem push-to-3-1)
(:domain push-to)

 (:objects  o1 - obj
            p11 
            p12  
            p13  
            p21  
            p22  
            p23  
            p31  
            p32  
            p33 - pos 
  )
  
 (:init (K (and
      (at p22)
      (pick-loc p11)     
      (pick-loc p33)     
      (adj p11 p21)
      (adj p21 p11)
      (adj p12 p22)
      (adj p22 p12)
      (adj p13 p23)
      (adj p23 p13)
      (adj p21 p31)
      (adj p31 p21)
      (adj p22 p32)
      (adj p32 p22)
      (adj p23 p33)
      (adj p33 p23)
      (adj p11 p12)
      (adj p12 p11)
      (adj p21 p22)
      (adj p22 p21)
      (adj p31 p32)
      (adj p32 p31)
      (adj p12 p13)
      (adj p13 p12)
      (adj p22 p23)
      (adj p23 p22)
      (adj p32 p33)
      (adj p33 p32)
      (obj-at o1 p11)
      )
    )
  )
  
  (:goal (K (holding o1)))
)
