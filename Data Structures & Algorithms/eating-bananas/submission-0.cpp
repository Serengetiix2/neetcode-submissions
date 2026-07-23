class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxK = 1;
        int k = 1;
        int mid;
        for(auto pile : piles){
            maxK = max(maxK, pile);
        }

        while(k < maxK){

            mid = ((k + maxK) / 2);
            int cHours = 0;
            for(int i = 0; i < piles.size(); ++i){
                if(piles[i] < mid){
                    ++cHours;
                    ++i;
                    if(i == piles.size()) continue;
                }
                cHours += (piles[i] /mid);
                if(!(piles[i] % mid == 0)){
                    ++cHours;
                }

            }

            if(cHours <= h){
                maxK = mid;
                
            }else if(cHours > h){
                k = mid + 1;
            }
        }
        return k;
        
    }
};