#include <bits/stdc++.h>
using namespace std;

void printBFS(bool** edges, int v, int sv){
    if (v == 0){
        return;
    }
    bool* visited = new bool[v];
    for (int i = 0; i < v; i++){
        visited[i] = false;
    }
    
    queue<int> bfs;
    bfs.push(sv);
    visited[sv] = true;
    while (!bfs.empty()){
        int cv = bfs.front();
        bfs.pop();
        cout << cv << " ";
        
        for (int i = 0; i < v; i++){
            if (edges[cv][i] == true){
                if (!visited[i]){
                    bfs.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    delete []visited;
}

int main() {
    // Write your code here
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
    for (int i = 0 ; i < e; i++){
        int f, s;
        cin >> f >> s;
        edges[f][s] = true;
        edges[s][f] = true;
    }
    
    printBFS(edges, v, 0);
}