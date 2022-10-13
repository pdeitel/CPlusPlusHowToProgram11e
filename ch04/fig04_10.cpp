// fig04_10.cpp
// Logical operators.
#include <fmt/format.h>
#include <iostream>
using namespace std;

int main() {
   // create truth table for && (logical AND) operator
   cout << "Logical AND (&&)\n"
      << fmt::format("false && false: {}\n", false && false)
      << fmt::format("false && true: {}\n", false && true)
      << fmt::format("true && false: {}\n", true && false)
      << fmt::format("true && true: {}\n\n", true && true);

   // create truth table for || (logical OR) operator
   cout << "Logical OR (||)\n"
      << fmt::format("false || false: {}\n", false || false)
      << fmt::format("false || true: {}\n", false || true)
      << fmt::format("true || false: {}\n", true || false)
      << fmt::format("true || true: {}\n\n", true || true);

   // create truth table for ! (logical negation) operator
   cout << "Logical negation (!)\n"
      << fmt::format("!false: {}\n", !false)
      << fmt::format("!true: {}\n", !true);
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
 *************************************************************************/
