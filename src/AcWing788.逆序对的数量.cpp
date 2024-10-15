#include <iostream>
using namespace std;

/**
 * @brief 利用归并排序求逆序对的数量
 * @param arr 待处理数组
 * @param tmp 临时数组（大小要和待处理数组一样）
 * @param left 左边界索引
 * @param right 右边界索引
 * @return 逆序对数量
 */
static int merge_find(int arr[], int tmp[], int left, int right) {
    // 递归终止条件
    if (left >= right) return 0;

    // 递归排序
    int mid = (left + right) / 2;
    int count = merge_find(arr, tmp, left, mid) + merge_find(arr, tmp, mid + 1, right); // 统计左子数组和右子数组的逆序对数量之和（统计第一、二种可能 | 见下方说明）

    // 初始化变量
    int i = left,
        j = mid + 1,
        k = 0;

    // 归并排序
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            tmp[k++] = arr[i++];
        } 
        else {
            tmp[k++] = arr[j++];
            count += (mid - i + 1);     // 统计第三种可能（见下方说明）
        }
    }

    // 扫尾
    while (i <= mid) {
        tmp[k++] = arr[i++];
    }
    while (j <= right) {
        tmp[k++] = arr[j++];
    }

    // 物归原主
    for (int ai = left, ti = 0; ai <= right; ai++, ti++) {
        arr[ai] = tmp[ti];
    }

    // 返回逆序对数量
    return count;
}

/*
* 逆序对的三种可能：
* 1. 两个数完全在左子数组；
* 2. 两个数完全在右子数组；
* 3. 两个数其中一个在左子数组，另一个在右子数组。
*/