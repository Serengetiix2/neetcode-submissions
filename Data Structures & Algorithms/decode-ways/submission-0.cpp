class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        unordered_map<int, int> configs;
        int n = s.size();
        int count = 1;
        configs[n] = 1;

       for(int i = n -1; i >= 0; --i){
        if(s[i] == '0'){
            configs[i] = 0;
        }else{
            configs[i] = configs[i + 1];
        if(i + 1 < n){
            int td = stoi(s.substr(i, 2));
            if(td <= 26){
                configs[i] += configs[i + 2];
            }
        }

        }
        
       }
       return configs[0];
        
    }
};