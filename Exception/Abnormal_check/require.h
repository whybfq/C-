//
// Created by HangYi Wang on 7/27/18.
// 异常处理机制，为处理各种错误提供了一种有效的方法而不是中止程序的运行。
// 每个函数包含std因为声明不对时，编译器不会包含namespace中std中标准的C库函数。这样将不能使用std而
// 导致编译错误。局部声明允许require.h同正确的和不正确的库一起工作，它
// 不会为了包含了这个头文件的人打开std

#ifndef JULY_REQUIRE_H
#define JULY_REQUIRE_H

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>

inline void require(bool requirement,
        const std::string& msg = "Requirement failed "){
    using namespace std;
    if(!requirement){
        fputs(msg.c_str(), stderr);
        fputs("\n", stderr);
        exit(1);
    }
}

inline void requireArgs(int argc, int args,      //argc包括了总是作为第一个参数的程序名，所以argc比实际的命令行参数数目多一
        const std::string& msg = "Must use %d arguments ") {
    using namespace std;
    if(argc != args + 1 ) {
        fprintf(stderr, msg.c_str(), args);
        fputs("\n", stderr);
        exit(1);
    }
}

inline void requireMinArgs(int argc, int minArgs,
        const std::string& msg = "Must use at least %d arguments") {
    using namespace std;
    if(argc < minArgs + 1) {
        fprintf(stderr, msg.c_str(), minArgs);
        fputs("\n", stderr);
        exit(1);
    }
}

inline void assure(std::ifstream& in,
        const std::string& filename = "") {
    using namespace std;
    if(!in) {
        fprintf(stderr, "Could not open file %s \n ", filename.c_str() );
        exit(1);
    }
}

inline void assure(std::ofstream& out,
        const std::string& filename = "") {
    using namespace std;000
    if(!out) {
        fprintf(stderr, "Could not open file %s \n", filename.c_str() );
        exit(1);
    }
}
#endif //JULY_RE QUIRE_H
