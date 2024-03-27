/*给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
示例 2：

输入：height = [4,2,0,3,2,5]
输出：9

方法一：动态规划

对于下标 i，下雨后水能到达的最大高度等于下标 iii 两边的最大高度的最小值，下标 i 处能接的雨水量等于下标 i 处的水能到达的最大高度减去 height[i]。

朴素的做法是对于数组 height 中的每个元素，分别向左和向右扫描并记录左边和右边的最大高度，然后计算每个下标位置能接的雨水量。假设数组 height 的长度为 n，该做法需要对每个下标位置使用 O(n) 的时间向两边扫描并得到最大高度，因此总时间复杂度是 O(n^2)。

上述做法的时间复杂度较高是因为需要对每个下标位置都向两边扫描。如果已经知道每个位置两边的最大高度，则可以在 O(n) 的时间内得到能接的雨水总量。使用动态规划的方法，可以在 O(n) 的时间内预处理得到每个位置两边的最大高度。

算法步骤
创建两个长度为 n 的数组 leftMax 和 rightMax。对于 0 ≤ i < n，leftMax[i] 表示下标 i 及其左边的位置中，height 的最大高度，rightMax[i] 表示下标 i 及其右边的位置中，height 的最大高度。
计算 leftMax 和 rightMax 的值。
当 1 ≤ i ≤ n−1 时，leftMax[i] = max(leftMax[i−1], height[i])。
当 0 ≤ i ≤ n−2 时，rightMax[i] = max(rightMax[i+1], height[i])。
遍历 height 数组，对于每个位置 i，计算 min(leftMax[i], rightMax[i]) − height[i]，即该位置能接的雨水量，并累加得到总的雨水量。
复杂度分析
时间复杂度：O(n)，其中 n 是数组 height 的长度。预处理 leftMax 和 rightMax 数组需要 O(n) 的时间，遍历 height 数组同样需要 O(n) 的时间。
空间复杂度：O(n)，需要额外的空间存储 leftMax 和 rightMax 数组。

*/

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
