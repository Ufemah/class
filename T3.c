#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 100


typedef struct {
  int      ndim;   // ступінь поліному
  double   a[N];      // коефіцієнти поліному
} Polynome;


Polynome inp(int n)
{
  Polynome p;
  p.ndim = n;
  printf("type coefs: ");

  for (int i = 0; i <= n; i++)
  {
    scanf("%lf", &p.a[i]);
  }

  return p;
}


Polynome sum(Polynome p1, Polynome p2)
{
  Polynome p3;
  p3.ndim = fmax(p1.ndim, p2.ndim);
  for (int i = 0; i <= p3.ndim + 1; i++)
  {
    p3.a[i] = p1.a[i] + p2.a[i];
  }
  return p3;
}


Polynome mult(Polynome p1, Polynome p2)
{
  Polynome p4;
  p4.ndim = p1.ndim + p2.ndim;
  for (int i = 0; i <= p1.ndim; i++)
  {
    for (int j = 0; j <= p2.ndim; j++)
    {
      p4.a[i + j] = p1.a[i] * p2.a[j];
    }
  }
  return p4;
}


void show(Polynome p)
{
  for(int j = 0; j <= p.ndim; j++)
  { if(j != p.ndim)
    {
      printf("%lfx**%d + ", p.a[j], p.ndim - j);
    }
    else
    {
      printf("%lfx**%d", p.a[j], p.ndim - j);
    }
  }
}



double dot(Polynome p, double d)
{
  double res = 0;

  for(int j = 0; j <= p.ndim; j++)
  {
      res += p.a[j] * pow(d, p.ndim - j);
  }

  return res;
}



int main()
{
  Polynome a, b, c, d;
  int n = 2;
  a = inp(n);
  b = inp(n);

  c = sum(a, b);
  show(c);
  printf("\n");

  d = mult(a, b);
  show(d);
  printf("\n");

  double m = dot(a, 2);
  printf("%lf\n", m);
  return 0;
}
