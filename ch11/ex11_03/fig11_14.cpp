// fig11_14.cpp
// HugeInteger test program.
#include <iostream>
#include "HugeInteger.h"

int main() {
   HugeInteger n1{7654321};
   HugeInteger n2{7891234};
   HugeInteger n3{"99999999999999999999999999999"};
   HugeInteger n4{"1"};
   HugeInteger n5{};

   std::cout << "n1: " << n1 << "\nn2: " << n2 << "\nn3: " << n3
      << "{}\nn4: " << n4 << "\nn5: " << n5 << "\n\n";

   n5 = n1 + n2;
   std::cout << n1 << " + " << n2 << " = " << n5 << "\n\n";

   std::cout << n3 << " + " << n4 << " = " << (n3 + n4) << "\n\n";

   n5 = n1 + 9;
   std::cout << n1 << " + " << 9 << " = " << n5 << "\n\n";

   n5 = n2 + "10000";
   std::cout << n2 << " + " << "10000" << " = " << n5 << "\n";
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
