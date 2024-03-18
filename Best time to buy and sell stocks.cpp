#include <iostream>
#include <vector>

// Function to calculate the maximum profit from buying and selling stocks
int maxProfit(std::vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) {
        return 0; // If the array length is less than or equal to 1, no transactions can be made, so maximum profit is 0
    }

    int maxProfit = 0; // Initialize maximum profit to 0
    int minPrice = prices[0]; // Initialize minimum stock price to the price of the first day

    // Loop through the prices array
    for (int i = 1; i < n; ++i) {
        // Update the minimum stock price
        minPrice = std::min(minPrice, prices[i]);

        // Calculate the current profit and update the maximum profit
        maxProfit = std::max(maxProfit, prices[i] - minPrice);
    }

    return maxProfit; // Return the maximum profit
}

// Main function
int main() {
    int n;

    // Get the size of the array from the user
    std::cout << "Enter the array size: ";
    std::cin >> n;

    std::vector<int> prices(n);

    // Get the stock prices array from the user
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> prices[i];
    }

    // Calculate the maximum profit
    int result = maxProfit(prices);

    // Output the result
    std::cout << "Maximum profit: " << result << std::endl;

    return 0;
}


/*给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

 

示例 1：

输入：[7,1,5,3,6,4]
输出：5
解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
示例 2：

输入：prices = [7,6,4,3,1]
输出：0
解释：在这种情况下, 没有交易完成, 所以最大利润为 0。 */
