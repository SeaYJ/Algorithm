#include <iostream>
using namespace std;

/**
 * @brief ���� x ��������ʽ�б������һ�� 1 ������� 0 �����������ֵ
 * @param x ���������
 * @return x ��������ʽ�б������һ�� 1 ������� 0 �����������ֵ
 */
static int lowbit(int x) {
    return x & -x;
}