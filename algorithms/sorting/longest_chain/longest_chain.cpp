// Given a pair of numbers where in every pair the first
// element is less than the second element, find the
// longest chain of pairs so that for consecutive pair
// in the chain, (a, b) and (c, d), b < c.
//
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool comp(const vector<int>& v1, const vector<int>& v2) {
    return v1[1] < v2[0] || v1[1] < v2[1];
}

int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end(), comp);
    int res = 1;
    int lastPos = 0;
    int n = pairs.size();
    
    for (int i = 1; i < n; ++i) {
        if (pairs[i][0] > pairs[lastPos][1]) {
            res++;
            lastPos = i;
        }
    }
    
    return res;
}

int main(void)
{
    vector<vector<int>> pairs = {{1, 2}, {2, 3}, {3, 4}};

    cout<<findLongestChain(pairs)<<endl;

    return 0;
}