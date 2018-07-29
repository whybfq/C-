
/*********************************************************************************
  *Author:  Sanner
  *IDE: Clion 2018.3
  *OS:  macOS High Sierra 10.13.6
  *Processor: 2.2 GHz Intel Core i7
  *Graphics: Intel Iris Pro 1536 MB
  *Date:  July 24,2018
  *Description: 程序输出并不像期望的那样。C语言中默认的按位拷贝的方式没有达到预期的效果。
  *             C++中对象比一组比特位复杂的多。因为对象具有含义，这个含义也许不能由它具有的位拷贝很好的反映。

  *Others:      And this is the reason why we need copy-constructor
  *Function List:
     1.

  *History:  //modify history list, every record should consist the date, Revision and modification content introduction
     1.Date:
       Author:
       Modification:
     2.Date:
       Author:
       Modification:

**********************************************************************************/

#include <iostream>
#include <fstream>
#include "./cmake-build-debug/Dependency2.h"
namespace s = std;  //alias it
using namespace s;
ofstream out("test.out");

class HowMany {
public:
    HowMany() { ++objectCount; }
    static void print(const string& msg = " " )
    {
        if(msg.size() != 0) out << msg << ": ";
        out << "objectCount = " << objectCount << endl;
    }
    ~HowMany(){
        --objectCount;
        print("~HowMany() ");
    }
private:
    static int objectCount;
};

int HowMany::objectCount = 0;

HowMany f(HowMany a) {          //Pass and return by value:
    a.print("a argument inside f() : ");
    return a;
}     //局部对象出了其范围，析构函数就被调用，析构函数使objectCount 减小

int main(int argc, char const *argv[]) {
    HowMany h;
    HowMany::print("after construcion of h ");
    HowMany h2 = f(h);  //对象h存在于函数框架之外，同时在函数体内又增加了一个对象，这个对象是通过传值方式传入的对象的拷贝。
                        // 然而，参数的传递是使用C的原始的位拷贝的概念，但C++ HowMany类需要真正的初始化来维护它的完整性。
                        // 所以，默认的位拷贝不能达到预期的效果。 h2对象的创建也是用位拷贝产生。
    HowMany::print("after call to f() ");
   return 0;
}

Output: (In test.out)
after construcion of h : x = 1
a argument inside f() : : x = 1
~HowMany() : x = 0
after call to f() : x = 0
~HowMany() : x = -1
~HowMany() : x = -2

