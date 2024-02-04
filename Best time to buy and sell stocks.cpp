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
