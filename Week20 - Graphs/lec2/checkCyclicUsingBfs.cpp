#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

template <typename T>
class Graph
{
public:
    unordered_map<T, list<T>> adjList;
    void addEdge(T u, T v, bool direction)
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
            for (auto neighbour : node.second)
            {
                cout << neighbour << ", ";
            }
            cout << endl;
        }
    }
    bool checkCyclicUsingBfs(T src)
    {
        unordered_map<T, bool> visited;
        unordered_map<T, T> parent;
        queue<T> q;

        q.push(src);
        visited[src] = true;
        parent[src] = src;

        while (!q.empty())
        {
            T currentNode = q.front();
            q.pop();

            for (auto neighbour : adjList[currentNode])
            {
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = currentNode;
                }
                else if (neighbour != parent[currentNode])
                {
                    // If the neighbour is visited and not the parent of the current node,
                    // then a cycle is detected.
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(2, 0, 0);
    g.printAdjList();

    bool ans = false;
    unordered_map<int, bool> visited;

    for (int i = 0; i < 5; i++)
    {
        if (!visited[i])
        {
            ans = g.checkCyclicUsingBfs(i);
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
