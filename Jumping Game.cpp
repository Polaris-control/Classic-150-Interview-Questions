#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		int maxReachable = 0;

		for (int i = 0; i < n; ++i) {
			if (i > maxReachable)
				return false;

			maxReachable = max(maxReachable, i + nums[i]);
			if (maxReachable >= n - 1) 
				return true;
			
				
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
   


