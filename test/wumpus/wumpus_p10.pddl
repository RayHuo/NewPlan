(define (problem wumpus-10)
	(:domain wumpus)
    (:objects
			p1-1
			p1-2
			p1-3
			p1-4
			p1-5
			p1-6
			p1-7
			p1-8
			p1-9
			p1-10
			p2-1
			p2-2
			p2-3
			p2-4
			p2-5
			p2-6
			p2-7
			p2-8
			p2-9
			p2-10
			p3-1
			p3-2
			p3-3
			p3-4
			p3-5
			p3-6
			p3-7
			p3-8
			p3-9
			p3-10
			p4-1
			p4-2
			p4-3
			p4-4
			p4-5
			p4-6
			p4-7
			p4-8
			p4-9
			p4-10
			p5-1
			p5-2
			p5-3
			p5-4
			p5-5
			p5-6
			p5-7
			p5-8
			p5-9
			p5-10
			p6-1
			p6-2
			p6-3
			p6-4
			p6-5
			p6-6
			p6-7
			p6-8
			p6-9
			p6-10
			p7-1
			p7-2
			p7-3
			p7-4
			p7-5
			p7-6
			p7-7
			p7-8
			p7-9
			p7-10
			p8-1
			p8-2
			p8-3
			p8-4
			p8-5
			p8-6
			p8-7
			p8-8
			p8-9
			p8-10
			p9-1
			p9-2
			p9-3
			p9-4
			p9-5
			p9-6
			p9-7
			p9-8
			p9-9
			p9-10
			p10-1
			p10-2
			p10-3
			p10-4
			p10-5
			p10-6
			p10-7
			p10-8
			p10-9
			p10-10 - pos
    )

	(:init(K (and
				 (at p1-1)
				 (alive)
				 (adj p1-1 p2-1)
				 (adj p2-1 p1-1)
				 (adj p1-2 p2-2)
				 (adj p2-2 p1-2)
				 (adj p1-3 p2-3)
				 (adj p2-3 p1-3)
				 (adj p1-4 p2-4)
				 (adj p2-4 p1-4)
				 (adj p1-5 p2-5)
				 (adj p2-5 p1-5)
				 (adj p1-6 p2-6)
				 (adj p2-6 p1-6)
				 (adj p1-7 p2-7)
				 (adj p2-7 p1-7)
				 (adj p1-8 p2-8)
				 (adj p2-8 p1-8)
				 (adj p1-9 p2-9)
				 (adj p2-9 p1-9)
				 (adj p1-10 p2-10)
				 (adj p2-10 p1-10)
				 (adj p2-1 p3-1)
				 (adj p3-1 p2-1)
				 (adj p2-2 p3-2)
				 (adj p3-2 p2-2)
				 (adj p2-3 p3-3)
				 (adj p3-3 p2-3)
				 (adj p2-4 p3-4)
				 (adj p3-4 p2-4)
				 (adj p2-5 p3-5)
				 (adj p3-5 p2-5)
				 (adj p2-6 p3-6)
				 (adj p3-6 p2-6)
				 (adj p2-7 p3-7)
				 (adj p3-7 p2-7)
				 (adj p2-8 p3-8)
				 (adj p3-8 p2-8)
				 (adj p2-9 p3-9)
				 (adj p3-9 p2-9)
				 (adj p2-10 p3-10)
				 (adj p3-10 p2-10)
				 (adj p3-1 p4-1)
				 (adj p4-1 p3-1)
				 (adj p3-2 p4-2)
				 (adj p4-2 p3-2)
				 (adj p3-3 p4-3)
				 (adj p4-3 p3-3)
				 (adj p3-4 p4-4)
				 (adj p4-4 p3-4)
				 (adj p3-5 p4-5)
				 (adj p4-5 p3-5)
				 (adj p3-6 p4-6)
				 (adj p4-6 p3-6)
				 (adj p3-7 p4-7)
				 (adj p4-7 p3-7)
				 (adj p3-8 p4-8)
				 (adj p4-8 p3-8)
				 (adj p3-9 p4-9)
				 (adj p4-9 p3-9)
				 (adj p3-10 p4-10)
				 (adj p4-10 p3-10)
				 (adj p4-1 p5-1)
				 (adj p5-1 p4-1)
				 (adj p4-2 p5-2)
				 (adj p5-2 p4-2)
				 (adj p4-3 p5-3)
				 (adj p5-3 p4-3)
				 (adj p4-4 p5-4)
				 (adj p5-4 p4-4)
				 (adj p4-5 p5-5)
				 (adj p5-5 p4-5)
				 (adj p4-6 p5-6)
				 (adj p5-6 p4-6)
				 (adj p4-7 p5-7)
				 (adj p5-7 p4-7)
				 (adj p4-8 p5-8)
				 (adj p5-8 p4-8)
				 (adj p4-9 p5-9)
				 (adj p5-9 p4-9)
				 (adj p4-10 p5-10)
				 (adj p5-10 p4-10)
				 (adj p5-1 p6-1)
				 (adj p6-1 p5-1)
				 (adj p5-2 p6-2)
				 (adj p6-2 p5-2)
				 (adj p5-3 p6-3)
				 (adj p6-3 p5-3)
				 (adj p5-4 p6-4)
				 (adj p6-4 p5-4)
				 (adj p5-5 p6-5)
				 (adj p6-5 p5-5)
				 (adj p5-6 p6-6)
				 (adj p6-6 p5-6)
				 (adj p5-7 p6-7)
				 (adj p6-7 p5-7)
				 (adj p5-8 p6-8)
				 (adj p6-8 p5-8)
				 (adj p5-9 p6-9)
				 (adj p6-9 p5-9)
				 (adj p5-10 p6-10)
				 (adj p6-10 p5-10)
				 (adj p6-1 p7-1)
				 (adj p7-1 p6-1)
				 (adj p6-2 p7-2)
				 (adj p7-2 p6-2)
				 (adj p6-3 p7-3)
				 (adj p7-3 p6-3)
				 (adj p6-4 p7-4)
				 (adj p7-4 p6-4)
				 (adj p6-5 p7-5)
				 (adj p7-5 p6-5)
				 (adj p6-6 p7-6)
				 (adj p7-6 p6-6)
				 (adj p6-7 p7-7)
				 (adj p7-7 p6-7)
				 (adj p6-8 p7-8)
				 (adj p7-8 p6-8)
				 (adj p6-9 p7-9)
				 (adj p7-9 p6-9)
				 (adj p6-10 p7-10)
				 (adj p7-10 p6-10)
				 (adj p7-1 p8-1)
				 (adj p8-1 p7-1)
				 (adj p7-2 p8-2)
				 (adj p8-2 p7-2)
				 (adj p7-3 p8-3)
				 (adj p8-3 p7-3)
				 (adj p7-4 p8-4)
				 (adj p8-4 p7-4)
				 (adj p7-5 p8-5)
				 (adj p8-5 p7-5)
				 (adj p7-6 p8-6)
				 (adj p8-6 p7-6)
				 (adj p7-7 p8-7)
				 (adj p8-7 p7-7)
				 (adj p7-8 p8-8)
				 (adj p8-8 p7-8)
				 (adj p7-9 p8-9)
				 (adj p8-9 p7-9)
				 (adj p7-10 p8-10)
				 (adj p8-10 p7-10)
				 (adj p8-1 p9-1)
				 (adj p9-1 p8-1)
				 (adj p8-2 p9-2)
				 (adj p9-2 p8-2)
				 (adj p8-3 p9-3)
				 (adj p9-3 p8-3)
				 (adj p8-4 p9-4)
				 (adj p9-4 p8-4)
				 (adj p8-5 p9-5)
				 (adj p9-5 p8-5)
				 (adj p8-6 p9-6)
				 (adj p9-6 p8-6)
				 (adj p8-7 p9-7)
				 (adj p9-7 p8-7)
				 (adj p8-8 p9-8)
				 (adj p9-8 p8-8)
				 (adj p8-9 p9-9)
				 (adj p9-9 p8-9)
				 (adj p8-10 p9-10)
				 (adj p9-10 p8-10)
				 (adj p9-1 p10-1)
				 (adj p10-1 p9-1)
				 (adj p9-2 p10-2)
				 (adj p10-2 p9-2)
				 (adj p9-3 p10-3)
				 (adj p10-3 p9-3)
				 (adj p9-4 p10-4)
				 (adj p10-4 p9-4)
				 (adj p9-5 p10-5)
				 (adj p10-5 p9-5)
				 (adj p9-6 p10-6)
				 (adj p10-6 p9-6)
				 (adj p9-7 p10-7)
				 (adj p10-7 p9-7)
				 (adj p9-8 p10-8)
				 (adj p10-8 p9-8)
				 (adj p9-9 p10-9)
				 (adj p10-9 p9-9)
				 (adj p9-10 p10-10)
				 (adj p10-10 p9-10)
				 (adj p1-1 p1-2)
				 (adj p1-2 p1-1)
				 (adj p2-1 p2-2)
				 (adj p2-2 p2-1)
				 (adj p3-1 p3-2)
				 (adj p3-2 p3-1)
				 (adj p4-1 p4-2)
				 (adj p4-2 p4-1)
				 (adj p5-1 p5-2)
				 (adj p5-2 p5-1)
				 (adj p6-1 p6-2)
				 (adj p6-2 p6-1)
				 (adj p7-1 p7-2)
				 (adj p7-2 p7-1)
				 (adj p8-1 p8-2)
				 (adj p8-2 p8-1)
				 (adj p9-1 p9-2)
				 (adj p9-2 p9-1)
				 (adj p10-1 p10-2)
				 (adj p10-2 p10-1)
				 (adj p1-2 p1-3)
				 (adj p1-3 p1-2)
				 (adj p2-2 p2-3)
				 (adj p2-3 p2-2)
				 (adj p3-2 p3-3)
				 (adj p3-3 p3-2)
				 (adj p4-2 p4-3)
				 (adj p4-3 p4-2)
				 (adj p5-2 p5-3)
				 (adj p5-3 p5-2)
				 (adj p6-2 p6-3)
				 (adj p6-3 p6-2)
				 (adj p7-2 p7-3)
				 (adj p7-3 p7-2)
				 (adj p8-2 p8-3)
				 (adj p8-3 p8-2)
				 (adj p9-2 p9-3)
				 (adj p9-3 p9-2)
				 (adj p10-2 p10-3)
				 (adj p10-3 p10-2)
				 (adj p1-3 p1-4)
				 (adj p1-4 p1-3)
				 (adj p2-3 p2-4)
				 (adj p2-4 p2-3)
				 (adj p3-3 p3-4)
				 (adj p3-4 p3-3)
				 (adj p4-3 p4-4)
				 (adj p4-4 p4-3)
				 (adj p5-3 p5-4)
				 (adj p5-4 p5-3)
				 (adj p6-3 p6-4)
				 (adj p6-4 p6-3)
				 (adj p7-3 p7-4)
				 (adj p7-4 p7-3)
				 (adj p8-3 p8-4)
				 (adj p8-4 p8-3)
				 (adj p9-3 p9-4)
				 (adj p9-4 p9-3)
				 (adj p10-3 p10-4)
				 (adj p10-4 p10-3)
				 (adj p1-4 p1-5)
				 (adj p1-5 p1-4)
				 (adj p2-4 p2-5)
				 (adj p2-5 p2-4)
				 (adj p3-4 p3-5)
				 (adj p3-5 p3-4)
				 (adj p4-4 p4-5)
				 (adj p4-5 p4-4)
				 (adj p5-4 p5-5)
				 (adj p5-5 p5-4)
				 (adj p6-4 p6-5)
				 (adj p6-5 p6-4)
				 (adj p7-4 p7-5)
				 (adj p7-5 p7-4)
				 (adj p8-4 p8-5)
				 (adj p8-5 p8-4)
				 (adj p9-4 p9-5)
				 (adj p9-5 p9-4)
				 (adj p10-4 p10-5)
				 (adj p10-5 p10-4)
				 (adj p1-5 p1-6)
				 (adj p1-6 p1-5)
				 (adj p2-5 p2-6)
				 (adj p2-6 p2-5)
				 (adj p3-5 p3-6)
				 (adj p3-6 p3-5)
				 (adj p4-5 p4-6)
				 (adj p4-6 p4-5)
				 (adj p5-5 p5-6)
				 (adj p5-6 p5-5)
				 (adj p6-5 p6-6)
				 (adj p6-6 p6-5)
				 (adj p7-5 p7-6)
				 (adj p7-6 p7-5)
				 (adj p8-5 p8-6)
				 (adj p8-6 p8-5)
				 (adj p9-5 p9-6)
				 (adj p9-6 p9-5)
				 (adj p10-5 p10-6)
				 (adj p10-6 p10-5)
				 (adj p1-6 p1-7)
				 (adj p1-7 p1-6)
				 (adj p2-6 p2-7)
				 (adj p2-7 p2-6)
				 (adj p3-6 p3-7)
				 (adj p3-7 p3-6)
				 (adj p4-6 p4-7)
				 (adj p4-7 p4-6)
				 (adj p5-6 p5-7)
				 (adj p5-7 p5-6)
				 (adj p6-6 p6-7)
				 (adj p6-7 p6-6)
				 (adj p7-6 p7-7)
				 (adj p7-7 p7-6)
				 (adj p8-6 p8-7)
				 (adj p8-7 p8-6)
				 (adj p9-6 p9-7)
				 (adj p9-7 p9-6)
				 (adj p10-6 p10-7)
				 (adj p10-7 p10-6)
				 (adj p1-7 p1-8)
				 (adj p1-8 p1-7)
				 (adj p2-7 p2-8)
				 (adj p2-8 p2-7)
				 (adj p3-7 p3-8)
				 (adj p3-8 p3-7)
				 (adj p4-7 p4-8)
				 (adj p4-8 p4-7)
				 (adj p5-7 p5-8)
				 (adj p5-8 p5-7)
				 (adj p6-7 p6-8)
				 (adj p6-8 p6-7)
				 (adj p7-7 p7-8)
				 (adj p7-8 p7-7)
				 (adj p8-7 p8-8)
				 (adj p8-8 p8-7)
				 (adj p9-7 p9-8)
				 (adj p9-8 p9-7)
				 (adj p10-7 p10-8)
				 (adj p10-8 p10-7)
				 (adj p1-8 p1-9)
				 (adj p1-9 p1-8)
				 (adj p2-8 p2-9)
				 (adj p2-9 p2-8)
				 (adj p3-8 p3-9)
				 (adj p3-9 p3-8)
				 (adj p4-8 p4-9)
				 (adj p4-9 p4-8)
				 (adj p5-8 p5-9)
				 (adj p5-9 p5-8)
				 (adj p6-8 p6-9)
				 (adj p6-9 p6-8)
				 (adj p7-8 p7-9)
				 (adj p7-9 p7-8)
				 (adj p8-8 p8-9)
				 (adj p8-9 p8-8)
				 (adj p9-8 p9-9)
				 (adj p9-9 p9-8)
				 (adj p10-8 p10-9)
				 (adj p10-9 p10-8)
				 (adj p1-9 p1-10)
				 (adj p1-10 p1-9)
				 (adj p2-9 p2-10)
				 (adj p2-10 p2-9)
				 (adj p3-9 p3-10)
				 (adj p3-10 p3-9)
				 (adj p4-9 p4-10)
				 (adj p4-10 p4-9)
				 (adj p5-9 p5-10)
				 (adj p5-10 p5-9)
				 (adj p6-9 p6-10)
				 (adj p6-10 p6-9)
				 (adj p7-9 p7-10)
				 (adj p7-10 p7-9)
				 (adj p8-9 p8-10)
				 (adj p8-10 p8-9)
				 (adj p9-9 p9-10)
				 (adj p9-10 p9-9)
				 (adj p10-9 p10-10)
				 (adj p10-10 p10-9)

				 (gold-at p10-10)

				 (safe p1-1)
				 (safe p2-1)
				 (safe p3-1)
				 (safe p4-1)
				 (safe p5-1)
				 (safe p6-1)
				 (safe p7-1)
				 (safe p8-1)
				 (safe p9-1)
				 (safe p10-1)
				 (safe p1-2)
				 (safe p1-3)
				 (safe p1-4)
				 (safe p1-5)
				 (safe p1-6)
				 (safe p1-7)
				 (safe p1-8)
				 (safe p1-9)
				 (safe p1-10)
				 (safe p2-2)
				 (safe p2-4)
				 (safe p2-5)
				 (safe p2-6)
				 (safe p2-7)
				 (safe p2-8)
				 (safe p2-9)
				 (safe p2-10)
				 (oneof
					   (safe p2-3)
					   (safe p3-2)
				 )
			    (safe p3-3)
			    (safe p3-5)
			    (safe p3-6)
			    (safe p3-7)
			    (safe p3-8)
			    (safe p3-9)
			    (safe p3-10)
			    (safe p4-2)
				 (oneof
					   (safe p3-4)
					   (safe p4-3)
				 )
				  (safe p4-4)
				  (safe p4-6)
				  (safe p4-7)
				  (safe p4-8)
				  (safe p4-9)
				  (safe p4-10)
				  (safe p5-2)
				  (safe p5-3)
				 (oneof
					   (safe p4-5)
					   (safe p5-4)
				 )
				  (safe p5-5)
				  (safe p5-7)
				  (safe p5-8)
				  (safe p5-9)
				  (safe p5-10)
				  (safe p6-2)
				  (safe p6-3)
				  (safe p6-4)
				 (oneof
					   (safe p5-6)
					   (safe p6-5)
				 )
				  (safe p6-6)
				  (safe p6-8)
				  (safe p6-9)
				  (safe p6-10)
				  (safe p7-2)
				  (safe p7-3)
				  (safe p7-4)
				  (safe p7-5)
				 (oneof
					   (safe p6-7)
					   (safe p7-6)
					 )
				  (safe p7-7)
				  (safe p7-9)
				  (safe p7-10)
				  (safe p8-2)
				  (safe p8-3)
				  (safe p8-4)
				  (safe p8-5)
				  (safe p8-6)
				 (oneof
					   (safe p7-8)
					   (safe p8-7)
				 )
				  (safe p8-8)
				  (safe p8-10)
				  (safe p9-2)
				  (safe p9-3)
				  (safe p9-4)
				  (safe p9-5)
				  (safe p9-6)
				  (safe p9-7)
				 (oneof
					   (safe p8-9)
					   (safe p9-8)
				 )
				  (safe p9-9)
				  (safe p10-2)
				  (safe p10-3)
				  (safe p10-4)
				  (safe p10-5)
				  (safe p10-6)
				  (safe p10-7)
				  (safe p10-8)
				 (oneof
					   (safe p9-10)
					   (safe p10-9)
				 )
				  (safe p10-10)

				(or (not (safe p2-3)) (not (wumpus-at p2-3)))
				(or (not (safe p2-3)) (not (pit-at p2-3)) )
				(or (safe p2-3) (wumpus-at p2-3) (pit-at p2-3) )

				(or (not (safe p3-2)) (not (wumpus-at p3-2)))
				(or (not (safe p3-2)) (not (pit-at p3-2)) )
				(or (safe p3-2) (wumpus-at p3-2) (pit-at p3-2) )

				(or (not (safe p3-4)) (not (wumpus-at p3-4)))
				(or (not (safe p3-4)) (not (pit-at p3-4)) )
				(or (safe p3-4) (wumpus-at p3-4) (pit-at p3-4) )

				(or (not (safe p4-3)) (not (wumpus-at p4-3)))
				(or (not (safe p4-3)) (not (pit-at p4-3)) )
				(or (safe p4-3) (wumpus-at p4-3) (pit-at p4-3) )

				(or (not (safe p4-5)) (not (wumpus-at p4-5)))
				(or (not (safe p4-5)) (not (pit-at p4-5)) )
				(or (safe p4-5) (wumpus-at p4-5) (pit-at p4-5) )

				(or (not (safe p5-4)) (not (wumpus-at p5-4)))
				(or (not (safe p5-4)) (not (pit-at p5-4)) )
				(or (safe p5-4) (wumpus-at p5-4) (pit-at p5-4) )

				(or (not (safe p5-6)) (not (wumpus-at p5-6)))
				(or (not (safe p5-6)) (not (pit-at p5-6)) )
				(or (safe p5-6) (wumpus-at p5-6) (pit-at p5-6) )

				(or (not (safe p6-5)) (not (wumpus-at p6-5)))
				(or (not (safe p6-5)) (not (pit-at p6-5)) )
				(or (safe p6-5) (wumpus-at p6-5) (pit-at p6-5) )

				(or (not (safe p6-7)) (not (wumpus-at p6-7)))
				(or (not (safe p6-7)) (not (pit-at p6-7)) )
				(or (safe p6-7) (wumpus-at p6-7) (pit-at p6-7) )

				(or (not (safe p7-6)) (not (wumpus-at p7-6)))
				(or (not (safe p7-6)) (not (pit-at p7-6)) )
				(or (safe p7-6) (wumpus-at p7-6) (pit-at p7-6) )

				(or (not (safe p7-8)) (not (wumpus-at p7-8)))
				(or (not (safe p7-8)) (not (pit-at p7-8)) )
				(or (safe p7-8) (wumpus-at p7-8) (pit-at p7-8) )

				(or (not (safe p8-7)) (not (wumpus-at p8-7)))
				(or (not (safe p8-7)) (not (pit-at p8-7)) )
				(or (safe p8-7) (wumpus-at p8-7) (pit-at p8-7) )

				(or (not (safe p8-9)) (not (wumpus-at p8-9)))
				(or (not (safe p8-9)) (not (pit-at p8-9)) )
				(or (safe p8-9) (wumpus-at p8-9) (pit-at p8-9) )

				(or (not (safe p9-8)) (not (wumpus-at p9-8)))
				(or (not (safe p9-8)) (not (pit-at p9-8)) )
				(or (safe p9-8) (wumpus-at p9-8) (pit-at p9-8) )

				(or (not (safe p9-10)) (not (wumpus-at p9-10)))
				(or (not (safe p9-10)) (not (pit-at p9-10)) )
				(or (safe p9-10) (wumpus-at p9-10) (pit-at p9-10) )

				(or (not (safe p10-9)) (not (wumpus-at p10-9)))
				(or (not (safe p10-9)) (not (pit-at p10-9)) )
				(or (safe p10-9) (wumpus-at p10-9) (pit-at p10-9) )

				(or (stench p1-3) (not (wumpus-at p2-3)))
				(or (not (stench p1-3))  (wumpus-at p2-3))

				(or (stench p3-1) (not (wumpus-at p3-2)))
				(or (not (stench p3-1))  (wumpus-at p3-2))

				(or (not (stench p2-2)) (wumpus-at p3-2) (wumpus-at p2-3))
				(or (stench p2-2) (not (wumpus-at p3-2)))
				(or (stench p2-2) (not (wumpus-at p2-3)))

				(or (not (stench p2-4)) (wumpus-at p2-3)(wumpus-at p3-4) )
				(or (stench p2-4) (not (wumpus-at p2-3)))
				(or (stench p2-4) (not (wumpus-at p3-4)))

				(or (not (stench p4-2)) (wumpus-at p4-3)(wumpus-at p3-2) )
				(or (stench p4-2) (not (wumpus-at p4-3)))
				(or (stench p4-2) (not (wumpus-at p3-2)))

				(or (not (stench p3-3)) (wumpus-at p4-3) (wumpus-at p3-2)(wumpus-at p2-3) (wumpus-at p3-4) )
				(or (stench p3-3) (not (wumpus-at p4-3)))
				(or (stench p3-3) (not (wumpus-at p3-2)))
				(or (stench p3-3) (not (wumpus-at p2-3)))
				(or (stench p3-3) (not (wumpus-at p3-4)))

				(or (not (stench p3-5)) (wumpus-at p3-4)(wumpus-at p4-5) )
				(or (stench p3-5) (not (wumpus-at p3-4)))
				(or (stench p3-5) (not (wumpus-at p4-5)))

				(or (not (stench p5-3)) (wumpus-at p5-4)(wumpus-at p4-3) )
				(or (stench p5-3) (not (wumpus-at p5-4)))
				(or (stench p5-3) (not (wumpus-at p4-3)))

				(or (not (stench p4-4)) (wumpus-at p5-4) (wumpus-at p4-3)(wumpus-at p3-4) (wumpus-at p4-5) )
				(or (stench p4-4) (not (wumpus-at p5-4)))
				(or (stench p4-4) (not (wumpus-at p4-3)))
				(or (stench p4-4) (not (wumpus-at p3-4)))
				(or (stench p4-4) (not (wumpus-at p4-5)))

				(or (not (stench p4-6)) (wumpus-at p4-5)(wumpus-at p5-6) )
				(or (stench p4-6) (not (wumpus-at p4-5)))
				(or (stench p4-6) (not (wumpus-at p5-6)))

				(or (not (stench p6-4)) (wumpus-at p6-5)(wumpus-at p5-4) )
				(or (stench p6-4) (not (wumpus-at p6-5)))
				(or (stench p6-4) (not (wumpus-at p5-4)))

				(or (not (stench p5-5)) (wumpus-at p6-5) (wumpus-at p5-4)(wumpus-at p4-5) (wumpus-at p5-6) )
				(or (stench p5-5) (not (wumpus-at p6-5)))
				(or (stench p5-5) (not (wumpus-at p5-4)))
				(or (stench p5-5) (not (wumpus-at p4-5)))
				(or (stench p5-5) (not (wumpus-at p5-6)))

				(or (not (stench p5-7)) (wumpus-at p5-6)(wumpus-at p6-7) )
				(or (stench p5-7) (not (wumpus-at p5-6)))
				(or (stench p5-7) (not (wumpus-at p6-7)))

				(or (not (stench p7-5)) (wumpus-at p7-6)(wumpus-at p6-5) )
				(or (stench p7-5) (not (wumpus-at p7-6)))
				(or (stench p7-5) (not (wumpus-at p6-5)))

				(or (not (stench p6-6)) (wumpus-at p7-6) (wumpus-at p6-5)(wumpus-at p5-6) (wumpus-at p6-7) )
				(or (stench p6-6) (not (wumpus-at p7-6)))
				(or (stench p6-6) (not (wumpus-at p6-5)))
				(or (stench p6-6) (not (wumpus-at p5-6)))
				(or (stench p6-6) (not (wumpus-at p6-7)))

				(or (not (stench p6-8)) (wumpus-at p6-7)(wumpus-at p7-8) )
				(or (stench p6-8) (not (wumpus-at p6-7)))
				(or (stench p6-8) (not (wumpus-at p7-8)))

				(or (not (stench p8-6)) (wumpus-at p8-7)(wumpus-at p7-6) )
				(or (stench p8-6) (not (wumpus-at p8-7)))
				(or (stench p8-6) (not (wumpus-at p7-6)))

				(or (not (stench p7-7)) (wumpus-at p8-7) (wumpus-at p7-6)(wumpus-at p6-7) (wumpus-at p7-8) )
				(or (stench p7-7) (not (wumpus-at p8-7)))
				(or (stench p7-7) (not (wumpus-at p7-6)))
				(or (stench p7-7) (not (wumpus-at p6-7)))
				(or (stench p7-7) (not (wumpus-at p7-8)))

				(or (not (stench p7-9)) (wumpus-at p7-8)(wumpus-at p8-9) )
				(or (stench p7-9) (not (wumpus-at p7-8)))
				(or (stench p7-9) (not (wumpus-at p8-9)))

				(or (not (stench p9-7)) (wumpus-at p9-8)(wumpus-at p8-7) )
				(or (stench p9-7) (not (wumpus-at p9-8)))
				(or (stench p9-7) (not (wumpus-at p8-7)))

				(or (not (stench p8-8)) (wumpus-at p9-8) (wumpus-at p8-7)(wumpus-at p7-8) (wumpus-at p8-9) )
				(or (stench p8-8) (not (wumpus-at p9-8)))
				(or (stench p8-8) (not (wumpus-at p8-7)))
				(or (stench p8-8) (not (wumpus-at p7-8)))
				(or (stench p8-8) (not (wumpus-at p8-9)))

				(or (not (stench p8-10)) (wumpus-at p8-9)(wumpus-at p9-10) )
				(or (stench p8-10) (not (wumpus-at p8-9)))
				(or (stench p8-10) (not (wumpus-at p9-10)))

				(or (not (stench p10-8)) (wumpus-at p10-9)(wumpus-at p9-8) )
				(or (stench p10-8) (not (wumpus-at p10-9)))
				(or (stench p10-8) (not (wumpus-at p9-8)))

				(or (not (stench p9-9)) (wumpus-at p10-9) (wumpus-at p9-8)(wumpus-at p8-9) (wumpus-at p9-10) )
				(or (stench p9-9) (not (wumpus-at p10-9)))
				(or (stench p9-9) (not (wumpus-at p9-8)))
				(or (stench p9-9) (not (wumpus-at p8-9)))
				(or (stench p9-9) (not (wumpus-at p9-10)))

				(or (not (stench p10-10)) (wumpus-at p9-10)(wumpus-at p10-9) )
				(or (stench p10-10) (not (wumpus-at p9-10)))
				(or (stench p10-10) (not (wumpus-at p10-9)))

				(or (breeze p1-3) (not (pit-at p2-3)))
				(or (not (breeze p1-3))  (pit-at p2-3))

				(or (breeze p3-1) (not (pit-at p3-2)))
				(or (not (breeze p3-1))  (pit-at p3-2))

				(or (not (breeze p2-2)) (pit-at p3-2) (pit-at p2-3))
				(or (breeze p2-2) (not (pit-at p3-2)))
				(or (breeze p2-2) (not (pit-at p2-3)))

				(or (not (breeze p2-4)) (pit-at p2-3)(pit-at p3-4) )
				(or (breeze p2-4) (not (pit-at p2-3)))
				(or (breeze p2-4) (not (pit-at p3-4)))

				(or (not (breeze p4-2)) (pit-at p4-3)(pit-at p3-2) )
				(or (breeze p4-2) (not (pit-at p4-3)))
				(or (breeze p4-2) (not (pit-at p3-2)))

				(or (not (breeze p3-3)) (pit-at p4-3) (pit-at p3-2)(pit-at p2-3) (pit-at p3-4) )
				(or (breeze p3-3) (not (pit-at p4-3)))
				(or (breeze p3-3) (not (pit-at p3-2)))
				(or (breeze p3-3) (not (pit-at p2-3)))
				(or (breeze p3-3) (not (pit-at p3-4)))

				(or (not (breeze p3-5)) (pit-at p3-4)(pit-at p4-5) )
				(or (breeze p3-5) (not (pit-at p3-4)))
				(or (breeze p3-5) (not (pit-at p4-5)))

				(or (not (breeze p5-3)) (pit-at p5-4)(pit-at p4-3) )
				(or (breeze p5-3) (not (pit-at p5-4)))
				(or (breeze p5-3) (not (pit-at p4-3)))

				(or (not (breeze p4-4)) (pit-at p5-4) (pit-at p4-3)(pit-at p3-4) (pit-at p4-5) )
				(or (breeze p4-4) (not (pit-at p5-4)))
				(or (breeze p4-4) (not (pit-at p4-3)))
				(or (breeze p4-4) (not (pit-at p3-4)))
				(or (breeze p4-4) (not (pit-at p4-5)))

				(or (not (breeze p4-6)) (pit-at p4-5)(pit-at p5-6) )
				(or (breeze p4-6) (not (pit-at p4-5)))
				(or (breeze p4-6) (not (pit-at p5-6)))

				(or (not (breeze p6-4)) (pit-at p6-5)(pit-at p5-4) )
				(or (breeze p6-4) (not (pit-at p6-5)))
				(or (breeze p6-4) (not (pit-at p5-4)))

				(or (not (breeze p5-5)) (pit-at p6-5) (pit-at p5-4)(pit-at p4-5) (pit-at p5-6) )
				(or (breeze p5-5) (not (pit-at p6-5)))
				(or (breeze p5-5) (not (pit-at p5-4)))
				(or (breeze p5-5) (not (pit-at p4-5)))
				(or (breeze p5-5) (not (pit-at p5-6)))

				(or (not (breeze p5-7)) (pit-at p5-6)(pit-at p6-7) )
				(or (breeze p5-7) (not (pit-at p5-6)))
				(or (breeze p5-7) (not (pit-at p6-7)))

				(or (not (breeze p7-5)) (pit-at p7-6)(pit-at p6-5) )
				(or (breeze p7-5) (not (pit-at p7-6)))
				(or (breeze p7-5) (not (pit-at p6-5)))

				(or (not (breeze p6-6)) (pit-at p7-6) (pit-at p6-5)(pit-at p5-6) (pit-at p6-7) )
				(or (breeze p6-6) (not (pit-at p7-6)))
				(or (breeze p6-6) (not (pit-at p6-5)))
				(or (breeze p6-6) (not (pit-at p5-6)))
				(or (breeze p6-6) (not (pit-at p6-7)))

				(or (not (breeze p6-8)) (pit-at p6-7)(pit-at p7-8) )
				(or (breeze p6-8) (not (pit-at p6-7)))
				(or (breeze p6-8) (not (pit-at p7-8)))

				(or (not (breeze p8-6)) (pit-at p8-7)(pit-at p7-6) )
				(or (breeze p8-6) (not (pit-at p8-7)))
				(or (breeze p8-6) (not (pit-at p7-6)))

				(or (not (breeze p7-7)) (pit-at p8-7) (pit-at p7-6)(pit-at p6-7) (pit-at p7-8) )
				(or (breeze p7-7) (not (pit-at p8-7)))
				(or (breeze p7-7) (not (pit-at p7-6)))
				(or (breeze p7-7) (not (pit-at p6-7)))
				(or (breeze p7-7) (not (pit-at p7-8)))

				(or (not (breeze p7-9)) (pit-at p7-8)(pit-at p8-9) )
				(or (breeze p7-9) (not (pit-at p7-8)))
				(or (breeze p7-9) (not (pit-at p8-9)))

				(or (not (breeze p9-7)) (pit-at p9-8)(pit-at p8-7) )
				(or (breeze p9-7) (not (pit-at p9-8)))
				(or (breeze p9-7) (not (pit-at p8-7)))

				(or (not (breeze p8-8)) (pit-at p9-8) (pit-at p8-7)(pit-at p7-8) (pit-at p8-9) )
				(or (breeze p8-8) (not (pit-at p9-8)))
				(or (breeze p8-8) (not (pit-at p8-7)))
				(or (breeze p8-8) (not (pit-at p7-8)))
				(or (breeze p8-8) (not (pit-at p8-9)))

				(or (not (breeze p8-10)) (pit-at p8-9)(pit-at p9-10) )
				(or (breeze p8-10) (not (pit-at p8-9)))
				(or (breeze p8-10) (not (pit-at p9-10)))

				(or (not (breeze p10-8)) (pit-at p10-9)(pit-at p9-8) )
				(or (breeze p10-8) (not (pit-at p10-9)))
				(or (breeze p10-8) (not (pit-at p9-8)))

				(or (not (breeze p9-9)) (pit-at p10-9) (pit-at p9-8)(pit-at p8-9) (pit-at p9-10) )
				(or (breeze p9-9) (not (pit-at p10-9)))
				(or (breeze p9-9) (not (pit-at p9-8)))
				(or (breeze p9-9) (not (pit-at p8-9)))
				(or (breeze p9-9) (not (pit-at p9-10)))

				(or (not (breeze p10-10)) (pit-at p9-10)(pit-at p10-9) )
				(or (breeze p10-10) (not (pit-at p9-10)))
				(or (breeze p10-10) (not (pit-at p10-9)))
			)
		)
	)
      
	(:goal (K (and (got-the-treasure) (alive))))
) 
