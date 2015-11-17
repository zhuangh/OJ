 
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <iterator>
#include <string>
#include <stack>
#include <map>
#include <limits.h>

using   namespace   std;


class design{
    bool BFS(int s, int t, map<int,int>& parent);
    void DFS(int s, vector<bool>&visited);
    void minCut(int s, int t) ;
    void test();
public: 
    design(){};

};

/* Returns true if there is a path from source 's' to sink 't' in
   residual graph. Also store the path */
bool design::BFS(int s, int t, map<int,int>& parent) {
    // Create a visited array and mark all vertices as not visited
    vector<bool> visited;
    visited.resize(num_v, false);

    // Create a queue, enqueue source vertex and mark source vertex
    // as visited
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    // Standard BFS Loop
    while (!q.empty()) {

	int u = q.front();
	q.pop();

	for (int v=0; v<num_v; v++) {
	    if (!visited[v] && rgraph[u][v] > 0) {
		q.push(v);
		parent[v] = u; 
		visited[v] = true;
	    }
	}
    }

    // If we reached sink in BFS starting from source, then return
    // true, else false
    return visited[t];
}

// A DFS based function to find all reachable vertices from s.  The function
// marks visited[i] as true if i is reachable from s.  The initial values in
// visited[] must be false. We can also use BFS to find reachable vertices
void design::DFS(int s, vector<bool>&visited) {
    visited[s] = true;
    for (int i = 0; i < num_v; i++)
	if (rgraph[s][i] > 0 && !visited[i])
	    DFS(i, visited);
}

// Prints the minimum s-t cut
void design::minCut(int s, int t) {

    int u, v;

    // Create a residual graph and fill the residual graph with
    // given capacities in the original graph as residual capacities
    // in residual graph
    //
    num_v = graph.size();
    rgraph.resize(num_v);
    for (u = 0; u < num_v; u++) {
	for (v = 0; v < num_v; v++) {
	    rgraph[u].push_back(graph[u][v]);
	}
    }

    map<int, int> parent;  // This array is filled by BFS and to store path

    // Augment the flow while tere is path from source to sink
    while (BFS(s, t, parent))
    {
	// Find minimum residual capacity of the edhes along the
	// path filled by BFS. Or we can say find the maximum flow
	// through the path found.
	int path_flow = INT_MAX;
	for (v=t; v!=s; v=parent[v])
	{
	    u = parent[v];
	    if (rgraph[u][v] < path_flow) 
		path_flow = rgraph[u][v];
	}

	// update residual capacities of the edges and reverse edges
	// along the path
	for (v=t; v!=s; v=parent[v])
	{
	    u = parent[v];
	    rgraph[u][v] -= path_flow;
	    rgraph[v][u] += path_flow;
	}
    }

    // Flow is maximum now, find vertices reachable from s
    vector<bool> visited;
    visited.resize(num_v, false);
    DFS(s, visited);

    // Print all edges that are from a reachable vertex to
    // non-reachable vertex in the original graph
    for (int i = 0; i < num_v; i++)
	for (int j = 0; j < num_v; j++)
	    if (visited[i] && !visited[j] && graph[i][j] > 0)
		cout << i << " - " << j << endl;

}

void design::test() {
    vector<int> dummy;
    dummy.resize(8, 0);
    graph.resize(8, dummy);
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[0][3] = 1;
    graph[2][4] = 1;
    graph[3][4] = 1;
    graph[1][6] = 1;
    graph[4][1] = 1;
    graph[4][6] = 1;
    graph[5][7] = 1;
    graph[6][7] = 1;
    minCut(0, 7);
}

int main(){

    return 0;
}

