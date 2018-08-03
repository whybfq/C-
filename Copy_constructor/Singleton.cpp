
/*********************************************************************************
  *Author:  Sanner
  *IDE: Clion 2018.3
  *OS:  macOS High Sierra 10.13.6
  *Processor: 2.2 GHz Intel Core i7
  *Graphics: Intel Iris Pro 1536 MB
  *Date:  July 24,2018
  *Description:   Static member of same type, ensures that only for object of this type exists.
                  Also referred to as the "singleton" pattern

  *Others:         因为静态成员的初始化方法，所以可以把一个静态数据成员放到类内部，这样
                   Egg类只有一个唯一的对象存在，可以访问那个对象，但不能产生新的Egg对象
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

namespace s = std;  //alias it
using namespace s;
ofstream out("test.out");

class Egg {
public:
    static Egg* instance() { return & e;  }
    int val() const { return i; }
private:
    static Egg e;
    int i;
    Egg(int ii) : i(ii) { }
    Egg(const Egg&);   //prevent copy-construction  //如果去掉copy-construction
                         //  then could use
                        // Egg e = *Egg::instance();   or
                        //    Egg e2(*Egg::instance());  to create an object
};

//E的初始化出现在类的声明完成之后，compilier已有足够的信息为对象分配空间并调用构造函数
//Egg Egg::e = 100;
Egg Egg::e(420);
int main() {
    out << "inside main() " << endl;
//    Egg e = *Egg::instance();
//    Egg e2(*Egg::instance());
    cout << Egg::instance()->val() << endl;
    out << "leaving main() " << endl;
}


