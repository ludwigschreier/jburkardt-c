# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>

# include "asa005.h"

/******************************************************************************/

double alngam ( double xvalue, int *ifault )

/******************************************************************************/
/*
  Purpose:

    ALNGAM computes the logarithm of the gamma function.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 October 2010

  Author:

    Original FORTRAN77 version by Allan Macleod.
    C version by John Burkardt.

  Reference:

    Allan Macleod,
    Algorithm AS 245,
    A Robust and Reliable Algorithm for the Logarithm of the Gamma Function,
    Applied Statistics,
    Volume 38, Number 2, 1989, pages 397-402.

  Parameters:

    Input, double XVALUE, the argument of the Gamma function.

    Output, int *IFAULT, error flag.
    0, no error occurred.
    1, XVALUE is less than or equal to 0.
    2, XVALUE is too big.

    Output, double ALNGAM, the logarithm of the gamma function of X.
*/
{
  double alr2pi = 0.918938533204673;
  double r1[9] = {
    -2.66685511495, 
    -24.4387534237, 
    -21.9698958928, 
     11.1667541262, 
     3.13060547623, 
     0.607771387771, 
     11.9400905721, 
     31.4690115749, 
     15.2346874070 };
  double r2[9] = {
    -78.3359299449, 
    -142.046296688, 
     137.519416416, 
     78.6994924154, 
     4.16438922228, 
     47.0668766060, 
     313.399215894, 
     263.505074721, 
     43.3400022514 };
  double r3[9] = {
    -2.12159572323E+05, 
     2.30661510616E+05, 
     2.74647644705E+04, 
    -4.02621119975E+04, 
    -2.29660729780E+03, 
    -1.16328495004E+05, 
    -1.46025937511E+05, 
    -2.42357409629E+04, 
    -5.70691009324E+02 };
  double r4[5] = {
     0.279195317918525, 
     0.4917317610505968, 
     0.0692910599291889, 
     3.350343815022304, 
     6.012459259764103 };
  double value;
  double x;
  double x1;
  double x2;
  double xlge = 510000.0;
  double xlgst = 1.0E+30;
  double y;

  x = xvalue;
  value = 0.0;
/*
  Check the input.
*/
  if ( xlgst <= x )
  {
    *ifault = 2;
    return value;
  }

  if ( x <= 0.0 )
  {
    *ifault = 1;
    return value;
  }

  *ifault = 0;
/*
  Calculation for 0 < X < 0.5 and 0.5 <= X < 1.5 combined.
*/
  if ( x < 1.5 )
  {
    if ( x < 0.5 )
    {
      value = - log ( x );
      y = x + 1.0;
/*
  Test whether X < machine epsilon.
*/
      if ( y == 1.0 )
      {
        return value;
      }
    }
    else
    {
      value = 0.0;
      y = x;
      x = ( x - 0.5 ) - 0.5;
    }

    value = value + x * (((( 
        r1[4]   * y 
      + r1[3] ) * y 
      + r1[2] ) * y 
      + r1[1] ) * y 
      + r1[0] ) / (((( 
                  y 
      + r1[8] ) * y 
      + r1[7] ) * y 
      + r1[6] ) * y 
      + r1[5] );

    return value;
  }
/*
  Calculation for 1.5 <= X < 4.0.
*/
  if ( x < 4.0 )
  {
    y = ( x - 1.0 ) - 1.0;

    value = y * (((( 
        r2[4]   * x 
      + r2[3] ) * x 
      + r2[2] ) * x 
      + r2[1] ) * x 
      + r2[0] ) / (((( 
                  x 
      + r2[8] ) * x 
      + r2[7] ) * x 
      + r2[6] ) * x 
      + r2[5] );
  }
/*
  Calculation for 4.0 <= X < 12.0.
*/
  else if ( x < 12.0 ) 
  {
    value = (((( 
        r3[4]   * x 
      + r3[3] ) * x 
      + r3[2] ) * x 
      + r3[1] ) * x 
      + r3[0] ) / (((( 
                  x 
      + r3[8] ) * x 
      + r3[7] ) * x 
      + r3[6] ) * x 
      + r3[5] );
  }
/*
  Calculation for 12.0 <= X.
*/
  else
  {
    y = log ( x );
    value = x * ( y - 1.0 ) - 0.5 * y + alr2pi;

    if ( x <= xlge )
    {
      x1 = 1.0 / x;
      x2 = x1 * x1;

      value = value + x1 * ( ( 
             r4[2]   * 
        x2 + r4[1] ) * 
        x2 + r4[0] ) / ( ( 
        x2 + r4[4] ) * 
        x2 + r4[3] );
    }
  }

  return value;
}
/******************************************************************************/

