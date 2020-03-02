// https://leetcode.com/problems/loud-and-rich/
//
#include<iostream>
#include<vector>

using namespace std;

void buildAdjacencyList(vector<vector<int>>& richer, vector<vector<int>>& adjList)
{
    for (auto p : richer) {
        adjList[p[1]].push_back(p[0]);
    }
}

// Perform a post order traversal and build the result from bottom up.
//
int dfs (vector<vector<int>>& adjList, vector<int>& res, vector<int>& quiet, int i)
{
    if (res[i] >= 0) {
        return res[i];
    }
    
    res[i] = i;
    for (int c : adjList[i]) {
        if (quiet[dfs(adjList, res, quiet, c)] < quiet[res[i]]) {
            res[i] = res[c];
        }
    }

    return res[i];
}

vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet)
{
    int n = quiet.size();
    vector<vector<int>> adjList(n);
    vector<int> result(n);
    result.assign(n, -1);
    
    buildAdjacencyList(richer, adjList);
    
    for (int i = 0; i < n; ++i) {
        dfs(adjList, result, quiet, i);
    }
    
    return result;
}

int main(void)
{
    vector<vector<int>> richer = {{1, 0}, {2, 1}, {3, 1}, {3, 7}, {4, 3}, {5, 3}, {6, 3}};
    vector<int> quiet = {3, 2, 5, 4, 6, 1, 7, 0}; 

    vector<int> ans = loudAndRich(richer, quiet);

    for (int e : ans) {
        cout<<e<<" ";
    }

    cout<<endl;

    return 0;
}