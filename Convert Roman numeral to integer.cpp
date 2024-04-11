 #include <iostream>
#include <vector>
#include <string>

    using namespace std;

    class Solution {
    public:
        int romanToInt(string s) {
            vector<int> romanMap(128, 0); // 初始化ASCII码表的大小为128，所有字符的初始值为0
            romanMap['I'] = 1;
            romanMap['V'] = 5;
            romanMap['X'] = 10;
            romanMap['L'] = 50;
            romanMap['C'] = 100;
            romanMap['D'] = 500;
            romanMap['M'] = 1000;

            int result = 0;
            int prevValue = 0;

            for (char c : s) {
                int value = romanMap[c];
                result += value;

                if (value > prevValue) {
                    // 减去上一个字符的值的两倍，因为上一个字符已经被加过一次了
                    result -= 2 * prevValue;
                }

                prevValue = value;
            }

            return result;
        }
    };

    int main() {
        string s;
        cout << "Enter the roman number: ";
        cin >> s;

        Solution sol;
        int result = sol.romanToInt(s);
        cout << "Total number: " << result << endl;

        return 0;
    }
