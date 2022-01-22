#include <iostream>
#include <queue>
using namespace std;

// DFS
void printDFS(bool **edges, int n, int sv, bool *visited){
    cout << sv << " ";
    visited[sv] = true;

    for (int i = 0; i < n; i++){
        if (edges[sv][i] && !visited[i]){
            printDFS(edges, n, i, visited);
        }
    }
}

void DFS(bool **edges, int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++){
        visited[i] = false;
    }

    for (int i = 0; i < n; i++){
        if (!visited[i]){
            printDFS(edges, n, i, visited);
        }
    }
    delete []visited;
}

//BFS
void printBFS(bool **edges, int n, int sv, bool *visited){
    queue<int> pV;
    pV.push(sv);
    visited[sv] = true;
    while (!pV.empty()){
        int cv = pV.front();
        pV.pop();
        cout << cv << " ";
        for (int i = 0; i < n; i++){
            if (edges[cv][i] && !visited[i]){
                pV.push(i);
                visited[i] = true;
            }
        }
    }
}
void BFS(bool **edges, int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++){
        visited[i] = false;
    }

    for (int i = 0; i < n; i++){
        if (!visited[i]){
            printBFS(edges, n, i, visited);
        }
    }
    delete []visited;
}

int main(){
    int v;
    cin >> v;
    int e;
    cin >> e;

    bool** edges = new bool*[v];
    for (int i = 0; i < v; i++){
        edges[i] = new bool[v];
        for (int j = 0; j < v; j++){
            edges[i][j] = false;
        }
    }

    for (int i = 0; i < e; i++){
        int f, s;
        cin >> f >> s;
        edges[f][s] = true;
        edges[s][f] = true;
    }

    cout << "DFS: ";
    DFS(edges, v);
    cout << "\nBFS: ";
    BFS(edges, v);

    return 0;
}