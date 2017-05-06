#lang scheme

; evenitems.scm
; Cameron Showalter
; CS 331 - Assignment 7 Part C


;evenitems
; returns a list of all even items in itemList
(define (evenitems itemList)
    (if (null? itemList) '()
        (if (not(null? (cdr itemList)))
            (cons (car itemList) (evenitems (cddr itemList))) 
        itemList)    
    )
)