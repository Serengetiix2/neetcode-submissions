class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = -1;
        int maxFreq = 0;
        int maxLength = 0;
        unordered_map<int, int> freqMap;
        for( int r = 0; r < (int)s.size(); ++r){
            freqMap[s[r]]++;
            maxFreq = max(maxFreq, freqMap[s[r]]);
            while(r - left + 1 - maxFreq > k){
                freqMap[s[left]]--;
                ++left;
            }
            maxLength = max(maxLength, r - left + 1);
        }
        

        
        return maxLength;
    }
};
