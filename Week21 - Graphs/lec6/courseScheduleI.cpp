class Solution
{
private:
    unordered_map<int, list<int>> adjList;
    bool topoSortBfs(int n, vector<int> &ans)
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
        for (auto i : adjList)
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
        // check if there are any nodes with remaining indegrees
        for (auto i : indegree)
        {
            if (i.second > 0)
            {
                return false; // Cycle detected
            }
        }
        return true; // No cycle found
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        for (auto task : prerequisites)
        {
            int u = task[0];
            int v = task[1];
            adjList[v].push_back(u);
        }
        vector<int> ans;
        bool canFinish = topoSortBfs(numCourses, ans);
        return canFinish;
    }
};
