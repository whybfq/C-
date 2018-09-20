/*********************************************************************************
  *@copyright (C) 2018 san All Rights Reserved
  *@file    atomic.cpp
  *@date    Sep 2018
  *@author  san
  *@CMAKE_CXX_STANDARD 17
  *@IDE:    Clion 2018.3
  *@OS:     macOS High Sierra 10.13.6
  *
  *@brief: C++11中提供了如下4种语义的互斥量（mutex）：
  * std：：mutex：独占的互斥量，不能递归使用。
  * std：：timed_mutex：带超时的独占互斥量，不能递归使用。
  * std：：recursive_mutex：递归互斥量，不带超时功能。
  * std：：recursive_timed_mutex：带超时的递归互斥量。
  *
  * 使用原子变量就不需要使用互斥量来保护该变量了，原子类型 std::stomic<T>
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
#include <condition_variable>
#include <chrono>
using namespace std;

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
