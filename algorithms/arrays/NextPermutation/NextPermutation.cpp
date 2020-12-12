#include<iostream>
#include<vector>

std::vector<int> NextPermutation(std::vector<int> perm) {
    int i = 0;

    for (i = perm.size() - 1; i > 0; --i)
    {
        if (perm[i - 1] < perm[i])
        {
            int largerIdx = i;
            for (int j = i; j < perm.size(); ++j)
            {
                if (perm[j] <= perm[i - 1])
                {
                    largerIdx = j - 1;
                    break;
                }
                else
                {
                    largerIdx = j;
                }
            }
            
            std::swap(perm[i - 1], perm[largerIdx]);

            for (int j = i, k = perm.size() - 1; j < k; ++j, --k)
            {
                std::swap(perm[j], perm[k]);
            }

            break;
        }
    }

    if (i == 0)
    {
        return {};
    }

    return perm;
}

int main()
{
    std::vector<int> test = { 4, 2, 2, 4, 2};

    for (auto i : test)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    while (test.size())
    {
        test = NextPermutation(test);

        for (auto i : test)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

	return 0;
}