#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 利用二分算法查找非递减数组中第一个 target 出现的位置
 * @param arr 非递减数组
 * @param target 目标元素
 * @return 第一个 target 出现的位置索引
 */
static int binary_search(vector<int>& arr, int target) {
    // 变量初始化
    int left = -1,              // 初始化 left，因为考虑到无“蓝区间”的情况
        right = arr.size();     // 初始化 right，因为考虑到无“红区间”的情况

    // 二分查找
    while (left + 1 != right) {
        int mid = (left + right) / 2;   // 确定二分点（有时候要考虑溢出情况 -> left + (right - left) / 2）

        if (arr[mid] < target) {     // 这里以寻找数组中出现的第一个 target 为例，判断条件为 '< target'
            left = mid;         // 扩展“蓝区间”的右边界（注意结合图看）
        }
        else {
            right = mid;        // 扩展“红区间”的左边界（注意结合图看）
        }
    }

    // 后处理
    if (right == arr.size() || arr[right] != target) {   // 这里以寻找数组中出现的第一个 target 为例，判断条件中的 target 为目标元素的值
        return -1;              // 后处理要考虑未找到情况（判断条件注意索引越界问题）
    }
    else {
        return right;           // 这里以寻找数组中出现的第一个 target 为例，返回值为 'r'
    }
}


/**
 * @brief 利用二分算法查找非递减数组中最后一个 target 出现的位置
 * @param arr 非递减数组
 * @param target 目标元素
 * @return 最后一个 target 出现的位置索引
 */
static int binary_search(vector<int>& arr, int target) {
    // 变量初始化
    int left = -1,              
        right = arr.size();     

    // 二分查找
    while (left + 1 != right) {
        int mid = (left + right) / 2;   

        if (arr[mid] <= target) {      // 这里以寻找数组中出现的最后一个 target 为例，判断条件为 '<= target'
            left = mid;         
        }
        else {
            right = mid;        
        }
    }

    // 后处理
    if (left == -1 || arr[left] != target) {   // 这里以寻找数组中出现的最后一个 target 为例，判断条件中的 target 为目标元素的值
        return -1;
    }
    else {
        return left;           // 这里以寻找数组中出现的最后一个 target 为例，返回值为 'l'
    }
}