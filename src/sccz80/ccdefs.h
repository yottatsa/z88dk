/*
 *      Small C+ Compiler
 *
 *      The master header file
 *      Includes everything else!!!
 *
 *      $Id: ccdefs.h,v 1.5 2016-08-26 05:44:47 aralbrec Exp $
 */


#ifndef CCDEFS_H
#define CCDEFS_H

#include <sys/types.h>
#include <stdint.h>
#include <stdio.h>
#include <ctype.h>

#include "define.h"

/*
 * 	Now the fix for HP-UX
 *	Darn short filename filesystems!
 */

#ifdef hpux
#define FILENAME_LEN 1024
#else
#define FILENAME_LEN FILENAME_MAX
#endif


/*
 *      Now some system files for good luck
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 *      Prototypes
 */

extern void     callfunction(SYMBOL *ptr, Type *func_ptr_call_type);

#include "codegen.h"
extern void copy_to_stack(char *label, int stack_offset,  int size);
extern void copy_to_extern(const char *src, const char *dest, int size);
extern void push_char_sdcc_style(void);
#include "const.h"
extern void dofloat(double raw, unsigned char fa[]);
#include "data.h"
#include "declinit.h"

extern Type      *type_int;
extern void       array_free(array *arr);
extern size_t     array_len(array *arr);
extern void       array_add(array *arr, void *elem);
extern void      *array_get_byindex(array *arr, int index);
extern Type      *find_tag(const char *name);
extern Type      *find_tag_field(Type *tag, const char *fieldname);
extern Type      *parse_expr_type();
extern Type      *default_function(const char *name);
extern Type     *asm_function(const char *name);
extern Type      *make_pointer(Type *base_type);
extern Type      *dodeclare(enum storage_type storage);
extern int        declare_local(int local_static);
extern void       declare_func_kr();
extern int        ispointer(Type *type);
extern void       type_describe(Type *type, UT_string *output);
extern int        type_matches(Type *t1, Type *t2);

#include "error.h"
#include "expr.h"
extern GOTO_TAB *gotoq; /* Pointer for gotoq */
extern int      dolabel(void);
extern void     dogoto(void);
extern void     goto_cleanup(void);
#include "io.h"
#include "lex.h"
#include "main.h"
#include "misc.h"

/* plunge.c */
extern int      skim(char *opstr, void (*testfuncz)(LVALUE* lval, int label), void (*testfuncq)(int label), int dropval, int endval, int (*heir)(LVALUE* lval), LVALUE *lval);
extern void     dropout(int k, void (*testfuncz)(LVALUE* lval, int label), void (*testfuncq)(int label), int exit1, LVALUE *lval);
extern int      plnge1(int (*heir)(LVALUE* lval), LVALUE *lval);
extern void     plnge2a(int (*heir)(LVALUE* lval), LVALUE *lval, LVALUE *lval2, void (*oper)(LVALUE *lval), void (*doper)(LVALUE *lval), void (*constoper)(LVALUE *lval, int32_t constval));
extern void     plnge2b(int (*heir)(LVALUE* lval), LVALUE *lval, LVALUE *lval2, void (*oper)(LVALUE *lval));
extern void     load_constant(LVALUE *lval);

#include "preproc.h"
#include "primary.h"
#include "stmt.h"
#include "sym.h"
#include "while.h"

#endif
