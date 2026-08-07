class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> grid(m+1, vector<int>(n+1, 0));

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(text1[i] == text2[j]){
                    grid[i + 1][j + 1] = 1+grid[i][j];
                }else{
                    grid[i + 1][j + 1] += max(grid[i + 1][j], grid[i][j + 1]);
                }
            }
        }
        return grid[m][n];
        
    }
};