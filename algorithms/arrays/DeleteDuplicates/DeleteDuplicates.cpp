#include<iostream>
#include<vector>

/// <summary>
/// Delete all duplicates from a sorted array.
/// </summary>
/// <param name="A"></param>
/// <returns></returns>
int delete_duplicates(std::vector<int>& A) {
    int j = 1;

    if (!A.size())
    {
        return 0;
    }

    for (int i = 1; i < A.size(); ++i)
    {
        if (A[i] != A[i - 1])
        {
            A[j++] = A[i];
        }
    }

    A.resize(j);

    return A.size();
}

int main()
{
    std::vector<int> input = { 0, 0, 1, 2, 2, 3, 3, 3, 3, 4, 5, 6, 6, 7, 7 };
    std::cout << delete_duplicates(input) << std::endl;

    for (auto v : input)
    {
        std::cout << v << " ";
    }

    std::cout << std::endl;

	return 0;
}