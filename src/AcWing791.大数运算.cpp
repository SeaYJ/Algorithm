#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief �Ǹ��������� C = A + B
 * @param A �Ǹ�����������洢��
 * @param B �Ǹ�����������洢��
 * @return ������������洢��
 */
static vector<int> add(vector<int>& A, vector<int>& B) {
    vector<int> C;  // ������

    // �ӷ�����
    int t = 0;      // �ӷ���λ�����Ե�λ
    for (int i = 0; i < A.size() || i < B.size(); i++) {    // ע�⣺Ҫ��������������λ��������
        // ���� A[i] + B[i] + t
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];

        C.push_back(t % 10);    // ���汾λ����ֵ���
        t /= 10;                // �������ϵĽ�λֵ
    }

    // �п��� A �� B �е����λ֮�ϻ��н�λֵ
    if (t) C.push_back(t);
    
    // ���ؽ��
    return C;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief �ж� A >= B
 * @param A �Ǹ�����������洢��
 * @param B �Ǹ�����������洢��
 * @return A �Ƿ���ڵ��� B
 */
static bool cmp(vector<int>& A, vector<int>& B) {
    // λ������
    if (A.size() != B.size()) {     // �� A �� B λ����һ��ʱ
        return A.size() > B.size(); // λ����������ֵ����
    }

    // λ��һ��ʱ����ֵ����
    for (int i = A.size() - 1; i >= 0; i--) {   // �Ӹ�λ�����λ������ע�� A �� B λ��һ�£�
        if (A[i] != B[i]) {                     // ��һ��ͬλ��ֵ����ͬ��λ�ó���
            return A[i] > B[i];                 // ��λ����ֵ�����������
        }
    }
    
    // ȫ�����ʱ��A = B��
    return true;
}

/**
 * @brief ���� C = A - B��ע�� A ������ڵ��� B��ʹ��ǰ�����飩
 * @param A �Ǹ�����������洢��
 * @param B �Ǹ�����������洢��
 * @return ������
 */
static vector<int> sub(vector<int>& A, vector<int>& B) {
    vector<int> C;  // ������

    // ��������
    int t = 0;      // ������λ�����Ե�λ
    for (int i = A.size() - 1; i >= 0; i--) {
        // ���� A[i] - B[i]
        t = A[i] - t;
        if (i < B.size()) t -= B[i];

        // ע���λ��
        //   - ��ȥ��λ��λ t������������е� t ����ͬһ��������
        //   - ������λ��λҪ���� 10
        // �ܺ��������� (t + 10) % 10 �õ���λ����ֵ�����ﴦ��Ƚ��������⣩
        C.push_back((t + 10) % 10);

        // ���С�� 0 ������Ҫ���λ��λ
        t = (t < 0 ? 1 : 0);
    }

    // ȥ��ǰ׺ 0��ע���� C Ϊ 0 �������
    while (C.size() > 1 && C.back() == 0) C.pop_back();

    // ���ؽ��
    return C;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief ���������˷� C = A * b
 * @param A �Ǹ�����������洢��
 * @param b �Ǹ�����
 * @return ��������洢��
 */
static vector<int> mul(vector<int>& A, int b) {
    vector<int> C;  // ������

    // ���㣺(A[i] * b + t) % 10
    // ����Ƚ�����⣨��ƽ���ĳ˷���ʽ���㷽ʽ������ͬ��
    for (int i = 0, t = 0; i < A.size() || t; i++) {
        // C[i] = (A[i] * b + t) % 10
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);

        // �����λ
        t /= 10;
    }

    // ȥ�����ܵ�ǰ׺ 0���� b == 0 ʱ�ͻ����ǰ׺ 0��
    while (C.size() > 1 && C.back() == 0) C.pop_back();

    // ���ؽ��
    return C;
}

/**
 * @brief ���������˷� C = A * B
 * @param A �Ǹ�����������洢��
 * @param B �Ǹ�����������洢��
 * @return ��������洢��
 */
static vector<int> mul(vector<int> A, vector<int> B)
{
    // ����һ����СΪ A.size() + B.size() ������ C ���洢������
    vector<int> C(A.size() + B.size());

    // ����ѭ������ A �� B ��ÿһλ������ÿһλ�ĳ˻�
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            C[i + j] += A[i] * B[j]; // ���˻��ۼӵ� C �ж�Ӧ��λ��
        }
    }

    // �����λ
    for (int i = 0, t = 0; i < C.size() || t; i++)
    {
        t += C[i];              // ����ǰλ��ֵ�ӵ���λ��
        if (i >= C.size()) {
            C.push_back(t % 10);// ��� C ��δ��չ��������չ���洢��ǰλ
        }
        else {
            C[i] = t % 10;      // ���µ�ǰλΪ��λ��
        }

        t /= 10;                // �����µĽ�λ
    }

    // ȥ�����ܵ�ǰ׺ 0���� b == 0 ʱ�ͻ����ǰ׺ 0��
    while (C.size() > 1 && C.back() == 0) C.pop_back();

    return C; // ���س˻� C������洢��
}

///////////////////////////////////////////////////////////////////////////////////////////////////

#include <algorithm>

/**
 * @brief �������� A / b = C ... r
 * @param A �����������Ǹ�����������洢��
 * @param b ��������������
 * @param r ������out��
 * @return �̣�����洢��
 */
static vector<int> div(vector<int>& A, int b, int& r) {
    vector<int> C;  // ������

    // ���㣨���ճ�������˼ά���ɣ�
    r = 0;  // ������ʼ��Ϊ 0
    for (int i = A.size() - 1; i >= 0; i--) {
        r = r * 10 + A[i];      // ���㵱ǰλ���ӱ�����
        C.push_back(r / b);     // ���㵱ǰλ��ֵ C[i]
        r %= b;                 // ���㵱ǰλ��������
    }

    // �����洢��ʽ
    // ������ɺ󣬴洢�Ľ���ǡ�˳��洢���ģ���Ҫ��ת
    reverse(C.begin(), C.end());// ע�⣺������뷭ת

    // ȥ��ǰ׺ 0
    while (C.size() > 1 && C.back() == 0) C.pop_back();


    // ���ؽ��
    return C;
}
