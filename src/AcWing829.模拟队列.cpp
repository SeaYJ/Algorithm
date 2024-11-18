#include <iostream>
using namespace std;

// ������ȥģ����У��ٶȸ��죬���Ҹ������ʺ��ھ�����Ŀ��ʹ��

const int N = 1e6 + 10;
int queue[N],   // ���пռ�
    head = 0,   // ����ͷԪ����������ʼ��Ϊ 0
    tail = -1;  // ����βԪ����������ʼ��Ϊ -1

/**
 * @brief �ڶ���β�м�����Ԫ��
 * @param x ��Ԫ��
 */
static void push(int x) {
    queue[++tail] = x;
}

/**
 * @brief ��������ͷԪ��
 */
static void pop() {
    head++;
}

/**
 * @brief �ж϶����Ƿ�Ϊ��
 * @return 
 */
static bool empty() {
    return head > tail;
}

/**
 * @brief ���ض���ͷԪ��ֵ�����ǲ�����
 * @return ����ͷԪ��ֵ
 */
static int headVal() {
    return queue[head];
}

/**
 * @brief ���ض���βԪ��ֵ�����ǲ�ɾ��
 * @return ����βԪ��ֵ
 */
static int tailVal() {
    return queue[tail];
}