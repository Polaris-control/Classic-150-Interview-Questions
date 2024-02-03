#include <iostream>
#include <vector>

void rotate(std::vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n; // 处理 k 大于数组长度的情况

    // 先整体翻转数组
    std::reverse(nums.begin(), nums.end());

    // 再翻转前 k 个元素
    std::reverse(nums.begin(), nums.begin() + k);

    // 最后翻转剩余的元素
    std::reverse(nums.begin() + k, nums.end());
}

int main() {
    int size, k;

    // 从键盘获取数组大小和旋转步数
    std::cout << "Enter the size : ";
    std::cin >> size;

    std::vector<int> nums(size);

    std::cout << "Enter the element: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> nums[i];
    }

    std::cout << "k: ";
    std::cin >> k;

    // 执行数组旋转
    rotate(nums, k);

    // 输出结果
    std::cout << "result: [";
    for (int i = 0; i < nums.size(); ++i) {
        std::cout << nums[i];
        if (i < nums.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
