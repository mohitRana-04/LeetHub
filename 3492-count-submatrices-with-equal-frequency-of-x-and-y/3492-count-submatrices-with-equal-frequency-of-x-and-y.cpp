class Solution {
public:

    void helper(vector<vector<int>> &dp, char c, vector<vector<char>> grid){

        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i<n; i++){
            for(int j = 0; j< m; j++){
                if(grid[i][j] == c){
                    dp[i][j] = 1;
                }
            }
        }
    }

    void please(vector<vector<int>> &dp){
        int n = dp.size();
        int m = dp[0].size();

        for(int i = 0; i< n; i++){
            for(int j = 0; j< m; j++){
                if(i==0 && j == 0) dp[i][j] = dp[i][j];

                else if(i==0) dp[i][j]+=dp[i][j-1];
                else if(j==0) dp[i][j]+=dp[i-1][j];
                else dp[i][j] += dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]; 
            }
        }

    }

    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> xcount(n, vector<int>(m, 0));
        vector<vector<int>> ycount(n, vector<int>(m, 0));

        helper(xcount, 'X', grid);
        helper(ycount, 'Y', grid);

        please(xcount);
        please(ycount);
        int ans = 0;
        for(int i = 0; i< n; i++){
            for(int j = 0; j< m; j++){
                if(xcount[i][j] == ycount[i][j] && xcount[i][j]>0 ){
                    ans++;
                }
            }
        }
        return ans;
    }
};