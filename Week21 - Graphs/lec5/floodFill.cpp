class Solution
{
private:
    void dfs(int x, int y, int oldColor, int newColor, map<pair<int, int>, bool> &vis, vector<vector<int>> &arr)
    {
        vis[{x, y}] = true;
        arr[x][y] = newColor;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX >= 0 && newX < arr.size() && newY >= 0 && newY < arr[0].size() && !vis[{newX, newY}] && arr[newX][newY] == oldColor)
            {
                dfs(newX, newY, oldColor, newColor, vis, arr);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int oldColor = image[sr][sc];
        if (oldColor == newColor)
        {
            return image; // No need to perform flood fill if old and new colors are the same
        }

        map<pair<int, int>, bool> vis;
        vector<vector<int>> ans = image;
        dfs(sr, sc, oldColor, newColor, vis, ans);
        return ans;
    }
};