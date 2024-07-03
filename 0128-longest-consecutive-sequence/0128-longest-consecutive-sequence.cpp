class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(auto x: nums) st.insert(x);
        int maxi =0;
        for(auto x: st){
            // handling the left part means not present
            if(st.find(x-1)==st.end()){
                int length = 0;
                while(st.find(x+length) != st.end()){
                    length++;
                    maxi = max(maxi, length);
                }
            }
        }
        return maxi;
    }
};