#include <iostream>
using namespace std;

//DFS Traversal connected Graph
void printDFS(bool** edges, int n, int sv, bool *visited){
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++){
        if (edges[sv][i] == true){
            if(!visited[i]){
                printDFS(edges, n, i, visited);
            }
        }
    }
}

int main(){
    //Number of vertices
    int n;
    cin >> n;

    //Number of edges
    int e;
    cin >> e;
    
    //Adjacency matrix
    bool** edges = new bool*[n];

    for (int i = 0; i < n; i++){
        edges[i] = new bool[n];
        for (int j = 0; j < n; j++){
            edges[i][j] = false;
        }
    }

    for (int i = 0; i < e; i++){
        int f, s;
        cin >> f >> s;
        edges[f][s] = true;
        edges[s][f] = true;
    }
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++){
        visited[i] = false;
    }
    printDFS(edges, n, 0, visited);
    
    //Delete dynamic arrays
    for (int i = 0; i < n; i++){
        delete []edges[i];
    }
    delete []edges;
    delete []visited;

    return 0;
}