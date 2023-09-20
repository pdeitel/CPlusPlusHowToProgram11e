// Invoice.h
// Invoice class 
#include <format>
#include <stdexcept>
#include <string>

class Invoice {
public:
   // constructor
   Invoice(int partNumber, std::string partDescription, 
      int quantity, double price) {

      if (quantity <0) { // validate quantity
         throw std::invalid_argument{"Quantity must be>= 0"};
      }

      if (price <0.0) { // validate price
         throw std::invalid_argument{"Price per item must be>= 0"};
      }

      this->partNumber = partNumber;
      this->partDescription = partDescription;
      this->quantity = quantity;
      this->price = price;
   }

   // get part number
   int getPartNumber() const {
      return partNumber; 
   } 

   // get description
   std::string getPartDescription() const {
      return partDescription;
   } 

   // set quantity
   void setQuantity(int quantity) {
      if (quantity < 0) { 
         throw std::invalid_argument{"Quantity must be >= 0"};
      }

      this->quantity = quantity;
   } 

   // get quantity
   int getQuantity() const {
      return quantity;
   }

   // set price per item
   void setPrice(double price) {
      if (price < 0.0) { 
         throw std::invalid_argument{"Price per item must be>= 0"};
      }

      this->price = price;
   } 

   // get price per item
   double getPrice() const {
      return price;
   } 

   // return String representation of Invoice object

   std::string toString() const {
      return std::format(
         "{}: {:<2};  {}: {:<15};  {}: {:<4};  {}: {:>6.2f}",
         "Part #", getPartNumber(), "Description", getPartDescription(),
         "Quantity", getQuantity(), "Price", getPrice());
   } 
private:
   int partNumber; 
   std::string partDescription;
   int quantity;
   double price;
};



/**************************************************************************
 * (C) Copyright 1992-2018 by Deitel & Associates, Inc. and               *
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
