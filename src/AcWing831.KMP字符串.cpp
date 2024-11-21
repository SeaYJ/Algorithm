#include <iostream>
#include <vector>
#include <string>

// 计算部分匹配表（前缀函数）
static std::vector<int> computePrefixFunction(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> lps(m, 0); // 最长相等前缀后缀数组
    int j = 0;

    for (int i = 1; i < m; ++i) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = lps[j - 1]; // 回退
        }
        if (pattern[i] == pattern[j]) {
            ++j;
        }
        lps[i] = j;
    }

    return lps;
}

// KMP匹配函数
static void KMP(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();

    // 计算部分匹配表
    std::vector<int> lps = computePrefixFunction(pattern);

    int j = 0; // pattern的指针

    for (int i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = lps[j - 1]; // 回退
        }
        if (text[i] == pattern[j]) {
            ++j;
        }
        if (j == m) {
            std::cout << "Pattern found at index " << i - m + 1 << std::endl;
            j = lps[j - 1]; // 寻找下一个匹配
        }
    }
}