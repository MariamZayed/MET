(deffacts f1
  (a r g w) ; تخزن لسته من القيم (r, g, w) تحت اسم a
  (b y b k g r w m) ; بتخزن لسته تانية من القيم (y, b, k, g, r, w, m) تحت اسم b
)

(defrule r1
  (a $?x)
  (b $?y) ; بتبحث عن ليستة الفاكتس اللي اسمها a و b

  (test
	(subsetp $?x $?y)
  )
=>
  (progn$(?i $?x) ; we will itterate over ech item in list ?x
	(bind ?idx (member$ ?i $?y)) ; member$ function will search in the list for the item and then return the index 
                                 ; remember index starts with 1 
	(bind $?y (delete$ $?y ?idx ?idx) ) ; delete$ <multifield> <start> <end> 
  )
  (printout t $?y crlf)
)

