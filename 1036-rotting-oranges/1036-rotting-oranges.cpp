class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0, fresh = 0, rotten = 0;
        queue<pair<int, int>> pq;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i< n; i++){
            for(int j = 0; j< m; j++){
                if(grid[i][j] == 2){
                    pq.push({i,j});
                    rotten++;
                }
                if(grid[i][j] == 1) fresh++;
            }
        }

        int dir[4][2] = {{0,1}, {0,-1}, {-1,0}, {1,0}};
        while(pq.size()){
            int pqs = pq.size();
            for(int i = 0; i< pqs; i++){
                auto temp = pq.front();
                pq.pop();

                for(int j = 0; j<4; j++){
                    int x = temp.first+dir[j][0];
                    int y = temp.second+dir[j][1];
                    
                    if(x>=0 && y>=0 && x<n && y<m && grid[x][y] == 1){
                        fresh--;
                        grid[x][y] = 2;
                        pq.push({x,y});
                    }

                }

            }
            ans++;
        }

        if(fresh>0) return -1;
        return ans>0 ?ans-1:0;
    }
};