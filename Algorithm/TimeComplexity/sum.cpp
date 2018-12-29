#include <iostream>
#include <cmath>  // use pow
#include <ctime>

using std:: cout;
using std:: endl;

const double n = 1e6;

int sum1(int n) {  // the time complexity is n, is too large
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += int(pow(-1,i));
    }
    return sum;
}

int main(int argc, char* argv[]) {
    time_t s, e,sumtime;
    s = clock();
    cout << "sum:" << sum1(n)  << endl;

    e = clock();
    sumtime = e - s;
    cout << "time: " << sumtime  << endl;
}
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
