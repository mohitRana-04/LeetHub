class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        int ans = 1;
        int maxi = INT_MIN;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i]>nums[i-1]){
                ans++;
            }
            else{
                maxi = max(maxi, ans);
                ans = 1;
            }
        }
        return max(maxi, ans);

    }
};