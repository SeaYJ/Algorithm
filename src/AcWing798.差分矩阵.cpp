#include <iostream>
#include <vector>
using namespace std;

// ǰ׺��������Ҫ����ѧ��ʽ���Ƶ�
// ���Ｘ��û���ر��ģ�壬�����Ҫ������˼���Ӧ�ó���
// ��������������Ϊ��������ɼ��ҵĲ��� https://www.seayj.cn

// ����Լ�� b Ϊ a �Ĳ�֣�Ҳ���� a Ϊ b ��ǰ׺��
// ͬ��������Լ�� s Ϊ a ��ǰ׺�ͣ�Ҳ���� a Ϊ s �Ĳ��
// �������Լ��������ʹ�� a Ϊ���������

// Ӧ�ó������������� (x1, y1) �� (x2, y2) ���Ӿ����ÿ��Ԫ�ض����Ϲ̶�ֵ c
using matrix = vector<vector<int>>; // �������
/**
 * @brief ���ù�ʽ"�������� (x1, y1) �� (x2, y2) ���Ӿ����ÿ��Ԫ�ض����Ϲ̶�ֵ c"�������ڲ�־��� b �н��У������Ҫ�������¸� a
 * @param b a ����Ĳ�־���
 * @param x1 �Ӿ������Ͻ�������
 * @param y1 �Ӿ������Ͻ�������
 * @param x2 �Ӿ������½�������
 * @param y2 �Ӿ������½�������
 * @param c �̶�ֵ
 */
static void difference_insert(matrix& b, int x1, int y1, int x2, int y2, int c) {
    // ���ݹ�ʽ���ټ���
    b[x1][y1] += c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

/**
 * @brief �������� (x1, y1) �� (x2, y2) ���Ӿ����ÿ��Ԫ�ض����Ϲ̶�ֵ c
 * @param a ���������
 * @param b a ����Ĳ�־���
 * @param x1 �Ӿ������Ͻ�������
 * @param y1 �Ӿ������Ͻ�������
 * @param x2 �Ӿ������½�������
 * @param y2 �Ӿ������½�������
 * @param c �̶�ֵ
 */
static void difference(matrix& a, matrix& b, int x1, int y1, int x2, int y2, int c) {
    // ��������ģ
    const int m = static_cast<const int>(a.size());
    const int n = static_cast<const int>(a[0].size());

    // �����־��� b
    b[0][0] = b[0][1] = b[1][0] = a[0][0] = a[0][1] = a[1][0] = 0; // ��ʼ����ʼ��
    for (int x = 1; x <= m; x++) {
        for (int y = 1; y <= n; y++) {
            difference_insert(b, x, y, x, y, a[x][y]);
        }
    }

    // ���ݹ�ʽ���ټ���
    // ע�⣺ִ�� m x n �������ǲ������
    // ԭ���Լ�������ο� Acwing797.���.cpp
    difference_insert(b, x1, y1, x2, y2, c);

    // ���������ع鵽 a ������
    for (int x = 1; x <= m; x++) {
        for (int y = 1; y <= n; y++) {
            b[x][y] += b[x - 1][y] + b[x][y - 1] - b[x - 1][y - 1]; // �Ƚ� b ����תΪ�Լ���ǰ׺�;���
            a[x][y] = b[x][y];  // ��������Ƶ� a ���󣬼��ɸ��� a ����
        }
    }
}