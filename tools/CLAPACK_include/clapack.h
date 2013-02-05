/* header file for clapack 3.2.1 */

#ifndef __CLAPACK_H
#define __CLAPACK_H

#ifdef __cplusplus 	
extern "C" {	
#endif		

/* Subroutine */ int caxpy_(integer *n, complex *ca, complex *cx, integer *
	incx, complex *cy, integer *incy);

/* Subroutine */ int ccopy_(integer *n, complex *cx, integer *incx, complex *
	cy, integer *incy);

/* Complex */ VOID cdotc_(complex * ret_val, integer *n, complex *cx, integer 
	*incx, complex *cy, integer *incy);

/* Complex */ VOID cdotu_(complex * ret_val, integer *n, complex *cx, integer 
	*incx, complex *cy, integer *incy);

/* Subroutine */ int cgbmv_(char *trans, integer *m, integer *n, integer *kl, 
	integer *ku, complex *alpha, complex *a, integer *lda, complex *x, 
	integer *incx, complex *beta, complex *y, integer *incy);

/* Subroutine */ int cgemm_(char *transa, char *transb, integer *m, integer *
	n, integer *k, complex *alpha, complex *a, integer *lda, complex *b, 
	integer *ldb, complex *beta, complex *c__, integer *ldc);

/* Subroutine */ int cgemv_(char *trans, integer *m, integer *n, complex *
	alpha, complex *a, integer *lda, complex *x, integer *incx, complex *
	beta, complex *y, integer *incy);

/* Subroutine */ int cgerc_(integer *m, integer *n, complex *alpha, complex *
	x, integer *incx, complex *y, integer *incy, complex *a, integer *lda);

/* Subroutine */ int cgeru_(integer *m, integer *n, complex *alpha, complex *
	x, integer *incx, complex *y, integer *incy, complex *a, integer *lda);

/* Subroutine */ int chbmv_(char *uplo, integer *n, integer *k, complex *
	alpha, complex *a, integer *lda, complex *x, integer *incx, complex *
	beta, complex *y, integer *incy);

/* Subroutine */ int chemm_(char *side, char *uplo, integer *m, integer *n, 
	complex *alpha, complex *a, integer *lda, complex *b, integer *ldb, 
	complex *beta, complex *c__, integer *ldc);

/* Subroutine */ int chemv_(char *uplo, integer *n, complex *alpha, complex *
	a, integer *lda, complex *x, integer *incx, complex *beta, complex *y, 
	 integer *incy);

/* Subroutine */ int cher_(char *uplo, integer *n, real *alpha, complex *x, 
	integer *incx, complex *a, integer *lda);

/* Subroutine */ int cher2_(char *uplo, integer *n, complex *alpha, complex *
	x, integer *incx, complex *y, integer *incy, complex *a, integer *lda);

/* Subroutine */ int cher2k_(char *uplo, char *trans, integer *n, integer *k, 
	complex *alpha, complex *a, integer *lda, complex *b, integer *ldb, 
	real *beta, complex *c__, integer *ldc);

/* Subroutine */ int cherk_(char *uplo, char *trans, integer *n, integer *k, 
	real *alpha, complex *a, integer *lda, real *beta, complex *c__, 
	integer *ldc);

/* Subroutine */ int chpmv_(char *uplo, integer *n, complex *alpha, complex *
	ap, complex *x, integer *incx, complex *beta, complex *y, integer *
	incy);

/* Subroutine */ int chpr_(char *uplo, integer *n, real *alpha, complex *x, 
	integer *incx, complex *ap);

/* Subroutine */ int chpr2_(char *uplo, integer *n, complex *alpha, complex *
	x, integer *incx, complex *y, integer *incy, complex *ap);

/* Subroutine */ int crotg_(complex *ca, complex *cb, real *c__, complex *s);

/* Subroutine */ int cscal_(integer *n, complex *ca, complex *cx, integer *
	incx);

/* Subroutine */ int csrot_(integer *n, complex *cx, integer *incx, complex *
	cy, integer *incy, real *c__, real *s);

/* Subroutine */ int csscal_(integer *n, real *sa, complex *cx, integer *incx);

/* Subroutine */ int cswap_(integer *n, complex *cx, integer *incx, complex *
	cy, integer *incy);

/* Subroutine */ int csymm_(char *side, char *uplo, integer *m, integer *n, 
	complex *alpha, complex *a, integer *lda, complex *b, integer *ldb, 
	complex *beta, complex *c__, integer *ldc);

/* Subroutine */ int csyr2k_(char *uplo, char *trans, integer *n, integer *k, 
	complex *alpha, complex *a, integer *lda, complex *b, integer *ldb, 
	complex *beta, complex *c__, integer *ldc);

/* Subroutine */ int csyrk_(char *uplo, char *trans, integer *n, integer *k, 
	complex *alpha, complex *a, integer *lda, complex *beta, complex *c__, 
	 integer *ldc);

/* Subroutine */ int ctbmv_(char *uplo, char *trans, char *diag, integer *n, 
	integer *k, complex *a, integer *lda, complex *x, integer *incx);

/* Subroutine */ int ctbsv_(char *uplo, char *trans, char *diag, integer *n, 
	integer *k, complex *a, integer *lda, complex *x, integer *incx);

/* Subroutine */ int ctpmv_(char *uplo, char *trans, char *diag, integer *n, 
	complex *ap, complex *x, integer *incx);

/* Subroutine */ int ctpsv_(char *uplo, char *trans, char *diag, integer *n, 
	complex *ap, complex *x, integer *incx);

/* Subroutine */ int ctrmm_(char *side, char *uplo, char *transa, char *diag, 
	integer *m, integer *n, complex *alpha, complex *a, integer *lda, 
	complex *b, integer *ldb);

/* Subroutine */ int ctrmv_(char *uplo, char *trans, char *diag, integer *n, 
	complex *a, integer *lda, complex *x, integer *incx);

/* Subroutine */ int ctrsm_(char *side, char *uplo, char *transa, char *diag, 
	integer *m, integer *n, complex *alpha, complex *a, integer *lda, 
	complex *b, integer *ldb);

/* Subroutine */ int ctrsv_(char *uplo, char *trans, char *diag, integer *n, 
	complex *a, integer *lda, complex *x, integer *incx);

doublereal dasum_(integer *n, doublereal *dx, integer *incx);

/* Subroutine */ int daxpy_(integer *n, doublereal *da, doublereal *dx, 
	integer *incx, doublereal *dy, integer *incy);

doublereal dcabs1_(doublecomplex *z__);

/* Subroutine */ int dcopy_(integer *n, doublereal *dx, integer *incx, 
	doublereal *dy, integer *incy);

doublereal ddot_(integer *n, doublereal *dx, integer *incx, doublereal *dy, 
	integer *incy);

/* Subroutine */ int dgbmv_(char *trans, integer *m, integer *n, integer *kl, 
	integer *ku, doublereal *alpha, doublereal *a, integer *lda, 
	doublereal *x, integer *incx, doublereal *beta, doublereal *y, 
	integer *incy);

/* Subroutine */ int dgemm_(char *transa, char *transb, integer *m, integer *
	n, integer *k, doublereal *alpha, doublereal *a, integer *lda, 
	doublereal *b, integer *ldb, doublereal *beta, doublereal *c__, 
	integer *ldc);

/* Subroutine */ int dgemv_(char *trans, integer *m, integer *n, doublereal *
	alpha, doublereal *a, integer *lda, doublereal *x, integer *incx, 
	doublereal *beta, doublereal *y, integer *incy);

/* Subroutine */ int dger_(integer *m, integer *n, doublereal *alpha, 
	doublereal *x, integer *incx, doublereal *y, integer *incy, 
	doublereal *a, integer *lda);

doublereal dnrm2_(integer *n, doublereal *x, integer *incx);

/* Subroutine */ int drot_(integer *n, doublereal *dx, integer *incx, 
	doublereal *dy, integer *incy, doublereal *c__, doublereal *s);

/* Subroutine */ int drotg_(doublereal *da, doublereal *db, doublereal *c__, 
	doublereal *s);

/* Subroutine */ int drotm_(integer *n, doublereal *dx, integer *incx, 
	doublereal *dy, integer *incy, doublereal *dparam);

/* Subroutine */ int drotmg_(doublereal *dd1, doublereal *dd2, doublereal *
	dx1, doublereal *dy1, doublereal *dparam);

/* Subroutine */ int dsbmv_(char *uplo, integer *n, integer *k, doublereal *
	alpha, doublereal *a, integer *lda, doublereal *x, integer *incx, 
	doublereal *beta, doublereal *y, integer *incy);

/* Subroutine */ int dscal_(integer *n, doublereal *da, doublereal *dx, 
	integer *incx);

doublereal dsdot_(integer *n, real *sx, integer *incx, real *sy, integer *
	incy);

/* Subroutine */ int dspmv_(char *uplo, integer *n, doublereal *alpha, 
	doublereal *ap, doublereal *x, integer *incx, doublereal *beta, 
	doublereal *y, integer *incy);

/* Subroutine */ int dspr_(char *uplo, integer *n, doublereal *alpha, 
	doublereal *x, integer *incx, doublereal *ap);

/* Subroutine */ int dspr2_(char *uplo, integer *n, doublereal *alpha, 
	doublereal *x, integer *incx, doublereal *y, integer *incy, 
	doublereal *ap);

/* Subroutine */ int dswap_(integer *n, doublereal *dx, integer *incx, 
	doublereal *dy, integer *incy);

/* Subroutine */ int dsymm_(char *side, char *uplo, integer *m, integer *n, 
	doublereal *alpha, doublereal *a, integer *lda, doublereal *b, 
	integer *ldb, doublereal *beta, doublereal *c__, integer *ldc);

/* Subroutine */ int dsymv_(char *uplo, integer *n, doublereal *alpha, 
	doublereal *a, integer *lda, doublereal *x, integer *incx, doublereal 
	*beta, doublereal *y, integer *incy);

/* Subroutine */ int dsyr_(char *uplo, integer *n, doublereal *alpha, 
	doublereal *x, integer *incx, doublereal *a, integer *lda);

/* Subroutine */ int dsyr2_(char *uplo, integer *n, doublereal *alpha, 
	doublereal *x, integer *incx, doublereal *y, integer *incy, 
	doublereal *a, integer *lda);

/* Subroutine */ int dsyr2k_(char *uplo, char *trans, integer *n, integer *k, 
	doublereal *alpha, doublereal *a, integer *lda, doublereal *b, 
	integer *ldb, doublereal *beta, doublereal *c__, integer *ldc);

/* Subroutine */ int dsyrk_(char *uplo, char *trans, integer *n, integer *k, 
	doublereal *alpha, doublereal *a, integer *lda, doublereal *beta, 
	doublereal *c__, integer *ldc);

/* Subroutine */ int dtbmv_(char *uplo, char *trans, char *diag, integer *n, 
	integer *k, doublereal *a, integer *lda, doublereal *x, integer *incx);

/* Subroutine */ int dtbsv_(char *uplo, char *trans, char *diag, integer *n, 
	integer *k, doublereal *a, integer *lda, doublereal *x, integer *incx);

/* Subroutine */ int dtpmv_(char *uplo, char *trans, char *diag, integer *n, 
	doublereal *ap, doublereal *x, integer *incx);

/* Subroutine */ int dtpsv_(char *uplo, char *trans, char *diag, integer *n, 
	doublereal *ap, doublereal *x, integer *incx);

/* Subroutine */ int dtrmm_(char *side, char *uplo, char *transa, char *diag, 
	integer *m, integer *n, doublereal *alpha, doublereal *a, integer *
	lda, doublereal *b, integer *ldb);

/* Subroutine */ int dtrmv_(char *uplo, char *trans, char *diag, integer *n, 
	doublereal *a, integer *lda, doublereal *x, integer *incx);

/* Subroutine */ int dtrsm_(char *side, char *uplo, char *transa, char *diag, 
	integer *m, integer *n, doublereal *alpha, doublereal *a, integer *
	lda, doublereal *b, integer *ldb);

/* Subroutine */ int dtrsv_(char *uplo, char *trans, char *diag, integer *n, 
	doublereal *a, integer *lda, doublereal *x, integer *incx);

doublereal dzasum_(integer *n, doublecomplex *zx, integer *incx);

doublereal dznrm2_(integer *n, doublecomplex *x, integer *incx);

integer icamax_(integer *n, complex *cx, integer *incx);

integer idamax_(integer *n, doublereal *dx, integer *incx);

integer isamax_(integer *n, real *sx, integer *incx);

integer izamax_(integer *n, doublecomplex *zx, integer *incx);

logical lsame_(char *ca, char *cb);

doublereal sasum_(integer *n, real *sx, integer *incx);

/* Subroutine */ int saxpy_(integer *n, real *sa, real *sx, integer *incx, 
	real *sy, integer *incy);

doublereal scabs1_(complex *z__);

doublereal scasum_(integer *n, complex *cx, integer *incx);

doublereal scnrm2_(integer *n, complex *x, integer *incx);

/* Subroutine */ int scopy_(integer *n, real *sx, integer *incx, real *sy, 
	integer *incy);

doublereal sdot_(integer *n, real *sx, integer *incx, real *sy, integer *incy);

doublereal sdsdot_(integer *n, real *sb, real *sx, integer *incx, real *sy, 
	integer *incy);

/* Subroutine */ int sgbmv_(char *trans, integer *m, integer *n, integer *kl, 
	integer *ku, real *alpha, real *a, integer *lda, real *x, integer *
	incx, real *beta, real *y, integer *incy);

/* Subroutine */ int sgemm_(char *transa, char *transb, integer *m, integer *
	n, integer *k, real *alpha, real *a, integer *lda, real *b, integer *
	ldb, real *beta, real *c__, integer *ldc);

/* Subroutine */ int sgemv_(char *trans, integer *m, integer *n, real *alpha, 
	real *a, integer *lda, real *x, integer *incx, real *beta, real *y, 
	integer *incy);

/* Subroutine */ int sger_(integer *m, integer *n, real *alpha, real *x, 
	integer *incx, real *y, integer *incy, real *a, integer *lda);

doublereal snrm2_(integer *n, real *x, integer *incx);

/* Subroutine */ int srot_(integer *n, real *sx, integer *incx, real *sy, 
	integer *incy, real *c__, real *s);

/* Subroutine */ int srotg_(real *sa, real *sb, real *c__, real *s);

/* Subroutine */ int srotm_(integer *n, real *sx, integer *incx, real *sy, 
	integer *incy, real *sparam);

/* Subroutine */ int srotmg_(real *sd1, real *sd2, real *sx1, real *sy1, real 
	*sparam);

/* Subroutine */ int ssbmv_(char *uplo, integer *n, integer *k, real *alpha, 
	real *a, integer *lda, real *x, integer *incx, real *beta, real *y, 
	integer *incy);

/* Subroutine */ int sscal_(integer *n, real *sa, real *sx, integer *incx);

/* Subroutine */ int sspmv_(char *uplo, integer *n, real *alpha, real *ap, 
	real *x, integer *incx, real *beta, real *y, integer *incy);

/* Subroutine */ int sspr_(char *uplo, integer *n, real *alpha, real *x, 
	integer *incx, real *ap);

/* Subroutine */ int sspr2_(char *uplo, integer *n, real *alpha, real *x, 
	integer *incx, real *y, integer *incy, real *ap);

/* Subroutine */ int sswap_(integer *n, real *sx, integer *incx, real *sy, 
	integer *incy);

/* Subroutine */ int ssymm_(char *side, char *uplo, integer *m, integer *n, 
	real *alpha, real *a, integer *lda, real *b, integer *ldb, real *beta, 
	 real *c__, integer *ldc);

/* Subroutine */ int ssymv_(char *uplo, integer *n, real *alpha, real *a, 
	integer *lda, real *x, integer *incx, real *beta, real *y, integer *
	incy);

/* Subroutine */ int ssyr_(char *uplo, integer *n, real *alpha, real *x, 
	integer *incx, real *a, integer *lda);

/* Subroutine */ int ssyr2_(char *uplo, integer *n, real *alpha, real *x, 
	integer *incx, real *y, integer *incy, real *a, integer *lda);

/* Subroutine */ int ssyr2k_(char *uplo, char *trans, integer *n, integer *k, 
	real *alpha, real *a, integer *lda, real *b, integer *ldb, real *beta, 
	 real *c__, integer *ldc);

/* Subroutine */ int ssyrk_(char *uplo, char *trans, integer *n, integer *k, 
	real *alpha, real *a, integer *lda, real *beta, real *c__, integer *
	ldc);

/* Subroutine */ int stbmv_(char *uplo, char *trans, char *diag, integer *n, 
	integer *k, real *a, integer *lda, real *x, integer *incx);

/* Subroutine */ int stbsv_(char *uplo, char *trans, char *diag, integer *n, 
	integer *k, real *a, integer *lda, real *x, integer *incx);

/* Subroutine */ int stpmv_(char *uplo, char *trans, char *diag, integer *n, 
	real *ap, real *x, integer *incx);

/* Subroutine */ int stpsv_(char *uplo, char *trans, char *diag, integer *n, 
	real *ap, real *x, integer *incx);

/* Subroutine */ int strmm_(char *side, char *uplo, char *transa, char *diag, 
	integer *m, integer *n, real *alpha, real *a, integer *lda, real *b, 
	integer *ldb);

/* Subroutine */ int strmv_(char *uplo, char *trans, char *diag, integer *n, 
	real *a, integer *lda, real *x, integer *incx);

/* Subroutine */ int strsm_(char *side, char *uplo, char *transa, char *diag, 
	integer *m, integer *n, real *alpha, real *a, integer *lda, real *b, 
	integer *ldb);

/* Subroutine */ int strsv_(char *uplo, char *trans, char *diag, integer *n, 
	real *a, integer *lda, real *x, integer *incx);

/* Subroutine */ int xerbla_(char *srname, integer *info);

/* Subroutine */ int xerbla_array__(char *srname_array__, integer *
	srname_len__, integer *info, ftnlen srname_array_len);

/* Subroutine */ int zaxpy_(integer *n, doublecomplex *za, doublecomplex *zx, 
	integer *incx, doublecomplex *zy, integer *incy);

/* Subroutine */ int zcopy_(integer *n, doublecomplex *zx, integer *incx, 
	doublecomplex *zy, integer *incy);

/* Double Complex */ VOID zdotc_(doublecomplex * ret_val, integer *n, 
	doublecomplex *zx, integer *incx, doublecomplex *zy, integer *incy);

/* Double Complex */ VOID zdotu_(doublecomplex * ret_val, integer *n, 
	doublecomplex *zx, integer *incx, doublecomplex *zy, integer *incy);

/* Subroutine */ int zdrot_(integer *n, doublecomplex *cx, integer *incx, 
	doublecomplex *cy, integer *incy, doublereal *c__, doublereal *s);

/* Subroutine */ int zdscal_(integer *n, doublereal *da, doublecomplex *zx, 
	integer *incx);

/* Subroutine */ int zgbmv_(char *trans, integer *m, integer *n, integer *kl, 
	integer *ku, doublecomplex *alpha, doublecomplex *a, integer *lda, 
	doublecomplex *x, integer *incx, doublecomplex *beta, doublecomplex *
	y, integer *incy);

/* Subroutine */ int zgemm_(char *transa, char *transb, integer *m, integer *
	n, integer *k, doublecomplex *alpha, doublecomplex *a, integer *lda, 
	doublecomplex *b, integer *ldb, doublecomplex *beta, doublecomplex *
	c__, integer *ldc);

/* Subroutine */ int zgemv_(char *trans, integer *m, integer *n, 
	doublecomplex *alpha, doublecomplex *a, integer *lda, doublecomplex *
	x, integer *incx, doublecomplex *beta, doublecomplex *y, integer *
	incy);

/* Subroutine */ int zgerc_(integer *m, integer *n, doublecomplex *alpha, 
	doublecomplex *x, integer *incx, doublecomplex *y, integer *incy, 
	doublecomplex *a, integer *lda);

/* Subroutine */ int zgeru_(integer *m, integer *n, doublecomplex *alpha, 
	doublecomplex *x, integer *incx, doublecomplex *y, integer *incy, 
	doublecomplex *a, integer *lda);

/* Subroutine */ int zhbmv_(char *uplo, integer *n, integer *k, doublecomplex 
	*alpha, doublecomplex *a, integer *lda, doublecomplex *x, integer *
	incx, doublecomplex *beta, doublecomplex *y, integer *incy);

/* Subroutine */ int zhemm_(char *side, char *uplo, integer *m, integer *n, 
	doublecomplex *alpha, doublecomplex *a, integer *lda, doublecomplex *
	b, integer *ldb, doublecomplex *beta, doublecomplex *c__, integer *
	ldc);

/* Subroutine */ int zhemv_(char *uplo, integer *n, doublecomplex *alpha, 
	doublecomplex *a, integer *lda, doublecomplex *x, integer *incx, 
	doublecomplex *beta, doublecomplex *y, integer *incy);

/* Subroutine */ int zher_(char *uplo, integer *n, doublereal *alpha, 
	doublecomplex *x, integer *incx, doublecomplex *a, integer *lda);

/* Subroutine */ int zher2_(char *uplo, integer *n, doublecomplex *alpha, 
	doublecomplex *x, integer *incx, doublecomplex *y, integer *incy, 
	doublecomplex *a, integer *lda);

/* Subroutine */ int zher2k_(char *uplo, char *trans, integer *n, integer *k, 
	doublecomplex *alpha, doublecomplex *a, integer *lda, doublecomplex *
	b, integer *ldb, doublereal *beta, doublecomplex *c__, integer *ldc);

/* Subroutine */ int zherk_(char *uplo, char *trans, integer *n, integer *k, 
	doublereal *alpha, doublecomplex *a, integer *lda, doublereal *beta, 
	doublecomplex *c__, integer *ldc);

/* Subroutine */ int zhpmv_(char *uplo, integer *n, doublecomplex *alpha, 
	doublecomplex *ap, doublecomplex *x, integer *incx, doublecomplex *
	beta, doublecomplex *y, integer *incy);

/* Subroutine */ int zhpr_(char *uplo, integer *n, doublereal *alpha, 
	doublecomplex *x, integer *incx, doublecomplex *ap);

/* Subroutine */ int zhpr2_(char *uplo, integer *n, doublecomplex *alpha, 
	doublecomplex *x, integer *incx, doublecomplex *y, integer *incy, 
	doublecomplex *ap);

/* Subroutine */ int zrotg_(doublecomplex *ca, doublecomplex *cb, doublereal *
	c__, doublecomplex *s);

/* Subroutine */ int zscal_(integer *n, doublecomplex *za, doublecomplex *zx, 
	integer *incx);

/* Subroutine */ int zswap_(integer *n, doublecomplex *zx, integer *incx, 
	doublecomplex *zy, integer *incy);

/* Subroutine */ int zsymm_(char *side, char *uplo, integer *m, integer *n, 
	doublecomplex *alpha, doublecomplex *a, integer *lda, doublecomplex *
	b, integer *ldb, doublecomplex *beta, doublecomplex *c__, integer *
	ldc);

/* Subroutine */ int zsyr2k_(char *uplo, char *trans, integer *n, integer *k, 
	doublecomplex *alpha, doublecomplex *a, integer *lda, doublecomplex *
	b, integer *ldb, doublecomplex *beta, doublecomplex *c__, integer *
	ldc);

/* Subroutine */ int zsyrk_(char *uplo, char *trans, integer *n, integer *k, 
	doublecomplex *alpha, doublecomplex *a, integer *lda, doublecomplex *
	beta, doublecomplex *c__, integer *ldc);

/* Subroutine */ int ztbmv_(char *uplo, char *trans, char *diag, integer *n, 
	integer *k, doublecomplex *a, integer *lda, doublecomplex *x, integer 
	*incx);

/* Subroutine */ int ztbsv_(char *uplo, char *trans, char *diag, integer *n, 
	integer *k, doublecomplex *a, integer *lda, doublecomplex *x, integer 
	*incx);

/* Subroutine */ int ztpmv_(char *uplo, char *trans, char *diag, integer *n, 
	doublecomplex *ap, doublecomplex *x, integer *incx);

/* Subroutine */ int ztpsv_(char *uplo, char *trans, char *diag, integer *n, 
	doublecomplex *ap, doublecomplex *x, integer *incx);

/* Subroutine */ int ztrmm_(char *side, char *uplo, char *transa, char *diag, 
	integer *m, integer *n, doublecomplex *alpha, doublecomplex *a, 
	integer *lda, doublecomplex *b, integer *ldb);

/* Subroutine */ int ztrmv_(char *uplo, char *trans, char *diag, integer *n, 
	doublecomplex *a, integer *lda, doublecomplex *x, integer *incx);

/* Subroutine */ int ztrsm_(char *side, char *uplo, char *transa, char *diag, 
	integer *m, integer *n, doublecomplex *alpha, doublecomplex *a, 
	integer *lda, doublecomplex *b, integer *ldb);

/* Subroutine */ int ztrsv_(char *uplo, char *trans, char *diag, integer *n, 
	doublecomplex *a, integer *lda, doublecomplex *x, integer *incx);

/* Subroutine */ int cbdsqr_(char *uplo, integer *n, integer *ncvt, integer *
	nru, integer *ncc, real *d__, real *e, complex *vt, integer *ldvt, 
	complex *u, integer *ldu, complex *c__, integer *ldc, real *rwork, 
	integer *info);

/* Subroutine */ int cgbbrd_(char *vect, integer *m, integer *n, integer *ncc, 
	 integer *kl, integer *ku, complex *ab, integer *ldab, real *d__, 
	real *e, complex *q, integer *ldq, complex *pt, integer *ldpt, 
	complex *c__, integer *ldc, complex *work, real *rwork, integer *info);

/* Subroutine */ int cgbcon_(char *norm, integer *n, integer *kl, integer *ku, 
	 complex *ab, integer *ldab, integer *ipiv, real *anorm, real *rcond, 
	complex *work, real *rwork, integer *info);

/* Subroutine */ int cgbequ_(integer *m, integer *n, integer *kl, integer *ku, 
	 complex *ab, integer *ldab, real *r__, real *c__, real *rowcnd, real 
	*colcnd, real *amax, integer *info);

/* Subroutine */ int cgbequb_(integer *m, integer *n, integer *kl, integer *
	ku, complex *ab, integer *ldab, real *r__, real *c__, real *rowcnd, 
	real *colcnd, real *amax, integer *info);

/* Subroutine */ int cgbrfs_(char *trans, integer *n, integer *kl, integer *
	ku, integer *nrhs, complex *ab, integer *ldab, complex *afb, integer *
	ldafb, integer *ipiv, complex *b, integer *ldb, complex *x, integer *
	ldx, real *ferr, real *berr, complex *work, real *rwork, integer *
	info);

/* Subroutine */ int cgbrfsx_(char *trans, char *equed, integer *n, integer *
	kl, integer *ku, integer *nrhs, complex *ab, integer *ldab, complex *
	afb, integer *ldafb, integer *ipiv, real *r__, real *c__, complex *b, 
	integer *ldb, complex *x, integer *ldx, real *rcond, real *berr, 
	integer *n_err_bnds__, real *err_bnds_norm__, real *err_bnds_comp__, 
	integer *nparams, real *params, complex *work, real *rwork, integer *
	info);

/* Subroutine */ int cgbsv_(integer *n, integer *kl, integer *ku, integer *
	nrhs, complex *ab, integer *ldab, integer *ipiv, complex *b, integer *
	ldb, integer *info);

/* Subroutine */ int cgbsvx_(char *fact, char *trans, integer *n, integer *kl, 
	 integer *ku, integer *nrhs, complex *ab, integer *ldab, complex *afb, 
	 integer *ldafb, integer *ipiv, char *equed, real *r__, real *c__, 
	complex *b, integer *ldb, complex *x, integer *ldx, real *rcond, real 
	*ferr, real *berr, complex *work, real *rwork, integer *info);

/* Subroutine */ int cgbsvxx_(char *fact, char *trans, integer *n, integer *
	kl, integer *ku, integer *nrhs, complex *ab, integer *ldab, complex *
	afb, integer *ldafb, integer *ipiv, char *equed, real *r__, real *c__, 
	 complex *b, integer *ldb, complex *x, integer *ldx, real *rcond, 
	real *rpvgrw, real *berr, integer *n_err_bnds__, real *
	err_bnds_norm__, real *err_bnds_comp__, integer *nparams, real *
	params, complex *work, real *rwork, integer *info);

/* Subroutine */ int cgbtf2_(integer *m, integer *n, integer *kl, integer *ku, 
	 complex *ab, integer *ldab, integer *ipiv, integer *info);

/* Subroutine */ int cgbtrf_(integer *m, integer *n, integer *kl, integer *ku, 
	 complex *ab, integer *ldab, integer *ipiv, integer *info);

/* Subroutine */ int cgbtrs_(char *trans, integer *n, integer *kl, integer *
	ku, integer *nrhs, complex *ab, integer *ldab, integer *ipiv, complex 
	*b, integer *ldb, integer *info);

/* Subroutine */ int cgebak_(char *job, char *side, integer *n, integer *ilo, 
	integer *ihi, real *scale, integer *m, complex *v, integer *ldv, 
	integer *info);

/* Subroutine */ int cgebal_(char *job, integer *n, complex *a, integer *lda, 
	integer *ilo, integer *ihi, real *scale, integer *info);

/* Subroutine */ int cgebd2_(integer *m, integer *n, complex *a, integer *lda, 
	 real *d__, real *e, complex *tauq, complex *taup, complex *work, 
	integer *info);

/* Subroutine */ int cgebrd_(integer *m, integer *n, complex *a, integer *lda, 
	 real *d__, real *e, complex *tauq, complex *taup, complex *work, 
	integer *lwork, integer *info);

/* Subroutine */ int cgecon_(char *norm, integer *n, complex *a, integer *lda, 
	 real *anorm, real *rcond, complex *work, real *rwork, integer *info);

/* Subroutine */ int cgeequ_(integer *m, integer *n, complex *a, integer *lda, 
	 real *r__, real *c__, real *rowcnd, real *colcnd, real *amax, 
	integer *info);

/* Subroutine */ int cgeequb_(integer *m, integer *n, complex *a, integer *
	lda, real *r__, real *c__, real *rowcnd, real *colcnd, real *amax, 
	integer *info);

/* Subroutine */ int cgees_(char *jobvs, char *sort, L_fp select, integer *n, 
	complex *a, integer *lda, integer *sdim, complex *w, complex *vs, 
	integer *ldvs, complex *work, integer *lwork, real *rwork, logical *
	bwork, integer *info);

/* Subroutine */ int cgeesx_(char *jobvs, char *sort, L_fp select, char *
	sense, integer *n, complex *a, integer *lda, integer *sdim, complex *
	w, complex *vs, integer *ldvs, real *rconde, real *rcondv, complex *
	work, integer *lwork, real *rwork, logical *bwork, integer *info);

/* Subroutine */ int cgeev_(char *jobvl, char *jobvr, integer *n, complex *a, 
	integer *lda, complex *w, complex *vl, integer *ldvl, complex *vr, 
	integer *ldvr, complex *work, integer *lwork, real *rwork, integer *
	info);

/* Subroutine */ int cgeevx_(char *balanc, char *jobvl, char *jobvr, char *
	sense, integer *n, complex *a, integer *lda, complex *w, complex *vl, 
	integer *ldvl, complex *vr, integer *ldvr, integer *ilo, integer *ihi, 
	 real *scale, real *abnrm, real *rconde, real *rcondv, complex *work, 
	integer *lwork, real *rwork, integer *info);

/* Subroutine */ int cgegs_(char *jobvsl, char *jobvsr, integer *n, complex *
	a, integer *lda, complex *b, integer *ldb, complex *alpha, complex *
	beta, complex *vsl, integer *ldvsl, complex *vsr, integer *ldvsr, 
	complex *work, integer *lwork, real *rwork, integer *info);

/* Subroutine */ int cgegv_(char *jobvl, char *jobvr, integer *n, complex *a, 
	integer *lda, complex *b, integer *ldb, complex *alpha, complex *beta, 
	 complex *vl, integer *ldvl, complex *vr, integer *ldvr, complex *
	work, integer *lwork, real *rwork, integer *info);

/* Subroutine */ int cgehd2_(integer *n, integer *ilo, integer *ihi, complex *
	a, integer *lda, complex *tau, complex *work, integer *info);

/* Subroutine */ int cgehrd_(integer *n, integer *ilo, integer *ihi, complex *
	a, integer *lda, complex *tau, complex *work, integer *lwork, integer 
	*info);

/* Subroutine */ int cgelq2_(integer *m, integer *n, complex *a, integer *lda, 
	 complex *tau, complex *work, integer *info);

/* Subroutine */ int cgelqf_(integer *m, integer *n, complex *a, integer *lda, 
	 complex *tau, complex *work, integer *lwork, integer *info);

/* Subroutine */ int cgels_(char *trans, integer *m, integer *n, integer *
	nrhs, complex *a, integer *lda, complex *b, integer *ldb, complex *
	work, integer *lwork, integer *info);

/* Subroutine */ int cgelsd_(integer *m, integer *n, integer *nrhs, complex *
	a, integer *lda, complex *b, integer *ldb, real *s, real *rcond, 
	integer *rank, complex *work, integer *lwork, real *rwork, integer *
	iwork, integer *info);

/* Subroutine */ int cgelss_(integer *m, integer *n, integer *nrhs, complex *
	a, integer *lda, complex *b, integer *ldb, real *s, real *rcond, 
	integer *rank, complex *work, integer *lwork, real *rwork, integer *
	info);

/* Subroutine */ int cgelsx_(integer *m, integer *n, integer *nrhs, complex *
	a, integer *lda, complex *b, integer *ldb, integer *jpvt, real *rcond, 
	 integer *rank, complex *work, real *rwork, integer *info);

/* Subroutine */ int cgelsy_(integer *m, integer *n, integer *nrhs, complex *
	a, integer *lda, complex *b, integer *ldb, integer *jpvt, real *rcond, 
	 integer *rank, complex *work, integer *lwork, real *rwork, integer *
	info);

/* Subroutine */ int cgeql2_(integer *m, integer *n, complex *a, integer *lda, 
	 complex *tau, complex *work, integer *info);

/* Subroutine */ int cgeqlf_(integer *m, integer *n, complex *a, integer *lda, 
	 complex *tau, complex *work, integer *lwork, integer *info);

/* Subroutine */ int cgeqp3_(integer *m, integer *n, complex *a, integer *lda, 
	 integer *jpvt, complex *tau, complex *work, integer *lwork, real *
	rwork, integer *info);

/* Subroutine */ int cgeqpf_(integer *m, integer *n, complex *a, integer *lda, 
	 integer *jpvt, complex *tau, complex *work, real *rwork, integer *
	info);

/* Subroutine */ int cgeqr2_(integer *m, integer *n, complex *a, integer *lda, 
	 complex *tau, complex *work, integer *info);

/* Subroutine */ int cgeqrf_(integer *m, integer *n, complex *a, integer *lda, 
	 complex *tau, complex *work, integer *lwork, integer *info);

/* Subroutine */ int cgerfs_(char *trans, integer *n, integer *nrhs, complex *
	a, integer *lda, complex *af, integer *ldaf, integer *ipiv, complex *
	b, integer *ldb, complex *x, integer *ldx, real *ferr, real *berr, 
	complex *work, real *rwork, integer *info);

/* Subroutine */ int cgerfsx_(char *trans, char *equed, integer *n, integer *
	nrhs, complex *a, integer *lda, complex *af, integer *ldaf, integer *
	ipiv, real *r__, real *c__, complex *b, integer *ldb, complex *x, 
	integer *ldx, real *rcond, real *berr, integer *n_err_bnds__, real *
	err_bnds_norm__, real *err_bnds_comp__, integer *nparams, real *
	params, complex *work, real *rwork, integer *info);

/* Subroutine */ int cgerq2_(integer *m, integer *n, complex *a, integer *lda, 
	 complex *tau, complex *work, integer *info);

/* Subroutine */ int cgerqf_(integer *m, integer *n, complex *a, integer *lda, 
	 complex *tau, complex *work, integer *lwork, integer *info);

/* Subroutine */ int cgesc2_(integer *n, complex *a, integer *lda, complex *
	rhs, integer *ipiv, integer *jpiv, real *scale);

/* Subroutine */ int cgesdd_(char *jobz, integer *m, integer *n, complex *a, 
	integer *lda, real *s, complex *u, integer *ldu, complex *vt, integer 
	*ldvt, complex *work, integer *lwork, real *rwork, integer *iwork, 
	integer *info);

/* Subroutine */ int cgesv_(integer *n, integer *nrhs, complex *a, integer *
	lda, integer *ipiv, complex *b, integer *ldb, integer *info);

/* Subroutine */ int cgesvd_(char *jobu, char *jobvt, integer *m, integer *n, 
	complex *a, integer *lda, real *s, complex *u, integer *ldu, complex *
	vt, integer *ldvt, complex *work, integer *lwork, real *rwork, 
	integer *info);

/* Subroutine */ int cgesvx_(char *fact, char *trans, integer *n, integer *
	nrhs, complex *a, integer *lda, complex *af, integer *ldaf, integer *
	ipiv, char *equed, real *r__, real *c__, complex *b, integer *ldb, 
	complex *x, integer *ldx, real *rcond, real *ferr, real *berr, 
	complex *work, real *rwork, integer *info);

/* Subroutine */ int cgesvxx_(char *fact, char *trans, integer *n, integer *
	nrhs, complex *a, integer *lda, complex *af, integer *ldaf, integer *
	ipiv, char *equed, real *r__, real *c__, complex *b, integer *ldb, 
	complex *x, integer *ldx, real *rcond, real *rpvgrw, real *berr, 
	integer *n_err_bnds__, real *err_bnds_norm__, real *err_bnds_comp__, 
	integer *nparams, real *params, complex *work, real *rwork, integer *
	info);

/* Subroutine */ int cgetc2_(integer *n, complex *a, integer *lda, integer *
	ipiv, integer *jpiv, integer *info);

/* Subroutine */ int cgetf2_(integer *m, integer *n, complex *a, integer *lda, 
	 integer *ipiv, integer *info);

/* Subroutine */ int cgetrf_(integer *m, integer *n, complex *a, integer *lda, 
	 integer *ipiv, integer *info);

/* Subroutine */ int cgetri_(integer *n, complex *a, integer *lda, integer *
	ipiv, complex *work, integer *lwork, integer *info);

/* Subroutine */ int cgetrs_(char *trans, integer *n, integer *nrhs, complex *
	a, integer *lda, integer *ipiv, complex *b, integer *ldb, integer *
	info);

/* Subroutine */ int cggbak_(char *job, char *side, integer *n, integer *ilo, 
	integer *ihi, real *lscale, real *rscale, integer *m, complex *v, 
	integer *ldv, integer *info);

/* Subroutine */ int cggbal_(char *job, integer *n, complex *a, integer *lda, 
	complex *b, integer *ldb, integer *ilo, integer *ihi, real *lscale, 
	real *rscale, real *work, integer *info);

/* Subroutine */ int cgges_(char *jobvsl, char *jobvsr, char *sort, L_fp 
	selctg, integer *n, complex *a, integer *lda, complex *b, integer *
	ldb, integer *sdim, complex *alpha, complex *beta, complex *vsl, 
	integer *ldvsl, complex *vsr, integer *ldvsr, complex *work, integer *
	lwork, real *rwork, logical *bwork, integer *info);

/* Subroutine */ int cggesx_(char *jobvsl, char *jobvsr, char *sort, L_fp 
	selctg, char *sense, integer *n, complex *a, integer *lda, complex *b, 
	 integer *ldb, integer *sdim, complex *alpha, complex *beta, complex *
	vsl, integer *ldvsl, complex *vsr, integer *ldvsr, real *rconde, real 
	*rcondv, complex *work, integer *lwork, real *rwork, integer *iwork, 
	integer *liwork, logical *bwork, integer *info);

/* Subroutine */ int cggev_(char *jobvl, char *jobvr, integer *n, complex *a, 
	integer *lda, complex *b, integer *ldb, complex *alpha, complex *beta, 
	 complex *vl, integer *ldvl, complex *vr, integer *ldvr, complex *
	work, integer *lwork, real *rwork, integer *info);

/* Subroutine */ int cggevx_(char *balanc, char *jobvl, char *jobvr, char *
	sense, integer *n, complex *a, integer *lda, complex *b, integer *ldb, 
	 complex *alpha, complex *beta, complex *vl, integer *ldvl, complex *
	vr, integer *ldvr, integer *ilo, integer *ihi, real *lscale, real *
	rscale, real *abnrm, real *bbnrm, real *rconde, real *rcondv, complex 
	*work, integer *lwork, real *rwork, integer *iwork, logical *bwork, 
	integer *info);

/* Subroutine */ int cggglm_(integer *n, integer *m, integer *p, complex *a, 
	integer *lda, complex *b, integer *ldb, complex *d__, complex *x, 
	complex *y, complex *work, integer *lwork, integer *info);

/* Subroutine */ int cgghrd_(char *compq, char *compz, integer *n, integer *
	ilo, integer *ihi, complex *a, integer *lda, complex *b, integer *ldb, 
	 complex *q, integer *ldq, complex *z__, integer *ldz, integer *info);

/* Subroutine */ int cgglse_(integer *m, integer *n, integer *p, complex *a, 
	integer *lda, complex *b, integer *ldb, complex *c__, complex *d__, 
	complex *x, complex *work, integer *lwork, integer *info);

/* Subroutine */ int cggqrf_(integer *n, integer *m, integer *p, complex *a, 
	integer *lda, complex *taua, complex *b, integer *ldb, complex *taub, 
	complex *work, integer *lwork, integer *info);

/* Subroutine */ int cggrqf_(integer *m, integer *p, integer *n, complex *a, 
	integer *lda, complex *taua, complex *b, integer *ldb, complex *taub, 
	complex *work, integer *lwork, integer *info);

/* Subroutine */ int cggsvd_(char *jobu, char *jobv, char *jobq, integer *m, 
	integer *n, integer *p, integer *k, integer *l, complex *a, integer *
	lda, complex *b, integer *ldb, real *alpha, real *beta, complex *u, 
	integer *ldu, complex *v, integer *ldv, complex *q, integer *ldq, 
	complex *work, real *rwork, integer *iwork, integer *info);

/* Subroutine */ int cggsvp_(char *jobu, char *jobv, char *jobq, integer *m, 
	integer *p, integer *n, complex *a, integer *lda, complex *b, integer 
	*ldb, real *tola, real *tolb, integer *k, integer *l, complex *u, 
	integer *ldu, complex *v, integer *ldv, complex *q, integer *ldq, 
	integer *iwork, real *rwork, complex *tau, complex *work, integer *
	info);

/* Subroutine */ int cgtcon_(char *norm, integer *n, complex *dl, complex *
	d__, complex *du, complex *du2, integer *ipiv, real *anorm, real *
	rcond, complex *work, integer *info);

/* Subroutine */ int cgtrfs_(char *trans, integer *n, integer *nrhs, complex *
	dl, complex *d__, complex *du, complex *dlf, complex *df, complex *
	duf, complex *du2, integer *ipiv, complex *b, integer *ldb, complex *
	x, integer *ldx, real *ferr, real *berr, complex *work, real *rwork, 
	integer *info);

/* Subroutine */ int cgtsv_(integer *n, integer *nrhs, complex *dl, complex *
	d__, complex *du, complex *b, integer *ldb, integer *info);

/* Subroutine */ int cgtsvx_(char *fact, char *trans, integer *n, integer *
	nrhs, complex *dl, complex *d__, complex *du, complex *dlf, complex *
	df, complex *duf, complex *du2, integer *ipiv, complex *b, integer *
	ldb, complex *x, integer *ldx, real *rcond, real *ferr, real *berr, 
	complex *work, real *rwork, integer *info);

/* Subroutine */ int cgttrf_(integer *n, complex *dl, complex *d__, complex *
	du, complex *du2, integer *ipiv, integer *info);

/* Subroutine */ int cgttrs_(char *trans, integer *n, integer *nrhs, complex *
	dl, complex *d__, complex *du, complex *du2, integer *ipiv, complex *
	b, integer *ldb, integer *info);

/* Subroutine */ int cgtts2_(integer *itrans, integer *n, integer *nrhs, 
	complex *dl, complex *d__, complex *du, complex *du2, integer *ipiv, 
	complex *b, integer *ldb);

/* Subroutine */ int chbev_(char *jobz, char *uplo, integer *n, integer *kd, 
	complex *ab, integer *ldab, real *w, complex *z__, integer *ldz, 
	complex *work, real *rwork, integer *info);

/* Subroutine */ int chbevd_(char *jobz, char *uplo, integer *n, integer *kd, 
	complex *ab, integer *ldab, real *w, complex *z__, integer *ldz, 
	complex *work, integer *lwork, real *rwork, integer *lrwork, integer *
	iwork, integer *liwork, integer *info);

/* Subroutine */ int chbevx_(char *jobz, char *range, char *uplo, integer *n, 
	integer *kd, complex *ab, integer *ldab, complex *q, integer *ldq, 
	real *vl, real *vu, integer *il, integer *iu, real *abstol, integer *
	m, real *w, complex *z__, integer *ldz, complex *work, real *rwork, 
	integer *iwork, integer *ifail, integer *info);

/* Subroutine */ int chbgst_(char *vect, char *uplo, integer *n, integer *ka, 
	integer *kb, complex *ab, integer *ldab, complex *bb, integer *ldbb, 
	complex *x, integer *ldx, complex *work, real *rwork, integer *info);

/* Subroutine */ int chbgv_(char *jobz, char *uplo, integer *n, integer *ka, 
	integer *kb, complex *ab, integer *ldab, complex *bb, integer *ldbb, 
	real *w, complex *z__, integer *ldz, complex *work, real *rwork, 
	integer *info);

/* Subroutine */ int chbgvd_(char *jobz, char *uplo, integer *n, integer *ka, 
	integer *kb, complex *ab, integer *ldab, complex *bb, integer *ldbb, 
	real *w, complex *z__, integer *ldz, complex *work, integer *lwork, 
	real *rwork, integer *lrwork, integer *iwork, integer *liwork, 
	integer *info);

/* Subroutine */ int chbgvx_(char *jobz, char *range, char *uplo, integer *n, 
	integer *ka, integer *kb, complex *ab, integer *ldab, complex *bb, 
	integer *ldbb, complex *q, integer *ldq, real *vl, real *vu, integer *
	il, integer *iu, real *abstol, integer *m, real *w, complex *z__, 
	integer *ldz, complex *work, real *rwork, integer *iwork, integer *
	ifail, integer *info);

/* Subroutine */ int chbtrd_(char *vect, char *uplo, integer *n, integer *kd, 
	complex *ab, integer *ldab, real *d__, real *e, complex *q, integer *
	ldq, complex *work, integer *info);

/* Subroutine */ int checon_(char *uplo, integer *n, complex *a, integer *lda, 
	 integer *ipiv, real *anorm, real *rcond, complex *work, integer *
	info);

/* Subroutine */ int cheequb_(char *uplo, integer *n, complex *a, integer *
	lda, real *s, real *scond, real *amax, complex *work, integer *info);

/* Subroutine */ int cheev_(char *jobz, char *uplo, integer *n, complex *a, 
	integer *lda, real *w, complex *work, integer *lwork, real *rwork, 
	integer *info);

/* Subroutine */ int cheevd_(char *jobz, char *uplo, integer *n, complex *a, 
	integer *lda, real *w, complex *work, integer *lwork, real *rwork, 
	integer *lrwork, integer *iwork, integer *liwork, integer *info);

/* Subroutine */ int cheevr_(char *jobz, char *range, char *uplo, integer *n, 
	complex *a, integer *lda, real *vl, real *vu, integer *il, integer *
	iu, real *abstol, integer *m, real *w, complex *z__, integer *ldz, 
	integer *isuppz, complex *work, integer *lwork, real *rwork, integer *
	lrwork, integer *iwork, integer *liwork, integer *info);

/* Subroutine */ int cheevx_(char *jobz, char *range, char *uplo, integer *n, 
	complex *a, integer *lda, real *vl, real *vu, integer *il, integer *
	iu, real *abstol, integer *m, real *w, complex *z__, integer *ldz, 
	complex *work, integer *lwork, real *rwork, integer *iwork, integer *
	ifail, integer *info);

/* Subroutine */ int chegs2_(integer *itype, char *uplo, integer *n, complex *
	a, integer *lda, complex *b, integer *ldb, integer *info);

/* Subroutine */ int chegst_(integer *itype, char *uplo, integer *n, complex *
	a, integer *lda, complex *b, integer *ldb, integer *info);

/* Subroutine */ int chegv_(integer *itype, char *jobz, char *uplo, integer *
	n, complex *a, integer *lda, complex *b, integer *ldb, real *w, 
	complex *work, integer *lwork, real *rwork, integer *info);

/* Subroutine */ int chegvd_(integer *itype, char *jobz, char *uplo, integer *
	n, complex *a, integer *lda, complex *b, integer *ldb, real *w, 
	complex *work, integer *lwork, real *rwork, integer *lrwork, integer *
	iwork, integer *liwork, integer *info);

/* Subroutine */ int chegvx_(integer *itype, char *jobz, char *range, char *
	uplo, integer *n, complex *a, integer *lda, complex *b, integer *ldb, 
	real *vl, real *vu, integer *il, integer *iu, real *abstol, integer *
	m, real *w, complex *z__, integer *ldz, complex *work, integer *lwork, 
	 real *rwork, integer *iwork, integer *ifail, integer *info);

/* Subroutine */ int cherfs_(char *uplo, integer *n, integer *nrhs, complex *
	a, integer *lda, complex *af, integer *ldaf, integer *ipiv, complex *
	b, integer *ldb, complex *x, integer *ldx, real *ferr, real *berr, 
	complex *work, real *rwork, integer *info);

/* Subroutine */ int cherfsx_(char *uplo, char *equed, integer *n, integer *
	nrhs, complex *a, integer *lda, complex *af, integer *ldaf, integer *
	ipiv, real *s, complex *b, integer *ldb, complex *x, integer *ldx, 
	real *rcond, real *berr, integer *n_err_bnds__, real *err_bnds_norm__, 
	 real *err_bnds_comp__, integer *nparams, real *params, complex *work, 
	 real *rwork, integer *info);

/* Subroutine */ int chesv_(char *uplo, integer *n, integer *nrhs, complex *a, 
	 integer *lda, integer *ipiv, complex *b, integer *ldb, complex *work, 
	 integer *lwork, integer *info);

/* Subroutine */ int chesvx_(char *fact, char *uplo, integer *n, integer *
	nrhs, complex *a, integer *lda, complex *af, integer *ldaf, integer *
	ipiv, complex *b, integer *ldb, complex *x, integer *ldx, real *rcond, 
	 real *ferr, real *berr, complex *work, integer *lwork, real *rwork, 
	integer *info);

/* Subroutine */ int chesvxx_(char *fact, char *uplo, integer *n, integer *
	nrhs, complex *a, integer *lda, complex *af, integer *ldaf, integer *
	ipiv, char *equed, real *s, complex *b, integer *ldb, complex *x, 
	integer *ldx, real *rcond, real *rpvgrw, real *berr, integer *
	n_err_bnds__, real *err_bnds_norm__, real *err_bnds_comp__, integer *
	nparams, real *params, complex *work, real *rwork, integer *info);

/* Subroutine */ int chetd2_(char *uplo, integer *n, complex *a, integer *lda, 
	 real *d__, real *e, complex *tau, integer *info);

/* Subroutine */ int chetf2_(char *uplo, integer *n, complex *a, integer *lda, 
	 integer *ipiv, integer *info);

/* Subroutine */ int chetrd_(char *uplo, integer *n, complex *a, integer *lda, 
	 real *d__, real *e, complex *tau, complex *work, integer *lwork, 
	integer *info);

/* Subroutine */ int chetrf_(char *uplo, integer *n, complex *a, integer *lda, 
	 integer *ipiv, complex *work, integer *lwork, integer *info);

/* Subroutine */ int chetri_(char *uplo, integer *n, complex *a, integer *lda, 
	 integer *ipiv, complex *work, integer *info);

/* Subroutine */ int chetrs_(char *uplo, integer *n, integer *nrhs, complex *
	a, integer *lda, integer *ipiv, complex *b, integer *ldb, integer *
	info);

/* Subroutine */ int chfrk_(char *transr, char *uplo, char *trans, integer *n, 
	 integer *k, real *alpha, complex *a, integer *lda, real *beta, 
	complex *c__);

/* Subroutine */ int chgeqz_(char *job, char *compq, char *compz, integer *n, 
	integer *ilo, integer *ihi, complex *h__, integer *ldh, complex *t, 
	integer *ldt, complex *alpha, complex *beta, complex *q, integer *ldq, 
	 complex *z__, integer *ldz, complex *work, integer *lwork, real *
	rwork, integer *info);

/* Character */ VOID chla_transtype__(char *ret_val, ftnlen ret_val_len, 
	integer *trans);

/* Subroutine */ int chpcon_(char *uplo, integer *n, complex *ap, integer *
	ipiv, real *anorm, real *rcond, complex *work, integer *info);

/* Subroutine */ int chpev_(char *jobz, char *uplo, integer *n, complex *ap, 
	real *w, complex *z__, integer *ldz, complex *work, real *rwork, 
	integer *info);

/* Subroutine */ int chpevd_(char *jobz, char *uplo, integer *n, complex *ap, 
	real *w, complex *z__, integer *ldz, complex *work, integer *lwork, 
	real *rwork, integer *lrwork, integer *iwork, integer *liwork, 
	integer *info);

/* Subroutine */ int chpevx_(char *jobz, char *range, char *uplo, integer *n, 
	complex *ap, real *vl, real *vu, integer *il, integer *iu, real *
	abstol, integer *m, real *w, complex *z__, integer *ldz, complex *
	work, real *rwork, integer *iwork, integer *ifail, integer *info);

/* Subroutine */ int chpgst_(integer *itype, char *uplo, integer *n, complex *
	ap, complex *bp, integer *info);

/* Subroutine */ int chpgv_(integer *itype, char *jobz, char *uplo, integer *
	n, complex *ap, complex *bp, real *w, complex *z__, integer *ldz, 
	complex *work, real *rwork, integer *info);

/* Subroutine */ int chpgvd_(integer *itype, char *jobz, char *uplo, integer *
	n, complex *ap, complex *bp, real *w, complex *z__, integer *ldz, 
	complex *work, integer *lwork, real *rwork, integer *lrwork, integer *
	iwork, integer *liwork, integer *info);

/* Subroutine */ int chpgvx_(integer *itype, char *jobz, char *range, char *
	uplo, integer *n, complex *ap, complex *bp, real *vl, real *vu, 
	integer *il, integer *iu, real *abstol, integer *m, real *w, complex *
	z__, integer *ldz, complex *work, real *rwork, integer *iwork, 
	integer *ifail, integer *info);

/* Subroutine */ int chprfs_(char *uplo, integer *n, integer *nrhs, complex *
	ap, complex *afp, integer *ipiv, complex *b, integer *ldb, complex *x, 
	 integer *ldx, real *ferr, real *berr, complex *work, real *rwork, 
	integer *info);

/* Subroutine */ int chpsv_(char *uplo, integer *n, integer *nrhs, complex *
	ap, integer *ipiv, complex *b, integer *ldb, integer *info);

/* Subroutine */ int chpsvx_(char *fact, char *uplo, integer *n, integer *
	nrhs, complex *ap, complex *afp, integer *ipiv, complex *b, integer *
	ldb, complex *x, integer *ldx, real *rcond, real *ferr, real *berr, 
	complex *work, real *rwork, integer *info);

/* Subroutine */ int chptrd_(char *uplo, integer *n, complex *ap, real *d__, 
	real *e, complex *tau, integer *info);

/* Subroutine */ int chptrf_(char *uplo, integer *n, complex *ap, integer *
	ipiv, integer *info);

/* Subroutine */ int chptri_(char *uplo, integer *n, complex *ap, integer *
	ipiv, complex *work, integer *info);

/* Subroutine */ int chptrs_(char *uplo, integer *n, integer *nrhs, complex *
	ap, integer *ipiv, complex *b, integer *ldb, integer *info);

/* Subroutine */ int chsein_(char *side, char *eigsrc, char *initv, logical *
	select, integer *n, complex *h__, integer *ldh, complex *w, complex *
	vl, integer *ldvl, complex *vr, integer *ldvr, integer *mm, integer *
	m, complex *work, real *rwork, integer *ifaill, integer *ifailr, 
	integer *info);

/* Subroutine */ int chseqr_(char *job, char *compz, integer *n, integer *ilo, 
	 integer *ihi, complex *h__, integer *ldh, complex *w, complex *z__, 
	integer *ldz, complex *work, integer *lwork, integer *info);

/* Subroutine */ int cla_gbamv__(integer *trans, integer *m, integer *n, 
	integer *kl, integer *ku, real *alpha, complex *ab, integer *ldab, 
	complex *x, integer *incx, real *beta, real *y, integer *incy);

doublereal cla_gbrcond_c__(char *trans, integer *n, integer *kl, integer *ku, 
	complex *ab, integer *ldab, complex *afb, integer *ldafb, integer *
	ipiv, real *c__, logical *capply, integer *info, complex *work, real *
	rwork, ftnlen trans_len);

doublereal cla_gbrcond_x__(char *trans, integer *n, integer *kl, integer *ku, 
	complex *ab, integer *ldab, complex *afb, integer *ldafb, integer *
	ipiv, complex *x, integer *info, complex *work, real *rwork, ftnlen 
	trans_len);

/* Subroutine */ int cla_gbrfsx_extended__(integer *prec_type__, integer *
	trans_type__, integer *n, integer *kl, integer *ku, integer *nrhs, 
	complex *ab, integer *ldab, complex *afb, integer *ldafb, integer *
	ipiv, logical *colequ, real *c__, complex *b, integer *ldb, complex *
	y, integer *ldy, real *berr_out__, integer *n_norms__, real *errs_n__,
	 real *errs_c__, complex *res, real *ayb, complex *dy, complex *
	y_tail__, real *rcond, integer *ithresh, real *rthresh, real *dz_ub__,
	 logical *ignore_cwise__, integer *info);

doublereal cla_gbrpvgrw__(integer *n, integer *kl, integer *ku, integer *
	ncols, complex *ab, integer *ldab, complex *afb, integer *ldafb);

/* Subroutine */ int cla_geamv__(integer *trans, integer *m, integer *n, real 
	*alpha, complex *a, integer *lda, complex *x, integer *incx, real *
	beta, real *y, integer *incy);

doublereal cla_gercond_c__(char *trans, integer *n, complex *a, integer *lda, 
	complex *af, integer *ldaf, integer *ipiv, real *c__, logical *capply,
	 integer *info, complex *work, real *rwork, ftnlen trans_len);

doublereal cla_gercond_x__(char *trans, integer *n, complex *a, integer *lda, 
	complex *af, integer *ldaf, integer *ipiv, complex *x, integer *info, 
	complex *work, real *rwork, ftnlen trans_len);

/* Subroutine */ int cla_gerfsx_extended__(integer *prec_type__, integer *
	trans_type__, integer *n, integer *nrhs, complex *a, integer *lda, 
	complex *af, integer *ldaf, integer *ipiv, logical *colequ, real *c__,
	 complex *b, integer *ldb, complex *y, integer *ldy, real *berr_out__,
	 integer *n_norms__, real *errs_n__, real *errs_c__, complex *res, 
	real *ayb, complex *dy, complex *y_tail__, real *rcond, integer *
	ithresh, real *rthresh, real *dz_ub__, logical *ignore_cwise__, 
	integer *info);

/* Subroutine */ int cla_heamv__(integer *uplo, integer *n, real *alpha, 
	complex *a, integer *lda, complex *x, integer *incx, real *beta, real 
	*y, integer *incy);

doublereal cla_hercond_c__(char *uplo, integer *n, complex *a, integer *lda, 
	complex *af, integer *ldaf, integer *ipiv, real *c__, logical *capply,
	 integer *info, complex *work, real *rwork, ftnlen uplo_len);

doublereal cla_hercond_x__(char *uplo, integer *n, complex *a, integer *lda, 
	complex *af, integer *ldaf, integer *ipiv, complex *x, integer *info, 
	complex *work, real *rwork, ftnlen uplo_len);

/* Subroutine */ int cla_herfsx_extended__(integer *prec_type__, char *uplo, 
	integer *n, integer *nrhs, complex *a, integer *lda, complex *af, 
	integer *ldaf, integer *ipiv, logical *colequ, real *c__, complex *b, 
	integer *ldb, complex *y, integer *ldy, real *berr_out__, integer *
	n_norms__, real *errs_n__, real *errs_c__, complex *res, real *ayb, 
	complex *dy, complex *y_tail__, real *rcond, integer *ithresh, real *
	rthresh, real *dz_ub__, logical *ignore_cwise__, integer *info, 
	ftnlen uplo_len);

doublereal cla_herpvgrw__(char *uplo, integer *n, integer *info, complex *a, 
	integer *lda, complex *af, integer *ldaf, integer *ipiv, real *work, 
	ftnlen uplo_len);

/* Subroutine */ int cla_lin_berr__(integer *n, integer *nz, integer *nrhs, 
	complex *res, real *ayb, real *berr);

doublereal cla_porcond_c__(char *uplo, integer *n, complex *a, integer *lda, 
	complex *af, integer *ldaf, real *c__, logical *capply, integer *info,
	 complex *work, real *rwork, ftnlen uplo_len);

doublereal cla_porcond_x__(char *uplo, integer *n, complex *a, integer *lda, 
	complex *af, integer *ldaf, complex *x, integer *info, complex *work, 
	real *rwork, ftnlen uplo_len);

/* Subroutine */ int cla_porfsx_extended__(integer *prec_type__, char *uplo, 
	integer *n, integer *nrhs, complex *a, integer *lda, complex *af, 
	integer *ldaf, logical *colequ, real *c__, complex *b, integer *ldb, 
	complex *y, integer *ldy, real *berr_out__, integer *n_norms__, real *
	errs_n__, real *errs_c__, complex *res, real *ayb, complex *dy, 
	complex *y_tail__, real *rcond, integer *ithresh, real *rthresh, real 
	*dz_ub__, logical *ignore_cwise__, integer *info, ftnlen uplo_len);

doublereal cla_porpvgrw__(char *uplo, integer *ncols, complex *a, integer *
	lda, complex *af, integer *ldaf, real *work, ftnlen uplo_len);

doublereal cla_rpvgrw__(integer *n, integer *ncols, complex *a, integer *lda, 
	complex *af, integer *ldaf);

/* Subroutine */ int cla_syamv__(integer *uplo, integer *n, real *alpha, 
	complex *a, integer *lda, complex *x, integer *incx, real *beta, real 
	*y, integer *incy);

doublereal cla_syrcond_c__(char *uplo, integer *n, complex *a, integer *lda, 
	complex *af, integer *ldaf, integer *ipiv, real *c__, logical *capply,
	 integer *info, complex *work, real *rwork, ftnlen uplo_len);

doublereal cla_syrcond_x__(char *uplo, integer *n, complex *a, integer *lda, 
	complex *af, integer *ldaf, integer *ipiv, complex *x, integer *info, 
	complex *work, real *rwork, ftnlen uplo_len);

/* Subroutine */ int cla_syrfsx_extended__(integer *prec_type__, char *uplo, 
	integer *n, integer *nrhs, complex *a, integer *lda, complex *af, 
	integer *ldaf, integer *ipiv, logical *colequ, real *c__, complex *b, 
	integer *ldb, complex *y, integer *ldy, real *berr_out__, integer *
	n_norms__, real *errs_n__, real *errs_c__, complex *res, real *ayb, 
	complex *dy, complex *y_tail__, real *rcond, integer *ithresh, real *
	rthresh, real *dz_ub__, logical *ignore_cwise__, integer *info, 
	ftnlen uplo_len);

doublereal cla_syrpvgrw__(char *uplo, integer *n, integer *info, complex *a, 
	integer *lda, complex *af, integer *ldaf, integer *ipiv, real *work, 
	ftnlen uplo_len);

/* Subroutine */ int cla_wwaddw__(integer *n, complex *x, complex *y, complex 
	*w);

/* Subroutine */ int clabrd_(integer *m, integer *n, integer *nb, complex *a, 
	integer *lda, real *d__, real *e, complex *tauq, complex *taup, 
	complex *x, integer *ldx, complex *y, integer *ldy);

/* Subroutine */ int clacgv_(integer *n, complex *x, integer *incx);

/* Subroutine */ int clacn2_(integer *n, complex *v, complex *x, real *est, 
	integer *kase, integer *isave);

/* Subroutine */ int clacon_(integer *n, complex *v, complex *x, real *est, 
	integer *kase);

/* Subroutine */ int clacp2_(char *uplo, integer *m, integer *n, real *a, 
	integer *lda, complex *b, integer *ldb);

/* Subroutine */ int clacpy_(char *uplo, integer *m, integer *n, complex *a, 
	integer *lda, complex *b, integer *ldb);

/* Subroutine */ int clacrm_(integer *m, integer *n, complex *a, integer *lda, 
	 real *b, integer *ldb, complex *c__, integer *ldc, real *rwork);

/* Subroutine */ int clacrt_(integer *n, complex *cx, integer *incx, complex *
	cy, integer *incy, complex *c__, complex *s);

/* Complex */ VOID cladiv_(complex * ret_val, complex *x, complex *y);

/* Subroutine */ int claed0_(integer *qsiz, integer *n, real *d__, real *e, 
	complex *q, integer *ldq, complex *qstore, integer *ldqs, real *rwork, 
	 integer *iwork, integer *info);

/* Subroutine */ int claed7_(integer *n, integer *cutpnt, integer *qsiz, 
	integer *tlvls, integer *curlvl, integer *curpbm, real *d__, complex *
	q, integer *ldq, real *rho, integer *indxq, real *qstore, integer *
	qptr, integer *prmptr, integer *perm, integer *givptr, integer *
	givcol, real *givnum, complex *work, real *rwork, integer *iwork, 
	integer *info);

/* Subroutine */ int claed8_(integer *k, integer *n, integer *qsiz, complex *
	q, integer *ldq, real *d__, real *rho, integer *cutpnt, real *z__, 
	real *dlamda, complex *q2, integer *ldq2, real *w, integer *indxp, 
	integer *indx, integer *indxq, integer *perm, integer *givptr, 
	integer *givcol, real *givnum, integer *info);

/* Subroutine */ int claein_(logical *rightv, logical *noinit, integer *n, 
	complex *h__, integer *ldh, complex *w, complex *v, complex *b, 
	integer *ldb, real *rwork, real *eps3, real *smlnum, integer *info);

/* Subroutine */ int claesy_(complex *a, complex *b, complex *c__, complex *
	rt1, complex *rt2, complex *evscal, complex *cs1, complex *sn1);

/* Subroutine */ int claev2_(complex *a, complex *b, complex *c__, real *rt1, 
	real *rt2, real *cs1, complex *sn1);

/* Subroutine */ int clag2z_(integer *m, integer *n, complex *sa, integer *
	ldsa, doublecomplex *a, integer *lda, integer *info);

/* Subroutine */ int clags2_(logical *upper, real *a1, complex *a2, real *a3, 
	real *b1, complex *b2, real *b3, real *csu, complex *snu, real *csv, 
	complex *snv, real *csq, complex *snq);

/* Subroutine */ int clagtm_(char *trans, integer *n, integer *nrhs, real *
	alpha, complex *dl, complex *d__, complex *du, complex *x, integer *
	ldx, real *beta, complex *b, integer *ldb);

/* Subroutine */ int clahef_(char *uplo, integer *n, integer *nb, integer *kb, 
	 complex *a, integer *lda, integer *ipiv, complex *w, integer *ldw, 
	integer *info);

/* Subroutine */ int clahqr_(logical *wantt, logical *wantz, integer *n, 
	integer *ilo, integer *ihi, complex *h__, integer *ldh, complex *w, 
	integer *iloz, integer *ihiz, complex *z__, integer *ldz, integer *
	info);

/* Subroutine */ int clahr2_(integer *n, integer *k, integer *nb, complex *a, 
	integer *lda, complex *tau, complex *t, integer *ldt, complex *y, 
	integer *ldy);

/* Subroutine */ int clahrd_(integer *n, integer *k, integer *nb, complex *a, 
	integer *lda, complex *tau, complex *t, integer *ldt, complex *y, 
	integer *ldy);

/* Subroutine */ int claic1_(integer *job, integer *j, complex *x, real *sest, 
	 complex *w, complex *gamma, real *sestpr, complex *s, complex *c__);

/* Subroutine */ int clals0_(integer *icompq, integer *nl, integer *nr, 
	integer *sqre, integer *nrhs, complex *b, integer *ldb, complex *bx, 
	integer *ldbx, integer *perm, integer *givptr, integer *givcol, 
	integer *ldgcol, real *givnum, integer *ldgnum, real *poles, real *
	difl, real *difr, real *z__, integer *k, real *c__, real *s, real *
	rwork, integer *info);

/* Subroutine */ int clalsa_(integer *icompq, integer *smlsiz, integer *n, 
	integer *nrhs, complex *b, integer *ldb, complex *bx, integer *ldbx, 
	real *u, integer *ldu, real *vt, integer *k, real *difl, real *difr, 
	real *z__, real *poles, integer *givptr, integer *givcol, integer *
	ldgcol, integer *perm, real *givnum, real *c__, real *s, real *rwork, 
	integer *iwork, integer *info);

/* Subroutine */ int clalsd_(char *uplo, integer *smlsiz, integer *n, integer 
	*nrhs, real *d__, real *e, complex *b, integer *ldb, real *rcond, 
	integer *rank, complex *work, real *rwork, integer *iwork, integer *
	info);

doublereal clangb_(char *norm, integer *n, integer *kl, integer *ku, complex *
	ab, integer *ldab, real *work);

doublereal clange_(char *norm, integer *m, integer *n, complex *a, integer *
	lda, real *work);

doublereal clangt_(char *norm, integer *n, complex *dl, complex *d__, complex 
	*du);

doublereal clanhb_(char *norm, char *uplo, integer *n, integer *k, complex *
	ab, integer *ldab, real *work);

doublereal clanhe_(char *norm, char *uplo, integer *n, complex *a, integer *
	lda, real *work);

doublereal clanhf_(char *norm, char *transr, char *uplo, integer *n, complex *
	a, real *work);

doublereal clanhp_(char *norm, char *uplo, integer *n, complex *ap, real *
	work);

doublereal clanhs_(char *norm, integer *n, complex *a, integer *lda, real *
	work);

doublereal clanht_(char *norm, integer *n, real *d__, complex *e);

doublereal clansb_(char *norm, char *uplo, integer *n, integer *k, complex *
	ab, integer *ldab, real *work);

doublereal clansp_(char *norm, char *uplo, integer *n, complex *ap, real *
	work);

doublereal clansy_(char *norm, char *uplo, integer *n, complex *a, integer *
	lda, real *work);

doublereal clantb_(char *norm, char *uplo, char *diag, integer *n, integer *k, 
	 complex *ab, integer *ldab, real *work);

doublereal clantp_(char *norm, char *uplo, char *diag, integer *n, complex *
	ap, real *work);

doublereal clantr_(char *norm, char *uplo, char *diag, integer *m, integer *n, 
	 complex *a, integer *lda, real *work);

/* Subroutine */ int clapll_(integer *n, complex *x, integer *incx, complex *
	y, integer *incy, real *ssmin);

/* Subroutine */ int clapmt_(logical *forwrd, integer *m, integer *n, complex 
	*x, integer *ldx, integer *k);

/* Subroutine */ int claqgb_(integer *m, integer *n, integer *kl, integer *ku, 
	 complex *ab, integer *ldab, real *r__, real *c__, real *rowcnd, real 
	*colcnd, real *amax, char *equed);

/* Subroutine */ int claqge_(integer *m, integer *n, complex *a, integer *lda, 
	 real *r__, real *c__, real *rowcnd, real *colcnd, real *amax, char *
	equed);

/* Subroutine */ int claqhb_(char *uplo, integer *n, integer *kd, complex *ab, 
	 integer *ldab, real *s, real *scond, real *amax, char *equed);

/* Subroutine */ int claqhe_(char *uplo, integer *n, complex *a, integer *lda, 
	 real *s, real *scond, real *amax, char *equed);

/* Subroutine */ int claqhp_(char *uplo, integer *n, complex *ap, real *s, 
	real *scond, real *amax, char *equed);

/* Subroutine */ int claqp2_(integer *m, integer *n, integer *offset, complex 
	*a, integer *lda, integer *jpvt, complex *tau, real *vn1, real *vn2, 
	complex *work);

/* Subroutine */ int claqps_(integer *m, integer *n, integer *offset, integer 
	*nb, integer *kb, complex *a, integer *lda, integer *jpvt, complex *
	tau, real *vn1, real *vn2, complex *auxv, complex *f, integer *ldf);

/* Subroutine */ int claqr0_(logical *wantt, logical *wantz, integer *n, 
	integer *ilo, integer *ihi, complex *h__, integer *ldh, complex *w, 
	integer *iloz, integer *ihiz, complex *z__, integer *ldz, complex *
	work, integer *lwork, integer *info);

/* Subroutine */ int claqr1_(integer *n, complex *h__, integer *ldh, complex *
	s1, complex *s2, complex *v);

/* Subroutine */ int claqr2_(logical *wantt, logical *wantz, integer *n, 
	integer *ktop, integer *kbot, integer *nw, complex *h__, integer *ldh, 
	 integer *iloz, integer *ihiz, complex *z__, integer *ldz, integer *
	ns, integer *nd, complex *sh, complex *v, integer *ldv, integer *nh, 
	complex *t, integer *ldt, integer *nv, complex *wv, integer *ldwv, 
	complex *work, integer *lwork);

/* Subroutine */ int claqr3_(logical *wantt, logical *wantz, integer *n, 
	integer *ktop, integer *kbot, integer *nw, complex *h__, integer *ldh, 
	 integer *iloz, integer *ihiz, complex *z__, integer *ldz, integer *
	ns, integer *nd, complex *sh, complex *v, integer *ldv, integer *nh, 
	complex *t, integer *ldt, integer *nv, complex *wv, integer *ldwv, 
	complex *work, integer *lwork);

/* Subroutine */ int claqr4_(logical *wantt, logical *wantz, integer *n, 
	integer *ilo, integer *ihi, complex *h__, integer *ldh, complex *w, 
	integer *iloz, integer *ihiz, complex *z__, integer *ldz, complex *
	work, integer *lwork, integer *info);

/* Subroutine */ int claqr5_(logical *wantt, logical *wantz, integer *kacc22, 
	integer *n, integer *ktop, integer *kbot, integer *nshfts, complex *s, 
	 complex *h__, integer *ldh, integer *iloz, integer *ihiz, complex *
	z__, integer *ldz, complex *v, integer *ldv, complex *u, integer *ldu, 
	 integer *nv, complex *wv, integer *ldwv, integer *nh, complex *wh, 
	integer *ldwh);

/* Subroutine */ int claqsb_(char *uplo, integer *n, integer *kd, complex *ab, 
	 integer *ldab, real *s, real *scond, real *amax, char *equed);

/* Subroutine */ int claqsp_(char *uplo, integer *n, complex *ap, real *s, 
	real *scond, real *amax, char *equed);

/* Subroutine */ int claqsy_(char *uplo, integer *n, complex *a, integer *lda, 
	 real *s, real *scond, real *amax, char *equed);

/* Subroutine */ int clar1v_(integer *n, integer *b1, integer *bn, real *
	lambda, real *d__, real *l, real *ld, real *lld, real *pivmin, real *
	gaptol, complex *z__, logical *wantnc, integer *negcnt, real *ztz, 
	real *mingma, integer *r__, integer *isuppz, real *nrminv, real *
	resid, real *rqcorr, real *work);

/* Subroutine */ int clar2v_(integer *n, complex *x, complex *y, complex *z__, 
	 integer *incx, real *c__, complex *s, integer *incc);

/* Subroutine */ int clarcm_(integer *m, integer *n, real *a, integer *lda, 
	complex *b, integer *ldb, complex *c__, integer *ldc, real *rwork);

/* Subroutine */ int clarf_(char *side, integer *m, integer *n, complex *v, 
	integer *incv, complex *tau, complex *c__, integer *ldc, complex *
	work);

/* Subroutine */ int clarfb_(char *side, char *trans, char *direct, char *
	storev, integer *m, integer *n, integer *k, complex *v, integer *ldv, 
	complex *t, integer *ldt, complex *c__, integer *ldc, complex *work, 
	integer *ldwork);

/* Subroutine */ int clarfg_(integer *n, complex *alpha, complex *x, integer *
	incx, complex *tau);

/* Subroutine */ int clarfp_(integer *n, complex *alpha, complex *x, integer *
	incx, complex *tau);

/* Subroutine */ int clarft_(char *direct, char *storev, integer *n, integer *
	k, complex *v, integer *ldv, complex *tau, complex *t, integer *ldt);

/* Subroutine */ int clarfx_(char *side, integer *m, integer *n, complex *v, 
	complex *tau, complex *c__, integer *ldc, complex *work);

/* Subroutine */ int clargv_(integer *n, complex *x, integer *incx, complex *
	y, integer *incy, real *c__, integer *incc);

/* Subroutine */ int clarnv_(integer *idist, integer *iseed, integer *n, 
	complex *x);

/* Subroutine */ int clarrv_(integer *n, real *vl, real *vu, real *d__, real *
	l, real *pivmin, integer *isplit, integer *m, integer *dol, integer *
	dou, real *minrgp, real *rtol1, real *rtol2, real *w, real *werr, 
	real *wgap, integer *iblock, integer *indexw, real *gers, complex *
	z__, integer *ldz, integer *isuppz, real *work, integer *iwork, 
	integer *info);

/* Subroutine */ int clarscl2_(integer *m, integer *n, real *d__, complex *x, 
	integer *ldx);

/* Subroutine */ int clartg_(complex *f, complex *g, real *cs, complex *sn, 
	complex *r__);

/* Subroutine */ int clartv_(integer *n, complex *x, integer *incx, complex *
	y, integer *incy, real *c__, complex *s, integer *incc);

/* Subroutine */ int clarz_(char *side, integer *m, integer *n, integer *l, 
	complex *v, integer *incv, complex *tau, complex *c__, integer *ldc, 
	complex *work);

/* Subroutine */ int clarzb_(char *side, char *trans, char *direct, char *
	storev, integer *m, integer *n, integer *k, integer *l, complex *v, 
	integer *ldv, complex *t, integer *ldt, complex *c__, integer *ldc, 
	complex *work, integer *ldwork);

/* Subroutine */ int clarzt_(char *direct, char *storev, integer *n, integer *
	k, complex *v, integer *ldv, complex *tau, complex *t, integer *ldt);

/* Subroutine */ int clascl_(char *type__, integer *kl, integer *ku, real *
	cfrom, real *cto, integer *m, integer *n, complex *a, integer *lda, 
	integer *info);

/* Subroutine */ int clascl2_(integer *m, integer *n, real *d__, complex *x, 
	integer *ldx);

/* Subroutine */ int claset_(char *uplo, integer *m, integer *n, complex *
	alpha, complex *beta, complex *a, integer *lda);

/* Subroutine */ int clasr_(char *side, char *pivot, char *direct, integer *m, 
	 integer *n, real *c__, real *s, complex *a, integer *lda);

/* Subroutine */ int classq_(integer *n, complex *x, integer *incx, real *
	scale, real *sumsq);

/* Subroutine */ int claswp_(integer *n, complex *a, integer *lda, integer *
	k1, integer *k2, integer *ipiv, integer *incx);

/* Subroutine */ int clasyf_(char *uplo, integer *n, integer *nb, integer *kb, 
	 complex *a, integer *lda, integer *ipiv, complex *w, integer *ldw, 
	integer *info);

/* Subroutine */ int clatbs_(char *uplo, char *trans, char *diag, char *
	normin, integer *n, integer *kd, complex *ab, integer *ldab, complex *
	x, real *scale, real *cnorm, integer *info);

/* Subroutine */ int clatdf_(integer *ijob, integer *n, complex *z__, integer 
	*ldz, complex *rhs, real *rdsum, real *rdscal, integer *ipiv, integer 
	*jpiv);

/* Subroutine */ int clatps_(char *uplo, char *trans, char *diag, char *
	normin, integer *n, complex *ap, complex *x, real *scale, real *cnorm, 
	 integer *info);

/* Subroutine */ int clatrd_(char *uplo, integer *n, integer *nb, complex *a, 
	integer *lda, real *e, complex *tau, complex *w, integer *ldw);

/* Subroutine */ int clatrs_(char *uplo, char *trans, char *diag, char *
	normin, integer *n, complex *a, integer *lda, complex *x, real *scale, 
	 real *cnorm, integer *info);

/*