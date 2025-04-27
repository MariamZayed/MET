; Define a custom function to calculate the average
(defun calculate-average (?num1 ?num2)
    (/ (+ ?num1 ?num2) 2)
)

; Define initial facts
(deffacts initial-numbers
    (number 80)
    (number 90)
)

; Rule to calculate the average
(defrule calculate-average-rule
    (number ?num1)
    (number ?num2)
    =>
    (bind ?average (calculate-average ?num1 ?num2))  ; Calculate the average using the function
    (printout t "The average is " ?average "." crlf)  ; Print the result
)