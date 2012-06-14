#include <iostream>
#include <string>

using namespace std;

int count_palindromic_slices(const string &S) {
	int count = 0;

	for (int position=0; position<S.length(); position++) {
		int offset = 0;

		// Check the "aa" situation
		while((position-offset>=0) && (position+offset+1)<S.length() && (S.at(position-offset))==(S.at(position+offset+1))) {
			count ++;
			offset ++;
		}

		offset = 1;  // reset it for the odd length checking
		// Check the string for "aba" situation
		while((position-offset>=0) && position+offset<S.length() && (S.at(position-offset))==(S.at(position+offset))) {
			count ++;
			offset ++;
		}
	}
	return count;
}

int main() {
	string s;
	cout << "Please input the string: ";
	cin >> s;
	int count = count_palindromic_slices(s);
	cout << count << endl;
}

