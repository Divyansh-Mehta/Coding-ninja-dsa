/*
Code : All connected components
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.

Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.

Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two space separated integers, that denote that there exists an edge between vertex a and b.

Output Format :
Print different components in new line. And each component should be printed in increasing order of vertices (separated by space). Order of different components doesn't matter.

Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1

Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 

Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
0 1 3 
2
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(bool **edges, int n, int sv, vector<int> &ans, bool *visited)
{
    ans.push_back(sv);
    visited[sv] = true;

    for (int i = 0; i < n; i++)
    {
        if (edges[sv][i] && !visited[i])
        {
            DFS(edges, n, i, ans, visited);
        }
    }
}

vector<vector<int>> *allConnectedComponents(bool **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    vector<vector<int>> *ans = new vector<vector<int>>();
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            vector<int> smallAns;
            DFS(edges, n, i, smallAns, visited);
            ans->push_back(smallAns);
        }
    }
    delete[] visited;
    return ans;
}

int main()
{
    int v;
    cin >> v;
    int e;
    cin >> e;

    bool **edges = new bool *[v];
    for (int i = 0; i < v; i++)
    {
        edges[i] = new bool[v];
        for (int j = 0; j < v; j++)
        {
            edges[i][j] = false;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = true;
        edges[s][f] = true;
    }

    vector<vector<int>> *ans = allConnectedComponents(edges, v);

    for (int i = 0; i < ans->size(); i++)
    {
        sort(ans->at(i).begin(), ans->at(i).end());
        for (int j = 0; j < ans->at(i).size(); j++)
        {
            cout << ans->at(i).at(j) << " ";
        }
        cout << endl;
    }

    return 0;
}