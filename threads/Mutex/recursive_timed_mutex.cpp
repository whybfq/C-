/*********************************************************************************
  *@copyright (C) 2018 san All Rights Reserved
  *@file    recursive_timed_mutex.cpp
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
  * recursive_timed_mutex比timed_mutex多了递归锁功能
  * timed_mutex比mutex多了两个超时获取锁的接口: try_lock_for and try_lock_until
  * use while() loop to get 互斥量
  *@function_lists:
  *  1. func() Set time to let thread join and leave

  *@warning:
  *@history:
     1.Date:
       Author:
       Modification:
**********************************************************************************/

#include <thread>
#include <iostream>
#include <mutex>
#include <chrono>
using namespace std;

timed_mutex mutex1;
void work() {
    chrono:: milliseconds timeout(100);
    while(1){
        if(mutex1.try_lock_for(timeout)) {
            cout << this_thread:: get_id() << ": do work wthe mutex" << endl;;
            chrono:: milliseconds sleepDuration(250);
            this_thread:: sleep_for(sleepDuration);
            mutex1.unlock();
            this_thread:: sleep_for(sleepDuration);
        } else {
            cout << this_thread:: get_id() << " do work without mutex " << endl;
            chrono:: milliseconds sleepDuration(100); // 如果超时还没有获取到锁时就休眠100毫秒，再继续获取超时锁
            this_thread:: sleep_for(sleepDuration);
        }
    }
}

int main()
{
   thread t1(work);
   thread t2(work);
   t1.join();
   t2.join();
}
