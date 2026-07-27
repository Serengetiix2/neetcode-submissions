class Solution {
public:
    vector<vector<string>> result;
    bool isPali(string s, int left, int right){
        while(left < right){
            if(s[left] != s[right]) return false;
        ++left;
        --right;
        }
        return true;
    }

    void backtrack(string& s, int pos, vector<string>& current){
        if(pos == s.size()){
            result.push_back(current);
            return;
        }
       for(int i = pos; i < s.size(); ++i){
        string sub = s.substr(pos, i - pos + 1);
        if(isPali(sub, 0, sub.size() -1)){
        current.push_back(sub);
        backtrack(s,i + 1,current);
        current.pop_back(); 
        }
       }
}


    vector<vector<string>> partition(string s) {
        vector<string> current;
        string sub;
        int pos = 0;
        backtrack(s,pos, current);
        return result;
    }
};