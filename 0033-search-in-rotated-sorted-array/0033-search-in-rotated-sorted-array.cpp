class Solution {
public:
    int pivot(vector<int>& nums){
        // here we're finding smallest element
        int l = 0, r = nums.size()-1;
        while(l< r){
            int mid = l+(r-l)/2;
            if(nums[mid]>=nums[r]){
                l = mid+1;
            } else{
                r = mid;
            }
        }
        return l;
    }

    int bsearch(vector<int>& nums, int l, int r, int target){
       
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

    int search(vector<int>& nums, int target) {
        
        int n = pivot(nums);
        // return n;
        int dig1 = bsearch(nums, 0, n-1, target);
        if(dig1 != -1) return dig1;
        int dig2 = bsearch(nums, n, nums.size()-1, target);
        return dig2;

    }
};