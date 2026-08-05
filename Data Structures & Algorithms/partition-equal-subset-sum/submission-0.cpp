class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int numSum = 0;
        for(auto n : nums){
            numSum += n;
        }
         if(numSum % 2) return false;
        int target = numSum /2;

        unordered_set<int> seen;
        seen.insert(0);

        for(int i = n -1; i >=0; --i){
            vector<int> tempset;
            for(auto t : seen){
                auto cSum = t + nums[i];
                if((cSum) == target){
                    return true;
                }
                if(cSum <= target){
                    tempset.push_back(cSum);
                }
            }
            seen.insert(tempset.begin(), tempset.end());
        }
        return false;

    }
};