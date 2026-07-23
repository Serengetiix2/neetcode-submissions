class Solution {
public:
    int search(vector<int>& nums, int target){
        if(nums[0] == target) return 0;
        int left = 0;
        int right = nums.size()-1;
        int mid;

        while(left < right){
            mid = (left + (right - left)/2);
            if(nums[mid] == target) return mid;
            if(nums[left] <= nums[mid]){
                if(target < nums[mid] && target >= nums[left]){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }else{
                if(target > nums[mid] && target <= nums[right]){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
            if(nums[left] == target || nums[right] == target){
                if(nums[left] == target){
                    return left;
                }else{
                    return right;
                }
            }

        }
        return -1;
        
    }
};