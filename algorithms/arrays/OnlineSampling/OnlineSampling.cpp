#include <iostream>
#include <vector>
#include <random>

/// <summary>
/// Given a stream of integers and a number k, at any time extract a subset
/// of k number with equal probabilty.
/// </summary>
/// <param name="stream_begin"></param>
/// <param name="stream_end"></param>
/// <param name="k"></param>
/// <returns></returns>
std::vector<int> OnlineRandomSample(std::vector<int>::const_iterator stream_begin,
    const std::vector<int>::const_iterator stream_end,
    int k) {

    std::vector<int> result;
    int readSoFar = 0;

    std::default_random_engine seed((std::random_device())());

    for (auto it = stream_begin; it != stream_end; ++it)
    {
        ++readSoFar;
        if (result.size() < k)
        {
            result.emplace_back(*it);
        }
        else
        {
            int replacePos = std::uniform_int_distribution<int>{ 0, readSoFar - 1 }(seed);

            if (replacePos < k)
            {
                result[replacePos] = *it;
            }
        }
    }

    return result;
}

int main()
{
    std::vector<int> input = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::vector<int> res = OnlineRandomSample(input.cbegin(), input.cend(), 4);

    for (int v : res)
    {
        std::cout << v << " ";
    }

	return 0;
}