class Solution {
public:
    vector<vector<int>> result;
    void backtrack(vector<int>& nums, int start,vector<int>& current, vector<bool>& usage){
        for(int i = start; i < nums.size(); ++i){
            if(i > start && nums[i - 1] == nums[i]){
                continue;
            }
            if(usage[i] == false){
            usage[i] = true;
            current.push_back(nums[i]);
            result.push_back(current);
            backtrack(nums, i + 1,current,usage);
            current.pop_back();
            usage[i] = false;
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> current;
        vector<bool> usage(nums.size());
        sort(nums.begin(),nums.end());
        result.push_back(current);
        backtrack(nums, 0, current,usage);
        return result;
    }
};