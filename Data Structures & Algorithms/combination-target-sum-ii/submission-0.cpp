class Solution {
public:
    vector<vector<int>> result;
    void combine(vector<int>& candidates, int pos,int target,int sum,vector<int>& current){   
        if(sum == target){
            result.push_back(current);
            return;
        }
            for(int i = pos; i < candidates.size(); ++i){
            if(sum > target) return;
            if(i > pos && candidates[i - 1] == candidates[i]) continue;
            if(candidates[i] > target) continue;;
                current.push_back(candidates[i]);
                sum += candidates[i];
                combine(candidates,i + 1, target, sum,current);
                current.pop_back();
                sum -= candidates[i];
        }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> state(candidates.size());
        sort(candidates.begin(), candidates.end());
        int sum = 0;
        vector<int> current;
        
        combine(candidates,0,target, sum, current);
        return result;
    }
};