class Solution {
public:

    int solve(int ind, int parent, vector<bool>& hasApple, unordered_map<int, vector<int>>& mp){
        
        int time = 0;

        for(auto child: mp[ind]){
            if(child == parent) continue;
            int time_taken = solve(child, ind, hasApple, mp);
            if(hasApple[child] || time_taken>0){
                time += time_taken+2;
            }
        }
       return time;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> mp;
        for(auto x: edges){
            mp[x[0]].push_back(x[1]);
            mp[x[1]].push_back(x[0]);
        }
        
        return solve(0, -1, hasApple, mp);
    }
};