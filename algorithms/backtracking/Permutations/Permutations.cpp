#include <vector>
#include <iostream>

using namespace std;

void permute_acc(vector<int>* sol, int idx, vector<vector<int>>* result)
{
    if (idx == size(*sol))
    {
        result->emplace_back(*sol);
    }

    for (int i = idx; i < size(*sol); ++i)
    {
        swap((*sol)[idx], (*sol)[i]);
        permute_acc(sol, idx + 1, result);
        swap((*sol)[idx], (*sol)[i]);
    }
}

/// <summary>
/// Generatea all permutations of a specified array.
/// </summary>
/// <param name="nums">The input array.</param>
/// <returns>All permutations</returns>
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    permute_acc(&nums, 0, &result);

    return result;
}

int main()
{
    vector<int> input1 = { 1, 2, 3, 4, 5 };
    vector<vector<int>> result1 = permute(input1);

    for (vector<int> sol : result1)
    {
        cout << "(";
        for (int el : sol)
        {
            cout << el << " ";
        }
        cout << ") ";
    }

    return 0;
}