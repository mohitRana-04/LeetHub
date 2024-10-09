class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0;
        int maxi = INT_MIN;

        for(auto x: nums){
            cur = cur+x;
            maxi = max(maxi, cur);
            if(cur<0){
                cur = 0;
            }
        }
        return maxi;
    }
};