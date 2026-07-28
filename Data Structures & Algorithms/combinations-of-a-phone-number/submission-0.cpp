class Solution {
public:
    vector<string> result;
    void backtrack(vector<string>& numset, string& digits,int pos, string curString){
        if (digits.empty()) return;
        if(curString.size() == digits.size()){
            result.push_back(curString);
            return;
        }
        
            int idx = digits[pos] - '0';
            for(int j = 0; j < numset[idx].size(); ++j){
            curString.push_back(numset[idx][j]);
            backtrack(numset, digits, pos + 1, curString);
            curString.pop_back();
            }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>numset;
        numset.insert(numset.end(), {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
        int pos = 0;
        string curString = "";
        backtrack(numset, digits, pos, curString);
        return result;
    }
};