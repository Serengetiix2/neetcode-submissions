class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m  = board.size();
        int n = board[0].size();
        deque<pair<int,int>> queue;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if((i == 0 || i == m-1 || j == 0 || j == n-1) && board[i][j] == 'O'){
                    board[i][j] = '#';
                    queue.push_back({i,j});
                }
            }
        }
        vector<int> dR{-1,1,0,0};
        vector<int> dC{0,0,-1,1};
        while(!queue.empty()){
            auto coord = queue.front();
            auto x = coord.first;
            auto y = coord.second;
            queue.pop_front();

            for(int i = 0; i < 4; ++i){
                int newR = x + dR[i];
                int newC = y + dC[i];
                if((min(newR, newC) < 0) || (newR == m || newC == n)|| board[newR][newC] == '#' || board[newR][newC] == 'X') continue;

                board[newR][newC] = '#';
                queue.push_back({newR,newC});
            }
            
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};