
#include<bits/stdc++.h> 
using namespace std; 
class Graph 
{ 
	int V;
	list<int> *adj; 

	// A recursive function used by DFS 
	void DFSUtil(int v, bool visited[]); 
public: 
	Graph(int V); // Constructor 

	// function to add an edge to graph 
	void addEdge(int v, int w); 

	// DFS traversal of the vertices 
	// reachable from v 
	void DFS(int v); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); // Add w to v’s list. 
} 

void Graph::DFSUtil(int v, bool visited[]) 
{ 
	// Mark the current node as visited and 
	// print it 
	visited[v] = true; 
	cout << v << " "; 

	// Recur for all the vertices adjacent 
	// to this vertex 
	list<int>::iterator i; 
	for (i = adj[v].begin(); i != adj[v].end(); ++i) 
		if (!visited[*i]) 
			DFSUtil(*i, visited); 
} 
    void Graph::DFS(int v) 
    { 
        bool *visited = new bool[V]; 
        for (int i = 0; i < V; i++) 
            visited[i] = false; 
        DFSUtil(v, visited); 
    } 
    int main() 
    { 
        
            Graph g(7); 
            g.addEdge(0, 1); 
            g.addEdge(0, 2); 
            g.addEdge(1, 3); 
            g.addEdge(1, 4); 
            g.addEdge(2, 5); 
            g.addEdge(2, 6); 

            cout << "Following is Depth First Traversal"
                    " (starting from vertex 2) \n"; 
            g.DFS(0); 

            return 0; 
    } 
