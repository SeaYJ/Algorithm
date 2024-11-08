#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * @brief �ҳ���������Ĳ������ظ��������������䣬��������ĳ��ȡ�
 * @param arr ����������
 * @return ��������Ĳ������ظ���������������ĳ���
 */
static int longestUniqueSubsequence(vector<int>& arr) {
    unordered_map<int, int> count;              // ͳ���϶���������ÿ��Ԫ�س��ֵĴ���
    int max_len = 0;                            // ��¼��󳤶�

    for (int i = 0, j = 0; i < arr.size(); i++) {
        count[arr[i]]++;                        // �� i ָ���Ԫ��ͳ�Ƽ��� + 1

        while (count[arr[i]] > 1) {             // ��� i ָ���Ԫ��ͳ�Ƽ������� 1���ʹ��� i �� j ָ��֮������г������ظ�Ԫ��
            count[arr[j]]--;                    // j ָ�뿪ʼ���ƣ�ͬʱҪ������ - 1�������Ǵ�Ҫ����Ҫ��ͳ�Ƽ����ĸ��£�
            j++;
        }

        max_len = max(max_len, i - j + 1);      // ��̬�滮���ҵ�ȫ����󳤶�
    }

    return max_len;                             // ���ؽ��
}