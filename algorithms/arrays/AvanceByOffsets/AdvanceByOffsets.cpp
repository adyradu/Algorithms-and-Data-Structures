#include<iostream>
#include<vector>

/// <summary>
/// Given an array of non-negative integers, each time a player can
/// move ahead up to the value at the current position. The player
/// starts at position 0. Determine if the player can reach the last
/// element in the array.
/// Solution:
/// Maintain the maximum position that can be reached while
/// traversing the array. If we got to a position that is not reachable
/// then it means that there is no solution to the game. If we
/// reach the end of the array then it means that there is a solution.
/// </summary>
/// <param name="max_advance_steps"></param>
/// <returns></returns>
bool can_reach_end(const std::vector<int>& max_advance_steps) {
    int max_reachable = 0;
    int lastPos = max_advance_steps.size() - 1;

    for (int i = 0; i <= max_reachable &&
        i < max_advance_steps.size(); ++i)
    {
        int local_max_reachable = i + max_advance_steps[i];

        if (local_max_reachable >= lastPos)
        {
            return true;
        }

        max_reachable = std::max(max_reachable, local_max_reachable);
    }

    return max_reachable >= lastPos;
}

int main(void)
{
    std::vector<int> test = { 3, 2, 0, 0, 2, 0, 1 };
    std::cout << can_reach_end(test);
	return 0;
}