class Solution {
public:
    int minimumDeletions(string s) {
        int cnt = 0;
        stack<char> st;
        for(auto x: s){
            if(st.size() && (st.top() == 'b' && x == 'a')){
                st.pop(); 
                cnt++;
            }
            else st.push(x);
        }
        return cnt;


    }
};