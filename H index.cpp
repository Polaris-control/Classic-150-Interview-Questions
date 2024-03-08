#include <iostream>
#include <vector>
#include <algorithm>

int hIndex(std::vector<int>& citations) {
    std::sort(citations.begin(), citations.end(), std::greater<int>());
    int h = 0;
    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] >= i + 1) {
            h = i + 1;
        }
        else {
            break;
        }
    }
    return h;
}

int main() {
    std::vector<int> citations;
    int n;
    std::cout << "Enter the number of citations: ";
    std::cin >> n;
    std::cout << "Enter the citations: ";
    for (int i = 0; i < n; i++) {
        int citation;
        std::cin >> citation;
        citations.push_back(citation);
    }
    int h = hIndex(citations);
    std::cout << "The h-index is: " << h << std::endl;
    return 0;
}
/*这段代码首先对引用次数进行排序，然后遍历排序后的引用次数数组，
找到最大的h值。h的初始值为0，然后从数组的第一个元素开始遍历，如果当前元素的引用次数大于等于当前索引+1，
将h更新为当前索引+1。如果当前元素的引用次数小于当前索引+1，则结束遍历。最后返回h作为h指数。*/