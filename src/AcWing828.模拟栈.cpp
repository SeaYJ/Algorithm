#include <iostream>
using namespace std;

// ������ȥģ��ջ���ٶȸ��죬���Ҹ������ʺ��ھ�����Ŀ��ʹ��

const int N = 1e6 + 10;
int stk[N],     // ջ�ռ�
    top = -1;   // ָ��ջ��Ԫ�ص���������ʼ��Ϊ -1

/**
 * @brief ѹջ
 * @param x ����
 */
static void push(int x) {
    stk[++top] = x;
}

/**
 * @brief ��һ��Ԫ�س�ջ
 */
static void pop() {
    top--;
}

/**
 * @brief �ж�ջ�Ƿ�Ϊ��
 * @return ��Ϊ true���ǿ�Ϊ false
 */
static bool empty() {
    return top < 0;
}

/**
 * @brief ����ջ��Ԫ��ֵ����������ջ
 * @return ջ��Ԫ��ֵ
 */
static int topVal() {
    return stk[top];
}