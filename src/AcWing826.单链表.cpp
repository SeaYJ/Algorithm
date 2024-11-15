#include <iostream>
using namespace std;

// ע�⣬֮���Բ�ʹ�ö�̬��������Ϊ new �������˷Ѵ�����ʱ�䣬
// ͬʱ������ʱ�������������������ǲ�����д��Ŀ�������ǣ�ֻ��Ҫ�ú��ʵ��㷨�����ǰ�����⼴�ɡ�

const int N = 1e5;  // ��Ŀ���ܵ���������ģ
int el[N],          // �洢�����ֵ element
    ne[N],          // �洢��������ӹ�ϵ next
    idx = 1;        // �൱�ڵ������� end��ָ����һ�����õ�λ��

/**
 * @brief ��ʼ���������� 0 λ������Ϊ����ͷ head��
 */
static void initNode() {
    ne[0] = -1; // ������ -1 ��Ϊ��������ı�־
}

/**
 * @brief �� k λ�ú�������½ڵ�
 * @param k λ��
 * @param x �½ڵ�ı���ֵ
 */
static void insertNode(int k, int x) {
    el[idx] = x;        // ����λ�ã�idx���������ֵ
    ne[idx] = ne[k];    // ����λ�ã�idx����ָ������Ϊ k λ�ýڵ��ָ��
    ne[k] = idx;        // �� k λ�õĽڵ�ָ����λ�� idx
    idx++;              // ָ����һ������λ��
}

/**
 * @brief ɾ�� k �ڵ�����һ���ڵ�
 * @param k λ��
 */
static void removeNode(int k) {
    ne[k] = ne[ne[k]];  // ֱ�ӽ� k λ�ýڵ��ָ������Ϊ��k λ�ýڵ�ָ��Ľڵ��ָ��
}

