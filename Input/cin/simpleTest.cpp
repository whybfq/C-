/*********************************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @license: GPL
  * @version:
  * @data:    Nov 2018
  * @file:
  * @related: http://www.sohu.com/a/120517509_427866
  * @brief:   The aim of this file is to test cin()
  * @bug :
  * @author:  sanner
  *
  * @CMAKE_CXX_STANDARD 14
  * @IDE:     Clion 2018.2
  * @OS:      macOS 10.14
  *
  * @function_lists:
  *  1.       void inputTest()    --   test cin()
  * @Revision:
     1.@date:
       @author:
       @modification: Original
     2.@date:
       @author:
       @modification:
**********************************************************************************/
#include <iostream>
using std::cin ;
using std::cout;
using std::string;
using std::endl;

void testInput() {
    string str;
    cout << "cin test " << endl;
    cin >> str;

    cout << str << endl;
    cin.sync();
    cin >> str;
    cout << str << endl;
}

//接收一定长度的字符串 cin.get(字符数组名，接收长度，结束符)，结束符为可选参数，默认为 Enter，
//可以接受 Space 、Tab，对于结束符的处理要注意，结束符并不会丢掉
void inputTest2() {
    char ch1,ch2;
    cout << "input two strings: " << endl;
    cin.get(ch1);
    cin.get(ch2);
    cout << "the two strings are: " << endl; 
    cout << ch1 << endl;
    cout << ch2 << endl;
    cout << (int)ch1 << " " << (int)ch2 << endl;  // output ASCII 值
}

int main(int argc, char* argv[]) {
    inputTest2();
}
