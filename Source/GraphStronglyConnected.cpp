#include <bits/stdc++.h>
using namespace std;

//Say a graph given:
//  0←---3    5---→6←---7
//  |    ↑    ↑   /     |
//  ↓    |    |  /      ↓
//  1---→2---→4←        8
//Given this graph we need to find strongly connected components: Strongly connected is when there is a path
//between all pairs of vertices

//Using Kosaraju's Algorithm
//Apply DFS to all unvisited nodes
//As the node get's exit put it in a stack
//Then find transpose of graph, transpose simply means reverse the graph arrows
//Apply DFS again to the stack as per new visited set. DFS on nodes from stack
//Here output will show
//7, 8, 0-3-2-1, 4-6-5
//These are strongly connected components

stack<int> st;

void DFS(vector<int> *adj, bool *visited, int node, bool show)
{
    if (show)
        cout << node << " ";
    
    visited[node] = true;
    for (int i=0; i<adj[node].size(); i++)
    {
        int next = adj[node][i];
        if (!visited[next])
            DFS(adj, visited, next, show);
    }

    st.push(node);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin >> n >> e;
    int nodes[n];    
    vector<int> adj[n];
    vector<int> adjT[n];
    for (int i=0; i<n; i++)
        nodes[i] = i;
    for (int i=0; i<e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adjT[b].push_back(a);
    }

    bool visited[n];
    for (int i=0; i<n; i++)
    {
        if (!visited[i])
            DFS(&adj[0], &visited[0], i, false);
    }

    bool visited2[n];
    while (!st.empty())
    {
        if (!visited2[st.top()])
        {
            DFS(&adjT[0], &visited2[0], st.top(), true);
            cout << endl;
        }
        st.pop();
    }
    return 0;
}