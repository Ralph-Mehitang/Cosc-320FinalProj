 /* James Kwedi Jr. & Ralph Mehitang
*  COSC320 Project 3: Disjoin Sets in graphs
*  Dr. Anderson
*  
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define edge pair<int,int>

class Graph
{
private:
	vector <pair<int,edge>>G;    // Graph
	vector <pair<int,edge>>T;    // mst
	int *parent;
	int	V;            // number of vertices/nodes in graph
public:
	Graph(int V);
	void AddEdgeAndWeight(int u, int v, int weight);
	int find_set(int i);
	void union_set(int u, int v);
	bool find_cycle();
};

/*******************************************************************/
/*******************************************************************/

Graph::Graph(int V)
{
	parent = new int[V];

	//Ex: i          0 1 2 3 4 5
	//Ex: parent[i]  0 1 2 3 4 5
	for (int i = 0; i < V; i++)
		parent[i] = i;

	G.clear();
	T.clear();
}

/*******************************************************************/
/*******************************************************************/

void Graph::AddEdgeAndWeight(int u, int v, int weight)
{
	// reset graph and mst
	G.push_back(make_pair(weight, edge(u, v)));
}

/*******************************************************************/
/*******************************************************************/

int Graph::find_set(int i)
{
	// If i is the parent of itself
	if (i == parent[i])
		return i;
	else
		// Else if i is not the parent of itself
		// Then i is not the representative of his set,
		// so we recursively call Find on its parent
		return find_set(parent[i]);
}

/*******************************************************************/
/*******************************************************************/

//The parent of u will be the parent of v
void Graph::union_set(int u, int v)
{
	parent[u] = parent[v];
}

/*******************************************************************/
/*******************************************************************/

// Finds a cycle in the graph to see
bool Graph::find_cycle()
{
	int i, uRep, vRep;
	for (i = 0; i < G.size(); i++)
	{
		uRep = find_set(G[i].second.first);
		vRep = find_set(G[i].second.second);
		if (uRep != vRep)
		{
			union_set(uRep, vRep);
		}
		else if (uRep = vRep)
		{
			return true;
			break;
		}
	}
	return false;
}

/*******************************************************************/
/*******************************************************************/


int main()
{
	Graph g(6);
	g.AddEdgeAndWeight(0, 1, 4);
	g.AddEdgeAndWeight(0, 2, 4);
	g.AddEdgeAndWeight(1, 2, 2);
	g.AddEdgeAndWeight(1, 0, 4);
	g.AddEdgeAndWeight(2, 0, 4);
	g.AddEdgeAndWeight(2, 1, 2);
	g.AddEdgeAndWeight(2, 3, 3);
	g.AddEdgeAndWeight(2, 5, 2);
	g.AddEdgeAndWeight(2, 4, 4);
	g.AddEdgeAndWeight(3, 2, 3);
	g.AddEdgeAndWeight(3, 4, 3);
	g.AddEdgeAndWeight(4, 2, 4);
	g.AddEdgeAndWeight(4, 3, 3);
	g.AddEdgeAndWeight(5, 2, 2);
	g.AddEdgeAndWeight(5, 4, 3);

	if (g.find_cycle())
		cout << "The graph has cycle" << endl;
	else
		cout << "The graph has no cycle" << endl;

	//cout << "Graph data: " << endl;
	//g.printGraph();

	cout << "The parent for each node: " << endl;
	cout << "0: " << g.find_set(0) << endl;
	cout << "1: " << g.find_set(1) << endl;
	cout << "2: " << g.find_set(2) << endl;
	cout << "3: " << g.find_set(3) << endl;
	cout << "4: " << g.find_set(4) << endl;
	cout << "5: " << g.find_set(5) << endl;

	return 0;
}
