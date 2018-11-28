/*********************************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @license: GPL
  * @version:
  * @data:    Nov 2018
  * @file:    BasicUse.cpp
  * @related:
  * @brief:   some basic uses in C++ string class
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
    cout << str.data() << endl;  // Convert to character array  123
    cout << str.empty() << endl; // test the string is empty  0
    cout << str.c_str() << endl; // Convert to string in C style  123
    str.erase(2);       // Delete all characters starting from the second position
    cout << str.c_str() << endl;  // 12
    cout << str.find("2",0)  << endl; // look for the string "2" from the first position  1
    str.assign("1234567890");   // reassign
    cout << str.find_first_not_of("234",1) << endl; // 4 Find the first character that does not appear in "234"
    cout << str.c_str()  << endl; // return the string in C style
    str.insert(2,"ww");  // insert the string "ww" from the second position
    cout << str.c_str() << endl; // return the string in C style
    cout << str.max_size() << endl; // Calculate the maximum possible size in a string  18446744073709551599
    cout << str.size() << endl; // the length of the string  12
    cout << str.length() << endl; // the length of the string  12
    cout << str.substr(1,3).c_str() << endl; // substring  2ww
    cout << str.c_str() << endl;  // 12ww3456890
    cout << str.replace(1,4,"bbbbbbb").c_str() << endl;  //1bbbbbbb4567890
    str.resize(10);  // reassign 10 bytes of space
    cout << str.max_size() << endl; // 18446744073709551599
    str.swap(str2);  // swap with str2
    cout << str.c_str() << endl; // 200
}
