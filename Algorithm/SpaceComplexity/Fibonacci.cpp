


    /*********************************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @license: GP
  * @version:
  * @data:    Dec 2018
  * @file:    sum.cpp
  * @related:
  * @reference: https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
  * @brief:     a good algorithm should be high efficiency, low storage, small O(f(n)),
  *             compare the time between two algorithms
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

using std:: cin;
using std:: cout;
using std:: endl;

// O(2^n)  O(n)
long long Fib1(int n) {
    if(n < 1) return -1;
    else if(n == 1 || n == 2) return 1;
    else return Fib1(n - 1) + Fib1(n - 2);
}

// O(n)  O(n)
long double Fib2(int n) { // Save previous values to avoid heavy double counting
    long double temp;
    if(n < 1) return -1;
    long double *a = new long double[n + 1];
    a[1] = a[2] = 1;
    for(int i = 3; i <= n; ++i) { // Dynamic planning 动态规划
        a[i] = a[i - 1] + a[i - 2];
        cout << a[i] << endl; // for test
    }
    temp = a[n];
    delete []a;
    return temp;
}

// the improvement of Fib(2)   O(n)  O(1)
long double Fib3(int n) {
    int i, s1, s2;
    if(n < 1) return -1;
    if(n == 1 || n == 2) return 1;
    s1 = 1;
    s2 = 1;
    for(i = 3; i <= n; ++i ) {
        s2 = s1 + s2;  // Twisting and adding
        s1 = s2 - s1;  // Record the previous item
    }
    return s2;
}

int main(int argc, char* argv[]) {
    time_t start, e, sumtime;
    int n;
    cin >> n;
    start = clock();
    // cout << fixed << serp
//    cout << "Fib1("<<n<<")=" << Fib1(n) << endl;
//    cout << "Fib2("<<n<<")=" << Fib2(n) << endl;
    cout << "Fib3("<<n<<")=" << Fib3(n) << endl;
    e = clock();
    sumtime = e - start;
    cout << "time: " << sumtime << endl;
}
