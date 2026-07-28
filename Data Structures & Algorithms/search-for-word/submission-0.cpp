class Solution {
public:
    vector<pair<int, int>> getNeighbours(int m, int n, int r, int c, vector<pair<int,int>>& neighbours){
        vector<int> UpDown{-1, 1, 0,0};
        vector<int> LeftRight{0,0,-1,1};
        for(int l = 0; l < 4; ++l){
            int newR = r + LeftRight[l];
            int newC = c + UpDown[l];
            if((newR >= 0) && (newR < m)&&(newC >= 0) && (newC < n)){
                neighbours.push_back({newR,newC});
            }
        }
        return neighbours;
}

    bool backtrack(vector<vector<char>>& board, string word,int r, int c, int idx, vector<vector<bool>>& visited){
        int m = board.size();
        int n = board[0].size();
        if(r < 0 || r >= m || c < 0 || c >= n || visited[r][c] || board[r][c] != word[idx]){
            return false;
        }
        if(idx == (int)word.size() - 1) return true;
        visited[r][c] = true;
        vector<pair<int,int>> neighbours;
        getNeighbours(m, n, r, c, neighbours);

        for(auto& nb : neighbours){
            if(backtrack(board, word, nb.first, nb.second, idx + 1, visited)){
                return true;
            }
        }
        visited[r][c] = false;
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int idx = 0;
        vector<vector<bool>>visited(m,vector<bool>(n, false));
        vector<int> needed(128,0);
        vector<int> inBoard(128,0);
        for(auto c : word){
            needed[c]++;
        }
        for(auto r : board){
            for(auto c : r){
                inBoard[c]++;
            }
        }
        for(int x = 0; x < needed.size(); ++x){
            if(needed[x] > inBoard[x]) return false;
        }

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(backtrack(board, word, i, j, idx, visited)){
                    return true;
                }
            }
        }

        return false;


    }
};