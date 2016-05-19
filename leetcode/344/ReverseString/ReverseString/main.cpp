/*
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".

Subscribe to see which companies asked this question

*/

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	string reverseString(string s) {
		for (int left = 0, right = s.length() - 1; left < right; left++, right--) {
			char tmp = s[left];
			s[left] = s[right];
			s[right] = tmp;
		}
		return s;
	}
};

int main() {
	Solution test;
	cout << test.reverseString("hello") << endl;
}