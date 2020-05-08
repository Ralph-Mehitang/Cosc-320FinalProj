#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

#define edge pair<int,int>

class Graph {
private:
	vector<pair<int, edge>> G; // graph
	vector<pair<int, edge>> mst; // mst
	int *parent;
	int V; // number of vertices/nodes in graph
public:
	Graph(int V);
	void AddWeightedEdge(int u, int v, int w);
	int find_set(int i);
	void union_set(int u, int v);
	void kruskal();
	void printMST();
	void printG();
	void allParents();
};
Graph::Graph(int U) {
	parent = new int[U];

	//Ex: i			0 1 2 3 4 5
	//Ex: parent[i] 0 1 2 3 4 5
	for (int i = 0; i < U; i++)
		parent[i] = i;

	G.clear();
	mst.clear();
}
void Graph::AddWeightedEdge(int u, int v, int weight) {
	G.push_back(make_pair(weight, edge(u, v)));
}


int Graph::find_set(int i) {
	// If i is the parent of itself
	if (i == parent[i])
		return i;
	else
		// Else if i is not the parent of itself
		// Then i is not the representative of his set,
		// so we recursively call Find on its parent
		return find_set(parent[i]);
}

void Graph::union_set(int u, int v) {
	parent[u] = parent[v];
}

void Graph::kruskal() {
	int i, uRep, vRep;
	sort(G.begin(), G.end()); // increasing weight
	for (i = 0; i < G.size(); i++) {
		uRep = find_set(G[i].second.first);
		vRep = find_set(G[i].second.second);
		if (uRep != vRep) {
			mst.push_back(G[i]); // add to tree
			union_set(uRep, vRep);
		}
	}
}
void Graph::printMST() {
	cout << "Vertices:" << " Weight of edge" << endl;
	for (int i = 0; i < mst.size(); i++) {
		cout << mst[i].second.first << " <-> " << mst[i].second.second << " : "
			<< mst[i].first;
		cout << endl;
	}
}

void Graph::printG() {
	cout << "Vertices:" << " Weight of edge" << endl;
	for (int i = 0; i < G.size(); i++) {
		cout << G[i].second.first << " <-> " << G[i].second.second << " : "
			<< G[i].first;
		cout << endl;
	}
}

int main() {
	Graph g(6);
	g.AddWeightedEdge(0, 1, 4);
	g.AddWeightedEdge(0, 2, 4);
	g.AddWeightedEdge(1, 2, 2);
	g.AddWeightedEdge(1, 0, 4);
	g.AddWeightedEdge(2, 0, 4);
	g.AddWeightedEdge(2, 1, 2);
	g.AddWeightedEdge(2, 3, 3);
	g.AddWeightedEdge(2, 5, 2);
	g.AddWeightedEdge(2, 4, 4);
	g.AddWeightedEdge(3, 2, 3);
	g.AddWeightedEdge(3, 4, 3);
	g.AddWeightedEdge(4, 2, 4);
	g.AddWeightedEdge(4, 3, 3);
	g.AddWeightedEdge(5, 2, 2);
	g.AddWeightedEdge(5, 4, 3);

	cout << "Original graph: " << endl;
	g.printG();
	cout << endl << endl;

	//Timing the find function for 4
	auto start = std::chrono::system_clock::now();
	cout << "The parent of 4 in the graph is: " << g.find_set(4) << endl;
	auto end = std::chrono::system_clock::now();
	chrono::duration<double> elapsed_seconds = end - start;
	time_t end_time = chrono::system_clock::to_time_t(end);
	cout << "Finding the parent took "
		<< elapsed_seconds.count() << " seconds." << endl << endl;


	//Timing the find function for 5
	start = std::chrono::system_clock::now();
	cout << "The parent of 5 in the graph is: " << g.find_set(5) << endl;
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	end_time = chrono::system_clock::to_time_t(end);
	cout << "Finding the parent took "
		<< elapsed_seconds.count() << " seconds." << endl << endl;


	//Timing the union function for 4 and 5
	start = std::chrono::system_clock::now();
	g.union_set(4, 5);
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	end_time = chrono::system_clock::to_time_t(end);
	cout << "The union took of 4 and 5 took "
		<< elapsed_seconds.count() << " seconds." << endl << endl;

	//Timing the find function for 4
	start = std::chrono::system_clock::now();
	cout << "After union, parent of 4: " << g.find_set(4) << endl;
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	end_time = chrono::system_clock::to_time_t(end);
	cout << "Finding the parent took "
		<< elapsed_seconds.count() << " seconds." << endl << endl;


	//Timing the find function for 5
	start = std::chrono::system_clock::now();
	cout << "After union, parent of 5: " << g.find_set(5) << endl;
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	end_time = chrono::system_clock::to_time_t(end);
	cout << "Finding the parent took "
		<< elapsed_seconds.count() << " seconds." << endl << endl;
	

	//Timing the find function for 1
	start = std::chrono::system_clock::now();
	cout << "The parent of 1 in the graph is: " << g.find_set(1) << endl;
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	end_time = chrono::system_clock::to_time_t(end);
	cout << "Finding the parent took "
		<< elapsed_seconds.count() << " seconds." << endl << endl;


	//Timing the find function for 3
	start = std::chrono::system_clock::now();
	cout << "The parent of 3 in the graph is: " << g.find_set(3) << endl;
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	end_time = chrono::system_clock::to_time_t(end);
	cout << "Finding the parent took "
		<< elapsed_seconds.count() << " seconds." << endl << endl;


	//Timing the union for 1 and 3
	start = std::chrono::system_clock::now();
	g.union_set(1, 3);
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	end_time = chrono::system_clock::to_time_t(end);
	cout << "The union took of 1 and 3 took "
		<< elapsed_seconds.count() << " seconds." << endl << endl;

	//Timing the find function for 1
	start = std::chrono::system_clock::now();
	cout << "After union, parent of 1: " << g.find_set(1) << endl;
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	end_time = chrono::system_clock::to_time_t(end);
	cout << "Finding the parent took "
		<< elapsed_seconds.count() << " seconds." << endl << endl;


	//Timing the find function for 3
	start = std::chrono::system_clock::now();
	cout << "After union, parent of 3: " << g.find_set(3) << endl;
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	end_time = chrono::system_clock::to_time_t(end);
	cout << "Finding the parent took "
		<< elapsed_seconds.count() << " seconds." << endl << endl;


	cout << "Performing Kruskal's Algorithm and printing the minimum spanning tree: " << endl;
	start = std::chrono::system_clock::now();
	g.kruskal();
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	end_time = chrono::system_clock::to_time_t(end);
	cout << "Finding the parent took "
		<< elapsed_seconds.count() << " seconds." << endl << endl;
	g.printMST();
	return 0;
}
