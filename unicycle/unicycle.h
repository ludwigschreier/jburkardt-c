int i4_factorial ( int n );
int i4_max ( int i1, int i2 );
int i4_min ( int i1, int i2 );
int i4_modp ( int i, int j );
int i4_uniform ( int a, int b, int *seed );
int i4_wrap ( int ival, int ilo, int ihi );
void i4vec_indicator ( int n, int a[] );
int *i4vec_indicator_new ( int n );
void i4vec_reverse ( int n, int a[] );
void perm_check ( int n, int p[] );
int perm_enum ( int n );
int *perm_inverse ( int n, int p[] );
int perm_is_unicycle ( int n, int p[] );
void perm_lex_next ( int n, int p[], int *rank );
int perm_lex_rank ( int n, int p[] );
int *perm_lex_unrank ( int n, int rank );
void perm_print ( int n, int p[], char *title );
int *perm_random ( int n, int *seed );
int s_len_trim ( char *s );
void timestamp ( void );
void unicycle_check ( int n, int u[] );
int unicycle_enum ( int n );
int *unicycle_index ( int n, int u[] );
void unicycle_index_print ( int n, int u_index[], char *title );
int *unicycle_index_to_sequence ( int n, int u_index[] );
int *unicycle_inverse ( int n, int u[] );
void unicycle_next ( int n, int u[], int *rank );
void unicycle_print ( int n, int u[], char *title );
int *unicycle_random ( int n, int *seed );
int unicycle_rank ( int n, int u[] );
int *unicycle_unrank ( int n, int rank );
