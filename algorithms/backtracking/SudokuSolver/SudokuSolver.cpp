#include <iostream>
#include <vector>

using namespace std;

const int sudoku_table_size = 9;

/// <summary>
/// Validate whether the new assignment (c_row, c_col) violates the constraints.
/// </summary>
/// <param name="partial_assignment_ptr"></param>
/// <param name="c_row"></param>
/// <param name="c_col"></param>
/// <returns></returns>
bool IsValid(vector<vector<int>>* partial_assignment_ptr, int c_row, int c_col)
{
    vector<vector<int>>& partial_assignment = *partial_assignment_ptr;

    // Check row c_row.
    //
    for (int j = 0; j < sudoku_table_size; ++j)
    {
        if (j != c_col && partial_assignment[c_row][j] == partial_assignment[c_row][c_col])
        {
            return false;
        }
    }

    // Check row c_col.
    //
    for (int i = 0; i < sudoku_table_size; ++i)
    {
        if (i != c_row && partial_assignment[i][c_col] == partial_assignment[c_row][c_col])
        {
            return false;
        }
    }

    int q_r_start = c_row - (c_row % 3), q_r_end = q_r_start + 3;
    int q_c_start = c_col - (c_col % 3), q_c_end = q_c_start + 3;

    // Check quadrant.
    //
    for (int i = q_r_start; i < q_r_end; ++i)
    {
        for (int j = q_c_start; j < q_c_end; ++j)
        {
            if ((i != c_row || j != c_col) && partial_assignment[i][j] == partial_assignment[c_row][c_col])
            {
                return false;
            }
        }
    }

    return true;
}

/// <summary>
/// Solves the sudoku table from position (i, j) onwards.
/// </summary>
/// <param name="partial_assignment"></param>
/// <param name="i"></param>
/// <param name="j"></param>
/// <returns></returns>
bool SolvePartialSudoku(vector<vector<int>>* partial_assignment, int i, int j)
{
    vector<vector<int>>& pa = *partial_assignment;

    // We reached the end of the table so return true.
    //
    if (i == sudoku_table_size)
    {
        return true;
    }

    // Compute the next position.
    //
    int next_i, next_j;

    if (j == sudoku_table_size - 1)
    {
        next_i = i + 1;
        next_j = 0;
    }
    else
    {
        next_i = i;
        next_j = j + 1;
    }

    // If the current position is not empty, advance the position.
    //
    if (pa[i][j] != 0)
    {
        return SolvePartialSudoku(partial_assignment, next_i, next_j);
    }
    // If it is empty, try all numbers. Return true if the current assignment
    // satisfies the constraints there is a valid assignment for all remaining
    // empty slots (recursive call).
    //
    else
    {
        for (int k = 1; k <= 9; ++k)
        {
            pa[i][j] = k;
            if (IsValid(partial_assignment, i, j) &&
                SolvePartialSudoku(partial_assignment, next_i, next_j))
            {
                return true;
            }
            else
            {
                pa[i][j] = 0;
            }
        }
    }

    return false;
}

/// <summary>
/// Solves the sudoku table.
/// </summary>
/// <param name="partial_assignment"></param>
/// <returns>false if the table cannot be solved; true otherwise</returns>
bool SolveSudoku(vector<vector<int>>* partial_assignment)
{
    bool result = SolvePartialSudoku(partial_assignment, 0, 0);

    return result;
}

int main()
{
    // TODO
    //
    return 0;
}
