class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> arr = grid;
        int ansTime = 0;

        // Insert all rotten oranges in the queue
        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[row].size(); col++)
            {
                if (grid[row][col] == 2)
                {
                    // Rotten orange found
                    pair<int, int> coordinate = make_pair(row, col);
                    q.push({coordinate, 0});
                }
            }
        }

        while (!q.empty())
        {
            pair<int, int> fNode = q.front().first;
            int x = fNode.first;
            int y = fNode.second;
            int time = q.front().second;
            q.pop();

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (newX >= 0 && newX < arr.size() && newY >= 0 && newY < arr[0].size() && arr[newX][newY] == 1)
                {
                    pair<int, int> newCoordinates = make_pair(newX, newY);
                    ansTime = max(ansTime, time + 1);
                    q.push({newCoordinates, time + 1});
                    // Mark rotten
                    arr[newX][newY] = 2;
                }
            }
        }

        // Check for fresh oranges
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                if (arr[i][j] == 1)
                {
                    // Fresh orange still exists, return -1
                    return -1;
                }
            }
        }

        return ansTime;
    }
};
