// fig04_17.cpp
// Compound-interest example with boost::multiprecision. 
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <fmt/format.h> // in C++20, this will be #include <format>
#include <iostream>
#include "decimalformatter.h" 

using namespace std;
using boost::multiprecision::cpp_dec_float_50;

int main() {
   // fixed-point formatting diplays unformatted floating-point and  
   // cpp_dec_float_50 values with six digits of precision by default
   cout << fixed;

   cpp_dec_float_50 principal{"1000.00"}; // initial amount
   cpp_dec_float_50 rate{"0.05"}; // interest rate

   cout << fmt::format("Initial principal: {:>7}\n", principal)
      << fmt::format("    Interest rate: {:>7}\n\n", rate);

   // display headers
   cout << fmt::format("{}{:>20}   {}\n",
      "Year", "Amount on deposit", "Unrounded Amount");

   // calculate amount on deposit for each of ten years
   for (int year{1}; year <= 10; ++year) {
      cpp_dec_float_50 amount{principal * pow(1 + rate, year)};
      cout << fmt::format("{:>4}{:>20}   ", year, amount);

      // use boost's cpp_dec_float_50 output (<<) operator to  
      // display amount with C++'s default precision (six digits)
      cout << amount << '\n';
   }
}

/**************************************************************************
 * (C) Copyright 1992-2023 by Deitel & Associates, Inc. and               *
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
