#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 其实，“离散化”更像是一种思想，而不是某个算法模板。本质上，“离散化”的理念和哈希表有点类似，都是一种“映射”思想的具象化。

// 这里简单讲解一下：
// 离散化就是将一段连续的元素（有很多元素用不到，只会需要使用其中部分元素）中需要用到的元素提取出来，存放到新的空间里。
// 只不过这种存放是通过“映射”完成的，并不是真的申请一段空间进行存储，数据仍然存放在原空间。

// 所以，这里总结不出来什么算法模板。至于 AcWing 的标准答案里的 find 函数，我认为用 hash 表处理更为妥当。
// 最后，总结一个我认为相对来说比较重要的函数吧！

// 附注：实在理解不了“离散化”思想的可以看这个代码：https://www.acwing.com/solution/content/13511/#comment_content_702675
// 希望对你有帮助！

/**
 * @brief 移除数组中的重复元素
 * @param arr 待处理数组
 */
static void arrayDeduplication(vector<int>& arr) {
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    // unique 会将不重复的元素排到前面形成一个新序列，并返回不重复元素序列的 end() 迭代器。
    // 注意：unique 不会删除原数组的多余数据，只会将不重复的元素重新排列到前面，即 unique 不能改变数组或容器的大小。
    // 所以，最后多出来的位置需要用 erase 擦除。
}