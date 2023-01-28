// Fig. 11.10: Complex.cpp
// Complex class member-function definitions.
#include <format>
#include <string>
#include "Complex.h" // Complex class definition

// Constructor
Complex::Complex(double realPart, double imaginaryPart) 
   : real{realPart}, imaginary{imaginaryPart} {}

// addition operator
Complex Complex::operator+(const Complex& operand2) const {
   return Complex{real + operand2.real, imaginary + operand2.imaginary};
} 

// subtraction operator
Complex Complex::operator-(const Complex& operand2) const {
   return Complex{real - operand2.real, imaginary - operand2.imaginary};
} 

// return string representation of a Complex object in the form: (a, b)
std::string Complex::toString() const {
   return std::format("({:.2f}, {:.2f})", real, imaginary);
} 



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
