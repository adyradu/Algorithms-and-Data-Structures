#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct GraphVertex {
    int label;
    vector<GraphVertex*> edges;
};

GraphVertex* TraverseAndClone(GraphVertex* graph, std::unordered_map<int, GraphVertex*>& label_to_vertex)
{
    auto it = label_to_vertex.find(graph->label);

    if (it != label_to_vertex.end())
    {
        return it->second;
    }

    GraphVertex* newClone = new GraphVertex();
    newClone->label = graph->label;
    label_to_vertex.insert({ graph->label, newClone });

    for (auto g : graph->edges)
    {
        GraphVertex* childClone = TraverseAndClone(g, label_to_vertex);

        if (childClone != nullptr)
        {
            newClone->edges.emplace_back(childClone);
        }
    }

    return newClone;
}

/// <summary>
/// Perform a deep copy of a graph.
/// </summary>
/// <param name="graph"></param>
/// <returns></returns>
GraphVertex* CloneGraph(GraphVertex* graph) {
    std::unordered_map<int, GraphVertex*> label_to_vertex;

    return TraverseAndClone(graph, label_to_vertex);
}

int main()
{
    return 0;
}