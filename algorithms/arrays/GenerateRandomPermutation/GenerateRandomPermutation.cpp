#include<iostream>
#include<random>
#include<vector>

/// <summary>
/// Generate a random permutation where each permutation is equally
/// likely.
/// Initialize permutation with 1..(n - 1)
/// In each iteration k select a number from indeces k to n - 1 and
/// swap with the current position.
/// Complexity: time O(n), if the time to select a random number from
/// k to n - 1 is O(1).
/// Space complexity O(1) if we discount the result.
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
std::vector<int> GenerateRandomPermutation(int n) {
    std::vector<int> result(n);
    std::default_random_engine seed((std::random_device())());

    for (int i = 0; i < n; ++i)
    {
        result[i] = i;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        std::swap(result[i], result[std::uniform_int_distribution<int>{i, n - 1}(seed)]);
    }

    return result;
}

int main()
{
    std::vector<int> permutation = GenerateRandomPermutation(17);

    for (int n : permutation)
    {
        std::cout << n << " ";
    }

	return 0;
}