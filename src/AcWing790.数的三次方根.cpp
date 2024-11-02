#include <iostream>
using namespace std;

/**
 * @brief �󸡵�����������
 * @param n ���󸡵���
 * @param left ������ n ������Χ��Сֵ
 * @param right ������ n ������Χ���ֵ
 * @return ��������������������Ϊ 6 λС����
 */
static double cubic_root(double n, double left = -10000.0f, double right = 10000.0f) {
    while (left - right > 1e-8) {   // ע��������ж�������һ���ˣ�һ�����ʱ���ñȾ���λ������λ��ֵ��
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