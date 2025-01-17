;       Z88 Small C+ Run Time Library 
;       Long functions
;       "8080" mode
;       Stefano - 29/4/2002
;

SECTION   code_crt0_sccz80

PUBLIC  l_long_add
EXTERN  __retloc

;primary = secondary + primary
;enter with secondary, primary on stack

.l_long_add
    ex    (sp),hl
    ld    (__retloc),hl
    pop    bc

    ld      hl,0
    add     hl,sp   ;points to hl on stack

    ld      a,(hl)
    add     c
    inc     hl
    ld      c,a

    ld      a,(hl)
    adc     a,b
    inc     hl
    ld      b,a

    ld      a,(hl)
    adc     a,e
    inc     hl
    ld      e,a

    ld      a,(hl)
    adc     a,d
    inc    hl
    ld      d,a

    ld    sp,hl
    ld    hl,(__retloc)
    push    hl

    ld      l,c     ;get the lower 16 back into hl
    ld      h,b
    ret
