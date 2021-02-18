#include<iostream>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

typedef std::pair<vector<int>::const_iterator, vector<int>::const_iterator> PairIt;

/// <summary>
/// Merge k sorted arrays.
/// </summary>
/// <param name="sorted_arrays"></param>
/// <returns>Return the sorted array.</returns>
vector<int> MergeSortedArrays(const vector<vector<int>>& sorted_arrays) {
    vector<int> results;
    priority_queue<
        PairIt,
        vector<PairIt>,
        function<bool(PairIt, PairIt)>> pq([](const PairIt& p1, const PairIt& p2)
    {
        return *(p1.first) > *(p2.first);
    });

    // Add the first element in the arrays in a min heap.
    //
    for (const vector<int>& array : sorted_arrays)
    {
        if (!empty(array))
        {
            pq.emplace(make_pair(cbegin(array), cend(array)));
        }
    }

    // While the queue is not empty add the front of the queue to the
    // result and get the next element in the respective array.
    //
    while (!pq.empty())
    {
        auto pairIt = pq.top();

        pq.pop();

        results.emplace_back(*(pairIt.first));

        if (next(pairIt.first) != pairIt.second)
        {
            pq.emplace(std::make_pair(next(pairIt.first), pairIt.second));
        }
    }

    return results;
}
