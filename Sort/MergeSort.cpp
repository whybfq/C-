/*********************************************************************************
  * @copyright (C)  2018 sanner All Rights Reserved
  * @license: GPL
  * @version:
  * @data:    Nov 2018
  * @file:    MergeSort.c
  * @related: http://www.cnblogs.com/eniac12/p/5329396.html
  * @brief:   This file contains the method of merge sort
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
**********************************************************************************
归并排序(Merge Sort)
归并排序：1945年由冯·诺伊曼首次提出。
归并排序的实现分为递归实现与非递归(迭代)实现。递归实现的归并排序是算法设计中分治策略的典型应用，我们将一个大问题分割成小问题分别解决，
然后用所有小问题的答案来解决整个大问题。非递归(迭代)实现的归并排序首先进行是两两归并，然后四四归并，然后是八八归并，一直下去直到归并了整个数组。
归并排序算法主要依赖归并(Merge)操作。归并操作指的是将两个已经排序的序列合并成一个序列的操作，归并操作步骤如下：

申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列
        设定两个指针，最初位置分别为两个已经排序序列的起始位置
        比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置
        重复步骤3直到某一指针到达序列尾
将另一序列剩下的所有元素直接复制到合并序列尾
**********************************************************************************/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::swap;

void Merge(int *A, int left, int mid, int right) {
    int len = right - left + 1;
    int *temp = new int[len];
    int i = left, j = mid + 1, k = 0;
    while(i <= mid && j <= right) {
        temp[k++] = A[i] <= A[j] ? A[i++] : A[j++];
    }
    while(i <= mid) temp[k++] = A[i++];
    while(j <= right) temp[k++] = A[j++];
    for (int l = 0; l < len; ++l) {
        A[left++] = temp[l];
    }
}

void MergeSortRecursion(int *A, int left, int right)  // 递归实现的归并排序(自顶向下)
{
    int middle = left + (right - left) / 2;
    if(left == right) return; // 当待排序的序列长度为1时，递归开始回溯，进行merge操作
    MergeSortRecursion(A,left,middle);
    MergeSortRecursion(A,middle + 1,right);
    Merge(A,left,middle,right);
}

void MergeSortIteration(int *A,int len) { // 非递归(迭代)实现的归并排序(自底向上)
    int left, mid ,right;  // 子数组索引,前一个为A[left...mid]，后一个子数组为A[mid+1...right]
    for (int i = 1; i < len; i *= 2) {    // 子数组的大小i初始为1，每轮翻倍
        left = 0;
        while(left + i < len) {   // 后一个子数组存在(需要归并)
            mid = left + i - 1;
            right = mid + i < len ? mid + i : len - 1; // 后一个子数组大小可能不够
            Merge(A,left,mid,right);
            left = right + 1;     // 前一个子数组索引向后移动
        }
    }
}

int main(int argc, char* argv[]) {
    int A[] = {12,23,92,1, 56, 67};
    int n = sizeof(A) / sizeof(A[0]);

//    MergeSortRecursion(A,0,n);
    MergeSortIteration(A,n);
    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }
}
