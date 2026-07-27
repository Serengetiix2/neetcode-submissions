class Solution {
public:
    vector<vector<int>> result;
    void permute(vector<int>& nums, vector<int>& current, int pos, vector<bool>& usage){
        if(current.size() == nums.size()){
            result.push_back(current);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(i > 0 && nums[i - 1] == nums[i] && usage[i - 1] == false) continue;
            if(usage[i] == false){
            usage[i] = true;
            current.push_back(nums[i]);
            permute(nums, current, i+1, usage);
            current.pop_back();
            usage[i] = false;
            }
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int pos = 0;
        vector<bool> usage(nums.size(),false);
        vector<int> current;
        permute(nums,current, pos, usage);
        
        return result;
    }
};