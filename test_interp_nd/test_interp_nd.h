double csevl ( double x, double a[], int n );
int i4vec_sum ( int n, int a[] );
int inits ( double dos[], int nos, double eta );
double *p00_c ( int prob, int m, int *seed );
double *p00_d ( int prob, int m, int id, double c[], double w[], int n, 
  double x[] );
double *p00_f ( int prob, int m, double c[], double w[], int n, double x[] );
int p00_prob_num ( void );
double p00_q ( int prob, int m, double c[], double w[] );
char *p00_title ( int prob );
double *p00_w ( int prob, int m, int *seed );
double *p01_d ( int m, int id, double c[], double w[], int n, double x[] );
double *p01_f ( int m, double c[], double w[], int n, double x[] );
double p01_q ( int m, double c[], double w[] );
char *p01_title ( void );
double *p02_d ( int m, int id, double c[], double w[], int n, double x[] );
double *p02_f ( int m, double c[], double w[], int n, double x[] );
double p02_q ( int m, double c[], double w[] );
char *p02_title ( void );
double *p03_d ( int m, int id, double c[], double w[], int n, double x[] );
double *p03_f ( int m, double c[], double w[], int n, double x[] );
double p03_q ( int m, double c[], double w[] );
char *p03_title ( void );
double *p04_d ( int m, int id, double c[], double w[], int n, double x[] );
double *p04_f ( int m, double c[], double w[], int n, double x[] );
double p04_q ( int m, double c[], double w[] );
char *p04_title ( void );
double *p05_d ( int m, int id, double c[], double w[], int n, double x[] );
double *p05_f ( int m, double c[], double w[], int n, double x[] );
double p05_q ( int m, double c[], double w[] );
char *p05_title ( void );
double *p06_d ( int m, int id, double c[], double w[], int n, double x[] );
double *p06_f ( int m, double c[], double w[], int n, double x[] );
double p06_q ( int m, double c[], double w[] );
char *p06_title ( void );
double r8_error ( double x );
double r8_errorc ( double x );
double r8_mach ( int i );
void tuple_next ( int m1, int m2, int n, int *rank, int x[] );
