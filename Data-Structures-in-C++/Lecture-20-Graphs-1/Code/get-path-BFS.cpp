/*
Code : Get Path - BFS
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.

Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.

Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
The following line contain two integers, that denote the value of v1 and v2.

Output Format :
Print the path from v1 to v2 in reverse order.

Constraints :
2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1
Time Limit: 1 second

Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1

Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> *getPathBFS(bool **edges, int n, int start, int end)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    bool done = false;
    queue<int> pV;
    pV.push(start);
    visited[start] = true;
    unordered_map<int, int> path;

    while (!pV.empty() && !done)
    {
        int cv = pV.front();
        pV.pop();
        for (int i = 0; i < n; i++)
        {
            if (edges[cv][i] && !visited[i])
            {
                pV.push(i);
                visited[i] = true;
                path[i] = cv;
                if (i == end)
                {
                    done = true;
                    break;
                }
            }
        }
    }
    delete[] visited;
    if (!done)
    {
        return NULL;
    }
    vector<int> *ans = new vector<int>();
    int current = end;
    ans->push_back(current);
    while (current != start)
    {
        current = path[current];
        ans->push_back(current);
    }
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

    int start, end;
    cin >> start >> end;
    vector<int> *ans = getPathBFS(edges, v, start, end);
    if (ans != NULL)
    {
        for (int i = 0; i < ans->size(); i++)
        {
            cout << ans->at(i) << " ";
        }
    }
    return 0;
}