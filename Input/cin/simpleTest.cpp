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

void testCin() { //根据 cin>>sth 中 sth 的变量类型读取数据，这里变量类型可以为 int，float,char,char*,string 等诸多类型。这一输入操作，在遇到结束符（Space、Tab、Enter）就结束，且对于结束符，并不保存到 sth 中
    char ch1[10],ch2[20];
    cout << "please input two strings: " << endl;
    cin >> ch1;
    cin >> ch2;
    cout << "two strings are: " << endl;
    cout << ch1 << endl;
    cout << ch2 << endl;
}

void testGetline() { // istream is,string str, 结束符
    string str;
    cout << "cin test " << endl;
    getline(cin,str,'a'); // need to add #include <string> string库函数下,遇到a结束
    cout << str << endl;
}

void testGets() {  //( char *ch )
    char ch[10];
    cout << "please input the content of char* : " << endl;
    gets(ch); // 注意输入的字符串长度不要大于n，否则会报错。同样gets()对空格也不敏感。
    cout << ch << endl;
}

void inputcinget() {  // ch=cin.get  ==> cin.get(char ch)
    char ch1,ch2[10];
    cout << "input two strings: " << endl;
    cin.get(ch1);
    cin.get(ch2,6);
    cout << "the two strings are: " << endl;
    cout << ch1 << endl;
    cout << ch2 << endl;
    cout << (int)ch1 << " "  << endl;  // output the value of ASCII
}

void testcingetline() { // cin.getline() 字符数组名，接收长度，结束符
    char ch1,ch2[10];
    cout << "please input the string : " << endl;
    cin.getline(ch2,6); //在不遇到结束符的情况下，最多可接收 6-1=5 个字符到 ch2 中
    cin >> ch1;
    cout << ch2 << endl;
    cout << ch1 << endl << (int)ch1 << endl;
}

int main(int argc, char* argv[]) {
    testCin();
//    testcingetline();
//    testGetline();
//    testGets();
}

