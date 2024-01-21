#include <iostream>
#include<vector>


using namespace std;

int removeDuplicates(std::vector<int>& nums) {
    //数组长度小于等于2的时候数组不会改变 所以直接输出 数组长度和 数组
    if (nums.size() <= 2) {
        return  nums.size();

    }
    int i = 2;
    int j = 1;
    //使用双指针 i 指向原数组的第三个元素 j指向新数组的最后一个元素
    while (i < nums.size()) {
        if (nums[i] == nums[j] && nums[i] == nums[j - 1]) {
            i++;
        }//原数组当前检查元素如果和新数组的最后或倒数第二个元素相同时 向后移动索引
        else {
            j++;
            nums[j] = nums[i];
            i++;
        }//比较元素不同时更新当前元素到新数组中
    }
    return j + 1;
}

    int main(){
        std::vector<int>nums;

        int num;
        std::cout << "nums=" << std::endl;

        while (std::cin >> num) {
           
            nums.push_back(num);
        }
        int len = removeDuplicates(nums);

        std::cout << "length:" << len << ",nums = [";
        for (int i = 0; i < len; i++) {
            std::cout << nums[i]<< (i == len-1 ? "": ",");
            //为了确保最后一个元素后面没有额外的逗号和空格

        }
        std::cout << "]\n";

        return 0;
    }