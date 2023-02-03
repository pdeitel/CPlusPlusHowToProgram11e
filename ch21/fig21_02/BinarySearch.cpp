// Fig 21.2: BinarySearch.cpp
// Binary search of an array.
#include <algorithm> 
#include <array>
#include <format>
#include <iostream>
#include <random> 

// display array elements from index low through index high
template <typename T, size_t size>
void displayElements(const std::array<T, size>& items, 
   size_t low, size_t high) {

   for (size_t i{0}; i < items.size() && i < low; ++i) {
      std::cout << "   "; // display spaces for alignment 
   }

   for (size_t i{low}; i < items.size() && i <= high; ++i) {
      std::cout << std::format("{} ", items[i]); // display element
   }

   std::cout << "\n";
} 

// perform a binary search on the data                             
template <typename T, size_t size>                                
int binarySearch(const std::array<T, size>& items, const T& key) {
   int low{0}; // low index of elements to search                 
   int high{static_cast<int>(items.size()) - 1}; // high index    
   int middle{(low + high + 1) / 2}; // middle element            
   int location{-1}; // key's index; -1 if not found              

   do { // loop to search for element                             
      // display remaining elements of array to be searched        
      displayElements(items, low, high);                         
                                                                   
      // output spaces for alignment                               
      for (int i{0}; i < middle; ++i) {                          
         std::cout << "   ";                                             
      }

      std::cout << " * \n"; // indicate current middle
   
      // if the element is found at the middle                
      if (key == items[middle]) {                             
         location = middle; // location is the current middle 
      }                                                       
      else if (key < items[middle]) { // middle is too high   
         high = middle - 1; // eliminate the higher half      
      }                                                       
      else { // middle element is too low                     
         low = middle + 1; // eliminate the lower half        
      }                                                       
   
      middle = (low + high + 1) / 2; // recalculate the middle
   } while ((low <= high) && (location == -1));               

   return location; // return location of key
} 

int main() {
   // use the default random-number generation engine to produce
   // uniformly distributed pseudorandom int values from 10 to 99
   std::random_device rd; // used to seed the default_random_engine
   std::default_random_engine engine{rd()}; // rd() produces a seed
   std::uniform_int_distribution<int> randomInt{10, 99};

   std::array<int, 15> arrayToSearch; // create 15-element array

   // fill arrayToSearch with random values
   for (int &item : arrayToSearch) {
      item = randomInt(engine);
   }

   std::sort(arrayToSearch.begin(), arrayToSearch.end()); 

   // display arrayToSearch's values
   displayElements(arrayToSearch, 0, arrayToSearch.size() - 1); 

   // get input from user
   std::cout << "\nPlease enter an integer value (-1 to quit): ";
   int searchKey; // value to locate 
   std::cin >> searchKey; // read an int from user
   std::cout << "\n";

   // repeatedly input an integer; -1 terminates the program
   while (searchKey != -1) {
      // use binary search to try to find integer
      int position{binarySearch(arrayToSearch, searchKey)};

      // return value of -1 indicates integer was not found
      if (position == -1) {
         std::cout << std::format("{} was not found.\n", searchKey);
      }
      else {
         std::cout << std::format("{} was found in position {}.\n",
            searchKey, position);
      }

      // get input from user
      std::cout << "\n\nPlease enter an integer value (-1 to quit): ";
      std::cin >> searchKey; // read an int from user
      std::cout << "\n";
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