double alnorm ( double x, int upper )

/******************************************************************************/
/*
  Purpose:

    ALNORM computes the cumulative density of the standard normal distribution.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 October 2010

  Author:

    Original FORTRAN77 version by David Hill.
    C version by John Burkardt.

  Reference:

    David Hill,
    Algorithm AS 66:
    The Normal Integral,
    Applied Statistics,
    Volume 22, Number 3, 1973, pages 424-427.

  Parameters:

    Input, double X, is one endpoint of the semi-infinite interval
    over which the integration takes place.

    Input, int UPPER, determines whether the upper or lower
    interval is to be integrated:
    1  => integrate from X to + Infinity;
    0 => integrate from - Infinity to X.

    Output, double ALNORM, the integral of the standard normal
    distribution over the desired interval.
*/
{
  double a1 = 5.75885480458;
  double a2 = 2.62433121679;
  double a3 = 5.92885724438;
  double b1 = -29.8213557807;
  double b2 = 48.6959930692;
  double c1 = -0.000000038052;
  double c2 = 0.000398064794;
  double c3 = -0.151679116635;
  double c4 = 4.8385912808;
  double c5 = 0.742380924027;
  double c6 = 3.99019417011;
  double con = 1.28;
  double d1 = 1.00000615302;
  double d2 = 1.98615381364;
  double d3 = 5.29330324926;
  double d4 = -15.1508972451;
  double d5 = 30.789933034;
  double ltone = 7.0;
  double p = 0.398942280444;
  double q = 0.39990348504;
  double r = 0.398942280385;
  int up;
  double utzero = 18.66;
  double value;
  double y;
  double z;

  up = upper;
  z = x;

  if ( z < 0.0 )
  {
    up = !up;
    z = - z;
  }

  if ( ltone < z && ( ( !up ) || utzero < z ) )
  {
    if ( up )
    {
      value = 0.0;
    }
    else
    {
      value = 1.0;
    }
    return value;
  }

  y = 0.5 * z * z;

  if ( z <= con )
  {
    value = 0.5 - z * ( p - q * y 
      / ( y + a1 + b1 
      / ( y + a2 + b2 
      / ( y + a3 ))));
  }
  else
  {
    value = r * exp ( - y ) 
      / ( z + c1 + d1 
      / ( z + c2 + d2 
      / ( z + c3 + d3 
      / ( z + c4 + d4 
      / ( z + c5 + d5 
      / ( z + c6 ))))));
  }

  if ( !up )
  {
    value = 1.0 - value;
  }

  return value;
}
/******************************************************************************/

double prncst ( double st, int idf, double d, int *ifault )

