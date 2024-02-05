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
