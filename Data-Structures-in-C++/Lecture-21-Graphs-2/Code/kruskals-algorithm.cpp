#include <iostream>
#include <algorithm>
using namespace std;

class Edge{
    public:
    int source;
    int dest;
    int weight;
};

bool compare(Edge &E1, Edge &E2){
    return E1.weight < E2.weight;
}

int findParent(int v, int *parent){
    if (parent[v] == v){
        return v;
    }
    return findParent(parent[v], parent);
}

Edge* kruskals(Edge *input, int n, int e){
    //Sort the input array in acc. order based on weights
    sort(input, input + e, compare);
    Edge *output = new Edge[n - 1];

    int *parent = new int[n];
    for (int i = 0; i < n; i++){
        parent[i] = i;
    }

    int count = 0, i = 0;
    while (count < n - 1){
        Edge currentEdge = input[i];

        //Check if we can add the currentEdge in MST or not
        int sourceParent = findParent(currentEdge.source, parent);
        int destParent = findParent(currentEdge.dest, parent);

        if (sourceParent != destParent){
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destParent;
        }
        i++;
    }

    return output;
}

int main(){
    int n, e;
    cin >> n >> e;
    Edge *input = new Edge[e];

    for (int i = 0; i < e; i++){
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;

    }
    Edge *output;
    output = kruskals(input, n, e);
    
    for (int i = 0; i < n - 1; i++){
        if (output[i].source < output[i].dest){
        cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
        }
        else{
            cout << output[i].dest << " " << output[i].source << " " << output[i].weight << endl;
        }
    }

    return 0;
}