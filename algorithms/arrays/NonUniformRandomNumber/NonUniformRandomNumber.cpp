#include<iostream>
#include<random>
#include<vector>

int binarySearch(const std::vector<double> intervals, double p)
{
    int low = 0, high = intervals.size();

    do
    {
        int cur = (low + high) / 2;

        if (p < intervals[cur]) {
            high = cur;
        }
        else if (p > intervals[cur])
        {
            low = cur + 1;
        }
        else {
            return cur;
        }
    } while (low < high);

    return low;
}

/// <summary>
/// Randomly select a number from an array with non-uniform
/// probabilities.
/// </summary>
/// <param name="values"></param>
/// <param name="probabilities"></param>
/// <returns></returns>
int NonuniformRandomNumberGeneration(
    const std::vector<int>& values,
    const std::vector<double>& probabilities)
{
    std::default_random_engine seed((std::random_device())());
    double d = std::generate_canonical<double, std::numeric_limits<double>::digits>(seed);

    std::vector<double> intervals;

    double totalP = 0;
    for (auto p : probabilities)
    {
        totalP += p;
        intervals.emplace_back(totalP);
    }

    int idx = binarySearch(intervals, d);

    return values[idx];
}

int main()
{
    return 0;
}