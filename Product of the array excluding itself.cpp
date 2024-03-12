#include <iostream>
#include <vector>

using namespace std;
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> answer(n, 1);
    // Calculate the product of all elements to the left of each element
    int leftProduct = 1;
    for (int i = 0; i < n; ++i) {
        answer[i] *= leftProduct;
        leftProduct *= nums[i];
    }
    int rightProduct = 1;
    for (int i = n - 1; i >= 0; --i) {
        answer[i] *= leftProduct;
        rightProduct *= nums[i];
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

    cout << "Output array: ";
    for (int num : answer) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}