#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * @brief 找出数组中最长的不包含重复的数的连续区间，并输出它的长度。
 * @param arr 待处理数组
 * @return 数组中最长的不包含重复的数的连续区间的长度
 */
static int longestUniqueSubsequence(vector<int>& arr) {
    unordered_map<int, int> count;              // 统计认定的序列中每个元素出现的次数
    int max_len = 0;                            // 记录最大长度

    for (int i = 0, j = 0; i < arr.size(); i++) {
        count[arr[i]]++;                        // 将 i 指针的元素统计计数 + 1

        while (count[arr[i]] > 1) {             // 如果 i 指针的元素统计计数大于 1，就代表 i 与 j 指针之间的序列出现了重复元素
            count[arr[j]]--;                    // j 指针开始后移，同时要将计数 - 1。后移是次要，主要是统计计数的更新！
            j++;
        }

        max_len = max(max_len, i - j + 1);      // 动态规划，找到全局最大长度
    }

    return max_len;                             // 返回结果
}