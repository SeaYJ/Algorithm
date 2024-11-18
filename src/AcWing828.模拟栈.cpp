#include <iostream>
using namespace std;

// 用数组去模拟栈，速度更快，并且更灵活，更适合在竞赛题目中使用

const int N = 1e6 + 10;
int stk[N],     // 栈空间
    top = -1;   // 指向栈顶元素的索引，初始化为 -1

/**
 * @brief 压栈
 * @param x 变量
 */
static void push(int x) {
    stk[++top] = x;
}

/**
 * @brief 弹一个元素出栈
 */
static void pop() {
    top--;
}

/**
 * @brief 判断栈是否为空
 * @return 空为 true；非空为 false
 */
static bool empty() {
    return top < 0;
}

/**
 * @brief 返回栈顶元素值，但不弹出栈
 * @return 栈顶元素值
 */
static int topVal() {
    return stk[top];
}