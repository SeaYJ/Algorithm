#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 给定两个“升序”排序的有序数组 A 和 B，以及一个目标值 x。求出满足 A[i]+B[j]=x 的下标数对 (i,j)。
 * @param a 升序数组
 * @param b 升序数组
 * @param x 目标值
 * @return 满足 A[i]+B[j]=x 的下标数对 (i,j)
 */
static pair<int, int> findTargetSum(vector<int>& a, vector<int>& b, int x) {
    for (int i = 0, j = static_cast<int>(b.size()) - 1; i < a.size(); i++) {    // “夹逼”遍历
        while (j >= 0 && a[i] + b[j] > x) {
            j--;
        }

        if (a[i] + b[j] == x) {
            return make_pair(i, j);
        }
    }

    return make_pair(-1, -1);   // 返回不存在的情况
}