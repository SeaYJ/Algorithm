#include <iostream>
#include <vector>
using namespace std;

// ǰ׺��������Ҫ����ѧ��ʽ���Ƶ�
// ���Ｘ��û���ر��ģ�壬�����Ҫ������˼���Ӧ�ó���
// ��������������Ϊ��������ɼ��ҵĲ��� https://www.seayj.cn

// ����Լ�� b Ϊ a �Ĳ�֣�Ҳ���� a Ϊ b ��ǰ׺��
// ͬ��������Լ�� s Ϊ a ��ǰ׺�ͣ�Ҳ���� a Ϊ s �Ĳ��
// �������Լ��������ʹ�� a Ϊ���������

// Ӧ�ó�������������� (x1, y1) �� (x2, y2) ���Ӿ����Ԫ�غ�
using matrix = vector<vector<int>>; // �������
/**
 * @brief ��������� (x1, y1) �� (x2, y2) ���Ӿ����Ԫ�غ�
 * @param a ����������
 * @param s a ��ǰ׺������
 * @param x1 �Ӿ������Ͻ�������
 * @param y1 �Ӿ������Ͻ�������
 * @param x2 �Ӿ������½�������
 * @param y2 �Ӿ������½�������
 * @return ������ (x1, y1) �� (x2, y2) ���Ӿ����Ԫ�غ�
 */
static int prefixSum(matrix& a, matrix& s, int x1, int y1, int x2, int y2) {
    // ��������ģ m x n
    const int m = static_cast<const int>(a.size());
    const int n = static_cast<const int>(a[0].size());

    // ����ǰ׺�;��� s
    s[0][0] = s[0][1] = s[1][0] = 0;  // ������ʼ��
    for (int x = 1; x <= m; x++) {
        for (int y = 1; y <= n; y++) {
            s[x][y] = s[x][y - 1] + s[x - 1][y] - s[x - 1][y - 1] + a[x][y];
        }
    }

    // ���ݹ�ʽ���ټ���
    int res = s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];

    // ���ؽ��
    return res;
}