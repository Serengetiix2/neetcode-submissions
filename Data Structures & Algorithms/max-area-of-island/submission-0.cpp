class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c){
        int area = 0;
        int m = grid.size();
        int n = grid[0].size();
        if(min(r, c) < 0 || r == m ||c == n || grid[r][c] == 0) return 0;
        else{
            grid[r][c] = 0;
            ++area;
            area += dfs(grid, r-1, c);
            area += dfs(grid, r+1, c);
            area += dfs(grid, r, c-1);
            area += dfs(grid, r, c+1);
        }
        return area;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int areaMax = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    auto newArea = dfs(grid, i, j);
                    areaMax = max(areaMax, newArea);
                }
            }
        }
        return areaMax;
    }
};