#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = nums1.size() - 1;
        m--;
        n--;
        while (n >= 0) {
            while (m >= 0 && nums1[m] > nums2[n]) {
                swap(nums1[i--], nums1[m--]);
            }
            swap(nums1[i--], nums2[n--]);
        }
    }
};

int main() {
    Solution solution;

    // 示例数组
    vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
    int m = 3;
    vector<int> nums2 = { 2, 5, 6 };
    int n = 3;

    // 合并数组
    solution.merge(nums1, m, nums2, n);

    // 打印合并后的数组
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
