#include <iostream>
using namespace std;

static void quick_sort(int arr[], int left, int right) {
    // 递归终止条件
    if (left >= right) { return; }

    // 初始化变量
    int x = arr[(left + right) / 2],    // 中间值，可以为 arr[left], arr[right], arr[(left + right) / 2]
        i = left - 1,                   // 左指针，初始化为数组左边界 - 1
        j = right + 1;                  // 右指正，初始化为数组右边界 + 1

    // 处理
    while (i < j) {
        do { i++; } while (arr[i] < x);     // 寻找数组左半边 >= x 的值
        do { j--; } while (arr[j] > x);     // 寻找数组右半边 <= x 的值
        if (i < j) swap(arr[i], arr[j]);    // 注意交换时指针边界
    }

    // 递归
    quick_sort(arr, left, j);           // 递归处理数组左半边（注意边界问题）
    quick_sort(arr, j + 1, right);      // 递归处理数组右半边（注意边界问题）
}