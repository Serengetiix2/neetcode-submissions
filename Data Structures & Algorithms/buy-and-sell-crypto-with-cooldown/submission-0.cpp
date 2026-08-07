class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size());
        int buy1 = 0;
        int sell1 = 0;
        int buy2 = 0;

        for(int c = prices.size() -1; c >= 0; --c){
            int buyNow = max(sell1 - prices[c], buy1);
            int sellNow = max(buy2 + prices[c], sell1);

            buy2 = buy1;
            buy1 = buyNow;
            sell1 = sellNow;
        }

        return buy1;
    }
};