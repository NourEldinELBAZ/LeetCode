class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int count = n*m;
        vector<vector<char>> grid(m, vector<char>(n, '0'));
        for(vector<int> &v: walls){
            grid[v[0]][v[1]] = 'w';
            count--;
        }
        for(int i = 0; i<guards.size(); ++i){
            grid[guards[i][0]][guards[i][1]] = 'g';
            count--;
        }
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto &g : guards) {
            int x = g[0], y = g[1];
            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                while (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != 'w' && grid[nx][ny] != 'g') {
                    if (grid[nx][ny] == '0') {
                        grid[nx][ny] = '1';
                        count--;
                    }
                    nx += dx;
                    ny += dy;
                }
            }
        }
        return count;
    }
};