/******************************************************************************/
/*
  Purpose:

    PRNCST computes the lower tail of noncentral T distribution.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 October 2010

  Author:

    Original FORTRAN77 version by BE Cooper.
    C version by John Burkardt.

  Reference:

    BE Cooper,
    Algorithm AS 5:
    The Integral of the Non-Central T-Distribution,
    Applied Statistics,
    Volume 17, Number 2, 1968, page 193.

  Parameters:

    Input, double ST, the argument.

    Input, int IDF, the number of degrees of freedom.

    Input, double D, the noncentrality parameter.

    Output, int *IFAULT, error flag.
    0, no error occurred.
    nonzero, an error occurred.

    Output, double PRNCST, the value of the lower tail of
    the noncentral T distribution.

  Local Parameters:

    Local, double G1, 1.0 / sqrt(2.0 * pi)

    Local, double G2, 1.0 / (2.0 * pi)

    Local, double G3, sqrt(2.0 * pi)
*/
{
  double a;
  double ak;
  double b;
  double da;
  double drb;
  double emin = 12.5;
  double f;
  double fk;
  double fkm1;
  double fmkm1;
  double fmkm2;
  double g1 = 0.3989422804;
  double g2 = 0.1591549431;
  double g3 = 2.5066282746;
  int ioe;
  int k;
  double rb;
  double sum;
  double value;

  f = ( double ) ( idf );
/*
  For very large IDF, use the normal approximation.
*/
  if ( 100 < idf )
  {
    *ifault = 1;

    a = sqrt ( 0.5 * f ) 
    * exp ( alngam ( 0.5 * ( f - 1.0 ), &k ) 
    - alngam ( 0.5 * f, &k ) ) * d;

    value = alnorm ( ( st - a ) / sqrt ( f * ( 1.0 + d * d ) 
    / ( f - 2.0 ) - a * a ), 0 );
    return value;
  }

  *ifault = 0;
  ioe = ( idf % 2 );
  a = st / sqrt ( f );
  b = f / ( f + st * st );
  rb = sqrt ( b );
  da = d * a;
  drb = d * rb;

  if ( idf == 1 )
  {
    value = alnorm ( drb, 1 ) + 2.0 * tfn ( drb, a );
    return value;
  }

  sum = 0.0;

  if ( r8_abs ( drb ) < emin )
  {
    fmkm2 = a * rb * exp ( - 0.5 * drb * drb ) 
    * alnorm ( a * drb, 0 ) * g1;
  }
  else
  {
    fmkm2 = 0.0;
  }

  fmkm1 = b * da * fmkm2;

  if ( r8_abs ( d ) < emin )
  {
    fmkm1 = fmkm1 + b * a * g2 * exp ( - 0.5 * d * d );
  }

  if ( ioe == 0 )
  {
    sum = fmkm2;
  }
  else
  {
    sum = fmkm1;
  }

  ak = 1.0;
  fk = 2.0;

  for ( k = 2; k <= idf - 2; k = k + 2 )
  {
    fkm1 = fk - 1.0;
    fmkm2 = b * ( da * ak * fmkm1 + fmkm2 ) * fkm1 / fk;
    ak = 1.0 / ( ak * fkm1 );
    fmkm1 = b * ( da * ak * fmkm2 + fmkm1 ) * fk / ( fk + 1.0 );

    if ( ioe == 0 )
    {
      sum = sum + fmkm2;
    }
    else
    {
      sum = sum + fmkm1;
    }
    ak = 1.0 / ( ak * fk );
    fk = fk + 2.0;
  }

  if ( ioe == 0 )
  {
    value = alnorm ( d, 1 ) + sum * g3;
  }
  else
  {
    value = alnorm ( drb, 1 ) + 2.0 * ( sum + tfn ( drb, a ) );
  }

  return value;
}
/******************************************************************************/

double r8_abs ( double x )

/******************************************************************************/
/*
  Purpose:

    R8_ABS returns the absolute value of an R8.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 November 2006

  Author:

    John Burkardt

  Parameters:

    Input, double X, the quantity whose absolute value is desired.

    Output, double R8_ABS, the absolute value of X.
*/
{
  double value;

  if ( 0.0 <= x )
  {
    value = x;
  } 
  else
  {
    value = -x;
  }
  return value;
}
/******************************************************************************/

void student_noncentral_cdf_values ( int *n_data, int *df, double *lambda, 
  double *x, double *fx )

