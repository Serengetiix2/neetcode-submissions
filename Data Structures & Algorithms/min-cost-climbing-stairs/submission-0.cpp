
class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int n = cost.size();
        int prev2 = cost[0];
        int prev1 = cost[1];
        
        for (int i = 2; i < n; ++i) {
            int current = cost[i] + std::min(prev1, prev2);
            prev2 = prev1;
            prev1 = current;
        }
        
        // The top of the floor can be reached from either the last step or second to last step
        return std::min(prev1, prev2);
    }
};