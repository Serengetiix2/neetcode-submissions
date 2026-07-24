class Solution {
public:
    int findDuplicate(vector<int>& nums){
        int slow = 0;
        int i;

        for(i = 0;  i < nums.size(); ++i){
            int pointer = abs(nums[i]) -1;
            if(nums[pointer] < 0){
                return abs(nums[i]);
            }
            nums[pointer] *= -1;
        }
        return 0;
        
    }
};