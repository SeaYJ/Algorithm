#include <iostream>
#include <vector>
using namespace std;

// 前缀和与差分主要是数学公式的推导
// 这里几乎没有特别的模板，更多的要理解这个思想和应用场景
// 所以这里以文章为主，详情可见我的博客 https://www.seayj.cn

// 我们约定 b 为 a 的差分，也就是 a 为 b 的前缀和
// 同样的我们约定 s 为 a 的前缀和，也就是 a 为 s 的差分
// 最后我们约定，我们使用 a 为待处理对象

// 应用场景：将矩阵中 (x1, y1) 到 (x2, y2) 的子矩阵的每个元素都加上固定值 c
using matrix = vector<vector<int>>; // 定义矩阵
/**
 * @brief 利用公式"将矩阵中 (x1, y1) 到 (x2, y2) 的子矩阵的每个元素都加上固定值 c"，计算在差分矩阵 b 中进行，结果需要回馈更新给 a
 * @param b a 矩阵的差分矩阵
 * @param x1 子矩阵左上角行坐标
 * @param y1 子矩阵左上角列坐标
 * @param x2 子矩阵右下角行坐标
 * @param y2 子矩阵右下角列坐标
 * @param c 固定值
 */
static void difference_insert(matrix& b, int x1, int y1, int x2, int y2, int c) {
    // 根据公式快速计算
    b[x1][y1] += c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

/**
 * @brief 将矩阵中 (x1, y1) 到 (x2, y2) 的子矩阵的每个元素都加上固定值 c
 * @param a 待处理矩阵
 * @param b a 矩阵的差分矩阵
 * @param x1 子矩阵左上角行坐标
 * @param y1 子矩阵左上角列坐标
 * @param x2 子矩阵右下角行坐标
 * @param y2 子矩阵右下角列坐标
 * @param c 固定值
 */
static void difference(matrix& a, matrix& b, int x1, int y1, int x2, int y2, int c) {
    // 计算矩阵规模
    const int m = static_cast<const int>(a.size());
    const int n = static_cast<const int>(a[0].size());

    // 计算差分矩阵 b
    b[0][0] = b[0][1] = b[1][0] = a[0][0] = a[0][1] = a[1][0] = 0; // 初始化起始数
    for (int x = 1; x <= m; x++) {
        for (int y = 1; y <= n; y++) {
            difference_insert(b, x, y, x, y, a[x][y]);
        }
    }

    // 根据公式快速计算
    // 注意：执行 m x n 次以下是不划算的
    // 原因自己分析或参考 Acwing797.差分.cpp
    difference_insert(b, x1, y1, x2, y2, c);

    // 将计算结果回归到 a 数组中
    for (int x = 1; x <= m; x++) {
        for (int y = 1; y <= n; y++) {
            b[x][y] += b[x - 1][y] + b[x][y - 1] - b[x - 1][y - 1]; // 先将 b 矩阵转为自己的前缀和矩阵
            a[x][y] = b[x][y];  // 将结果复制到 a 矩阵，即可更新 a 矩阵
        }
    }
}