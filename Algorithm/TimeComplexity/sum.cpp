/*********************************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @license: GPL
  * @version:
  * @data:    Dec 2018
  * @file:    sum.cpp
  * @related:
  * @brief:   a good algorithm should be high efficiency, low storage
  *           compare the time between two sum algorithms
  * @bug :
  * @author:  sanner
  *
  * @CMAKE_CXX_STANDARD 14
  * @IDE:     Clion 2018.3
  * @OS:      macOS 10.14
  *
  * @function_lists:
  *  1. 
  * @Revision:
     1.@date:
       @author:
       @modification:
**********************************************************************************/
#include <iostream>
#include <cmath>  // use pow
#include <ctime>

using std:: cout;
using std:: endl;

const double n = 1e8; // you can change the number later

int sum1(int n) {  // the time complexity is n, is too large
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += int(pow(-1,i));
    }
    return sum;
}

int sum2(int n) {
    if(n % 2 == 0) return 0;
    else return -1;
}

int main(int argc, char* argv[]) {
    time_t s, e,sumtime;
    s = clock();
//    cout << "sum1:" << sum1(n) << endl;
    cout << "sum2:" << sum2(n) << endl;
    e = clock();
    sumtime = e - s;
    cout << "time: " << sumtime  << endl;
}
