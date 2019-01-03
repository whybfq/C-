/*********************************************************************************
  *Author:  San
  *IDE:   Clion 2018.3
  *OS:    macOS High Sierra 10.14
  *Date:  Aug,2018
  *Description:  the basic use of atexit()
  *
  *Bug:
  *Function List:
  *  1.
  *History:
   1.Date:
     Author:
     Modification:
**********************************************************************************/

#include <cstdlib>
#include <iostream>
using namespace std;

void OpenDevice() { cout << "device is opended. " << endl; }
void ResetDevice() { cout << "device stat is reset. " << endl; }
void CloseDevice() { cout << "device is closed. " << endl; }


int main(int argc, char const *argv[]) {   // 注册函数调用次序与其注册顺序相反
    atexit(CloseDevice);
    atexit(ResetDevice);
    OpenDevice();
//    exit(0;)
}


Output:
device is opended. 
device stat is reset. 
device is closed.
