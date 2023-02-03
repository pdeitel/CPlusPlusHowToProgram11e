// Fig. 21.1: LinearSearch.cpp
// Linear search of an array.
#include <format>
#include <iostream>
#include <array>

// compare key to every element of array until location is     
// found or until end of array is reached; return location of  
// element if key is found or -1 if key is not found           
template <typename T, size_t size>                           
int linearSearch(const std::array<T, size>& items, const T& key) {
   for (int i{0}; i < items.size(); ++i) {
      if (key == items[i]) { // if found,                    
         return i; // return location of key                 
      }                                                      
   }                                                         
                                                       
   return -1; // key not found                               
}

int main() {
   std::array<int, 100> arrayToSearch; 

   for (int i{0}; i < arrayToSearch.size(); ++i) {
      arrayToSearch[i] = 2 * i; // create some data
   }

   std::cout << "Enter integer search key: ";
   int searchKey; // value to locate 
   std::cin >> searchKey;

   // attempt to locate searchKey in arrayToSearch
   int element{linearSearch(arrayToSearch, searchKey)};

   // display results
   if (element != -1) {
      std::cout << std::format("Found value in element {}\n", element);
   }
   else {
      std::cout << "Value not found\n";
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
