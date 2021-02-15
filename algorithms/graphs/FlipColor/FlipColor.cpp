#include<iostream>
#include<vector>
#include<deque>
#include<queue>

using namespace std;

vector<vector<int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

/// <summary>
/// Given a white black matrix and a position in the matrix, color
/// all the region that contains the given position.
/// Solution: We will use a BFS and flip the color gradually.
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="image_ptr"></param>
void FlipColor(int x, int y, vector<deque<bool>>* image_ptr) {
    queue<pair<int, int>> q;
    vector<deque<bool>>& image = *image_ptr;
    bool color = image[x][y];

    q.emplace(x, y);

    while (!empty(q))
    {
        pair<int, int> curr = q.front();
        q.pop();

        // Flip the color.
        //
        image[curr.first][curr.second] = !color;

        for (auto d : dirs)
        {
            if (curr.first + d[0] >= 0 && curr.first + d[0] < size(image) &&
                curr.second + d[1] >= 0 && curr.second + d[1] < size(image[0]) &&
                image[curr.first + d[0]][curr.second + d[1]] == color)
            {
                q.emplace(curr.first + d[0], curr.second + d[1]);
            }
        }
    }
}

int main()
{
    vector<deque<bool>> m = { {0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 1}, {0, 0, 0 ,1} };

    FlipColor(0, 0, &m);

    for (deque<bool> d : m)
    {
        for (bool c : d)
        {
            cout << c << " ";
        }

        cout << endl;
    }

    return 0;
}