/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

*/
#include <string>
#include <limits>
#include <iostream>

using namespace std;


class Solution {
public:
	int myAtoi(string str) {
		str = trim(str);

		// TODO: deal positive or negtive symbol
		bool isNegtive = false;
		if (isMinus(str[0])) { 
			isNegtive = true; 
			str = str.substr(1);
		}
		else if (isPositive(str[0])) {
			isNegtive = false;
			str = str.substr(1);
		}

		int result = 0;
		
		unsigned int i = 0;
		while (i < str.length() && isDigital(str[i])) {
			int old = result;
			result = result * 10 + (str[i] - '0');
			i++;
			// Check the overflow
			if (result / 10 != old) {
				return isNegtive ? numeric_limits<int>::min() : numeric_limits<int>::max();
			}
		}
		return isNegtive ? result * -1 : result;
	}
private:
	string trim(string s) {
		unsigned int i;
		for (i = 0; i < s.length() && isWhitespace(s[i]); i++) { ; }  
		if (i > 0) {
			return s.substr(i);
		}
		else {
			return s;
		}
	}

	bool isDigital(char c) {
		if (c >= '0' && c <= '9') {
			return true;
		}
		return false;
	}

	bool isMinus(char c) {
		if (c == '-') { return true; }
		return false;
	}

	bool isPositive(char c) {
		if (c == '+') { return true; }
		return false;
	}

	bool isWhitespace(char c) {
		if (c == ' ' || c == '\t') {
			return true;
		}
		return false;
	}
};

int main() {
	string test = "    -99d99dom! ";
	Solution* sol = new Solution();
	cout << sol->myAtoi(test) << endl;
}