class Solution {
public:
    void add(char c, vector<int>& window, vector<int>& need, int& match){
        int idx = c - 'a';
        if(window[idx] == need[idx]){
            match -= 1;
        }
        window[idx] += 1;
        if(window[idx] == need[idx]){
            match += 1;
        }
    }
    void remove(char c, vector<int>& window, vector<int>& need, int& match){
        int idx = c - 'a';
        if(window[idx] == need[idx]){
            match -= 1;
        }
        window[idx] -= 1;
        if(window[idx] == need[idx]){
            match += 1;
        }
    }


    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
        vector<int> need(26, 0);
        vector<int> window(26, 0);
        int match = 0;
        int k = s1.size();
        for(char c : s1){
            need[c - 'a'] += 1;
        }

        for(int i = 0; i < 26; ++i){
            if(need[i] == window[i]) match++;
        }

        for(int i = 0; i < k; ++i){
            add(s2[i], window, need, match);
        }
        if(match == 26) return true;

        for(int i = k; i < (int)s2.size(); ++i){
            add(s2[i], window, need, match);
            remove(s2[i - k], window, need, match);

            if(match == 26) return true;
        }
        return false;  
        }
};