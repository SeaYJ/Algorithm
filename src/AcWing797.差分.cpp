#include <iostream>
#include <vector>
using namespace std;

// ǰ׺��������Ҫ����ѧ��ʽ���Ƶ�
// ���Ｘ��û���ر��ģ�壬�����Ҫ������˼���Ӧ�ó���
// ��������������Ϊ��������ɼ��ҵĲ��� https://www.seayj.cn

// ����Լ�� b Ϊ a �Ĳ�֣�Ҳ���� a Ϊ b ��ǰ׺��
// ͬ��������Լ�� s Ϊ a ��ǰ׺�ͣ�Ҳ���� a Ϊ s �Ĳ��
// �������Լ��������ʹ�� a Ϊ���������

// Ӧ�ó������� a ������ [left, right] ֮���ÿ�������Ϲ̶�ֵ c
/**
 * @brief ���ù�ʽ���� a ������ [left, right] ֮���ÿ�������� c���������ڲ������ b �н��У������Ҫ�������¸� a
 * @param b a �Ĳ������
 * @param left ������߽�
 * @param right �����ұ߽�
 * @param c ���ӵĶ�ֵ
 */
static void difference_insert(vector<int>& b, int left, int right, int c) {
    // ���ݹ�ʽ���ټ���
    b[left] += c;
    b[right + 1] -= c;
}

/**
 * @brief �� a ������ [left, right] ֮���ÿ�������� c
 * @param a ����������
 * @param b a �Ĳ������
 * @param left ������߽�
 * @param right �����ұ߽�
 * @param c ���ӵĶ�ֵ
 */
static void difference(vector<int>& a, vector<int>& b, int left, int right, int c) {
    // ���� a ���鳤��
    const int n = static_cast<const int>(a.size());

    // ���ɲ������ b
    a[0] = b[0] = 0;    // ��ʼ����ʼ��
    for (int i = 1; i <= n; i++) {
        // ���� a ����ĳ�ʼֵȫ�� 0
        // ��ôʵ�ʵ� a ������Կ��ɼ���� a ������ [i, i] ֮���ÿ�������� a[i]
        difference_insert(b, i, i, a[i]);   // ���ù�ʽ���ɲ�����飨ע�⣬�ò���ʵ�ʹ�ʽû�й�ϵ��
    }
    // ��������棺���ɲ������ b
    // �������������������Ȼ�ھ����в�����ʹ�ñ�������淽�����ɶ�Ӧ�Ĳ�־���
    //for (int i = 1; i <= n; i++) {
    //    b[i] = a[i] - a[i - 1];
    //}

    // ���ݹ�ʽ���ټ���
    // ע�⣺ִ�� n �������ǲ������
    difference_insert(b, left, right, c);

    // ���������ع鵽 a ������
    // ����һ�����Կ�����
    // ����������� a ������ [left, right] ֮���ÿ�������� c��ִֻ�� < n ���ǲ�����ģ�
    // ��Ϊ����㷨���ʼ��Ҫ���� n �α�����
    // ����ֻ���ڴ���������������ʱ�����㷨�ž��и�Ч�ԡ�
    for (int i = 1; i <= n; i++) {
        b[i] += b[i - 1];   // �Ƚ� b ����תΪ�Լ���ǰ׺������
        a[i] = b[i];        // ��������Ƶ� a ���飬���ɸ��� a ����
    }
}