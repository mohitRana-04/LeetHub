class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if(startGene == endGene) return 0;
        unordered_map<string, int> mp;
        for(auto x: bank) mp[x]++;
        unordered_map<string,  int> visited;
        queue<string> pq;
        pq.push(startGene);
        visited[startGene]++;
        vector<char> dir = {'A', 'C', 'T', 'G'};
        int cnt = 0;
        while(pq.size()){

            int n = pq.size();
            for(int i = 0; i< n; i++){
                string temp = pq.front();
                pq.pop();
                if(temp == endGene) return cnt;
                // ab is string ko check krna hai 4se
                for(int k = 0; k<4; k++){
                    char c = dir[k];
                    for(int j = 0; j< 8; j++){
                        
                        char ran = temp[j];
                        temp[j] = c;
                        
                        if(mp[temp] && !visited[temp]){
                            pq.push(temp);
                            visited[temp]++;
                        } 
                        temp[j] = ran;
                    }
                }
                
            }
            cnt++;
        }
        return -1;

    }
};