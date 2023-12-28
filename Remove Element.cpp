#include <iostream>
#include<vector>

using namespace std;



int removeElement(vector<int>& nums, int val) {
	int i = 0;
	for (int j = 0; j < nums.size(); ++j) {
		if (nums[j] != val) {
			nums[i] = nums[j];
			i++;
		}
	}
	return i;
}//移除 nums 数组中所有等于 val 的元素

int main() {
	vector<int> nums;

	int n, val, input;

	cout << "Enter the number of elements in the array:";

	cin >> n;

	cout << "Enter" << n << "elements:";
	for (int i = 0; i < n; ++i) {
		cin >> input;
		nums.push_back(input);
	}

	cout << "Enter the value to remove";
	cin >> val;

	int newLength = removeElement(nums, val);
	cout << "New Length:" << newLength << ",nums=[ ";
	for (int i = 0; i < newLength; ++i) {
		cout << nums[i] << (i < newLength - 1 ? "," : "");
		/*
		这行代码输出当前元素 nums[i],紧接着，使用三元运算符判断是否需要在元素后面加上逗号和空格（除了最后一个元素外，其他元素后面都需要加逗号和空格）
		如果 i 小于 newLength - 1（不是最后一个元素），则输出 ", "；否则（是最后一个元素），不输出任何内容。*/
	}
	cout << "]" << endl;

	return 0;
}