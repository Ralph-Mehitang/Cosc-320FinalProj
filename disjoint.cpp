#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Graph {
private:
	map<int, vector<int>> dijset; //First = set# Second = the set values
	map<int, vector<int>> adj; // First = set# Second = The adjacency list
	map<int, int> parent; // First = set#, Second set#

public:
	int find(int);
	void Union(int, int);

};

// Find the subset of an element i
int Graph::find(int i) {

	if (parent[i] == -1) {
		return i;
	}
	find(parent[i]);

}

void Graph::Union(){


}
