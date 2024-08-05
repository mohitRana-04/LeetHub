class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> ans(11, vector<int>(11, 0));

        for(auto x: pick){
            int x1 = x[0];
            int y1 = x[1];
            ans[x1][y1]++;
        }
        int res = 0;
        for(int i = 0; i< n; i++){
            for(int j = 0; j< 11; j++){
                if(ans[i][j]>i){
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};