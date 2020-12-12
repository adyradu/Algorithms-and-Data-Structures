#include<iostream>
#include<vector>
#include<random>


/// <summary>
/// Select k elements from an array. The subset of size k should be equally likely.
/// We start from 1 element and we randomly select an element of the array.
/// If we find an element at position r we swap with the current index.
/// </summary>
/// <param name="k"></param>
/// <param name="A"></param>
void RandomSampling(int k, std::vector<int>& A) {
    std::default_random_engine seed((std::random_device())());

    for (int i = 0; i < k; ++i)
    {
        int r = std::uniform_int_distribution<int>{ i, static_cast<int>(A.size() - 1) }(seed);

        std::swap(A[i], A[r]);
    }
}

int main()
{
	return 0;
}