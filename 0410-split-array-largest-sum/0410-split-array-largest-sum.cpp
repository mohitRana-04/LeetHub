class Solution {
public:

    bool feasible(int mid, vector<int>& nums, int k){
        int part = 1;
        int sum = 0;
        for(auto x: nums){
            sum+=x;
            if(sum>mid){
                sum=x;
                part++;
            }
        }
        if(part>k) return false;
        return true;

    }

    int splitArray(vector<int>& nums, int k) {
        int l=0, r=0;
        for(auto x: nums){
            l =max(l, x);
            r +=x;
        }
        while(l<r){
            int mid = l+(r-l)/2;
            if(feasible(mid, nums, k)){
                r = mid;
            } else{
                l = mid+1;
            }
            
        }
        return l;
    }
};