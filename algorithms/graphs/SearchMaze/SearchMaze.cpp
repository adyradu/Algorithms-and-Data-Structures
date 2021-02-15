#include<iostream>
#include<vector>
#include<string>

using namespace std;

enum class Color { kWhite, kBlack };
struct Coordinate {
    bool operator==(const Coordinate& that) const {
        return x == that.x && y == that.y;
    }

    int x, y;
};

vector<vector<int>> dirs = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

bool FindExit(vector<vector<Color>>* maze, const Coordinate& c, const Coordinate& e, vector<Coordinate>* pathSoFar)
{
    // Stop search if we are out of the maze or the current position is a wall
    // or we visited the current position.
    //
    if (c.x < 0 || c.x >= size(*maze) || c.y < 0 || c.y >= size((*maze)[0]) ||
        (*maze)[c.x][c.y] == Color::kBlack)
    {
        return false;
    }

    // Add the current position to the current path.
    //
    pathSoFar->emplace_back(c);

    // We found the exit.
    //
    if (c == e)
    {
        return true;
    }

    (*maze)[c.x][c.y] = Color::kBlack;

    for (auto dir : dirs)
    {
        // If there is a path return true.
        //
        if (FindExit(maze, Coordinate{ c.x + dir[0], c.y + dir[1] }, e, pathSoFar))
        {
            return true;
        }
    }

    // Otherwise back out.
    //
    pathSoFar->pop_back();

    return false;
}

/// <summary>
/// Given a nxm maze with black and white cells.Find if there is a path from position s to
/// position e. Black cells represent obstacles.
/// </summary>
/// <param name="maze"></param>
/// <param name="s"></param>
/// <param name="e"></param>
/// <returns></returns>
vector<Coordinate> SearchMaze(vector<vector<Color>> maze, const Coordinate& s,
    const Coordinate& e) {
    vector<Coordinate> result;

    FindExit(&maze, s, e, &result);

    return result;
}

int main()
{
    vector<vector<Color>> maze = { {Color::kWhite, Color::kWhite, Color::kWhite, Color::kBlack},
        {Color::kWhite, Color::kBlack, Color::kBlack, Color::kBlack},
        {Color::kWhite, Color::kWhite, Color::kWhite, Color::kWhite} };

    vector<Coordinate> path = SearchMaze(maze, Coordinate{ 0, 0 }, Coordinate{ 2, 3 });

    for (Coordinate c : path)
    {
        cout << "(" << c.x << " " << c.y << "), ";
    }

	return 0;
}