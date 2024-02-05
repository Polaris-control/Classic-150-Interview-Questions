#include <iostream>
#include <vector>

int maxProfit(std::vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) {
        return 0; // 如果数组长度小于等于1，则无法进行交易，最大利润为0
    }

    int maxProfit = 0; // 初始化最大利润为0

    for (int i = 1; i < n; ++i) {
        // 如果当前股价高于前一天，就在前一天买入，在当天卖出
        if (prices[i] > prices[i - 1]) {
            maxProfit += prices[i] - prices[i - 1];
        }
    }

    return maxProfit;
}

int main() {
    int n;

    // 从键盘获取数组大小
    std::cout << "Enter array size: ";
    std::cin >> n;

    std::vector<int> prices(n);

    // 从键盘获取股票价格数组
    std::cout << "Enter array element: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> prices[i];
    }

    // 计算最大利润
    int result = maxProfit(prices);

    // 输出结果
    std::cout << "max price: " << result << std::endl;

    return 0;
}


/*给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。

在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。

返回 你能获得的 最大 利润 。

 

示例 1：

输入：prices = [7,1,5,3,6,4]
输出：7
解释：在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3 。
     总利润为 4 + 3 = 7 。
示例 2：

输入：prices = [1,2,3,4,5]
输出：4
解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4 。
     总利润为 4 。
示例 3：

输入：prices = [7,6,4,3,1]
输出：0
解释：在这种情况下, 交易无法获得正利润，所以不参与交易可以获得最大利润，最大利润为 0 。*/
