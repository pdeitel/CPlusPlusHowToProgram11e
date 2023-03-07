// Fig. 11.9: Complex.h
// Complex class definition.
#pragma once
#include <string>

class Complex {
public:
   explicit Complex(double realPart = 0.0, double imaginaryPart = 0.0); 
   Complex operator+(const Complex& right) const; // addition
   Complex operator-(const Complex& right) const; // subtraction
   std::string toString() const; 
private:
   double real; // real part
   double imaginary; // imaginary part
}; 


/**************************************************************************
 * (C) Copyright 1992-2022 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
