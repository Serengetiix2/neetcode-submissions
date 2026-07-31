class Solution {
public:
    int INF = 2147483647;
    vector<pair<int,int>> getNs(vector<vector<int>>& grid, int r, int c){
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int,int>> neighbours;
        vector<int> dR{1,-1,0,0};
        vector<int> dC{0,0,1,-1};

        for(int i = 0; i < 4; ++i){
            auto newR = r + dR[i];
            auto newC = c + dC[i];
            if(!(min(newR, newC) < 0) && !(newR == m || newC == n || grid[newR][newC] < INF)){
                neighbours.push_back({newR, newC});
            }
        }
        return neighbours;
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        deque<pair<int,int>> queue;
        for(int i = 0; i < m; ++i){
            for(int j= 0; j < n; ++j){
                if(grid[i][j] == 0){
                    pair<int,int> start{i,j};
                    queue.push_front(start);
                }
            }
        }
        while(!queue.empty()){
            int distance = 0;
            auto coord = queue.begin();
            auto x = coord->first;
            auto y = coord->second;
            queue.pop_front();
            auto NBs = getNs(grid, x, y);
            for(auto nb : NBs){
                auto nr = nb.first;
                auto nc = nb.second;
                if(grid[nr][nc] == INF){
                grid[nr][nc] = grid[x][y] + 1;
                queue.push_back({nr, nc});
            }
            }
        }
        
    }
    
};
