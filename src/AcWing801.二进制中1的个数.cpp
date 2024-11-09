#include <iostream>
using namespace std;

/**
 * @brief 计算 x 二进制形式中保留最后一个 1 及后面的 0 所代表的数的值
 * @param x 待处理的数
 * @return x 二进制形式中保留最后一个 1 及后面的 0 所代表的数的值
 */
static int lowbit(int x) {
    return x & -x;
}