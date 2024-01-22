#include <iostream>
#include <vector>

class Solution {
public:
    // 函数用于找到数组中的多数元素
    int majorityElement(std::vector<int>& nums) {
        // 初始化候选元素和计数器
        int candidate = nums[0];
        int count = 1;

        // 遍历数组
        for (int i = 1; i < nums.size(); ++i) {
            // 如果计数为零，则更新候选元素
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            }
            // 如果当前元素与候选元素相同，则增加计数
            else if (nums[i] == candidate) {
                ++count;
            }
            // 如果当前元素不同，则减少计数
            else {
                --count;
            }
        }

        // 候选元素即为多数元素
        return candidate;
    }
};

int main() {
    Solution solution;

    // 提示用户输入数组元素
    std::cout << "nums：";

    std::vector<int> nums;
    int num;

    // 读取输入元素，直到提供非整数输入
    while (std::cin >> num) {
        nums.push_back(num);
    }

    // 使用 majorityElement 函数找到多数元素
    int result = solution.majorityElement(nums);

    // 显示多数元素
    std::cout << "majorityElement：" << result << std::endl;

    return 0;
}
