/*********************************************************************************
  *@copyright (C) 2018 san All Rights Reserved
  *@file    recursive_mutex.cpp
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
  * 这个例子[1]运行起来后就会发生死锁，因为在调用both时获取了互斥量，
  * 之后再调用mul又要获取相同的互斥量，但是这个互斥量已经被当前线程获取了,
  * 无法释放，这时就会发生死锁。要解决这个死锁的问题，一个简单的办法就是用递归锁：std：：recursive_mutex，
  * 它允许同一线程多次获得互斥量，
  *
  *@function_lists:
  *  1. func() Set time to let thread join and leave

  *@warning: 需要注意的是尽量不要使用递归锁好，主要原因如下:
  *         1.需要用到递归锁定的多线程互斥处理往往本身就是可以简化的，允许递归互斥很容易放纵复杂逻辑的产生，
  *         从而导致一些多线程同步引起的晦涩问题。递归锁比起非递归锁，效率会低一些。
  *         2.递递归锁虽然允许同一个线程多次获得同一个互斥量，可重复获得的最大次数并未具体说明，
  *         一旦超过一定次数，再对lock进行调用就会抛出std::system错误。
  *@history:
     1.Date:
       Author: san
       Modification: use rescursive::
       In struct Complex:
         change mutex mutex1 to recursive_mutex mutex2
         change all lock_guard<mutex> to lock_guard<recursive_mutex>
**********************************************************************************/

#include <thread>
#include <iostream>
#include <mutex>
#include <chrono>
using namespace std;

struct Complex {
//    mutex mutex1;
    recursive_mutex mutex2;

    int i;
    Complex() : i(0) { }
    void mul(int x){
        lock_guard<recursive_mutex> lock(mutex);
        i *= x;
    }
    void div(int x) {
        lock_guard<recursive_mutex> lock(mutex);
        i /= x;
    }
    void both(int x, int y){
        lock_guard<recursive_mutex> lock(mutex);
        mul(x);
        div(y);
    }
};



int main()
{
    Complex complex;
    complex.both(32, 23);  // 因为同一线程可以多次获取同一互斥量，不会发生死锁
}

