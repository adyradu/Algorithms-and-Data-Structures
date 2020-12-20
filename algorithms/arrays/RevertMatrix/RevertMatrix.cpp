#include <iostream>
#include <vector>

/// <summary>
/// Rotate a matrix in-place.
/// Solution: Traverse the matrix from the outer layer to the center.
/// Each time swap 4 elements corresponding to the 4 edges.
/// </summary>
/// <param name="square_matrix_ptr"></param>
void RotateMatrix(std::vector<std::vector<int>>* square_matrix_ptr) {
    std::vector<std::vector<int>>& A = *square_matrix_ptr;
    int aux;
    int l = 0, h = A.size() - 1;

    while (l < h)
    {
        for (int i = l; i < h; ++i)
        {
            aux = A[i][h];
            A[i][h] = A[l][i];
            std::swap(aux, A[h][h - i + l]);
            std::swap(aux, A[h - i + l][l]);
            A[l][i] = aux;
        }

        ++l;
        --h;
    }
}

int main()
{
    std::vector<std::vector<int>> test = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };

    RotateMatrix(&test);

    for (auto row : test)
    {
        for (auto el : row)
        {
            std::cout << el << " ";
        }

        std::cout << std::endl;
    }

	return 0;
}