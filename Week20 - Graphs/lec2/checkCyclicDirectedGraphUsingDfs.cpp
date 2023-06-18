#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;
    void addEdge(int u, int v, bool direction)
    {
        // direction = 0 -> undirected
        // direction = 1 -> directed
        // Create an edge from u to v
        adjList[u].push_back(v);
        // if undirected
        if (direction == 0)
            adjList[v].push_back(u); // edge created from v to u
    }
    void printAdjList()
    {
        for (auto node : adjList)
        {
            cout << node.first << "-> ";
            for (auto neighbours : node.second)
            {
                cout << neighbours << ", ";
            }
            cout << endl;
        }
    }
    bool checkCyclicDirectedUsingDfs(int src, unordered_map<int, bool> &visited, unordered_map<int, bool> dfsVisited)
    {
        visited[src] = true;
        dfsVisited[src] = true;
        for (auto neighbour : adjList[src])
        {
            if (!visited[neighbour])
            {
                bool checkAageKaAns = checkCyclicDirectedUsingDfs(neighbour, visited, dfsVisited);
                if (checkAageKaAns == true)
                    return true;
            }
            else if (dfsVisited[neighbour] == true && visited[neighbour] == true)
                return true;
        }
        // yahi glti krunga
        dfsVisited[src] = false;
        return false;
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(2, 4, 0);
    g.printAdjList();

    bool ans = false;
    unordered_map<int, bool> visited;

    for (int i = 0; i < 5; i++)
    {
        if (!visited[i])
        {
            ans = g.checkCyclicDirectedUsingDfs(i, visited, -1);
            if (ans)
            {
                break;
            }
        }
    }

    if (ans)
        cout << "Cycle detected" << endl;
    else
        cout << "No cycle detected" << endl;

    return 0;
}
