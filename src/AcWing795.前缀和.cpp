#include <iostream>
#include <vector>
using namespace std;

// ǰ׺��������Ҫ����ѧ��ʽ���Ƶ�
// ���Ｘ��û���ر��ģ�壬�����Ҫ������˼���Ӧ�ó���
// ��������������Ϊ��������ɼ��ҵĲ��� https://www.seayj.cn

// ����Լ�� b Ϊ a �Ĳ�֣�Ҳ���� a Ϊ b ��ǰ׺��
// ͬ��������Լ�� s Ϊ a ��ǰ׺�ͣ�Ҳ���� a Ϊ s �Ĳ��
// �������Լ��������ʹ�� a Ϊ���������

// Ӧ�ó��������� a �����дӵ� left �������� right �����ĺ�
/**
 * @brief ���� a �����дӵ� left �������� right �����ĺ�
 * @param a ����������
 * @param s a ��ǰ׺������
 * @param left ������߽�
 * @param right �����ұ߽�
 * @return a �����дӵ� left �������� right �����ĺ�
 */
static int prefixSum(vector<int>& a, vector<int>&s, int left, int right) {
    // ��ȡ a ���鳤��
    const int n = static_cast<const int>(a.size());

    // ���� a ��ǰ׺������ s
    s[0] = 0;   // ������ʼ��
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }

    // ͨ����ʽ���ټ���
    int res = s[right] - s[left - 1];

    // ���ؽ��
    return res;
}