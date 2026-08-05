class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();
        vector<bool> seg(n + 1, false);
        seg[n] = true;
        
        for(int i = n-1; i >= 0; --i){
            for(auto& word : wordDict){
                if((i + word.size()) <= n && s.substr(i, word.size()) == word){
                    seg[i] = seg[i + word.size()];
                }
                 if(seg[i]){
                break;
            }
            }
        }
        return seg[0];

    }
};