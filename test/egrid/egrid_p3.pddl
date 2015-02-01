(define (problem grid-x3-y3-t2-k12-l22-p100)
	(:domain egrid)
	(:objects 
			f0-0f 
			f1-0f 
			f2-0f 
			f0-1f 
			f1-1f 
			f2-1f 
			f0-2f 
			f1-2f 
			f2-2f - POS 
			shape0 
			shape1 - SHAPE 
			key0-0 
			key1-0 
			key1-1 - KEY 
	)
	
	(:init (K (and
				(key key0-0)
				(key-shape key0-0 shape0)
				(key key1-0)
				(key-shape key1-0 shape1)
				(key key1-1)
				(key-shape key1-1 shape1)
				(conn f0-0f f1-0f)
				(conn f1-0f f2-0f)
				(conn f0-1f f1-1f)
				(conn f1-1f f2-1f)
				(conn f0-2f f1-2f)
				(conn f1-2f f2-2f)
				(conn f0-0f f0-1f)
				(conn f1-0f f1-1f)
				(conn f2-0f f2-1f)
				(conn f0-1f f0-2f)
				(conn f1-1f f1-2f)
				(conn f2-1f f2-2f)
				(conn f1-0f f0-0f)
				(conn f2-0f f1-0f)
				(conn f1-1f f0-1f)
				(conn f2-1f f1-1f)
				(conn f1-2f f0-2f)
				(conn f2-2f f1-2f)
				(conn f0-1f f0-0f)
				(conn f1-1f f1-0f)
				(conn f2-1f f2-0f)
				(conn f0-2f f0-1f)
				(conn f1-2f f1-1f)
				(conn f2-2f f2-1f)
				(open f1-1f)
				(open f2-1f)
				(open f0-2f)
				(open f1-2f)
				(open f2-2f)
				(locked f0-0f)
#				(unknown (lock-shape f0-0f shape0))
#				(unknown (lock-shape f0-0f shape1))
				(oneof
					(lock-shape f0-0f shape0)
					(lock-shape f0-0f shape1)
				)
				(locked f2-0f)
#				(unknown (lock-shape f2-0f shape0))
#				(unknown (lock-shape f2-0f shape1))
				(oneof
					(lock-shape f2-0f shape0)
					(lock-shape f2-0f shape1)
				)
				(locked f1-0f)
#				(unknown (lock-shape f1-0f shape0))
#				(unknown (lock-shape f1-0f shape1))
				(oneof
					(lock-shape f1-0f shape0)
					(lock-shape f1-0f shape1)
				)
				(locked f0-1f)
#				(unknown (lock-shape f0-1f shape0))
#				(unknown (lock-shape f0-1f shape1))
				(oneof
					(lock-shape f0-1f shape0)
					(lock-shape f0-1f shape1)
				)
				(at key0-0 f1-2f)
				(at key1-0 f2-2f)
				(at key1-1 f0-1f)
				(at-robot f1-2f)
				)
			)
	)
	
	(:goal(K (and
				(at key0-0 f0-0f)
				(at key1-0 f1-1f)
				(at key1-1 f0-1f)
			 )
	      )
	)
)


