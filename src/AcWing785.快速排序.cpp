#include <iostream>
#include <utility>
using namespace std;


/**
 * @brief 快速排序算法模板
 * @param arr 待排序数组
 * @param left 左边界索引
 * @param right 右边界索引
 */
// 递归时使用 j 作边界（推荐）
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

// 递归使用 i 做边界
static void quick_sort(int arr[], int left, int right) {
    if (left >= right) { return; }

    int x = arr[(left + right + 1) / 2],    // 这里必须修改
        i = left - 1,
        j = right + 1;

    while (i < j) {
        do { i++; } while (arr[i] < x);
        do { j--; } while (arr[j] > x);
        if (i < j) swap(arr[i], arr[j]);
    }

    quick_sort(arr, left, i - 1);   // 递归处理数组左半边（注意边界问题）
    quick_sort(arr, i, right);      // 递归处理数组右半边（注意边界问题）
}