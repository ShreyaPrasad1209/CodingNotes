#include<bits/stdc++.h>

using namespace std;

template<typename T>
class DisjointSet
{
private:
    struct Node
    {
        T data;
        Node* parent;
        int rank;
    };
    unordered_map<T, Node*> map;

public:
    void makeSet(T _data)
    {
        Node* node = new Node();
        node->data = _data;
        node->parent = node;
        node->rank = 0;
        map.insert(make_pair<T, Node*>((T)_data, (Node*)node));
    }

    void makeUnion(T _data1, T _data2)
    {
        Node* parent1 = findSet(map.find(_data1) -> second);
        Node* parent2 = findSet(map.find(_data2) -> second);

        if (parent1->data == parent2->data)
            return;
        else if (parent1->rank >= parent2->rank)
        {
            parent1->rank = (parent1->rank == parent2->rank) ? parent1->rank + 1 : parent1->rank;
            parent2->parent = parent1;
        }
        else
            parent1->parent = parent2;
    }

    Node* findSet(Node* _node)
    {
        Node* parent = _node->parent;
        if (parent == _node)
            return parent;
        _node->parent = findSet(_node->parent);
        return _node->parent;
    }

    T find(T _data) { return findSet(map.find(_data) -> second)->data; }
};

//Other way is by using DFS, we choose any non visited node put it into the visited list and the explore it's non visited neighbours
//We also passes in recurssion that we are comming from that previous node so we do not continue in that direction
//Base case will be before setting visited and it will be if the node is already in visited set then simply means it has a cycle

//In case of undirected graph we maintain visited set as well as a complete visited set
//We do DFS on unvisited nodes and set it visited we also pass from which node it came from. If no more neighbour for a node it goes to complete visited set
//We do recurssive call if the node is not visited aswell as not completely visited.
//Base case will be if we are on a node which is in visited set but not in completely visited set

//To retrace path of loop we can simply print that node and previous nodes afterword till the cycle start point
int main()
{
    int n;
    cin >> n;

    DisjointSet<int> ds;

    for (int i=0; i<n; i++)
        ds.makeSet(i);
    
    for (int i=0; i<n; i++)
    {        
        for (int j=0; j<n; j++)
        {
            int a;
            cin >> a;
            if (i-j > 0 && a != 0)
            {
                if (ds.find(i) == ds.find(j))
                {
                    cout << "CYCLE FOUND"
                    return;
                }
                ds.makeUnion(i, j);
            }
        }
    }

    cout << "CYCLE NOT FOUND";

    return 0;
}