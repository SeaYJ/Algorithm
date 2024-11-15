#include <iostream>
using namespace std;

const int N = 1e5;
int el[N], l[N], r[N], idx = 2;

/**
 * @brief ��ʼ��˫����
 */
static void initNode() {
    r[0] = 1;   // ��ʼ�� head ��ָ��
    l[1] = 0;   // ��ʼ�� tail ��ָ��
}

/**
 * @brief �ڵ� k - 1 ���ڵ�֮������½ڵ㣨ע��˫����ռ�� 0 1 ����λ�÷ֱ���Ϊ head �� tail����
 * ���Ƿ��� head ������ 0������ tail ������ 1��
 * @param k λ��
 * @param x ����ֵ
 */
static void insertNode(int k, int x) {
    // �������ֵ
    el[idx] = x;    

    // ���½ڵ������ָ���������
    l[idx] = k;
    r[idx] = r[k];

    // �޸�����ָ��Ľڵ��ָ���ϵ
    r[l[idx]] = idx;
    l[r[idx]] = idx;

    // ����λ�ú���
    idx++;
}

/**
 * @brief ɾ�� k - 1 ������Ľڵ�
 * @param k λ��
 */
static void removeNode(int k) {
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}