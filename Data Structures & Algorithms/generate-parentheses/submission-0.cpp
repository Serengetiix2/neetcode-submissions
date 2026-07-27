class Solution {
public:
    vector<string> result;
    //n == 3
    void backtrack(int n, int open, int close, string current){
        if(open == n && close == n){
            result.push_back(current);
            return;
        }
        if(open < n){
            backtrack(n, open + 1, close, current + "(");
        }if(close < open){
            backtrack(n, open, close + 1, current + ")");
        }
    }

    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = 0;
        string current;
        backtrack(n, open, close, current);
        return result;
    }
};