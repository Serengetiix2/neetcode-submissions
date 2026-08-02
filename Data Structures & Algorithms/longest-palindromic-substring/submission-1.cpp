class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int length = 0;
        string cS = "";
        int l;
        int r;
        int start = 0;

        for(int c = 0; c < 2 * n-1; ++c){
            l = c /2;
            r = l + (c % 2);

            while(l >= 0 && r < n && s[l] == s[r]){
                --l;
                ++r;
            }

            if(r - l -1 > length){
                length = r - l - 1;
                start = l + 1;
            }
        }
        return s.substr(start, length);
        
    }
};