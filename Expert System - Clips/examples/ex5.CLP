; Define initial facts
(deffacts students
    (student name "Ali" grade 75)
    (student name "Mona" grade 85)
    (student name "Ahmed" grade 90)
)

; Rule to find students with grades above 80
(defrule high-performing-students
    ?s <- (student name ?name grade ?grade&:(> ?grade 80)) 
    ; Filter students with grade > 80
    =>
    (printout t "High-performing student: " ?name ", Grade: " ?grade crlf)
)