#include <iostream>
#include <vector>
using namespace std;


/**
 * @brief ����һ������Ϊ n ���������� a1, a2, ��, an �Լ�һ������Ϊ m ���������� b1, b2, ��, bm�������ж� a �����Ƿ�Ϊ b ���е������С�������ָ���е�һ�����ԭ�д������ж��õ����У���������{ a1,a3,a5 } ������{ a1,a2,a3,a4,a5 } ��һ�������С�
 * @param a �������� a
 * @param b �������� b
 * @return a �Ƿ��� b ��������
 */
static bool isSubsequence(vector<int>& a, vector<int>& b) {
    int i = 0, j = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            i++;
        }
        j++;
    }

    return (i >= a.size() ? true : false);
}