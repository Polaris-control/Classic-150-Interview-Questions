﻿#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class RandomizedSet {
private:
    unordered_map<int, int> valToIndex;
    vector<int> values;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(NULL));
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (valToIndex.find(val) != valToIndex.end())
            return false;

        values.push_back(val);
        valToIndex[val] = values.size() - 1;

        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (valToIndex.find(val) == valToIndex.end())
            return false;

        int index = valToIndex[val];
        int lastVal = values.back();

        values[index] = lastVal;
        valToIndex[lastVal] = index;

        values.pop_back();
        valToIndex.erase(val);

        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int randomIndex = rand() % values.size();
        return values[randomIndex];
    }
};

int main() {
    RandomizedSet randomizedSet;
    int val;
    char operation;

    while (true) {
        cout << "Enter operation (i for insert, r for remove, g for getRandom) followed by value: ";
        cin >> operation >> val;

        switch (operation) {
        case 'i':
            cout << randomizedSet.insert(val) << endl;
            break;
        case 'r':
            cout << randomizedSet.remove(val) << endl;
            break;
        case 'g':
            cout << randomizedSet.getRandom() << endl;
            break;
        default:
            cout << "Invalid operation!" << endl;
            break;
        }
    }

    return 0;
}

/*代码的核心是实现了一个数据结构 RandomizedSet
它提供了在常数时间复杂度内执行插入、删除和获取随机元素的功能。这个数据结构的核心思想是利用了哈希表（unordered_map）和动态数组（vector）*/
