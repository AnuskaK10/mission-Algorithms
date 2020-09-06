#include<bits/stdc++.h>
using namespace std;

void displayDFS(vector<vector<int>> edges, int vertices, int root) {
    unordered_map<int, vector<int>> adj;
    for(vector<int> i : edges) {
        adj[i[0]].push_back(i[1]);
        sort(adj[i[0]].begin(), adj[i[0]].end(), greater<int>());
        // adj[i[1]].push_back(i[0]);      // ! Comment this line for a directed graph
        // sort(adj[i[1]].begin(), adj[i[1]].end(), greater<int>());    // ! Comment this line for a directed graph
    }   

    vector<int> visited(vertices, 0);
    int visited_count = 0;
    stack<int> q;
    q.push(root);
    cout<<"Depth First Search: "<<endl;
    while(visited_count < vertices) {
        if(q.empty()) {
            for(int i = 0; i < vertices;i++) {
                if(visited[i] == 0) {
                    q.push(i);
                    break;
                }
            }
        }

        int node = q.top();
        q.pop();
        cout<<node<<" ";
        
        visited[node] = 1;
        visited_count++;
        for(int i: adj[node]) {
            if(visited[i] == 0) {
                q.push(i);
            }
        }
    }
    cout<<endl;
}

int main(int argc, char* argv[]) {
    int vertices, n, root;
    vector<vector<int>> edges; 
    if(argc == 1) {
        cout<<"Enter the number of vertices:";
        cin>>vertices;

        cout<<"Enter the number of edges:";
        cin>>n;

        cout<<"Enter the node to start BFS:";
        cin>>root;

        cout<<"Enter the two vertex of each node in each line:\n";
        
        for(int i = 0;i < n;i++) {
            int a, b;
            cin>>a>>b;
            edges.push_back({a, b});
        }

    }

    else {
        ifstream fin(argv[1]);
        string inp;
        fin>>inp;
        vertices = stoi(inp);
        fin>>inp;
        n = stoi(inp);
        fin>>inp;
        root = stoi(inp);
        for(int i = 0;i < n;i++) {
            int a, b;
            fin>>inp;
            a = stoi(inp);
            fin>>inp;
            b = stoi(inp);
            edges.push_back({a, b});
        }
    }

    double start = clock();
    displayDFS(edges, vertices, root);
    double stop = clock();

    cout<<"Time taken = "<<(double)(stop-start)<<" seconds"<<endl;
    return 0;
}