#include <iostream>
using namespace std;

// 注意，之所以不使用动态链表是因为 new 操作会浪费大量的时间，
// 同时在做题时（比赛或者其他）我们不用像写项目那样考虑，只需要用合适的算法解决当前的问题即可。

const int N = 1e5;  // 题目可能的最大链表规模
int el[N],          // 存储链表的值 element
    ne[N],          // 存储链表的连接关系 next
    idx = 1;        // 相当于迭代器的 end，指向下一个可用的位置

/**
 * @brief 初始化链表（设置 0 位置用作为链表头 head）
 */
static void initNode() {
    ne[0] = -1; // 这里以 -1 作为链表结束的标志
}

/**
 * @brief 在 k 位置后面插入新节点
 * @param k 位置
 * @param x 新节点的变量值
 */
static void insertNode(int k, int x) {
    el[idx] = x;        // 在新位置（idx）保存变量值
    ne[idx] = ne[k];    // 在新位置（idx）的指向设置为 k 位置节点的指向
    ne[k] = idx;        // 将 k 位置的节点指向新位置 idx
    idx++;              // 指向下一个可用位置
}

/**
 * @brief 删除 k 节点后面的一个节点
 * @param k 位置
 */
static void removeNode(int k) {
    ne[k] = ne[ne[k]];  // 直接将 k 位置节点的指向设置为“k 位置节点指向的节点的指向”
}

