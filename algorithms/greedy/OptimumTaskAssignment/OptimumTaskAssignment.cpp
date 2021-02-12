#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct PairedTasks {
	int task_1, task_2;
};

/// <summary>
/// Given an even set of tasks expressed in the number of hours, assign the tasks so
/// that every worker gets two and the total time it takes to finish all tasks is minimized.
/// All tasks can be worked independently.
/// Solution: We sort the tasks and start pairing the task that takes the most of the time
/// with the tasks that takes the least amount of time.
/// </summary>
/// <param name="task_durations"></param>
/// <returns></returns>
vector<PairedTasks> OptimumTaskAssignment(vector<int> task_durations) {
    vector<PairedTasks> result;

    std::sort(task_durations.begin(), task_durations.end(), std::greater<>());

    for (int i = 0, j = size(task_durations) - 1; i < j; ++i, --j)
    {
        result.emplace_back(PairedTasks{ task_durations[j], task_durations[i] });
    }

    return result;
}

int main()
{
	return 0;
}
