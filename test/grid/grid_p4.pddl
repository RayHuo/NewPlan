(define (problem grid-x3-y3-t2-k23-l23-p100)
	(:domain grid)
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
		key0-1 
        key1-0 
		key1-1
		key1-2 - KEY 
	)	
	
	(:init (K (and
				(arm-empty)
				(place f0-0f)
				(place f1-0f)
				(place f2-0f)
				(place f0-1f)
				(place f1-1f)
				(place f2-1f)
				(place f0-2f)
				(place f1-2f)
				(place f2-2f)
				(shape shape0)
				(shape shape1)
				(key key0-0)
				(key-shape key0-0 shape0)
				(key key0-1)
				(key-shape key0-1 shape0)
				(key key1-0)
				(key-shape key1-0 shape1)
				(key key1-1)
				(key-shape key1-1 shape1)
				(key key1-2)
				(key-shape key1-2 shape1)
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
				(open f0-0f)
				(open f1-0f)
				(open f2-1f)
				(open f2-2f)
				(locked f1-1f)
				(oneof
					(lock-shape f1-1f shape0)
					(lock-shape f1-1f shape1)
				)
				(locked f0-1f)
				(oneof
					(lock-shape f0-1f shape0)
					(lock-shape f0-1f shape1)
				)
				(locked f0-2f)
				(oneof
					(lock-shape f0-2f shape0)
					(lock-shape f0-2f shape1)
				)
				(locked f2-0f)
				(oneof
					(lock-shape f2-0f shape0)
					(lock-shape f2-0f shape1)
				)
				(locked f1-2f)
				(oneof
					(lock-shape f1-2f shape0)
					(lock-shape f1-2f shape1)
				)
				(at key0-0 f0-2f)
				(at key0-1 f0-0f)
				(at key1-0 f0-1f)
				(at key1-1 f0-0f)
				(at key1-2 f0-0f)
				(at-robot f1-0f)
				)
			)
	)
	
	(:goal(K (and
				(at key0-0 f2-2f)
				(at key0-1 f0-0f)
				(at key1-0 f0-1f)
				(at key1-1 f1-0f)
				(at key1-2 f2-2f)
			)
	    )
    )
)


