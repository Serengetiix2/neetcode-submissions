class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int maxP = nums[0];
        int minP = nums[0];
        int result = maxP;

        for(int i = 1; i < n; ++i){
            int tempMax = max(nums[i],max(maxP * nums[i],nums[i] * minP));
            minP = min(nums[i],min(maxP * nums[i],nums[i] * minP));

            maxP = tempMax;
            result = max(maxP, result);

        }
        return result;
        
    }
};