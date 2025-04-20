(deffacts Test
  (colors blue red green)
  ;(colors red green) ;ده تعليق
  ;(colors green blue)
  ;(colors red blue)
)
; لازم تعمل reset عشان يعمل run for the facts

; في CLIPS، الـ test هو جزء من القاعدة (defrule) بيستخدم لتنفيذ شروط إضافية معقدة، زي مقارنة قيم أو تقييم تعبيرات منطقية. بمعنى آخر، بيكون زي "اختبار" إضافي يجب أن يكون صحيح علشان القاعدة تتنفذ.


(defrule  Mix1
   (colors ?c1  ?c2) ; بيدور على فاكت اسمها كلور وعندها متغيرين
   (test
        (and (or (eq  ?c1  red)  (eq  ?c2  red))
             (or (eq  ?c1  green)  (eq  ?c2  green))
   ))
=>
   (printout  t  "Red + Green = Yellow"  crlf)
)
;لازم واحدة من القيمتين تكون أحمر (red)
; ولازم التانية تكون أخضر (green)

; يعني التوليفة المقبولة هي:
; (colors red green)
; (colors green red)

; لكن مثلًا (colors red blue) أو (colors green blue) مش هتشغّل لو




(defrule Mix2
   (colors ?c1 ?c2)
   (test(or (eq ?c1 green)(eq ?c2 green)))
   (test(or (eq ?c1 blue)(eq ?c2 blue)))
=>
   (printout t "Green + Blue = Cyan" crlf)
)

(defrule Mix3
   (colors ?c1 ?c2)
   (test(or (eq ?c1 red)(eq ?c2 red)))
   (test(or (eq ?c1 blue)(eq ?c2 blue)))
=>
   (printout t "Red + Blue = Magenta" crlf)
)

(defrule Mix4
   (colors ?c1 ?c2 ?c3)
   (test(or (eq ?c1 red) (eq ?c2 red) (eq ?c3 red)))
   (test(or (eq ?c1 green) (eq ?c2 green) (eq ?c3 green)))
   (test(or (eq ?c1 blue) (eq ?c2 blue) (eq ?c3 blue)))
=>
   (printout t "Red + Green + Blue = White" crlf)
)
