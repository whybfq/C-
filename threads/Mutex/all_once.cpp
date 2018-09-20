/*********************************************************************************
  *@copyright (C) 2018 san All Rights Reserved
  *@file    all_once.cpp
  *@date    Sep 2018
  *@author  san
  *@CMAKE_CXX_STANDARD 17
  *@IDE:    Clion 2018.3
  *@OS:     macOS High Sierra 10.13.6
  *
  *@brief: the basic use of call_once & once_flag
  *@function_lists:
  *  1.

  *@warning:
  *@history:
     1.Date:
       Author:
       Modification:
**********************************************************************************/

#include <thread>
#include <iostream>
#include <mutex>
#include <atomic>
//#include <condition_variable>
#include <chrono>
using namespace std;

once_flag flag;
void do_once() {
    call_once(flag, [](){ cout << "Called once " << endl; });
}

struct Counter {  // 用mutex实现的计时器
    int value;
    std:: mutex mutex2;
    void increment(){
        lock_guard<mutex> lock(mutex);
        ++value;
    }
    void decrement(){
        lock_guard<mutex> lock(mutex);
        --value;
    }
    int get() {
        return value;
    }
};

struct AtomicCounter {    //原子变量实现的计时器
    atomic<int> value;
    void increment() {
        ++value;
    }
    void decrement() {
        --value;
    }
    int get() {
        return value.load();
    }
};

int main() {
    thread t1(do_once);
    thread t2(do_once);
    thread t3(do_once);
    t1.join();
    t2.join();
    t3.join();
}
