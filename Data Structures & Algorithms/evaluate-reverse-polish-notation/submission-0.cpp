class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int result;

        for(int n = 0; n < tokens.size(); ++n){
        string s = tokens[n];
        if(s == "+" || s == "-" || s == "*" || s == "/"){
            int left = nums.top();
            nums.pop();
            int right = nums.top();
            nums.pop();
            if(tokens[n] == "+"){
                nums.push(right + left);
            }else if(tokens[n] == "*"){
                nums.push(right * left);
            }else if(tokens[n] == "/"){
                nums.push(right / left);
            }else{
                nums.push(right - left);
            }
           
        }else{
            nums.push(stoi(s));
        }

        }
        return nums.top();
    }
};
