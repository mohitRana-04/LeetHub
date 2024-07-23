class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {

        vector<int> diff(nums.size(), 0);
        for(int i = 0; i< nums.size(); i++){
            diff[i] = -(nums[i]-target[i]);
        }

        int prev = diff[0];
        long long ans = abs(diff[0]);

        for(int i = 1; i< nums.size(); i++){
            if((prev>0 && diff[i]>0) || (prev<0 && diff[i]<0) ){
                if(abs(diff[i])>abs(prev)){
                    ans = ans + abs(diff[i])-abs(prev);
                }
            }else{
                ans = ans + abs(diff[i]);
            }
            prev = diff[i];
        }
        return ans;
    }
};