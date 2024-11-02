#include <iostream>
#include <vector>
using namespace std;

// 前缀和与差分主要是数学公式的推导
// 这里几乎没有特别的模板，更多的要理解这个思想和应用场景
// 所以这里以文章为主，详情可见我的博客 https://www.seayj.cn

// 我们约定 b 为 a 的差分，也就是 a 为 b 的前缀和
// 同样的我们约定 s 为 a 的前缀和，也就是 a 为 s 的差分
// 最后我们约定，我们使用 a 为待处理对象

// 应用场景：计算矩阵中 (x1, y1) 到 (x2, y2) 的子矩阵的元素和
using matrix = vector<vector<int>>; // 定义矩阵
/**
 * @brief 计算矩阵中 (x1, y1) 到 (x2, y2) 的子矩阵的元素和
 * @param a 待处理数组
 * @param s a 的前缀和数组
 * @param x1 子矩阵左上角行坐标
 * @param y1 子矩阵左上角列坐标
 * @param x2 子矩阵右下角行坐标
 * @param y2 子矩阵右下角列坐标
 * @return 矩阵中 (x1, y1) 到 (x2, y2) 的子矩阵的元素和
 */
static int prefixSum(matrix& a, matrix& s, int x1, int y1, int x2, int y2) {
    // 计算矩阵规模 m x n
    const int m = static_cast<const int>(a.size());
    const int n = static_cast<const int>(a[0].size());

    // 计算前缀和矩阵 s
    s[0][0] = s[0][1] = s[1][0] = 0;  // 定义起始数
    for (int x = 1; x <= m; x++) {
        for (int y = 1; y <= n; y++) {
            s[x][y] = s[x][y - 1] + s[x - 1][y] - s[x - 1][y - 1] + a[x][y];
        }
    }

    // 根据公式快速计算
    int res = s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];

    // 返回结果
    return res;
}