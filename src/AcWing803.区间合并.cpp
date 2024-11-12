#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using interval = pair<int, int>;

/**
 * @brief 合并区间
 * @param intervals 待处理的区间集合
 * @return 合并后的区间集合
 */
static vector<interval> mergeIntervals(vector<interval>& intervals) {
    vector<interval> res;   // 存储合并后的区间集合

    // 按照区间左值进行排序（当左值一样时，sort 函数会自动以右值进行二次判断并排序）
    sort(intervals.begin(), intervals.end());

    // 获取第一个区间并设为处理对象
    int start = intervals[0].first;
    int end = intervals[0].second;

    // 开始合并
    for (int i = 1; i < intervals.size(); i++) {
        if (end < intervals[i].first) {     // 如果当前区间对象的 end 小于下一个区间的 end，那么就代表我们已经找到了一个“独立的区间结果”（后续不会再有区间可以与之合并了）
            res.push_back({ start, end });  // 保存结果

            start = intervals[i].first;     // 将下一个区间设置为处理对象
            end = intervals[i].second;
        }
        else {
            end = max(end, intervals[i].second);    // 前区间对象的 end 大于等于下一个区间的 end，代表二者有相交，需要进行合并（既然有相交，那么直接去最大的 end 即可）
        }
    }
    res.push_back({ start, end });  // 无论怎样，最后一个处理的区间对象是无法被添加进结果的，所以需要扫尾

    return res; // 返回结果
}