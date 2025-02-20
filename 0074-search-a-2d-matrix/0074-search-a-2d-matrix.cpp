class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left= 0, right = matrix[0].size()-1;

        while(left<matrix.size() && right>=0 ){
            if(matrix[left][right] == target) return true;
            else if(matrix[left][right]> target){
                right--;
            } else{
                left++;
            }
        }
        return false;
    }
};