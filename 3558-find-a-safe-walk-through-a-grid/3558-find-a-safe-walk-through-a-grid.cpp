class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, -1));
        queue<tuple<int, int, int>> q;

        q.push({0, 0, health - grid[0][0]});
        visited[0][0] = health - grid[0][0];

        vector<int> directions = {0, 1, 0, -1, 0};

        while (!q.empty()) {
            auto [x, y, curr_health] = q.front();
            q.pop();

            if (curr_health <= 0)
                continue;
            if (x == m - 1 && y == n - 1)
                return true;

            for (int d = 0; d < 4; ++d) {
                int new_x = x + directions[d];
                int new_y = y + directions[d + 1];

                if (new_x >= 0 && new_y >= 0 && new_x < m && new_y < n) {
                    int new_health = curr_health - grid[new_x][new_y];
                    if (new_health > visited[new_x][new_y]) {
                        visited[new_x][new_y] = new_health;
                        q.push({new_x, new_y, new_health});
                    }
                }
            }
        }
        return false;
    }
};