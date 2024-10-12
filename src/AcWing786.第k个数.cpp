#include <iostream>
#include <utility>
using namespace std;

/**
 * @brief 寻找第 K 个数的快速排序解决方案
 * @param arr 待处理数组
 * @param left 左边界索引
 * @param right 右边界索引
 * @param k 第 K 个数
 * @return 第 K 个数的索引
 */
static int quick_find(int arr[], int left, int right, int k) {
    // 递归终止条件
    if (left == right) return arr[left];

    // 变量初始化
    int x = arr[(left + right) / 2],
        i = left - 1,
        j = right + 1;

    // 排序处理
    while (i < j) {
        while (arr[++i] < x);
        while (arr[--j] > x);

        if (i < j) swap(arr[i], arr[j]);
    }

    // 确定左边子数组总共有多少个数
    int sum_left = j - left + 1;

    // 局部递归处理
    if (k <= sum_left) {    // 第 K 个数在“左子数组”
        return quick_find(arr, left, j, k);
    }
    else {                  // 第 K 个数在“右子数组”
        return quick_find(arr, j + 1, right, k - sum_left);
    }
}