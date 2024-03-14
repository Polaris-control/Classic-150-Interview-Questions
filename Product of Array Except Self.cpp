#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> left(n, 1);
    vector<int> right(n, 1);
    vector<int> answer(n, 1);

    // 计算每个元素左侧所有元素的乘积
    for (int i = 1; i < n; ++i) {
        left[i] = left[i - 1] * nums[i - 1];
    }

    // 计算每个元素右侧所有元素的乘积
    for (int i = n - 2; i >= 0; --i) {
        right[i] = right[i + 1] * nums[i + 1];
    }

    // 左侧乘积与右侧乘积相乘得到最终结果
    for (int i = 0; i < n; ++i) {
        answer[i] = left[i] * right[i];
    }

    return answer;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<int> answer = productExceptSelf(nums);

    cout << "Resulting array: ";
    for (int num : answer) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
