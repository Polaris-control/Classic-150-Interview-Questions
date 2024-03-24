/*n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。

你需要按照以下要求，给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻两个孩子评分更高的孩子会获得更多的糖果。
请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。

 

示例 1：

输入：ratings = [1,0,2]
输出：5
解释：你可以分别给第一个、第二个、第三个孩子分发 2、1、2 颗糖果。
示例 2：

输入：ratings = [1,2,2]
输出：4
解释：你可以分别给第一个、第二个、第三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这满足题面中的两个条件。*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candies(n, 1); // 初始化每个孩子至少有一个糖果

    // 从左往右遍历，如果右边孩子的评分高于左边孩子，则右边孩子的糖果数为左边孩子的糖果数加一
    for (int i = 1; i < n; ++i) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // 从右往左遍历，如果左边孩子的评分高于右边孩子且糖果数不满足要求，则更新左边孩子的糖果数
    for (int i = n - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    // 统计总共需要的糖果数
    int total = 0;
    for (int candy : candies) {
        total += candy;
    }

    return total;
}

int main() {
    int n;
    cout << "Enter the number of children: ";
    cin >> n;

    vector<int> ratings(n);
    cout << "Enter the ratings of each child: ";
    for (int i = 0; i < n; ++i) {
        cin >> ratings[i];
    }

    int minCandies = candy(ratings);
    cout << "Minimum number of candies required: " << minCandies << endl;

    return 0;
}
