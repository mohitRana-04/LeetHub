class Solution {
public:
    int minimumPushes(string s) {
        
        vector<int> v(26, 0);

        for(auto x: s){
            v[x-'a']++;
            // cout<<v[x-'a'];
        }
        int ans = 0;
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        for(int i = 0; i< 26; i++){
            ans +=(i/8+1)*v[i];
        }
        return ans;


    }
};