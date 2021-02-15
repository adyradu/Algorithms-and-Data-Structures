#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

/// <summary>
/// DFS traversals from a particular cell.
/// </summary>
/// <param name="board"></param>
/// <param name="x"></param>
/// <param name="y"></param>
void TraverseFrom(vector<vector<char>>& board, int x, int y)
{
    if (x < 0 || y < 0 || x >= size(board) || y >= size(board[0]) ||
        board[x][y] == 'B' || board[x][y] == 'G')
    {
        return;
    }

    board[x][y] = 'G';

    for (auto d : dirs)
    {
        TraverseFrom(board, x + d[0], y + d[1]);
    }
}

/// <summary>
/// Given a white-black matrix find the enclosed regions. Colo with black
/// all enclosed regions.
/// Solution: Find the regions that are bordered first.
/// </summary>
/// <param name="board_ptr"></param>
void FillSurroundedRegions(vector<vector<char>>* board_ptr) {
    vector<vector<char>>& board = *board_ptr;

    // Start traversals from the cells that are on the border and
    // color them with gray.
    //
    for (int i = 0; i < size(board); ++i)
    {
        if (i == 0 || i == size(board) - 1)
        {
            for (int j = 0; j < size(board.front()); ++j)
            {
                TraverseFrom(board, i, j);
            }
        }
        else
        {
            TraverseFrom(board, i, 0);
            TraverseFrom(board, i, size(board.front()) - 1);
        }
    }

    for (int i = 0; i < size(board); ++i)
    {
        for (int j = 0; j < size(board.front()); ++j)
        {
            if (board[i][j] == 'W')
            {
                board[i][j] = 'B';
            }
            else if (board[i][j] == 'G')
            {
                board[i][j] = 'W';
            }
        }
    }
}

int main()
{
    return 0;
}