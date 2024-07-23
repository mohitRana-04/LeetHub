class Solution {
public:

    bool solve(unordered_map<int, vector<int>> &mp, int ind, vector<int>& vis){

        vis[ind] = 1;
        queue<int> pq;
        pq.push(ind);

        while(pq.size()){
            int n = pq.size();
            for(int i = 0; i< n; i++){
                auto temp = pq.front();
                pq.pop();
                for(auto x: mp[temp]){
                    if(vis[x] == vis[temp]) return false;
                    if(vis[x] == -1){
                        vis[x] = 1-vis[temp];
                        pq.push(x);
                    } 
                }
            }
        }
        return true;

    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i< dislikes.size(); i++){
            mp[dislikes[i][0]].push_back(dislikes[i][1]);
            mp[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        vector<int> vis(n+1, -1);

        for(int i = 1; i<= n; i++ ){
            if(vis[i] == -1){
                if(!solve(mp, i, vis)){
                    return false;
                }
            }   
        }
        return true;
    }
};