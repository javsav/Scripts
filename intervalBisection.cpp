#include <cmath>
#include <iostream>
#include <set>

class Fraction {

 private:
  int numerator;
  int denominator;

 public:

  Fraction(int num = 1, int denom = 1) : numerator(num), denominator(denom) {}

  static void print(const Fraction& fract) {
    std::cout << fract.numerator << "/" << fract.denominator << "\n";
  }

  void print() {
    std::cout << this->numerator << "/" << this->denominator << "\n";
  }

  void operator()(int a, int b) {
    this->numerator = a;
    this->denominator = b;    
  }

  void checkFactors(Fraction& fract) {
    std::set<int> divisors;
    int divisor = 1;
    if (fract.denominator < fract.numerator) {
      for (int i = 2; i < sqrt(fract.denominator); i++) {
        if (fract.denominator % i == 0) {
          divisors.insert(i);
        }
        
      }
      for (auto j = divisors.end(); j != divisors.begin(); --j) {
        if (fract.numerator % *j == 0) {
          divisor = *j;
          break;
        }
      }
      fract.numerator = fract.numerator / divisor;
      fract.denominator = fract.denominator / divisor;
    } else {
      for (int i = 2; i < sqrt(fract.numerator); i++) {
        if (fract.numerator % i == 0) {
          divisors.insert(i);
        }
        
      }
      for (auto j = divisors.end(); j != divisors.begin(); --j) {
        if (fract.denominator % *j == 0) {
          divisor = *j;
          break;
        }
      }
      fract.numerator = fract.numerator / divisor;
      fract.denominator = fract.denominator / divisor;
    }

    


  }

  Fraction operator*(const Fraction& fract) {
    int newNumerator;
    int newDenominator;
    
    newNumerator = this->numerator * fract.numerator;
    newDenominator = this->denominator * fract.denominator;
    
    Fraction newFraction(newNumerator, newDenominator);
    newFraction.checkFactors(newFraction);
    return newFraction;   
  }

  Fraction operator/(const Fraction& fract) {
    int newNumerator;
    int newDenominator;

    newNumerator = this->numerator * fract.denominator;
    newDenominator = this->denominator * fract.numerator;

    Fraction newFraction(newNumerator, newDenominator);
    newFraction.checkFactors(newFraction);
    return newFraction;
    
    return Fraction(newNumerator, newDenominator);    
  }
  
  
  Fraction operator-(const Fraction& fract) {
    int newNumerator;
    int newDenominator;

    if (this->denominator == fract.denominator) {
      newNumerator = this->numerator - fract.numerator;
      newDenominator = this->denominator;
    } else {      
      int newNumerator = (this->numerator * fract.denominator) - (fract.numerator * this->denominator);
      int newDenominator = (this->denominator * fract.denominator);
    }

    Fraction newFraction(newNumerator, newDenominator);
    newFraction.checkFactors(newFraction);
    return newFraction;
    
    return Fraction(newNumerator, newDenominator);    
  }


  Fraction operator+(const Fraction& fract) {
    int newNumerator;
    int newDenominator;

    if (this->numerator == 0) {
      return fract;
    } else if (fract.numerator == 0) {
      return *this;
    }

    if (this->denominator == fract.denominator) {
      newNumerator = this->numerator + fract.numerator;
      newDenominator = this->denominator;
    } else {
      
      newNumerator = (this->numerator * fract.denominator) + (fract.numerator * this->denominator);
      newDenominator = (this->denominator * fract.denominator);
    }

    Fraction newFraction(newNumerator, newDenominator);
    newFraction.checkFactors(newFraction);
    return newFraction;   


    return Fraction(newNumerator, newDenominator);    
  }

};

class IntervalBisection {

private:

  static int numerator;
  static int denominator;

 public:

 static double f(double x) {
  return (double)pow(x,5) - (double)2/3*pow(x,4) + (double)1/2*pow(x,3) - (double)1/3*pow(x,2) + (double)4*x - (double)8/3;
 }

 static double intBisect(double low, double high, double root, double precision) {

  if (!(f(low) < root)) {
    return -1;
  }
  if (!(f(high) > root)) {
    return -1;
  }
  double actualPrecision = INT32_MAX;
  double mid;
  double current;
  Fraction lowest(low, 1);
  Fraction highest(high, 1);
  Fraction middle;
  Fraction two(1,2);
  while ((high - low) > precision) {
    mid = (double)(low + high) / 2;
    middle = lowest + highest;
    middle = middle * two;
    current = f(mid);
    std::cout << "Fraction: ";
    middle.print();
    actualPrecision = fabs(fabs(current) - fabs(root));
    if (current < root) {
      low = mid;
      lowest = middle;
    } else if (current > root) {
      high = mid;
      highest = middle;
    } else {
      return mid;
    }
    std::cout << "\n";
    std::cout << "Mid: " << mid << "\n";
    std::cout << "Current: " << current << "\n";
    std::cout << "Required precision: " << precision << "\n";
    std::cout << "Actual precision: " << actualPrecision << "\n";

  } 

  return mid;

 }


};


int main() {
  //std::cout << IntervalBisection::f(0.75) << "\n";
  /*Fraction a(1,5);
  Fraction b(1,1);
  Fraction c = a+b;
  Fraction::print(c);*/
  //std::cout << IntervalBisection::intBisect(0, 1, 0, (double)1/128) << "\n";

  Fraction test(1,2);
  Fraction mult(1,3);
  int count = 0;
  while (count < 100) {
    test = test + mult;
    Fraction::print(test);
    count++;
  }
}