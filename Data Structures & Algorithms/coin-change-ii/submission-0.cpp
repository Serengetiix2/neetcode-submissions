class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<long long> dp(amount + 1, 0);
        dp[0] = 1;
        int g = coins[0];

        for(auto c : coins){
            g = gcd(g, c);
        }
        if(amount % g){
            return 0;
        }

        for(int i = 0; i < n; ++i){
            for(int j = coins[i]; j <= amount; ++j){
                dp[j] += dp[j - coins[i]];
                if (dp[j] > (1LL << 31)) dp[j] = (1LL << 31);
            }
        }

        return dp[amount];
    }
};