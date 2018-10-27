/*********************************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @file: Unexpected.cpp {-bor}
  * @brief: Exception sepcifications & unexcepted(),
  *         {-msc} (Doesn't terminate properly)
  *
  * @bug :
  * @author: sanner
  *
  * @CMAKE_CXX_STANDARD 14
  * @IDE: Clion 2018.2
  * @OS:  macOS 10.14
  *
  * @function_lists:
  *  1.  fg: void Swap(int A[] , int i, int j   -- exchange A[i] and A[j],dtype=int

     2.
  * @history:
     1.@date:
       @author:
       @modification: Original
     2.@date:
       @author:
       @modification:

**********************************************************************************/

#include <iostream>
#include <stdexcept>
#include <exception>

using namespace std;

class Up { };  // 异常类：保存附加信息提供个异常类

class Fit { };

//void g() {};  // Version 1
void g() { throw 47; };  // Version 2

void f(int i) throw(Up, Fit) {
    switch(i) {    // only two exceptions
        case 1: throw Up();
        case 2: throw Fit();
    }
    g();   //While use Version 2 may break the exception rules
}

void my_unexpected() {
    cout << "unexcepted exception thrown " << endl;
    exit(0);
}

int main(int argc, char const *argv[]) {
    set_unexpected(my_unexpected);   // Ignores return value
    for(int i = 1; i <= 3; ++i ){
        try {
            f(i);
        } catch(Up) {
            cout << "Up caught " << endl;
        } catch(Fit) {
            cout << "Fit caught " << endl;
        }
    }
}

