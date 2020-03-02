// https://leetcode.com/problems/network-delay-time/
//
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Edge {
    Edge(int _child, int _dist)
        :
        child(_child),
        dist(_dist)
    {}
    
    int child;
    int dist;
};

void buildAdjacencyList(vector<vector<int>>& times, vector<vector<Edge>>& adjList) {
    for(auto e : times) {
        adjList[e[0]].push_back(Edge(e[1], e[2]));
    }
}

int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    vector<vector<Edge>> adjList(N + 1);
    vector<bool> visited(N + 1);
    vector<int> dist(N + 1);
    
    visited.assign(N + 1, false);
    visited[0] = true;
    
    dist.assign(N + 1, INT_MAX);
    
    buildAdjacencyList(times, adjList);
    
    queue<int> q;
    q.push(K);
    dist[K] = 0;
    int result = INT_MIN;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        visited[cur] = true;
        
        for(auto e : adjList[cur]) {
            int newDist = dist[cur] + e.dist;
            if (newDist < dist[e.child]) {
                dist[e.child] = newDist;
                q.push(e.child);
            }
        }
    }
    
    for (int i = 1; i < dist.size(); ++i) {
        if (!visited[i]) {
            return -1;
        }
        
        if (result < dist[i]) {
            result = dist[i];
        }
    }
    
    return result;
}

int main(void)
{
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int N = 4;
    int K = 2;

    cout<<networkDelayTime(times, N, K)<<endl;

    return 0;
}