class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        deque<pair<int,int>> queue;
        int m = grid.size();
        int n = grid[0].size();
        int mins = 0;
        int freshoranges = 0;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 2){
                    queue.push_back({i,j});
                }else if(grid[i][j] == 1){
                    ++freshoranges;
                }
            }
        }

        while(!queue.empty()){
            int levelSize = queue.size();
            for(int k = 0; k < levelSize; ++k){
                vector<int> dR{1,-1,0,0};
            vector<int> dC{0,0,1,-1};
            auto coord = queue.begin();
            auto x = coord->first;
            auto y = coord->second;
            queue.pop_front();
            for(int i = 0; i < 4; ++i){
                auto newR = x + dR[i];
                auto newC = y + dC[i];
                if((min(newR, newC) < 0) || (newR == m || newC == n || grid[x][y] == 1)){
                    continue;
                    
                }else{
                    if(grid[newR][newC] == 1){
                        grid[newR][newC] = 2;
                        --freshoranges;
                        queue.push_back({newR, newC});
                    }   
                }

            }
            }
            if(!queue.empty()){
            ++mins;
        }   
        }
        if(freshoranges > 0) return -1;
        else return mins;
    }
};