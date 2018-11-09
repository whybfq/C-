/*********************************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @license: GPL
  * @version:
  * @data:    Nov 2018
  * @file:    Testflush.cpp
  * @related: https://en.cppreference.com/w/cpp/io/manip/flush
  * @brief:   
  * @bug :    
  * @author:  sanner
  *
  * @CMAKE_CXX_STANDARD 14
  * @IDE:     Clion 2018.2
  * @OS:      macOS 10.14
  *
  * @function_lists:
  *  1. flush() :
  *     template<class CharT, class Traits >
        std::basic_ostream<CharT , Traits>& flush(std::basic_ostream<CharT, Traits>& os);
  * @Revision:
     1.@date:
       @author:
       @modification: 
     2.@date:
       @author:
       @modification:
**********************************************************************************/
#include <iostream>
#include <chrono>

template<typename Diff>
void log_progress(Diff d)
{
    std::cout << "..("
              << std::chrono::duration_cast<std::chrono::milliseconds>(d).count()
              << " ms).." << std::flush;
}

int main(int argc, char* argv[]) {
    volatile int sink = 0;

    auto t1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10000; ++j) {
            for (int k = 0; k < 20000; ++k) {
                sink += k * j;
            }
        }
        auto now = std::chrono::high_resolution_clock::now();
        log_progress(now - t1);
    }
}

Output:
.. (466 ms).... (921 ms).... (1359 ms).... (1794 ms).... (2229 ms)..
