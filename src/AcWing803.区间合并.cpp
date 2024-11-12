#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using interval = pair<int, int>;

/**
 * @brief �ϲ�����
 * @param intervals ����������伯��
 * @return �ϲ�������伯��
 */
static vector<interval> mergeIntervals(vector<interval>& intervals) {
    vector<interval> res;   // �洢�ϲ�������伯��

    // ����������ֵ�������򣨵���ֵһ��ʱ��sort �������Զ�����ֵ���ж����жϲ�����
    sort(intervals.begin(), intervals.end());

    // ��ȡ��һ�����䲢��Ϊ�������
    int start = intervals[0].first;
    int end = intervals[0].second;

    // ��ʼ�ϲ�
    for (int i = 1; i < intervals.size(); i++) {
        if (end < intervals[i].first) {     // �����ǰ�������� end С����һ������� end����ô�ʹ��������Ѿ��ҵ���һ�����������������������������������������֮�ϲ��ˣ�
            res.push_back({ start, end });  // ������

            start = intervals[i].first;     // ����һ����������Ϊ�������
            end = intervals[i].second;
        }
        else {
            end = max(end, intervals[i].second);    // ǰ�������� end ���ڵ�����һ������� end������������ཻ����Ҫ���кϲ�����Ȼ���ཻ����ôֱ��ȥ���� end ���ɣ�
        }
    }
    res.push_back({ start, end });  // �������������һ�����������������޷�����ӽ�����ģ�������Ҫɨβ

    return res; // ���ؽ��
}