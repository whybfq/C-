/*********************************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @license: GPL
  * @version:
  * @data:    Jan 2019
  * @file:    SettingAccuracy.cpp
  * @related:
  * @reference:
  * @brief:
  * @bug :
  * @author:  sanner
  *
  * @CMAKE_CXX_STANDARD 14
  * @IDE:     Clion 2018.3
  * @OS:      macOS 10.14
  *
  * @function_lists:
  *  1.       setfill(char c)       -->    Set the padding character in C
  *  2.       setprecision(int n)   -->    Set the numerical precision expressed in n
  *  3.       setw(int n)           -->    Set the field width in n
  * @Revision:
     1.@date:
       @author:
       @modification:
**********************************************************************************/
#include <iostream>
#include <iomanip>
#include <cmath>

using std:: cin;
using std:: cout;
using std:: endl;

int main(int argc, char* argv[]) {
    double d = sqrt(2.0);
    cout << "Precision setting： " << endl;
    for (int i = 0; i < 5; ++i) {
//        cout << std::fixed; // add this, the precison means number of digits after the decimal point
        cout << std::setprecision(i) << d << endl; // different precision
    }
    cout << "current precision: " << cout.precision()  << endl; // the precision including all digits
    cout << "current width:" << cout.width() << endl;
//    cout << std::left;   // align left， default is right alignment
    cout << std::setw(6) << d << endl;  //  1.414 There is a space on the far left to fill six characters
    cout << "current fill character" << endl;
    cout << std::setfill('*') <<  std::setw(10) << d  << endl;
    // The setfill() function can be inserted directly into the strem, the defaut is right alignment
}


Output:
Precision setting： 
1
1
1.4
1.41
1.414
current precision: 4
current width:0
 1.41
current fill character
*****1.414
