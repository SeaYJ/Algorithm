#include <iostream>
using namespace std;

/**
 * @brief 归并排序
 * @param arr 待排序的数组
 * @param temp 辅助数组（必须与待排序的数组空间大小一致）
 * @param left 左边界
 * @param right 右边界
 */
static void merge_sort(int arr[], int temp[], int left, int right) {
    // 递归终止条件
    if (left >= right) return;

    // 确定分界点
    int mid = (left + right) / 2;

    // 递归左右子数组
    merge_sort(arr, temp, left, mid);
    merge_sort(arr, temp, mid + 1, right);

    // 初始化变量
    int k = 0,          // k 代表 temp 数组中已经存储的元素个数，也作为 temp 数组的存储索引
        i = left,       // i 代表“左子数组”的起点索引
        j = mid + 1;    // j 达标“右子数组”的起点索引

    // 归并
    while (i <= mid && j <= right) {    // 将有序的“左/右子数组”元素归并到 temp 数组
        if (arr[i] <= arr[j]) {         // 如果左子数组索引指向的元素更小，就复制左子数组索引指向的元素
            temp[k++] = arr[i++];
        }
        else {                          // 否则复制右子数组索引指向的元素
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {                  // 可能最后“左子数组”元素还没归并完
        temp[k++] = arr[i++];
    }
    while (j <= right) {                // 可能最后“右子数组”元素还没归并完
        temp[k++] = arr[j++];
    }

    // 将归并的结果复制回原数组
    for (int ai = left, ti = 0; ai <= right; ai++, ti++) {  // ai 为 arr 索引，ti 为 temp 索引
        arr[ai] = temp[ti];
    }
}
