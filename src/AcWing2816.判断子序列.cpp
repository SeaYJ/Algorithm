#include <iostream>
#include <vector>
using namespace std;


/**
 * @brief 给定一个长度为 n 的整数序列 a1, a2, …, an 以及一个长度为 m 的整数序列 b1, b2, …, bm。请你判断 a 序列是否为 b 序列的子序列。子序列指序列的一部分项按原有次序排列而得的序列，例如序列{ a1,a3,a5 } 是序列{ a1,a2,a3,a4,a5 } 的一个子序列。
 * @param a 整数序列 a
 * @param b 整数序列 b
 * @return a 是否是 b 的子序列
 */
static bool isSubsequence(vector<int>& a, vector<int>& b) {
    int i = 0, j = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            i++;
        }
        j++;
    }

    return (i >= a.size() ? true : false);
}