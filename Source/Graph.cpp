//In a tree there is n-1 edges for n node whearas in a Graph there is no such restriction
//In a graph V is the vertices array then we have edges array which is the link between edges like 0-1 2-3
//0 < |E| < n(n-1) [Directed]
//0 < |E| < n(n-1)/2 [Undirected]
//Directed means directional. direction matters
//A graph is called dense if it is close to maximum edges otherwise it is sparse
//We use adjancy matrix for dense graph and adjancy list for sparse graph

//GRAPH APPLICATIONS:
//1 - shortest path
//2 - web crawler
//3 - social network
//4 - cycle detection
//5 - to test if a graph is bipartite (Bipartite graph is in which the graph vertices are divided into to disjoint sets and the edges are stil connect for all)
//6 - broadcasting in network
//7 - maximum flow problem

//Topological sort is a sorting of graph. In a package manger a package has a dependencie with another so the
//package manager makes a graph of all the pacakages and perform a topological sort to get linear list of
//packages to be compiled in order
//To implement we take two thing a stack & a visited set. We choose any node which is not visited, put it to visited set
//Then check it's child if it's not visited. if a parent is totally visited we put it in our stack.
//In the end pop all elements from stack and the graph is topologically sorted.

//IMPORTANT ALGORITHMS
//1) Prim's Algorithmn for maximum spanning tree
//2) Kruskal's Algorithm for maximum spanning tree
//3) Depth First Search
//4) Breadth First Search
//5) Detect Cycle in an directed graph
//6) Kosaraju's Algorithm
//7) Dijikstra's Algorithm for shortest path
//8) Bellman Ford Algorithm - Dynamic Programming
//9) Topological Sort for a directed acyclic graph
//10) Floyd Warshall Algorithm - Dynamic Programming
//11) Ford-fulkerson algorithm for maximum flow problem
//12) Dinci's algorithm for maximum flow problem

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Graph
{
private:
    struct Edge
    {
        T* connectionA;
        T* connectionB;
        int weight;

        Edge(T* a, T* b, int _weight) : connectionA(a), connectionB(b), weight(_weight) { }
    };

    vector<T> vertexList;
    vector<Edge> edgeList;

public:
    void CreateVertex(T value)
    {
        vertexList.emplace_back(value);
    }

    void CreatePath(T nodeA, T nodeB)
    {
        edgeList.emplace_back(Edge(SearchNode(nodeA), SearchNode(nodeB), 1));
    }

    void CreatePath(T nodeA, T nodeB, int weight)
    {
        edgeList.emplace_back(Edge(SearchNode(nodeA), SearchNode(nodeB), weight));
    }

    T* SearchNode(T val)
    {
        for (int i = 0; i < vertexList.size(); i++)
        {
            if (vertexList[i] == val)
                return &vertexList[i];
        }
    }

    void Show()
    {
        for (int i=0; i < vertexList.size(); i++)
            cout << vertexList[i] << endl;
        
        for (int i=0; i < edgeList.size(); i++)
            cout << *edgeList[i].connectionA << " " << *edgeList[i].connectionB << " " << edgeList[i].weight << endl;
    }
};

int main()
{
    Graph<char> graph;
    graph.CreateVertex('A');
    graph.CreateVertex('B');
    graph.CreateVertex('C');
    graph.CreateVertex('D');
    graph.CreateVertex('E');
    graph.CreateVertex('F');
    graph.CreateVertex('G');
    graph.CreateVertex('H');

    graph.CreatePath('A', 'B', 5);
    graph.CreatePath('A', 'C', 7);
    graph.CreatePath('A', 'D', 3);
    graph.CreatePath('B', 'F', 10);
    graph.CreatePath('B', 'E', 2);
    graph.CreatePath('F', 'H', 4);
    graph.CreatePath('E', 'H', 2);

    graph.Show();
    
    return 0;
}