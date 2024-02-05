#include <iostream>
#include <vector>

int maxProfit(std::vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) {
        return 0; // 如果数组长度小于等于1，则无法进行交易，最大利润为0
    }

    int maxProfit = 0; // 初始化最大利润为0
    int minPrice = prices[0]; // 初始化最低股价为第一天的股价

    for (int i = 1; i < n; ++i) {
        // 更新最低股价
        minPrice = std::min(minPrice, prices[i]);

        // 计算当前利润并更新最大利润
        maxProfit = std::max(maxProfit, prices[i] - minPrice);
    }

    return maxProfit;
}

int main() {
    int n;

    // 从键盘获取数组大小
    std::cout << "Enter the array size: ";
    std::cin >> n;

    std::vector<int> prices(n);

    // 从键盘获取股票价格数组
    std::cout << "Enter the element: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> prices[i];
    }

    // 计算最大利润
    int result = maxProfit(prices);

    // 输出结果
    std::cout << "maximun profit: " << result << std::endl;

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
