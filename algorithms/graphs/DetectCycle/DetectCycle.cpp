#include<iostream>
#include<vector>

using namespace std;

struct GraphVertex {
    enum Color { kWhite, kGray, kBlack } color = kWhite;
    vector<GraphVertex*> edges;
};

bool DetectCycle(GraphVertex* currNode)
{
    if (currNode->color == GraphVertex::kGray)
    {
        return true;
    }

    currNode->color = GraphVertex::kGray;

    for (GraphVertex* neighbor : currNode->edges)
    {
        bool result = DetectCycle(neighbor);

        if (result)
        {
            return true;
        }
    }

    currNode->color = GraphVertex::kBlack;

    return false;
}

/// <summary>
/// Return true if the graph has cycles and false otherwise.
/// </summary>
/// <param name="graph"></param>
/// <returns></returns>
bool HasCycles(vector<GraphVertex>* graph) {
    vector<GraphVertex>& graph_ref = *graph;

    for (GraphVertex g : graph_ref)
    {
        if (DetectCycle(&g))
        {
            return true;
        }
    }

    return false;
}

struct Edge {
    int from;
    int to;
};

int main()
{
    return 0;
}