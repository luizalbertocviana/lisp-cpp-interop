(defpackage :lib
  (:use :common-lisp :sb-alien))

(in-package :lib)

(load-shared-object "Debug/liblib.so")

(define-alien-type nil (struct CPoint))

(define-alien-routine "CPoint_new" (* (struct CPoint))
  (x double)
  (y double))

(define-alien-routine "CPoint_x" double
  (point (* (struct CPoint))))

(define-alien-routine "CPoint_y" double
  (point (* (struct CPoint))))

(define-alien-routine "CPoint_delete" void
  (point (* (struct CPoint))))
