#include <iostream>
#include <vector>

using namespace std;

// Function to find the starting gas station index to complete the circuit
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    // Initialize variables to track total gas, total cost, current gas, and start station index
    int total_gas = 0;
    int total_cost = 0;
    int current_gas = 0;
    int start_station = 0;

    // Iterate through each gas station
    for (int i = 0; i < gas.size(); ++i) {
        // Calculate total gas and total cost
        total_gas += gas[i];
        total_cost += cost[i];
        // Calculate current gas considering the current station
        current_gas += gas[i] - cost[i];
        // If current gas is negative, reset start station to the next station and reset current gas
        if (current_gas < 0) {
            start_station = i + 1;
            current_gas = 0;
        }
    }

    // If total gas is less than total cost, it's impossible to complete the circuit
    if (total_gas < total_cost) {
        return -1;
    }

    // Return the starting gas station index
    return start_station;
}

// Main function
int main() {
    int n;
    // Prompt user to enter the number of gas stations
    cout << "Enter the number of gas stations: ";
    cin >> n;

    // Initialize vectors to store gas and cost for each station
    vector<int> gas(n);
    vector<int> cost(n);

    // Prompt user to enter gas for each station
    cout << "Enter gas for each station: ";
    for (int i = 0; i < n; ++i) {
        cin >> gas[i];
    }

    // Prompt user to enter cost for each station
    cout << "Enter cost for each station: ";
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    // Call the function to find the starting gas station index
    int result = canCompleteCircuit(gas, cost);

    // Output the result
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

