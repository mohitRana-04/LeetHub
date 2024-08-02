class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int r = 0, l = 0;
        int one = 0;
        for(auto x: nums) if(x) one++;
        int ans = 0, len = 0;
        while(r< nums.size()*2){
            if(nums[r%nums.size()]){
                len++;
            }
            if(r-l+1>one){
                len = len - nums[l%nums.size()];
                l++;
            }

            ans = max(len, ans);
            r++;
        }
        return one-ans;
    }
};