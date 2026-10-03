(defglobal  ?*cnt*  =  0)	;Possibilities Count
;==============
(deffacts DicesFaces
   (dice1   1)  (dice2   1)
   (dice1   2)  (dice2   2)
   (dice1   3)  (dice2   3)
   (dice1   4)  (dice2   4)
   (dice1   5)  (dice2   5)
   (dice1   6)  (dice2   6)
)
;==============

(defrule MainMenu
(initial-fact)
=>
   (printout  t  crlf "====================" crlf)
   (printout  t  "Enter your choice of rolling the two dice once:" crlf)
	(printout  t  "  1- The two sides are same."  crlf)
	(printout  t  "  2- The two sides are different."  crlf)
	(printout  t  "  3- The first dice side is less than the second." crlf)
	(printout  t  "  4- Exit." crlf)
	(printout  t  "-------------------------" crlf)
	(printout  t  "Your selection? ")
	(bind  ?s  (read) )
	;----------
	(bind  $?sel  (create$ 1 2 3 4))     ;The four selections list
	;Selections verifying:
	(if  (eq  (member$  ?s  $?sel)  FALSE) then
		(reset)
		(run)
	else 
		(set-strategy breadth)
		(bind  ?*cnt*  0)
		(assert (Selection_No  ?s) )
		(if (< ?s 4) then (printout t crlf "The Result:" crlf) )
	)
)

;==============

;(1- The two sides are same)
(defrule Case_1
  (Selection_No  1)
  (dice1 ?d1)
  (dice2 ?d2)
  (test (=  ?d1  ?d2))
=>
	(bind  ?*cnt*  (+  ?*cnt*  1) )
	(printout t  ?d1  " , "  ?d2  crlf)
)

;==============

;(2- The two sides are different)
(defrule Case_2
  (Selection_No  2)
  (dice1 ?d1)
  (dice1 ?d2)
  (test (<>  ?d1  ?d2))
=>
	(bind  ?*cnt*  (+  ?*cnt*  1) )
	(printout t  ?d1  " , "  ?d2  crlf)
)

;==============

;(3- The first dice side is less than the second)
(defrule Case_3
  (Selection_No  3)
  (dice1 ?d1)
  (dice1 ?d2)
  (test (<  ?d1  ?d2))
=>
	(bind  ?*cnt*  (+  ?*cnt*  1) )
	(printout t  ?d1  " , "  ?d2  crlf)
)

;==============
;Get the possibilities count
(defrule Case_Count   (declare (salience -10))
  (Selection_No  ~4)
=>
	(printout t  "==========="crlf)
	(printout t  " Possibilities Count =  "  ?*cnt*  crlf)
	(printout t "-------------------------" crlf)
	(printout t crlf "Do you want continue (y/n) ? " )
	(bind ?c (read) )
	(if (eq ?c y) then
		(reset)
		(run)
	)
)
