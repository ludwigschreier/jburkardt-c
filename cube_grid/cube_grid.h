double *cube_grid ( int n, int ns[], double a[], double b[], 
  int c[] );
void r8mat_transpose_print ( int m, int n, double a[], char *title );
void r8mat_transpose_print_some ( int m, int n, double a[], int ilo, int jlo,
  int ihi, int jhi, char *title );
void r8vec_direct_product ( int factor_index, int factor_order,
  double factor_value[], int factor_num, int point_num, double x[] );
void timestamp ( );

