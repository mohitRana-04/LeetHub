class Solution {
public:
    int minimumLength(string s) {
        
        unordered_map<char, int> mp;

        int ans = 0;
        for(auto x: s){
            mp[x]++;
        }

        for(auto x: mp){
            int count = x.second;
            while(count>=3){
                count = count-2;
            }
            ans = ans + count;
        }
        return ans;

        // return 5;
    }
};