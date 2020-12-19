#include <iostream>
#include <vector>

std::vector<int> MatrixInSpiralOrder(const std::vector<std::vector<int>>& square_matrix) {
    std::vector<int> result;

    if (square_matrix.size() == 0)
    {
        return result;
    }

    int ja = 0, jb = square_matrix[0].size() - 1, ia = 0, ib = square_matrix.size() - 1;

    while (ia <= ib || ja <= jb)
    {
        // From left to right.
        //
        for (int j = ja; j <= jb; ++j)
        {
            result.emplace_back(square_matrix[ia][j]);
        }

        ++ia;

        // From up to down.
        //
        for (int i = ia; i <= ib; ++i)
        {
            result.emplace_back(square_matrix[i][jb]);
        }

        --jb;

        // Form right to left.
        //
        for (int j = jb; j >= ja; --j)
        {
            result.emplace_back(square_matrix[ib][j]);
        }

        --ib;

        for (int i = ib; i >= ia; --i)
        {
            result.emplace_back(square_matrix[i][ja]);
        }

        ++ja;
    }

    return result;
}

int main()
{
    std::vector<std::vector<int>> matrix = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    std::vector<int> result = MatrixInSpiralOrder(matrix);

    for (auto v : result)
    {
        std::cout << v << " ";
    }

	return 0;
}
