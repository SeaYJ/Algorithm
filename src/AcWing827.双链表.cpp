#include <iostream>
using namespace std;

const int N = 1e5;
int el[N], l[N], r[N], idx = 2;

/**
 * @brief 初始化双链表
 */
static void initNode() {
    r[0] = 1;   // 初始化 head 右指向
    l[1] = 0;   // 初始化 tail 左指向
}

/**
 * @brief 在第 k - 1 个节点之后插入新节点（注意双链表占据 0 1 两个位置分别作为 head 和 tail）。
 * 但是访问 head 依旧用 0；访问 tail 依旧用 1；
 * @param k 位置
 * @param x 变量值
 */
static void insertNode(int k, int x) {
    // 保存变量值
    el[idx] = x;    

    // 对新节点的左右指向进行设置
    l[idx] = k;
    r[idx] = r[k];

    // 修改左右指向的节点的指向关系
    r[l[idx]] = idx;
    l[r[idx]] = idx;

    // 可用位置后移
    idx++;
}

/**
 * @brief 删除 k - 1 个插入的节点
 * @param k 位置
 */
static void removeNode(int k) {
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}