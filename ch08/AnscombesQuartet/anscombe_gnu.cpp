// anscombe.cpp
// Simple linear regression with Anscombe's Quartet, the 
// Boost Math library and plotting with gnuplot.
#include <boost/math/statistics/linear_regression.hpp>
#include <format>
#include <gnuplot.h>
#include <iostream>
#include <rapidcsv.h> 
#include <string>
#include <vector>

int main() {
   using boost::math::statistics::simple_ordinary_least_squares;
   using namespace std::string_literals; // for string object literals

   // set location to your user account's Documents folder
   std::string location{R"(./)"};

   // load Anscombe's Quartet using rapidcsv
   rapidcsv::Document quartet{location + "anscombe.csv"s};

   // get the Anscome's data
   auto x1{quartet.GetColumn<double>("x1")};
   auto y1{quartet.GetColumn<double>("y1")};
   auto x2{quartet.GetColumn<double>("x2")};
   auto y2{quartet.GetColumn<double>("y2")};
   auto x3{quartet.GetColumn<double>("x3")};
   auto y3{quartet.GetColumn<double>("y3")};
   auto x4{quartet.GetColumn<double>("x4")};
   auto y4{quartet.GetColumn<double>("y4")};

   // Use boost::math::statistics::simple_ordinary_least_squares to perform
   // simple linear regression on the x-y data samples  
   auto [intercept1, slope1] = simple_ordinary_least_squares(x1, y1);
   auto [intercept2, slope2] = simple_ordinary_least_squares(x2, y2);
   auto [intercept3, slope3] = simple_ordinary_least_squares(x3, y3);
   auto [intercept4, slope4] = simple_ordinary_least_squares(x4, y4);
   
   // vectors to store intercepts and slopes
   std::vector intercepts{intercept1, intercept2, intercept3, intercept4};
   std::vector slopes{slope1, slope2, slope3, slope4};

   // display slopes and intercepts for each dataset
   std::cout << std::format("{:>7}  {:>9}  {:>7}\n", 
      "Dataset", "Intercept", "Slope");
   for (int i{0}; i < 4; ++i) {
      std::cout << std::format("{:>7}  {:>9.5f}  {:>7.5f}\n", 
         i + 1, intercepts[i], slopes[i]);
   }

   // https://github.com/martinruenz/gnuplot-cpp
   // use gnuplot-cpp library's GnuplotPipe to send commands to gnuplot 
   GnuplotPipe pipe;

   // The rest of this program sends commands to gnuplot.

   // gnuplot can read data from a text file, such as anscombe.csv, and 
   // plot the data. The following command specifies the separator 
   // character used to separate the columns in each data row.
   // We use CSV data, so the separator is a comma.
   pipe.sendLine("set datafile separator ','");

   // gnuplot's "set terminal" command specifies the output file  
   // format and configuration. The command's arguments
   //   png size 1600,900 font ',30'
   // indicate that we'll output plots as PNG format images that are 
   // 1600 pixels wide and 900 pixels tall, using gnuplot's 
   // default font in 30pt size to label the plots. 
   pipe.sendLine("set terminal png size 1600,900 font ',30'");

   // gnuplot's "set pointsize" command sets the size of the 
   // dots plotted at each x-y coordinate.
   pipe.sendLine("set pointsize 5");

   // gnuplot's "unset key" command indicates that the plot should
   // not have a key describing the meanings of the plot elements. 
   pipe.sendLine("unset key");

   // gnuplot's "set xrange" command sets the x-axis range. 
   // We set every plot's x-axis range from 2 through 20 so 
   // all the plots have identical x-axes.
   pipe.sendLine("set xrange [2:20]");

   // gnuplot's "set yrange" command sets the y-axis range. 
   // We set every plot's y-axis range from 2 through 14 so all the 
   // plots have identical y-axes. Setting both the x- and y-axes 
   // identically for all four plots ensures that the dots and 
   // regression linesare plotted using the same scale, so you can 
   // see that the regression lines appear to be identical. 
   pipe.sendLine("set yrange [2:14]");

   // produce the four plots
   for (int i{0}; i < 4; ++i) {
      // gnuplot's "set output" command sets the PNG image's filename
      pipe.sendLine(std::format("set output '{}dataset{}.png'", 
         location, i + 1));

      // gnuplot's "set title" command sets the title above the plot
      pipe.sendLine(std::format("set title 'Dataset {}'", i + 1));

      // gnuplot's "plot" command creates a plot. 
      //
      // The following is a sample plot command sent to gnuplot 
      //    plot 'anscombe.csv' using 1:2 with points pointtype 7, 0.5*x+3.0 linewidth 3 linecolor rgb 'red'
      //
      // The following are the plot command's arguments:
      // 'anscombe.csv'
      //    The file containing the data to plot.
      //
      // using {}:{}
      //   Specifies the start and end column numbers to plot. We 
      //   substitute integer values for the {} placeholders. 
      //   For example, 0:1 indicates that the x-y coordinates for 
      //   the plot are in columns 0 and 1 of anscombes.csv.
      //
      // with points
      //   Gnuplot will display individual x-y data points.
      //
      // pointtype 7,
      //   Display points gnuplot point type 7 (circular dots).
      //
      // {:f}*x+{:f}
      //   The calculation mx + b used to calculate the regression line's
      //   points. The first {:f} is replaced with the slope (m) and 
      //   the second {:f} is replaced with the intercept (b).
      //
      // linewidth 3
      //   Specifies the regression line's thickness should be 3pt.
      //
      // linecolor rgb 'red'
      //   Specifies that lines should be displayed in red.
      // 
      // The following statement builds the plot command.
      std::string plotCommand{
         std::format("plot '{}anscombe.csv' ", location) + 
         std::format("using {}:{} ", i * 2 + 1, i * 2 + 2) +
         "with points "s + 
         "pointtype 7, "s +
         std::format("{:f}*x+{:f} ", slopes[i], intercepts[i]) + 
         "linewidth 3 linecolor rgb 'red'"
      };
      std::cout << plotCommand << "\n";
      pipe.sendLine(plotCommand);
   }
}
/**************************************************************************
* (C) Copyright 1992-2021 by Deitel & Associates, Inc. and               *
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
