/*
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
*/


#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        // dummyFindLadders(beginWord, endWord, wordList);
        vector<vector<string>>* result = new vector<vector<string>>();

        int round = 0;
        int shortestSteps = std::numeric_limits<int>::max();
        // Round by round, check the
        while(!wordList.empty()) {
            for (auto word=wordList.begin(); word!=wordList.end(); word++) {

            }
        }




    }
private:
    vector<vector<string>> dummyFindLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string>>* result = new vector<vector<string>>();
        vector<string>* r1 = new vector<string>();
        r1->push_back("hit");
        r1->push_back("hot");
        r1->push_back("dot");
        r1->push_back("dog");
        r1->push_back("cog");
        result->push_back(*r1);

        vector<string>* r2 = new vector<string>();
        r2->push_back("hit");
        r2->push_back("hot");
        r2->push_back("lot");
        r2->push_back("log");
        r2->push_back("cog");
        result->push_back(*r2);

        return *result;
    }
    int countDistance(string word1, string word2) {
        if (word1.length() != word2.length()) {
            return -1;
        }

        int count = 0;
        for (int i=0; i<word1.length(); i++) {
            if(word1[i] != word2[i]) {
                count ++;
            }
        }
        return count;
    }
};

int main() {
    Solution* sol = new Solution();
    unordered_set<string>* dict = new unordered_set<string>();
    vector<vector<string>> r = sol->findLadders("hit", "cog", *dict);

    // output the vector<vector>
    for (int i=0; i<r.size(); i++) {
        for (int j=0; j<r[i].size(); j++) {
            cout << r[i][j] << ", ";
        }
        cout << endl;
    }
    cout << "Hello, World!" << endl;
    return 0;
}