#include <iostream>
#include <vector>
using namespace std;

// 前缀和与差分主要是数学公式的推导
// 这里几乎没有特别的模板，更多的要理解这个思想和应用场景
// 所以这里以文章为主，详情可见我的博客 https://www.seayj.cn

// 我们约定 b 为 a 的差分，也就是 a 为 b 的前缀和
// 同样的我们约定 s 为 a 的前缀和，也就是 a 为 s 的差分
// 最后我们约定，我们使用 a 为待处理对象

// 应用场景：计算 a 数组中从第 left 个数到第 right 个数的和
/**
 * @brief 计算 a 数组中从第 left 个数到第 right 个数的和
 * @param a 待处理数组
 * @param s a 的前缀和数组
 * @param left 区间左边界
 * @param right 区间右边界
 * @return a 数组中从第 left 个数到第 right 个数的和
 */
static int prefixSum(vector<int>& a, vector<int>&s, int left, int right) {
    // 获取 a 数组长度
    const int n = static_cast<const int>(a.size());

    // 计算 a 的前缀和数组 s
    s[0] = 0;   // 定义起始数
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }

    // 通过公式快速计算
    int res = s[right] - s[left - 1];

    // 返回结果
    return res;
}