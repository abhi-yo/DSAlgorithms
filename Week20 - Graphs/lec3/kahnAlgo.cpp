#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
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
    void topoSortBfs(int n, vector<int> &ans)
    {
        queue<int> q;
        unordered_map<int, int> indegree;
        // calculate indegree of all nodes
        for (auto i : adjList)
        {
            int src = i.first;
            for (auto nbr : i.second)
            {
                indegree[nbr]++;
            }
        }
        // put all nodes inside queue with indegree 0
        for (int i = 0; i < n; i++)
        {
            int node = i.first;
            if (indegree[node] == 0)
            {
                q.push(node);
            }
        }
        // bfs
        while (!q.empty())
        {
            int fnode = q.front();
            q.pop();
            ans.push_back(fnode);
            for (auto nbr : adjList[fnode])
            {
                indegree[nbr]--;
                // check for zero again
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
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
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(4, 2, 1);
    g.addEdge(5, 2, 1);
    g.addEdge(6, 2, 1);
    g.addEdge(6, 3, 1);
    g.addEdge(6, 4, 1);
    g.addEdge(6, 5, 1);
    g.printAdjList();
    vector<int> ans;
    g.topoSortBfs(7, ans);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
