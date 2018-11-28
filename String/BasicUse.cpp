/*********************************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @license: GPL
  * @version:
  * @data:    Nov 2018
  * @file:    BasicUse.cpp
  * @related:
  * @brief:   some basic uses in C++ string
  * @bug :
  * @author:  sanner
  *
  * @CMAKE_CXX_STANDARD 14
  * @IDE:     Clion 2018.2
  * @OS:      macOS 10.14
  *
  * @function_lists:
  *  1.  void Swap(int A[] , int i, int j   -- exchange A[i] and A[j],dtype=int
     2.  void swap1(T&a,T&b)                -- exchange a and b
  * @Revision:
     1.@date:
       @author:
       @modification:
**********************************************************************************/

#include <iostream>
using namespace std;

int  main(int argc, char* argv[]) {
    string str("100");
    string str2("200");
    char cstr[3];
    str.append(str2);
    cout << str.c_str() << endl;  // 100200
    str.assign("123");   // reassign
    cout << str.c_str()  << endl;  // output in C style  123
    cout << str.at(2)  << endl;  // 3
    str.copy(cstr,2);    // Copy 2 characters to CSTR
    cstr[2] = '\0';      // Appended Terminator
    cout << cstr  << endl;  // 12
    cout << str.data()  << endl;  // Convert to character array
}
