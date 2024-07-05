class Solution {
public:

    int helper(vector<vector<int>>& grid, int i, int j, int n, int m){
        int count =0;
        queue<pair<int, int>> pq;
        pq.push({i, j});
        grid[i][j] = 0;
        count++;
        while(pq.size()){
            auto temp = pq.front();
            pq.pop();
            int dir[4][2] = {{0,1}, {0,-1}, {-1,0}, {1,0}};
            for(int i = 0; i<4; i++){
                int x = temp.first+dir[i][0];
                int y = temp.second+dir[i][1];

                if(x>=0 && y>=0 && x<n && y<m && grid[x][y] == 1){
                    pq.push({x,y});
                    grid[x][y] = 0;
                    count++;
                }

            }
        }
        return count;


    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

    
    int maxi = 0;
    int n = grid.size();
    int m = grid[0].size();
    for(int i = 0; i< n; i++){
        for(int j = 0; j< m; j++){
            if(grid[i][j] == 1){
                int countone = helper(grid, i, j, n, m);
                maxi = max(maxi, countone);
            }
        }
    }
    return maxi;

    }
};