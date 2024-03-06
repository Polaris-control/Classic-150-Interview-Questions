#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		int maxReachable = 0;

		for (int i = 0; i < n; ++i) {
			if (i <= maxReachable) {
				maxReachable = max(maxReachable, i + nums[i]);//更新当前能够到达的最远位置
				if (maxReachable >= n - 1) {
					return true; //如果当前最远位置已经能够到达最后一个下标。直接返回true
				}
			}
			
				
		}

		return false;
	}

	
};


int main()
{
	Solution solution;
	vector<int> nums;
	int num;
	cout << "Please enter a non-negative integer array element (end the input with -1):" << endl;
	while (true) {
		cin >> num;
		if (num == -1)
			break;
		nums.push_back(num);
	}
		bool result = solution.canJump(nums);
		if (result)
			cout << "True" << endl;
		else
			cout << "Flase" << endl;

		return 0;
	}
   

/*
* greedy algorithm

 我们可以用贪心的方法解决这个问题。

设想一下，对于数组中的任意一个位置 y，我们如何判断它是否可以到达？根据题目的描述，
只要存在一个位置 x，它本身可以到达，
并且它跳跃的最大长度为 x+nums[x]，
这个值大于等于 y，即 x+nums[x]≥y，那么位置 y 也可以到达。

换句话说，对于每一个可以到达的位置 x，
它使得 x+1,x+2,⋯ ,x+nums[x] 这些连续的位置都可以到达。

这样以来，我们依次遍历数组中的每一个位置，并实时维护 最远可以到达的位置。对于当前遍历到的位置 x，
如果它在 最远可以到达的位置 的范围内，那么我们就可以从起点通过若干次跳跃到达该位置，
因此我们可以用 x+nums[x]更新 最远可以到达的位置。

在遍历的过程中，如果 最远可以到达的位置 大于等于数组中的最后一个位置，那就说明最后一个位置可达，
我们就可以直接返回 True 作为答案。反之，如果在遍历结束后，最后一个位置仍然不可达，我们就返回 False 作为答案。


*/
