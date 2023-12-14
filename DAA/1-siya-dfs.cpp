#include<iostream>
#include<vector>

using namespace std;

void DFSRec(vector<int> adj[],int s,bool visited[]){

    visited[s] = true;
    cout<<s<<" ";

    for(int u:adj[s]){
        if(visited[u]==false)
            DFSRec(adj,u,visited);
    }
}


void DFS(vector<int> adj[],int v,int s){
    bool visited[v];
    for(int i=0;i<v;i++)
        visited[i]=false;
    
    DFSRec(adj,s,visited);
}


// bool isPathExists(vector<int> adj[], int v, int source, int destination) {
//     bool visited[v];
//     for (int i = 0; i < v; i++)
//         visited[i] = false;

//     DFSRec(adj, source, visited);

//     return visited[destination];
// }

int main() {
    int v; // Number of vertices
    cout << "Enter the number of vertices: ";
    cin >> v;

    vector<int> adj[v];

    cout << "Enter the adjacency list:" << endl;
    for (int i = 0; i < v; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int vertex;
            cin >> vertex;
            adj[i].push_back(vertex);
        }
    }

    // int source, destination;
    // cout << "Enter the source and destination vertices: ";
    // cin >> source >> destination;

    // if (isPathExists(adj, v, source, destination)) {
    //     cout << "Yes, Path Exists" << endl;
    // } else {
    //     cout << "No Such Path Exists" << endl;
    // }

    return 0;
}