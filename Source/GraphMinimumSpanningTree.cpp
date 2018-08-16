#include <bits/stdc++.h>
using namespace std;

//Spanning tree is a tree representation of a graph such that it includes all the nodes of graph
//Minimum spanning tree is in which the weight chosen is the smallest
//Using Kruskal's & Prim's Algorithm that are Greedy Algorithms
//Example-
//      0--1--3--6--4           
//     3|  3/ |  5/ |2
//      | /  1| /   |
//      1--1--2--4--5

//Kruskal's Algorithm - We first create disjoint sets for all nodes.
//We store path in a set and sort it in ascending order based on weight.
//Traverse this new sorted list and apply find set to see if two nodes of path are different then do union.
//Also print the connection because that is our final minimum spanning tree.

//Prim's Algorithm - In Prim's Algorithm we use a heap + map data structure with operations like: popMin, Insert, Decrease
//In the heap + map data structure we store all nodes with initial value infinity except any one node say 0th node
//While heap+map is not empty popmin from heap, explore that node's neighbours. If it's neighbour heap value is greater than path value specified
//put that path say 0 to 1 in a min Set stating 1 & 01. Also update to heap
//Likewise explore all neighbours and keep putting in minSet & updating heap
//Again apply popMin and also the node which is popped should be checked in the min set which will denote it's minimum path value add it to solution

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

struct Path
{
    int nodeA;
    int nodeB;
    int length;
};

bool cmp (Path i, Path j) { return (i.length < j.length); }

void PerformKruskalAlgorithm()
{
    int e, v;
    cin >> e >> v;

    DisjointSet<int> ds;

    for (int i=0; i<e; i++)
        ds.makeSet(i);

    vector<int> vertex[e];
    vector<Path> path(v);
    for (int i=0; i<v; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        vertex[a].push_back(b);
        vertex[b].push_back(a);
        path[i] = {a, b, c};
    }
    
    sort(path.begin(), path.end(), cmp);

    cout << "-------" << endl;

    for (int i=0; i<v; i++)
    {
        int a = ds.find(path[i].nodeA);
        int b = ds.find(path[i].nodeB);
        if (a != b)
        {
            ds.makeUnion(a, b);
            cout << path[i].nodeA << " " << path[i].nodeB << " - " << path[i].length << endl;
        }
    }
}

struct HeapNode
{
    int a;
    int b;
};

class HeapMap
{
    #define getParent(n) floor((n-1)/2)
    #define getChild1(n) (2*n + 1)
    #define getChild2(n) (2*n + 2)

private:
    void SwapWithParent(int &pos, int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
        heapMap.find(b) -> second = pos;
        heapMap.find(a) -> second = getParent(pos);
    }
    int getMinChild(int n)
    {
        int x = getChild1(n);
        int y = getChild2(n);
        if (x >= heapList.size())
            return -1;
        else if (y >= heapList.size())
            return x;
        else
            return (heapList[x].a > heapList[y].a) ? y : x;
    }

public:
    unordered_map<int, int> heapMap;
    vector<HeapNode> heapList;
    bool IsEmpty()
    {
        return (heapList.size() == 0);
    }
    int PopMin()
    {
        int val = heapMap.find(heapList[0].a) -> second;
        int pos = 0;
        while (getMinChild(pos) != -1)
        {            
            SwapWithParent(pos, heapList[getMinChild(pos)].a, heapList[pos].a);
            pos = getMinChild(pos);
        }
        
        heapMap.erase(heapMap.find(heapList[pos].a));
        heapList.erase(heapList.begin() + pos);
        return val;
    }
    void Insert(HeapNode value)
    {
        heapList.push_back(value);
        int pos = heapList.size() - 1;
        heapMap.insert(make_pair(value.a, pos));

        while (heapList[getParent(pos).a] > heapList[pos].a)
        {
            SwapWithParent(pos, heapList[getParent(pos)].a, heapList[pos].a);
            pos = getParent(pos);
        }
    }
    void Decrease(int oldValue, int newVal)
    {
        auto it = heapMap.find(oldValue);
        if (it == heapMap.end())
            return;
        
        int pos = it -> second;
        heapList[pos].a = newVal;
        heapMap.erase(it);
        heapMap.insert(make_pair(newVal, pos));

        while (heapList[getParent(pos)].a > heapList[pos].a)
        {
            SwapWithParent(pos, heapList[getParent(pos)].a, heapList[pos].a);
            pos = getParent(pos);
        }
    }
    
    void Print()
    {
        for (HeapNode t : heapList)
            cout << t.a << " " << t.b << ", ";
        cout << endl;

        for (auto it = heapMap.begin(); it != heapMap.end(); it++)
            cout << it -> first << " " << it -> second << ", ";
        cout << endl;
    }
};

void PerformPrimAlgorithm()
{
    int n;
    cin >> n;
    int adj[n][n];
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cin >> adj[i][j];
    }

    HeapMap hm;
    pair<int, int> minSet[n];
    hm.Insert{0, 0};
    minSet[0] = make_pair(-1, -1);
    for (int i=1; i<n; i++)
    {
        hm.Insert{i, 9999 + i};
        minSet[i] = make_pair(-1, -1);
    }
    
    while (!hm.IsEmpty())
    {
        hm.Print();
        int cur = hm.PopMin();
        if (minSet[cur].first != -1 && minSet[cur].second != -1)
            cout << minSet[cur].first << minSet[cur].second << " ";
        
        for (int i=0; i<n; i++)
        {
            int val = adj[cur][i];
            if (val != 0 && hm.heapList[i] > val)
            {
                hm.Decrease(hm.heapList[i], val);
                minSet[i] = make_pair(cur, i);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // PerformKruskalAlgorithm();
    PerformPrimAlgorithm();

    return 0;
}