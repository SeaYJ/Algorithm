#include <iostream>
using namespace std;

// 用数组去模拟队列，速度更快，并且更灵活，更适合在竞赛题目中使用

const int N = 1e6 + 10;
int queue[N],   // 队列空间
    head = 0,   // 队列头元素索引，初始化为 0
    tail = -1;  // 队列尾元素索引，初始化为 -1

/**
 * @brief 在队列尾中加入新元素
 * @param x 新元素
 */
static void push(int x) {
    queue[++tail] = x;
}

/**
 * @brief 弹出队列头元素
 */
static void pop() {
    head++;
}

/**
 * @brief 判断队列是否为空
 * @return 
 */
static bool empty() {
    return head > tail;
}

/**
 * @brief 返回队列头元素值，但是不弹出
 * @return 队列头元素值
 */
static int headVal() {
    return queue[head];
}

/**
 * @brief 返回队列尾元素值，但是不删除
 * @return 队列尾元素值
 */
static int tailVal() {
    return queue[tail];
}