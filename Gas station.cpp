#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int total_gas = 0;
    int total_cost = 0;
    int current_gas = 0;
    int start_station = 0;

    for (int i = 0; i < gas.size(); ++i) {
        total_gas += gas[i];
        total_cost += cost[i];
        current_gas += gas[i] - cost[i];
        if (current_gas < 0) {
            start_station = i + 1;
            current_gas = 0;
        }
    }

    if (total_gas < total_cost) {
        return -1;
    }

    return start_station;
}

int main() {
    int n;
    cout << "Enter the number of gas stations: ";
    cin >> n;

    vector<int> gas(n);
    vector<int> cost(n);

    cout << "Enter gas for each station: ";
    for (int i = 0; i < n; ++i) {
        cin >> gas[i];
    }

    cout << "Enter cost for each station: ";
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    int result = canCompleteCircuit(gas, cost);

    if (result != -1) {
        cout << "You can start from station " << result << "." << endl;
    }
    else {
        cout << "You cannot complete the circuit." << endl;
    }

    return 0;
}
/*核心算法基于贪心策略

算法的基本思想是，从第一个加油站出发，累积汽油剩余量，如果在某个加油站剩余汽油不足以到达下一个加油站
则将下一个加油站作为新的起点，同时重置累积的汽油剩余量。最终，如果所有加油站的汽油总量大于等于消耗总量，则返回当前起点的索引，否则返回 -1*/

