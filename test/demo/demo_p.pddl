(define (problem demo)
(:domain demo)

(:init (and
  (K (and (imply (doorOpen) (inRoom)) 
          (imply (not (lightOn)) (not(inRoom)))
      )
  )
  (DK (inRoom))
  (DK (not (inRoom)))
  (DK (lightOn))
  (DK (not (lightOn)))
  )
)

(:goal (or
  (K (inRoom))
  (K (not (inRoom)))
  )
)
)
