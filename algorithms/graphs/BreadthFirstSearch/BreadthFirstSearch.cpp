#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

template<class T>
struct GraphNode
{
	T label;
	vector<GraphNode<T>*> edges;
};

template<class T>
struct Graph
{
	Graph(int node_count, vector<T> labels)
		:
		vertices(node_count, nullptr)
	{
		for (unsigned int i = 0; i < size(labels); ++i)
		{
			vertices[i] = new GraphNode<T>();
			vertices[i]->label = labels[i];
		}
	}

	void AddEdge(GraphNode<T>* v1, GraphNode<T>* v2)
	{
		v1->edges.emplace_back(v2);
		v2->edges.emplace_back(v1);
	}

	vector<GraphNode<T>*> vertices;
};

template<typename T>
vector<T> BreadthFirst(GraphNode<T>* s)
{
	vector<T> result;
	queue<GraphNode<T>*> q;
	unordered_set<GraphNode<T>*> visited;

	q.emplace(s);
	visited.emplace(s);
	result.emplace_back(s->label);

	while (!empty(q))
	{
		GraphNode<T>* curr = q.front();
		q.pop();

		for (GraphNode<T>* e : curr->edges)
		{
			if (visited.find(e) == visited.end())
			{
				visited.emplace(e);
				result.emplace_back(e->label);
				q.emplace(e);
			}
		}
	}

	return result;
}

int main()
{
	Graph<int> g(7, { 0, 1, 2, 3, 4, 5, 6 });

	g.AddEdge(g.vertices[0], g.vertices[1]);
	g.AddEdge(g.vertices[0], g.vertices[2]);
	g.AddEdge(g.vertices[0], g.vertices[3]);

	g.AddEdge(g.vertices[1], g.vertices[2]);
	g.AddEdge(g.vertices[1], g.vertices[3]);
	g.AddEdge(g.vertices[1], g.vertices[5]);
	g.AddEdge(g.vertices[1], g.vertices[6]);

	g.AddEdge(g.vertices[3], g.vertices[4]);
	g.AddEdge(g.vertices[3], g.vertices[6]);

	g.AddEdge(g.vertices[4], g.vertices[5]);

	vector<int> path = BreadthFirst(g.vertices[0]);

	for (int l : path)
	{
		cout << l << " " << endl;
	}

	cout << endl;

	path = BreadthFirst(g.vertices[5]);

	for (int l : path)
	{
		cout << l << " " << endl;
	}

	return 0;
}