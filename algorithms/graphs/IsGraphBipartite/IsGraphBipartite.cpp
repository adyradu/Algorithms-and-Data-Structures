#include<iostream>
#include<vector>

using namespace std;

enum class Color
{
    kNone,
    kRed,
    kBlack
};

struct GraphVertex {
    Color c = Color::kNone;
    vector<GraphVertex*> edges;
};

bool CanColorGraph(GraphVertex* currNode, Color parentColor)
{
    if (currNode->c != Color::kNone)
    {
        return currNode->c != parentColor;
    }

    currNode->c = parentColor == Color::kNone ?
        Color::kRed : (parentColor == Color::kRed ? Color::kBlack : Color::kRed);

    for (GraphVertex* g : currNode->edges)
    {
        if (!CanColorGraph(g, currNode->c))
        {
            return false;
        }
    }

    return true;
}

bool IsGraphBipartite(vector<GraphVertex>* graph) {
    vector<GraphVertex>& graphRef = *graph;

    for (GraphVertex g : graphRef)
    {
        if (!CanColorGraph(&g, Color::kNone))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    return 0;
}