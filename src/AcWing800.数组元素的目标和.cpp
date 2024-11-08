#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief ��������������������������� A �� B���Լ�һ��Ŀ��ֵ x��������� A[i]+B[j]=x ���±����� (i,j)��
 * @param a ��������
 * @param b ��������
 * @param x Ŀ��ֵ
 * @return ���� A[i]+B[j]=x ���±����� (i,j)
 */
static pair<int, int> findTargetSum(vector<int>& a, vector<int>& b, int x) {
    for (int i = 0, j = static_cast<int>(b.size()) - 1; i < a.size(); i++) {    // ���бơ�����
        while (j >= 0 && a[i] + b[j] > x) {
            j--;
        }

        if (a[i] + b[j] == x) {
            return make_pair(i, j);
        }
    }

    return make_pair(-1, -1);   // ���ز����ڵ����
}