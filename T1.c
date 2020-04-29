#include <stdio.h>
#include <stdbool.h>


typedef struct {
  int          numerator;   // чисельник
  unsigned int denominator; // знаменник
} Rational;


Rational sum(Rational a1, Rational a2)
{
  Rational z;
  z.numerator = a1.denominator * a2.numerator +
                a2.denominator * a1.numerator;
  z.denominator = a1.denominator * a2.denominator;
  return z;
}


Rational mult(Rational a1, Rational a2)
{
  Rational z;
  z.numerator = a2.numerator * a1.numerator;
  z.denominator = a1.denominator * a2.denominator;
  return z;
}


bool compare(Rational a1, Rational a2)
{
  Rational b1, b2;
  b1.denominator = a1.denominator * a2.denominator;
  b2.denominator = a1.denominator * a2.denominator;

  b1.numerator = a1.denominator * a2.numerator;
  b2.numerator = a2.denominator * a1.numerator;

  if (b1.denominator == b2.denominator && b1.numerator == b2.numerator)
  {
    return true;
  }
  else
  {
  return false;
  }
}


int gcd(int a, int b)
{
  if (a == 0) return b;
  return gcd (b%a, a);
}

Rational cut(Rational a)
{
  int n = gcd(a.denominator, a.numerator);
  Rational z;
  z.denominator = a.denominator / n;
  z.numerator = a.numerator / n;
  return z;
}


Rational inp()
{
  Rational z;
  int a, b;
  printf("input (num/den)");
  scanf("%d %d",&a,&b);
  z.denominator = b;
  z.numerator = a;
  return z;
}


void show_ratio(Rational a)
{
  printf("%d\\%d\n", a.numerator, a.denominator);
}


int main()
{
  Rational a, b;

  a.numerator = 4;
  a.denominator = 6;

  b.numerator = 8;
  b.denominator = 9;

  Rational c;
  c = sum(a, b);
  printf("a + b = ");
  show_ratio(c);

  Rational d;
  d = mult(a, b);
  printf("a * b = ");
  show_ratio(d);

  bool e;
  e = compare(a, b);
  printf("(a ?= b) = ");
  printf("%d\n", e);

  Rational f;
  f = cut(a);
  printf("a = ");
  show_ratio(f);

  Rational g;
  g = inp();
  show_ratio(g);

  return 0;
}
