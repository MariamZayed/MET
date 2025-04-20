(deffacts f1
  (a r g w)
  (b y b k g r w m)
)

(defrule r1
  (a $?x)
  (b $?y)
  (test
	(subsetp $?x $?y)
  )
=>
  (progn$(?i $?x)
	(bind ?idx (member$ ?i $?y))
	(bind $?y (delete$ $?y ?idx ?idx) )
  )
  (printout t $?y crlf)
)

