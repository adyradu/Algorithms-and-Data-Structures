// https://leetcode.com/problems/word-ladder-ii/submissions/
//
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<algorithm>

using namespace std;

bool canTransformInto(string& a, string& b) {
    int cnt = 0;
    
    for(int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            ++cnt;
        }
        
        if (cnt > 1) {
            return false;
        }
    }
    
    return cnt == 1;
}

void getAllPossibleNextTransformations(string& beginWord, vector<string>& wordList, vector<string>& nextWords) {
    for (string w : wordList) {
        if (canTransformInto(beginWord, w)) {
            nextWords.push_back(w);
        }
    }
}

int bfs_dist(string& beginWord, string& endWord, vector<string>& wordList, unordered_map<string, vector<string>>& m,
            unordered_map<string, int>& restore) {
    queue<pair<string, int>> q;
    unordered_set<string> visited;
    int minPath = INT_MAX;
    vector<string> initPath;
    
    q.push(pair<string, int>(beginWord, 1));
    restore.insert(pair<string, int>(beginWord, 1));
    
    while (!q.empty()) {
        auto curPair = q.front();
        q.pop();
        
        string lastWord = curPair.first;
        int noWords = curPair.second + 1;
        
        visited.insert(lastWord);
        
        if (m.find(lastWord) == m.end()) {
            vector<string> nw;
            getAllPossibleNextTransformations(lastWord, wordList, nw);
            
            m.insert(pair<string, vector<string>>(lastWord, nw));
        }
        
        vector<string>& nextWords = m[lastWord];
        
        bool found = false;
        
        for (string w : nextWords) {
            
            if (w == endWord) {
                minPath = noWords;
                restore.insert(pair<string, int>(w, noWords));
            }
            else if (visited.find(w) == visited.end()){
                q.push(pair<string, int>(w, noWords));
                restore.insert(pair<string, int>(w, noWords));
            }
        }
        
        if (found) {
            return minPath;
        }
    }
    
    return minPath;
}

void dfs(string& beginWord, string& endWord, vector<string> path, unordered_set<string> pathset, vector<string>& wordList, vector<vector<string>>& paths, int& minPath, unordered_map<string, vector<string>>& m, unordered_map<string, int>& restore) {
    path.push_back(beginWord);
    //pathset.insert(beginWord);
    if (beginWord == endWord) {
        paths.push_back(path);
        return;
    }
    else if (path.size() == minPath) {
        return;
    }
    
    if (m.find(beginWord) == m.end()) {
        vector<string> nw;
        getAllPossibleNextTransformations(beginWord, wordList, nw);

        m.insert(pair<string, vector<string>>(beginWord, nw));
    }

    vector<string>& nextWords = m[beginWord];
    
    for (string w : nextWords) {
        if ((restore.find(w) == restore.end() &&
            restore.find(beginWord) == restore.end()) ||
            restore[w] == restore[beginWord] + 1) {
            dfs(w, endWord, path, pathset, wordList, paths, minPath, m, restore);
        }
    }
    
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> result;
    bool found = false;
    unordered_map<string, int> restore;
    unordered_map<string, vector<string>> m;

    for (string s : wordList) {
        if (s == endWord) {
            found = true;
        }
    }
    
    if (!found) {
        return result;
    }
    
    int minPath = bfs_dist(beginWord, endWord, wordList, m, restore);
    
    vector<string> path;
    unordered_set<string> pathset;
    dfs(beginWord, endWord, path, pathset, wordList, result, minPath, m, restore);
    
    return result;
}

int main(void)
{
    return 0;
}