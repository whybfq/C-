/*********************************************************************************
  *Author:  San
  *IDE: Clion 2018.3
  *OS:  macOS High Sierra 10.13.6
  *Date:  August 6,2018
  *Description:  A sample example of the deadclock
  *Bug:
  *Function List:
     1.
  *History:
   1.Date:
     Author:
     Modification:
**********************************************************************************/

#include <iostream>
#include <fstream>
#include <thread>
#include <stdio.h>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    std::mutex m1;
    std::mutex m2;
    thread t1([&m1, &m2] {
        cout << "1. Acquiring m1." << endl;
        m1.lock();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        cout << "1. Acquiring m2" << endl;
        m2.lock();
    });
    thread t2([&m1, &m2] {
        cout << "2. Acquiring m2" << endl;
        m2.lock();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        cout << "2. Acquiring m1" << endl;
        m1.lock();
    });

    t1.join();
    t2.join();
}

Output:
2. Acquiring m21. Acquiring m1.

1. Acquiring m2
2. Acquiring m1


/*modify History2:
   1.Date: Aug 6, 2018
     Author: San
     Modification: Easier
*/
int main() {
    std::mutex m1;
    thread t1([&m1] {
        cout << "1. Acquiring m1." << endl;
        m1.lock();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    });
    thread t2([&m1] {
        cout << "2. Acquiring m1" << endl;
        m1.lock();
    });

    t1.join();
    t2.join();
}

Output:
1. Acquiring m1.2. Acquiring m1

/*modify History 3:
   1.Date: Aug 6, 2018
     Author: San
     Modification: more clearly
*/
int main() {
    mutex m1;

    thread t3( [&m1] {
        cout << "This is threadt3, " ;
        cout << &m1  << endl;
    });


    thread t1([&m1] {
        cout << "1. Acquiring m1." << endl;
        m1.lock();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    });
    thread t2([&m1] {
        cout << "2. Acquiring m1" << endl;
        m1.lock();
    });


    t1.join();
    t2.join();
    t3.join();  //按照说明的顺序已经先执行
}
This is threadt3, 1. Acquiring m1.2. Acquiring m10x7ffee89ef988
