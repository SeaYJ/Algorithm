#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 非负大数运算 C = A + B
 * @param A 非负加数（逆序存储）
 * @param B 非负加数（逆序存储）
 * @return 运算结果（逆序存储）
 */
static vector<int> add(vector<int>& A, vector<int>& B) {
    vector<int> C;  // 运算结果

    // 加法计算
    int t = 0;      // 加法进位：来自低位
    for (int i = 0; i < A.size() || i < B.size(); i++) {    // 注意：要把两个数的所有位都计算完
        // 计算 A[i] + B[i] + t
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];

        C.push_back(t % 10);    // 保存本位的数值结果
        t /= 10;                // 计算向上的进位值
    }

    // 有可能 A 和 B 中的最高位之上还有进位值
    if (t) C.push_back(t);
    
    // 返回结果
    return C;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief 判断 A >= B
 * @param A 非负整数（逆序存储）
 * @param B 非负整数（逆序存储）
 * @return A 是否大于等于 B
 */
static bool cmp(vector<int>& A, vector<int>& B) {
    // 位数检验
    if (A.size() != B.size()) {     // 当 A 和 B 位数不一样时
        return A.size() > B.size(); // 位数更长的数值更大
    }

    // 位数一致时：数值检验
    for (int i = A.size() - 1; i >= 0; i--) {   // 从高位到向低位遍历（注意 A 和 B 位数一致）
        if (A[i] != B[i]) {                     // 第一个同位数值不相同的位置出现
            return A[i] > B[i];                 // 该位上数值更大的数更大
        }
    }
    
    // 全部相等时（A = B）
    return true;
}

/**
 * @brief 计算 C = A - B（注意 A 必须大于等于 B，使用前必须检查）
 * @param A 非负整数（逆序存储）
 * @param B 非负整数（逆序存储）
 * @return 运算结果
 */
static vector<int> sub(vector<int>& A, vector<int>& B) {
    vector<int> C;  // 运算结果

    // 减法计算
    int t = 0;      // 减法借位：来自低位
    for (int i = A.size() - 1; i >= 0; i--) {
        // 计算 A[i] - B[i]
        t = A[i] - t;
        if (i < B.size()) t -= B[i];

        // 注意借位：
        //   - 减去低位借位 t（与下面代码中的 t 不是同一个东西）
        //   - 如果向高位借位要加上 10
        // 总和下来就是 (t + 10) % 10 得到本位的数值（这里处理比较巧妙，多理解）
        C.push_back((t + 10) % 10);

        // 如果小于 0 代表需要向高位借位
        t = (t < 0 ? 1 : 0);
    }

    // 去掉前缀 0（注意结果 C 为 0 的情况）
    while (C.size() > 1 && C.back() == 0) C.pop_back();

    // 返回结果
    return C;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief 低配版大数乘法 C = A * b
 * @param A 非负整数（逆序存储）
 * @param b 非负整数
 * @return 积（逆序存储）
 */
static vector<int> mul(vector<int>& A, int b) {
    vector<int> C;  // 运算结果

    // 运算：(A[i] * b + t) % 10
    // 这里比较难理解（与平常的乘法列式计算方式有所不同）
    for (int i = 0, t = 0; i < A.size() || t; i++) {
        // C[i] = (A[i] * b + t) % 10
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);

        // 计算进位
        t /= 10;
    }

    // 去掉可能的前缀 0（当 b == 0 时就会出现前缀 0）
    while (C.size() > 1 && C.back() == 0) C.pop_back();

    // 返回结果
    return C;
}

/**
 * @brief 高配版大数乘法 C = A * B
 * @param A 非负整数（逆序存储）
 * @param B 非负整数（逆序存储）
 * @return 积（逆序存储）
 */
static vector<int> mul(vector<int> A, vector<int> B)
{
    // 创建一个大小为 A.size() + B.size() 的向量 C 来存储运算结果
    vector<int> C(A.size() + B.size());

    // 两层循环遍历 A 和 B 的每一位，计算每一位的乘积
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            C[i + j] += A[i] * B[j]; // 将乘积累加到 C 中对应的位置
        }
    }

    // 处理进位
    for (int i = 0, t = 0; i < C.size() || t; i++)
    {
        t += C[i];              // 将当前位的值加到进位中
        if (i >= C.size()) {
            C.push_back(t % 10);// 如果 C 还未扩展，进行扩展并存储当前位
        }
        else {
            C[i] = t % 10;      // 更新当前位为个位数
        }

        t /= 10;                // 计算新的进位
    }

    // 去掉可能的前缀 0（当 b == 0 时就会出现前缀 0）
    while (C.size() > 1 && C.back() == 0) C.pop_back();

    return C; // 返回乘积 C（逆序存储）
}

///////////////////////////////////////////////////////////////////////////////////////////////////

#include <algorithm>

/**
 * @brief 低配版除法 A / b = C ... r
 * @param A 被除数——非负整数（逆序存储）
 * @param b 除数——正整数
 * @param r 余数（out）
 * @return 商（逆序存储）
 */
static vector<int> div(vector<int>& A, int b, int& r) {
    vector<int> C;  // 运算结果

    // 运算（按照常规运算思维即可）
    r = 0;  // 余数初始化为 0
    for (int i = A.size() - 1; i >= 0; i--) {
        r = r * 10 + A[i];      // 计算当前位的子被除数
        C.push_back(r / b);     // 计算当前位的值 C[i]
        r %= b;                 // 计算当前位的子余数
    }

    // 修正存储方式
    // 计算完成后，存储的结果是“顺序存储”的，需要翻转
    reverse(C.begin(), C.end());// 注意：这里必须翻转

    // 去除前缀 0
    while (C.size() > 1 && C.back() == 0) C.pop_back();


    // 返回结果
    return C;
}
