#include<iostream>
#include<string>

using namespace std;

// 将整数转换为罗马数字的函数
// Function to convert an integer to Roman numeral

string intToRoman(int num) {
	string result = "";

	string romanChars[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	int values[] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };

	// 逐步减去对应的值，并将对应的罗马字符加入结果中
	// Subtract corresponding values step by step and append corresponding Roman characters to the result

	for (int i = 0; i < 13; i++) {
		while (num >= values[i]) {
			num -= values[i];
			result += romanChars[i];
		}
	}
	return result;

}

int main() {
	int num;
	cout << "enter the integer (1 to 3999):" << endl;
	cin >> num;

	if (num < 1 || num >3999) {
		cout << "input integer is out of valid range!" << endl;
		return 1;
	}

	string roman = intToRoman(num);
	cout << "Roman numeral is:" << roman << endl;

	return 0;

}
