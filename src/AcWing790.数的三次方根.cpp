#include <iostream>
using namespace std;

/**
 * @brief 求浮点数的立方根
 * @param n 待求浮点数
 * @param left 浮点数 n 所属范围最小值
 * @param right 浮点数 n 所属范围最大值
 * @return 浮点数的立方根（精度为 6 位小数）
 */
static double cubic_root(double n, double left = -10000.0f, double right = 10000.0f) {
    while (left - right > 1e-8) {   // 注意这里的判断条件不一样了（一般计算时采用比精度位数多两位的值）
        double mid = (left + right) / 2.0f;

        if (mid * mid * mid < n) {
            left = mid;
        }
        else {
            right = mid;
        }
    }

    return right;
}