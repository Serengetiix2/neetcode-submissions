class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        auto total = accumulate(nums.begin(), nums.end(), 0);

        if((total+target) % 2) return 0;
        if(abs(target) > total) return 0;
        
        int p = (total + target) / 2;
        vector<int>dp(p +1, 0);
        dp[0] = 1;

        for(auto num : nums){
            for(int c = p; c >= num; --c){
                dp[c] += dp[c - num];
            }
        }
        return dp[p];
    }
};