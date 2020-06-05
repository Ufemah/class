#include <iostream>

namespace newspace
{
  class Rational  {

  public:
     Rational( int = 0, int = 1 );
     Rational addition( const Rational & ) const;
     void printnamespace() const;
     void printRational () const;

  private:
     int numerator;
     int denominator;
     void reduce();
  };

  void Rational:: printnamespace() const
  {
    std::cout << "this is newspace namespace" << '\n';
  }

  Rational::Rational( int n, int d ) : numerator( n ), denominator( d )
  {
       reduce();
  }


  Rational Rational::addition( const Rational &a ) const
  {
      Rational t( a.numerator * denominator + a.denominator * numerator,
                      a.denominator * denominator );
      t.reduce();
      return t;

  }


  void Rational::printRational() const {
      if ( numerator == 0 )
      {
        std::cout << 0;
      }

      else
         {
           std::cout << numerator << '/' << denominator;
         }
  }


  void Rational::reduce() {
     int largest = numerator > denominator ? numerator : denominator;
     int gcd = 0;
     for ( int loop = 2; loop <= largest; ++loop )
     {
       if ( numerator % loop == 0 && denominator % loop == 0 )
       {
         gcd = loop;
       }
     }

     if (gcd != 0)
     {
        numerator /= gcd;
        denominator /= gcd;
     }
  }
}


class Rational  {

public:
   Rational( int = 0, int = 1 );
   Rational addition( const Rational & ) const;
   void printnamespace() const;
   void printRational () const;

private:
   int numerator;
   int denominator;
   void reduce();
};

void Rational:: printnamespace() const
{
  std::cout << "this is std namespace" << '\n';
}

Rational::Rational( int n, int d ) : numerator( n ), denominator( d )
{
     reduce();
}


Rational Rational::addition( const Rational &a ) const
{
    Rational t( a.numerator * denominator + a.denominator * numerator,
                    a.denominator * denominator );
    t.reduce();
    return t;

}


void Rational::printRational() const {
    if ( numerator == 0 )
    {
      std::cout << 0;
    }

    else
       {
         std::cout << numerator << '/' << denominator;
       }
}


void Rational::reduce() {
   int largest = numerator > denominator ? numerator : denominator;
   int gcd = 0;
   for ( int loop = 2; loop <= largest; ++loop )
   {
     if ( numerator % loop == 0 && denominator % loop == 0 )
     {
       gcd = loop;
     }
   }

   if (gcd != 0)
   {
      numerator /= gcd;
      denominator /= gcd;
   }
}


int main()
{
  newspace::Rational c(2, 6), d(7, 8), x;
  c.printnamespace();

  c.printRational();
  std::cout << " + ";
  d.printRational();
  x = c.addition( d );
  std::cout << " = ";
  x.printRational();

  std::cout << "\n\n";

  Rational c1(2, 6), d1(7, 8), x1;
  c1.printnamespace();

  c1.printRational();
  std::cout << " + ";
  d1.printRational();
  x1 = c1.addition( d1 );
  std::cout << " = ";
  x1.printRational();

  return 0;
}
