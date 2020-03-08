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

void getNextWords(string& beginWord, vector<string>& wordList, vector<string>& nextWords) {
    int size = beginWord.size();

    for (string w : wordList) {
        int diff = 0;

        for (int i = 0; i < size; ++i) {
            if (beginWord[i] != w[i]) {
                ++diff;
            }

            if (diff > 1) {
                break;
            }
        }

        if (diff == 1) {
            nextWords.push_back(w);
        }
    }     
}
    
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<pair<string, int>> q_up;
    queue<pair<string, int>> q_down;
    int size = beginWord.size();
    unordered_map<string, vector<string>> nextWordsMap;
    unordered_map<string, int> visited_up;
    unordered_map<string, int> visited_down;
    
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
    
    q_up.push(pair<string, int>(beginWord, 1));
    q_down.push(pair<string, int>(endWord, 1));
    
    while (!q_up.empty() && !q_down.empty()) {
        auto p_up = q_up.front(); q_up.pop();
        string curWordUp = p_up.first;
        int nextLevelUp = p_up.second + 1;
        
        if (nextWordsMap.find(curWordUp) == nextWordsMap.end()) {
            vector<string> nw;
            getNextWords(curWordUp, wordList, nw);
            nextWordsMap.insert(pair<string, vector<string>>(curWordUp, nw));
        }
        
        vector<string> nextWords = nextWordsMap[curWordUp];
        
        int minUpFound = INT_MAX;
        
        for (string w : nextWords) {           
            if (visited_down.find(w) != visited_down.end()) {
                int dist = nextLevelUp + visited_down[w] - 1;
                
                if (dist < minUpFound) {
                    minUpFound = dist;
                }
            }
            
            if (visited_up.find(w) == visited_up.end()) {
                q_up.push(pair<string, int>(w, nextLevelUp));
            }
        }
        
        visited_up.insert(pair<string, int>(curWordUp, p_up.second));
        
        if (minUpFound != INT_MAX) {
            return minUpFound;
        }
        
        auto p_down = q_down.front(); q_down.pop();
        string curWordDown = p_down.first;
        int nextLevelDown = p_down.second + 1;
        
        if (nextWordsMap.find(curWordDown) == nextWordsMap.end()) {
            vector<string> nw;
            getNextWords(curWordDown, wordList, nw);
            nextWordsMap.insert(pair<string, vector<string>>(curWordDown, nw));
        }
        
        nextWords = nextWordsMap[curWordDown];
        
        int minDownFound = INT_MAX;
        
        for (string w : nextWords) {
            
            if (visited_up.find(w) != visited_up.end()) {
                int dist = nextLevelDown + visited_up[w] - 1;
                if (dist < minDownFound) {
                    minDownFound = dist;
                }
            }
            
            if (visited_down.find(w) == visited_down.end()) {
                q_down.push(pair<string, int>(w, nextLevelDown));
            }
        }
        
        visited_down.insert(pair<string, int>(curWordDown, p_down.second));
        
        if (minDownFound != INT_MAX) {
            return minDownFound;
        }
    }
    
    return 0;
}


int main(void)
{
    return 0;
}