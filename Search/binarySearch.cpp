/*********************************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @license: GPL
  * @version:
  * @data:    Nov 2018
  * @file:    BasicUse.cpp
  * @param nums: The integer array.
  * @param target: Target to find.
  * @return: The first position of target. Position starts from 0.
  * @related:
  * @brief:   some basic uses in C++ string
  * @bug :
  * @author:  sanner
  *
  * @CMAKE_CXX_STANDARD 14
  * @IDE:     Clion 2018.2
  * @OS:      macOS 10.14
  *
  * @function_lists:
  *  1.  void Swap(int A[] , int i, int j   -- exchange A[i] and A[j],dtype=int
     2.  void swap1(T&a,T&b)                -- exchange a and b
  * @Revision:
     1.@date:
       @author:
       @modification:
**********************************************************************************/
    int binarySearch(vector<int> &A, int target) {
        // write your code here
        if(A.size() == 0) return -1;

        int start = 0;
        int end = int(A.size() - 1);
        int mid;

        while(start + 1 < end) {
            mid = start + (end - start) / 2;
            if(A[mid] == target) end = mid;
            else if(A[mid] < target) start = mid;
            else if(A[mid] > target) end = mid;
        }

        if(A[start] == target) return start;
        if(A[end] == target) return end;

        return -1;
    }
