/*给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
示例 2：

输入：height = [4,2,0,3,2,5]
输出：9*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) { // If there are no pillars, return 0 as there is no water trapped
            return 0;
        }
        vector<int> leftMax(n); // Create an array to store the maximum height to the left of each position
        leftMax[0] = height[0]; // The maximum height to the left of the first pillar is its own height
        for (int i = 1; i < n; ++i) { // Calculate the maximum height to the left of each position
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        vector<int> rightMax(n); // Create an array to store the maximum height to the right of each position
        rightMax[n - 1] = height[n - 1]; // The maximum height to the right of the last pillar is its own height
        for (int i = n - 2; i >= 0; --i) { // Calculate the maximum height to the right of each position
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        int ans = 0; // Initialize the amount of trapped water to 0
        for (int i = 0; i < n; ++i) { // Iterate through each position and calculate the amount of water that can be trapped at that position
            ans += min(leftMax[i], rightMax[i]) - height[i]; // The amount of water trapped is the minimum of the maximum heights to the left and right minus the height of the current pillar
        }
        return ans; // Return the total amount of trapped water
    }
};

int main() {
    Solution solution;
    vector<int> height;
    int n, input;

    cout << "Enter the number of elements in the height array: ";
    cin >> n;

    cout << "Enter the elements of the height array: ";
    for (int i = 0; i < n; ++i) { // Input the height of each pillar
        cin >> input;
        height.push_back(input); // Add the height to the height vector
    }

    int result = solution.trap(height); // Call the trap function to calculate the amount of trapped water
    cout << "The amount of water that can be trapped is: " << result << endl; // Output the result

    return 0;
}
