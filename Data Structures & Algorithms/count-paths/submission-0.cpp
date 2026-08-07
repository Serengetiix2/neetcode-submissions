class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> grid(m, vector<int>(n, 0));

        grid[m - 1][n -1] = 1;

        for(int r = m -1; r >= 0; --r){
            for(int c = n -1; c >=0; --c){
                if(grid[r][c] == 0){
                    int bV;
                    int lV;
                    if(r + 1 < m){
                        bV = grid[r + 1][c];
                    }else{
                        bV = 0;
                    }
                    if(c +1 < n){
                        lV = grid[r][c+1];
                    }else{
                        lV = 0;
                    }
                    grid[r][c] = (lV + bV);
                }
            }

        }
        return grid[0][0];
    }
};