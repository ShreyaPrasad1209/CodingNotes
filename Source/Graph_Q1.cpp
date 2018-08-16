#include <bits/stdc++.h>
using namespace std;

//Check if two nodes in a tree not necessarily a binary tree are in same path or not
//Like: 0 & 3 0 & 1 are in same path. 0 & 5 are in same path
//      0
//     / \
//    1   2
//   /   / \
//  3   4   5

//Intime: When we visit the node for the first time
//Outtime: When we visite the node again such that there is no children left unvisited

//For problem either one of two is parent and other is child so two conditions
//1) intime(v) < intime(u) && outtime(v) > outtime(u)   [v is parent of u]
//2) intime(u) < intime(v) && outtime(u) > outtime(v)   [u is parent of v]

int curtime = 0;
void DFS(vector<int> *adj, bool *visited, int *intime, int *outtime, int node)
{    
    visited[node] = true;
    ++curtime;
    intime[node] = curtime;
    for (int i=0; i<adj[node].size(); i++)
    {
        int next = adj[node][i];
        if (!visited[next])
            DFS(adj, visited, intime, outtime, next);
    }
    ++curtime;
    outtime[node] = curtime;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin >> n >> e;
    int nodes[n];
    bool visited[n];
    vector<int> adj[n];
    for (int i=0; i<n; i++)
        nodes[i] = i;
    for (int i=0; i<e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int intime[n];
    int outtime[n];
    intime[0] = 0;
    DFS(&adj[0], &visited[0], &intime[0], &outtime[0], 0);
    cout << endl;
    for (int i=0; i<n; i++)
        cout << i << " in: " << intime[i] << " out: " << outtime[i] << endl;
        
    return 0;
}