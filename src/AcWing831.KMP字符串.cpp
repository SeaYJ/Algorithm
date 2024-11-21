#include <iostream>
#include <vector>
#include <string>

// ���㲿��ƥ���ǰ׺������
static std::vector<int> computePrefixFunction(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> lps(m, 0); // ����ǰ׺��׺����
    int j = 0;

    for (int i = 1; i < m; ++i) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = lps[j - 1]; // ����
        }
        if (pattern[i] == pattern[j]) {
            ++j;
        }
        lps[i] = j;
    }

    return lps;
}

// KMPƥ�亯��
static void KMP(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();

    // ���㲿��ƥ���
    std::vector<int> lps = computePrefixFunction(pattern);

    int j = 0; // pattern��ָ��

    for (int i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = lps[j - 1]; // ����
        }
        if (text[i] == pattern[j]) {
            ++j;
        }
        if (j == m) {
            std::cout << "Pattern found at index " << i - m + 1 << std::endl;
            j = lps[j - 1]; // Ѱ����һ��ƥ��
        }
    }
}