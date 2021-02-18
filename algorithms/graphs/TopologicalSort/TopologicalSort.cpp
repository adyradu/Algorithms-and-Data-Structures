#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>
#include<array>

using namespace std;

template<class T>
struct GraphVertex
{
	T label;
	vector<GraphVertex<T>*> edges;
};

template<class T>
struct Graph
{
	Graph(vector<T>& labels)
	{
		for (T label : labels)
		{
			vertices.emplace_back(GraphVertex<T> { label });
		}
	}

	void AddEdge(GraphVertex<T>* v1, GraphVertex<T>* v2)
	{
		v1->edges.emplace_back(v2);
	}

	vector<GraphVertex<T>> vertices;
};

template<class T>
void TopologicalSortHelper(const GraphVertex<T>* curr, stack<T>& s, unordered_set<T>& visited)
{
	// Return if the node was already visited.
	//
	if (visited.find(curr->label) != visited.end())
	{
		return;
	}

	visited.emplace(curr->label);

	for (GraphVertex<T>* gv : curr->edges)
	{
		TopologicalSortHelper(gv, s, visited);
	}

	s.push(curr->label);
}

template<class T>
vector<T> TopologicalSort(const Graph<T>& g)
{
	stack<T> st;
	unordered_set<T> visited;
	vector<T> result;

	for (GraphVertex<T> v : g.vertices)
	{
		TopologicalSortHelper(&v, st, visited);
	}

	while (!empty(st))
	{
		result.emplace_back(st.top());
		st.pop();
	}

	return result;
}

int main()
{
	vector<int> labels = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	Graph<int> g(labels);

	g.AddEdge(&g.vertices[6], &g.vertices[0]);
	g.AddEdge(&g.vertices[2], &g.vertices[0]);
	g.AddEdge(&g.vertices[1], &g.vertices[0]);
	g.AddEdge(&g.vertices[4], &g.vertices[0]);
	g.AddEdge(&g.vertices[8], &g.vertices[2]);
	g.AddEdge(&g.vertices[5], &g.vertices[2]);
	g.AddEdge(&g.vertices[5], &g.vertices[1]);
	g.AddEdge(&g.vertices[3], &g.vertices[1]);
	g.AddEdge(&g.vertices[9], &g.vertices[1]);
	g.AddEdge(&g.vertices[9], &g.vertices[4]);
	g.AddEdge(&g.vertices[7], &g.vertices[3]);

	vector<int> topSortOrder = TopologicalSort(g);

	for (int l : topSortOrder)
	{
		cout << l << " ";
	}

	return 0;
}