/******************************************************************************/
/*
  Purpose:

    STUDENT_NONCENTRAL_CDF_VALUES returns values of the noncentral Student CDF.

  Discussion:

    In Mathematica, the function can be evaluated by:

      Needs["Statistics`ContinuousDistributions`"]
      dist = NoncentralStudentTDistribution [ df, lambda ]
      CDF [ dist, x ]

    Mathematica seems to have some difficulty computing this function
    to the desired number of digits.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    01 September 2004

  Author:

    John Burkardt

  Reference:

    Milton Abramowitz, Irene Stegun,
    Handbook of Mathematical Functions,
    National Bureau of Standards, 1964,
    ISBN: 0-486-61272-4,
    LC: QA47.A34.

    Stephen Wolfram,
    The Mathematica Book,
    Fourth Edition,
    Cambridge University Press, 1999,
    ISBN: 0-521-64314-7,
    LC: QA76.95.W65.

  Parameters:

    Input/output, int *N_DATA.  The user sets N_DATA to 0 before the
    first call.  On each call, the routine increments N_DATA by 1, and
    returns the corresponding data; when there is no more data, the
    output value of N_DATA will be 0 again.

    Output, int *DF, double *LAMBDA, the parameters of the
    function.

    Output, double *X, the argument of the function.

    Output, double *FX, the value of the function.
*/
{
# define N_MAX 30

  int df_vec[N_MAX] = { 
     1,  2,  3, 
     1,  2,  3, 
     1,  2,  3, 
     1,  2,  3, 
     1,  2,  3, 
    15, 20, 25, 
     1,  2,  3, 
    10, 10, 10, 
    10, 10, 10, 
    10, 10, 10 };

  double fx_vec[N_MAX] = { 
     0.8975836176504333E+00,  
     0.9522670169E+00,  
     0.9711655571887813E+00,  
     0.8231218864E+00,  
     0.9049021510E+00,  
     0.9363471834E+00,  
     0.7301025986E+00,  
     0.8335594263E+00,  
     0.8774010255E+00,  
     0.5248571617E+00,  
     0.6293856597E+00,  
     0.6800271741E+00,  
     0.20590131975E+00,  
     0.2112148916E+00,  
     0.2074730718E+00,  
     0.9981130072E+00,  
     0.9994873850E+00,  
     0.9998391562E+00,  
     0.168610566972E+00,  
     0.16967950985E+00,  
     0.1701041003E+00,  
     0.9247683363E+00,  
     0.7483139269E+00,  
     0.4659802096E+00,  
     0.9761872541E+00,  
     0.8979689357E+00,  
     0.7181904627E+00,  
     0.9923658945E+00,  
     0.9610341649E+00,  
     0.8688007350E+00 };

  double lambda_vec[N_MAX] = { 
     0.0E+00,  
     0.0E+00,  
     0.0E+00,  
     0.5E+00,  
     0.5E+00,  
     0.5E+00,  
     1.0E+00,  
     1.0E+00,  
     1.0E+00,  
     2.0E+00,  
     2.0E+00,  
     2.0E+00,  
     4.0E+00,  
     4.0E+00,  
     4.0E+00,  
     7.0E+00,  
     7.0E+00,  
     7.0E+00,  
     1.0E+00,  
     1.0E+00,  
     1.0E+00,  
     2.0E+00,  
     3.0E+00,  
     4.0E+00,  
     2.0E+00,  
     3.0E+00,  
     4.0E+00,  
     2.0E+00,  
     3.0E+00,  
     4.0E+00 };

  double x_vec[N_MAX] = { 
      3.00E+00,  
      3.00E+00,  
      3.00E+00,  
      3.00E+00,  
      3.00E+00,  
      3.00E+00,  
      3.00E+00,  
      3.00E+00,  
      3.00E+00,  
      3.00E+00,  
      3.00E+00,  
      3.00E+00,  
      3.00E+00,  
      3.00E+00,  
      3.00E+00,  
     15.00E+00,  
     15.00E+00,  
     15.00E+00,  
      0.05E+00,  
      0.05E+00,  
      0.05E+00,  
      4.00E+00,  
      4.00E+00,  
      4.00E+00,  
      5.00E+00,  
      5.00E+00,  
      5.00E+00,  
      6.00E+00,  
      6.00E+00,  
      6.00E+00 };

  if ( *n_data < 0 )
  {
    *n_data = 0;
  }

  *n_data = *n_data + 1;

  if ( N_MAX < *n_data )
  {
    *n_data = 0;
    *df = 0;
    *lambda = 0.0;
    *x = 0.0;
    *fx = 0.0;
  }
  else
  {
    *df = df_vec[*n_data-1];
    *lambda = lambda_vec[*n_data-1];
    *x = x_vec[*n_data-1];
    *fx = fx_vec[*n_data-1];
  }

  return;
# undef N_MAX
}
/******************************************************************************/

