class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m*n - 1;

        while(left <= right){
            int mid = (left + (right - left));
            int row = mid / n;
            int col = mid % n;

            if(matrix[row][col] == target) return true;
            if(matrix[row][col] > target){
                right = mid;
                --right;
            }else if(matrix[row][col] < target){
                left = mid;
                ++left;
            }
        }
        return false;
    }
};
