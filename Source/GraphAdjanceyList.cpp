//Adjancy matrix is good for sparse graph where each node is much connected to each other
//In general most of graphs data are sparse in which data is less likely connected to each node
//It is so because space complexity of adjancy matrix is N^2 which is too much 
//AdjanceyList is another approach in an adjancey matrix instead of a list it has a list of list to store
//which all nodes are connected to that node like thi
//0 -> 1, 2
//1 -> 2
//So zero is connected to 1 and 2, 1 is connect to 2

//ADJACEY LIST
//vector<int> adj[n];

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

template<typename T>
class UnweightedGraph
{
private:
    void DisjointCountRecurssion(int cur, bool *visited, vector<T> &res)
    {
        visited[cur] = true;
        res.push_back(FindNodeValueFromID(cur));
        for (int i=0; i<adjanceyList[cur].size(); i++)
        {
            if (visited[adjanceyList[cur][i]])
                continue;
            
            DisjointCountRecurssion(adjanceyList[cur][i], visited, res);
        }
    }

public:
    unordered_map<T, int> vertexList;
    vector< vector<int> > adjanceyList;

    void CreateVertex(T value)
    {
        vertexList.insert( make_pair(value, adjanceyList.size()) );

        int n = vertexList.size();
        adjanceyList.resize(n);
    }

    void CreatePath(T nodeA, T nodeB)
    {
        int a = vertexList.find (nodeA) -> second;
        int b = vertexList.find (nodeB) -> second;
        adjanceyList[a].push_back(b);
    }

    void RemoveVertex(T node)
    {
        int index = vertexList.find (node) -> second;
        vertexList.erase(node);

        adjanceyList.erase(adjanceyList.begin() + index);

        for (int i=0; i<adjanceyList.size(); i++)
        {
            for (int j=0; j<adjanceyList[i].size(); j++)
            {
                if (adjanceyList[i][j] == index)
                    adjanceyList[i].erase(adjanceyList[i].begin() + j);
            }
        }
    }

    T FindNodeValueFromID(int id)
    {
        for (auto it = vertexList.begin(); it != vertexList.end(); it++)
        {
            if (it->second == id)
                return it->first;
        }

        T garbage;
        return garbage;
    }

    int Count()
    {
       return vertexList.size();
    }

    vector< vector<T> > CountDisjoints()
    {
        bool visited[adjanceyList.size()];
        vector< vector<T> > res;

        for (int i=0; i<adjanceyList.size(); i++)
            visited[i] = false;

        for (int i=0; i<adjanceyList.size(); i++)
        {
            if (visited[i])
                continue;

            vector<T> resCur;
            DisjointCountRecurssion(i, &(visited[0]), resCur);
            res.push_back(resCur);
        }

        return res;
    }

    void Show()
    {
        for (int i=0; i<adjanceyList.size(); i++)
        {
            for (int j=0; j<adjanceyList[i].size(); j++)
                cout << adjanceyList[i][j] << " ";
            cout << endl;
        }
    }
};

template<typename T>
class WeightedGraph
{
private:
    void DisjointCountRecurssion(int cur, int *visited, vector<T> &res)
    {
        visited[cur] = 1;
        res.push_back(FindNodeValueFromID(cur));
        for (int i=0; i<adjanceyMatrix[cur].size(); i++)
        {
            if (adjanceyMatrix[cur][i] == 0 || visited[i] == 1)
                continue;
            
            DisjointCountRecurssion(i, visited, res);
        }
    }

public:
    //Works on the value which gets searched in constant time then id
    unordered_map<T, int> vertexList;
    vector< vector<int> > adjanceyMatrix;

    void CreateVertex(T value)
    {
        vertexList.insert( make_pair(value, adjanceyMatrix.size()) );

        int n = vertexList.size();
        adjanceyMatrix.resize(n);
        for (int i = 0; i < n; i++)
            adjanceyMatrix[i].resize(n);
    }

    void CreatePath(T nodeA, T nodeB, int weight)
    {
        int a = vertexList.find (nodeA) -> second;
        int b = vertexList.find (nodeB) -> second;
        adjanceyMatrix[a][b] = weight;
    }

    void RemoveVertex(T node)
    {
        int index = vertexList.find (node) -> second;
        vertexList.erase(node);

        //Delete row
        if (adjanceyMatrix.size() > index)
            adjanceyMatrix.erase( adjanceyMatrix.begin() + index );
        //Delete column
        for (unsigned i = 0; i < adjanceyMatrix.size(); ++i)
        {
            if (adjanceyMatrix[i].size() > index)
                adjanceyMatrix[i].erase(adjanceyMatrix[i].begin() + index);
        }
    }

    T FindNodeValueFromID(int id)
    {
        for (auto it = vertexList.begin(); it != vertexList.end(); it++)
        {
            if (it->second == id)
                return it->first;
        }

        T garbage;
        return garbage;
    }

    int Count()
    {
       return vertexList.size();
    }

    vector< vector<T> > CountDisjoints()
    {
        int visited[adjanceyMatrix.size()];
        vector< vector<T> > res;

        for (int i=0; i<adjanceyMatrix.size(); i++)
            visited[i] = 0;

        for (int i=0; i<adjanceyMatrix.size(); i++)
        {
            if (visited[i] != 0)
                continue;

            vector<T> resCur;            
            DisjointCountRecurssion(i, &(visited[0]), resCur);
            res.push_back(resCur);
        }

        return res;
    }

    void Show()
    {
        for (int i=0; i<adjanceyMatrix.size(); i++)
        {
            for (int j=0; j<adjanceyMatrix.size(); j++)
                cout << adjanceyMatrix[i][j] << " ";
            cout << endl;
        }
    }
};

int main()
{
    UnweightedGraph<int> graph;
    graph.CreateVertex(1);
    graph.CreateVertex(2);
    graph.CreateVertex(3);
    graph.CreateVertex(4);
    graph.CreatePath(2, 3);
    graph.CreatePath(2, 1);
    graph.CreatePath(3, 4);
    graph.Show();
    return 0;
}