double tfn ( double x, double fx )

/******************************************************************************/
/*
  Purpose:

    TFN calculates the T-function of Owen.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    16 January 2008

  Author:

    Original FORTRAN77 version by JC Young, Christoph Minder.
    C version by John Burkardt.

  Reference:

    MA Porter, DJ Winstanley,
    Remark AS R30:
    A Remark on Algorithm AS76:
    An Integral Useful in Calculating Noncentral T and Bivariate
    Normal Probabilities,
    Applied Statistics,
    Volume 28, Number 1, 1979, page 113.

    JC Young, Christoph Minder,
    Algorithm AS 76: 
    An Algorithm Useful in Calculating Non-Central T and 
    Bivariate Normal Distributions,
    Applied Statistics,
    Volume 23, Number 3, 1974, pages 455-457.

  Parameters:

    Input, double X, FX, the parameters of the function.

    Output, double TFN, the value of the T-function.
*/
{
# define NG 5

  double fxs;
  int i;
  double r[NG] = {
    0.1477621, 
    0.1346334, 
    0.1095432, 
    0.0747257, 
    0.0333357 };
  double r1;
  double r2;
  double rt;
  double tp = 0.159155;
  double tv1 = 1.0E-35;
  double tv2 = 15.0;
  double tv3 = 15.0;
  double tv4 = 1.0E-05;
  double u[NG] = {
    0.0744372, 
    0.2166977, 
    0.3397048,
    0.4325317, 
    0.4869533 };
  double value;
  double x1;
  double x2;
  double xs;
/*
  Test for X near zero.
*/
  if ( r8_abs ( x ) < tv1 )
  {
    value = tp * atan ( fx );
    return value;
  }
/*
  Test for large values of abs(X).
*/
  if ( tv2 < r8_abs ( x ) )
  {
    value = 0.0;
    return value;
  }
/*
  Test for FX near zero.
*/
  if ( r8_abs ( fx ) < tv1 )
  {
    value = 0.0;
    return value;
  }
/*
  Test whether abs ( FX ) is so large that it must be truncated.
*/
  xs = - 0.5 * x * x;
  x2 = fx;
  fxs = fx * fx;
/*
  Computation of truncation point by Newton iteration.
*/
  if ( tv3 <= log ( 1.0 + fxs ) - xs * fxs )
  {
    x1 = 0.5 * fx;
    fxs = 0.25 * fxs;

    for ( ; ; )
    {
      rt = fxs + 1.0;

      x2 = x1 + ( xs * fxs + tv3 - log ( rt ) ) 
      / ( 2.0 * x1 * ( 1.0 / rt - xs ) );

      fxs = x2 * x2;

      if ( r8_abs ( x2 - x1 ) < tv4 )
      {
        break;
      }
      x1 = x2;
    }
  }
/*
  Gaussian quadrature.
*/
  rt = 0.0;
  for ( i = 0; i < NG; i++ )
  {
    r1 = 1.0 + fxs * pow ( 0.5 + u[i], 2 );
    r2 = 1.0 + fxs * pow ( 0.5 - u[i], 2 );

    rt = rt + r[i] * ( exp ( xs * r1 ) / r1 + exp ( xs * r2 ) / r2 );
  }

  value = rt * x2 * tp;

  return value;
# undef NG
}
/******************************************************************************/

void timestamp ( void )

/******************************************************************************/
/*
  Purpose:

    TIMESTAMP prints the current YMDHMS date as a time stamp.

  Example:

    31 May 2001 09:45:54 AM

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    24 September 2003

  Author:

    John Burkardt

  Parameters:

    None
*/
{
# define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];
  const struct tm *tm;
  size_t len;
  time_t now;

  now = time ( NULL );
  tm = localtime ( &now );

  len = strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm );

  printf ( "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}
