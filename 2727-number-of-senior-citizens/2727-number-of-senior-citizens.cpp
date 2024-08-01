class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for(auto x: details){
            string s = "";
            s = x[11];
            s+=x[12];
            int n = stoi(s);
            if(n>60) cnt++;
            // return n;
        }
        return cnt;
    }
};