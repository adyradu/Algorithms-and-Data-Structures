// https://leetcode.com/problems/word-ladder/
//
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<pair<string, int>> q;
    int size = beginWord.size();
    unordered_map<string, vector<string>> nextWordsMap;
    unordered_set<string> visited;
    
    // Check whether the endWord is in the wordList
    //
    bool found = false;
    for (string w : wordList) {
        if (w == endWord) {
            found = true;
            break;
        }
    }
    
    if (!found) {
        return 0;
    }
    
    q.push(pair<string, int>(beginWord, 1));
    
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        string curWord = p.first;
        int nextLevel = p.second + 1;
        visited.insert(curWord);
        
        if (nextWordsMap.find(curWord) == nextWordsMap.end()) {
            vector<string> nw;
            for (string w : wordList) {
                int diff = 0;

                for (int i = 0; i < size; ++i) {
                    if (curWord[i] != w[i]) {
                        ++diff;
                    }

                    if (diff > 1) {
                        break;
                    }
                }

                if (diff == 1) {
                    nw.push_back(w);
                }
            }
            
            nextWordsMap.insert(pair<string, vector<string>>(curWord, nw));
        }
        
        vector<string> nextWords = nextWordsMap[curWord];
        
        for (string w : nextWords) {
            if (w == endWord) {
                return nextLevel;
            }
            
            if (visited.find(w) == visited.end()) {
                q.push(pair<string, int>(w, nextLevel));
            }
        }
    }
    
    return 0;
}

int main(void)
{
    return 0;
}