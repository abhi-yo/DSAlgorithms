#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction)
    {
        // direction = false -> undirected
        // direction = true -> directed
        // Create an edge from u to v
        adjList[u].push_back(v);

        // if undirected
        if (!direction)
            adjList[v].push_back(u); // edge created from v to u
    }

    void printAdjList()
    {
        for (auto node : adjList)
        {
            cout << node.first << "-> ";
            for (auto neighbour : node.second)
            {
                cout << neighbour << ", ";
            }
            cout << endl;
        }
    }
    void topoSortDfs(int src, unordered_map<int, bool> &visited, stack<int> &ans)
    {
        visited[src] = true;
        for (auto neighbour : adjList[src])
        {
            if (!visited[neighbour])
            {
                topoSortDfs(neighbour, visited, ans);
            }
        }
        ans.push(src);
    }
};

int main()
{
    Graph g;
    // undirected graph
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(0,2,0);

    // directed graph
    g.addEdge(1, 2, 1);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.printAdjList();
    unordered_map<int, bool> visited;
    stack<int> ans;
    for (auto node : g.adjList)
    {
        if (!visited[node.first])
        {
            g.topoSortDfs(node.first, visited, ans);
        }
    }
    while (!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }
    return 0;
}