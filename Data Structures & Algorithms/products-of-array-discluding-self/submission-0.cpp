class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> output;
    int suffixProd = 1;
    int prefixProd = 1;
    for(int i = 0; i < nums.size(); ++i){
        if(i != 0){
            prefixProd *= nums[i - 1];
        }
        output.push_back(prefixProd); 
    }
    int n = output.size() - 1;
    for(int j = n; j >= 0; --j){
        output[j] *= suffixProd;
        suffixProd *= nums[j];
    }
    return output;
    }
};
