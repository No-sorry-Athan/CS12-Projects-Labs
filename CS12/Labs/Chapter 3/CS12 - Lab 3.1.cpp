#include <iostream>

using namespace std;

// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int); 
      Rational(int, int); 
      const Rational add(const Rational &) const; 
      const Rational subtract(const Rational &) const; 
      const Rational multiply(const Rational &) const; 
      const Rational divide(const Rational &) const;
      void simplify();
      void display() const;
   private:
      int gcd(int, int) const;
};

// Implement Rational class member functions here

Rational::Rational() {
	numerator = 0;
	denominator = 1;
}

Rational::Rational(int val) {
	numerator = val;
	denominator = 1;
}

Rational::Rational(int val1, int val2) {
	numerator = val1;
	denominator = val2;
}

const Rational Rational::add(const Rational& rat) const {
	int numer = ((this->numerator * rat.denominator) + (this->denominator * rat.numerator));
	int denom = (this->denominator * rat.denominator);
	return Rational(numer, denom);
}

const Rational Rational::subtract(const Rational& rat) const {
	int numer = ((this->numerator * rat.denominator) - (this->denominator * rat.numerator));
	int denom = (this->denominator * rat.denominator);
	return Rational(numer, denom);
}

const Rational Rational::multiply(const Rational& rat) const {
	int numer = (this->numerator * rat.numerator);
	int denom = (this->denominator * rat.denominator);
	return Rational(numer, denom);
}

const Rational Rational::divide(const Rational& rat) const {
	int numer = (this->numerator * rat.denominator);
	int denom = (this->denominator * rat.numerator);
	return Rational(numer, denom);
}

void Rational::simplify() {
	int gcd = this->gcd(this->numerator, this->denominator);
	this->numerator /= gcd;
	this->denominator /= gcd;
}

void Rational::display() const{
	cout << numerator << " / " << denominator;
}

int Rational::gcd(int val1, int val2) const {
	if (val2 == 0)
		return val1;
	else
		return gcd(val2, val1%val2); //gcd method taken from wikipedia using recursion
}
// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

