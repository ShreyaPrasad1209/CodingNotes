//https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/utkarsh-in-gardens-february-easy/
//Calculate no. of Cycles in a graph

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> adj[n];
    int A[n][n];
    memset(A , 0 , sizeof(A));
    
    int val;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> val;
            if(val)
                adj[i].push_back(j);            
        }            
    }

    for(int i = 0; i < n; i++)
    {    
        int len = adj[i].size(); 
        for(int j = 0; j < len; j++)
        {
            for(int k = j+1 ; k < len ; k++)
                A[adj[i][j]][adj[i][k]]++;
        }        
    }
    
    long long ans = 0;
    //j is i+1 so as to get only top right diagonal part of the matrix
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i+1; j < n; j++)
            ans += ( (long long)A[i][j] * (long long)(A[i][j] - 1) ) / 2;
    }

    cout << (ans / 2) << endl;
    return 0;
}