#include <iostream>
#include <vector>
using namespace std;

// 前缀和与差分主要是数学公式的推导
// 这里几乎没有特别的模板，更多的要理解这个思想和应用场景
// 所以这里以文章为主，详情可见我的博客 https://www.seayj.cn

// 我们约定 b 为 a 的差分，也就是 a 为 b 的前缀和
// 同样的我们约定 s 为 a 的前缀和，也就是 a 为 s 的差分
// 最后我们约定，我们使用 a 为待处理对象

// 应用场景：将 a 数组中 [left, right] 之间的每个数加上固定值 c
/**
 * @brief 利用公式“将 a 数组中 [left, right] 之间的每个数加上 c”，计算在差分数组 b 中进行，结果需要回馈更新给 a
 * @param b a 的差分数组
 * @param left 区间左边界
 * @param right 区间右边界
 * @param c 待加的定值
 */
static void difference_insert(vector<int>& b, int left, int right, int c) {
    // 根据公式快速计算
    b[left] += c;
    b[right + 1] -= c;
}

/**
 * @brief 将 a 数组中 [left, right] 之间的每个数加上 c
 * @param a 待处理数组
 * @param b a 的差分数组
 * @param left 区间左边界
 * @param right 区间右边界
 * @param c 待加的定值
 */
static void difference(vector<int>& a, vector<int>& b, int left, int right, int c) {
    // 计算 a 数组长度
    const int n = static_cast<const int>(a.size());

    // 生成差分数组 b
    a[0] = b[0] = 0;    // 初始化起始数
    for (int i = 1; i <= n; i++) {
        // 假设 a 数组的初始值全是 0
        // 那么实际的 a 数组可以看成假设的 a 数组在 [i, i] 之间的每个数加上 a[i]
        difference_insert(b, i, i, a[i]);   // 利用公式生成差分数组（注意，该步与实际公式没有关系）
    }
    // 暴力计算版：生成差分数组 b
    // 建议理解上述方法，不然在矩阵中不便于使用暴力计算版方法生成对应的差分矩阵
    //for (int i = 1; i <= n; i++) {
    //    b[i] = a[i] - a[i - 1];
    //}

    // 根据公式快速计算
    // 注意：执行 n 次以下是不划算的
    difference_insert(b, left, right, c);

    // 将计算结果回归到 a 数组中
    // 从这一步可以看出，
    // 如果操作“将 a 数组中 [left, right] 之间的每个数加上 c”只执行 < n 次是不划算的，
    // 因为这个算法最后始终要进行 n 次遍历，
    // 所以只有在大量进行上述操作时，该算法才具有高效性。
    for (int i = 1; i <= n; i++) {
        b[i] += b[i - 1];   // 先将 b 数组转为自己的前缀和数组
        a[i] = b[i];        // 将结果复制到 a 数组，即可更新 a 数组
    }
}