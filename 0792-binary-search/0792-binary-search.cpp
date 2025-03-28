class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l< r){
            // 1 2 3 4 5 6 
            int mid = l+(r-l)/2;
            if(nums[mid]>=target){
                r = mid;
            } else{
                l = mid+1;
            }
        }
        return nums[l] == target? l: -1;
    }
};