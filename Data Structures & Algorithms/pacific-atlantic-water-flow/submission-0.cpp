class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacificVisited(m,vector<bool>(n, false));
        vector<vector<bool>> atlanticVisited(m,vector<bool>(n, false));
        vector<vector<int>> result;
        deque<pair<int,int>> pacQueue;
        deque<pair<int,int>> atlQueue;
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(i == 0 || j == 0){
                    pacificVisited[i][j] = true;
                    pacQueue.push_back({i, j});
                } 
                if(i == m-1 || j == n-1){
                    atlanticVisited[i][j] = true;
                    atlQueue.push_back({i, j});
                } 
            }
        }
        vector<int> dR{-1,1,0,0};
        vector<int> dC{0,0,-1,1};
        while(!pacQueue.empty()){
            auto coord = pacQueue.begin();
            auto x = coord->first;
            auto y = coord->second;
            pacQueue.pop_front();
            for(int i = 0; i < 4; ++i){
                auto newR = x + dR[i];
                auto newC = y + dC[i];
                if(min(newR,newC) < 0 || newR >= m || newC >= n || heights[newR][newC] < heights[x][y]) continue;
                if(pacificVisited[newR][newC] == true) continue;
                
                if(heights[newR][newC] >= heights[x][y]){
                    pacificVisited[newR][newC] = true;
                }
                pacQueue.push_back({newR, newC});
            }
        }
        while(!atlQueue.empty()){
            auto coord = atlQueue.begin();
            auto x = coord->first;
            auto y = coord->second;
            atlQueue.pop_front();
            for(int i = 0; i < 4; ++i){
                auto newR = x + dR[i];
                auto newC = y + dC[i];
                if(min(newR,newC) < 0 || newR >= m || newC >= n || heights[newR][newC] < heights[x][y]) continue;
                
                if(atlanticVisited[newR][newC] == true) continue;
                if (heights[newR][newC] >= heights[x][y]){
                    atlanticVisited[newR][newC] = true;
                }
                atlQueue.push_back({newR, newC});
            }
    
        }
        for(int r = 0; r < pacificVisited.size(); ++r){
            for(int c = 0; c < pacificVisited[r].size(); ++c){
                if(pacificVisited[r][c] == true && atlanticVisited[r][c] == true){
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};