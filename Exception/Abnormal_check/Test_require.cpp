
/*********************************************************************************
  *Author:  Sanner
  *IDE: Clion 2018.3
  *OS:  macOS High Sierra
  *Processor: 2.2 GHz Intel Core i7
  *Date:  July 27,2018
  *Description:  现在几乎总是使用内联函数代替预处理宏，在标准C预处理器（通过继承也是C++预处理器）里
  *              使用3个特征时例外：字符串定义，字符串拼接和标志黏贴
  *Others:    Test require.cpp
  *Function List:
     1.

  *History:  //modify history list, every record should consist the date, Revision and modification content introduction
     1.Date: July 27,2018
       Author: sanner
       Modification: Original
     2.Date:
       Author: sanner
       Modification:

**********************************************************************************/

#include "cmake-build-debug/require.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
    int i = 1;
    require(i, "value must be nonzero");
    requireArgs(argc, 1);
    requireMinArgs(argc, 1);
    ifstream in(argv[1]);
    assure(in, argv[1]);  // Use the file name
    ifstream nofile("nofile.xxx");
    // Fails:
    // ! assure(nofile);     // The default argument
    ofstream out("tmp.txt");
    assure(out);
    return 0;
}
