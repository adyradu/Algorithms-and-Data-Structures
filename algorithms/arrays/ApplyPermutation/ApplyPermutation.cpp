#include<iostream>
#include<vector>

/// <summary>
/// Given a permutation and an array, apply the permutation.
/// Time complexity: O(n). Space complexity: O(1).
/// </summary>
/// <param name="perm"></param>
/// <param name="A"></param>
void apply_permutation(std::vector<int> perm, std::vector<int>& A) {

    for (int i = 0; i < A.size(); ++i)
    {
        while (i != perm[i])
        {
            std::swap(A[perm[i]], A[i]);
            std::swap(perm[i], perm[perm[i]]);
        }
    }

    return;
}

int main(void)
{
	return 0;
}