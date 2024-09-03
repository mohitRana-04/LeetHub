class Solution {
public:

    int solve(string s){
        int sum  = 0;
        for(auto x: s){
            int dig ;
            dig = x-'a'+1;
            while(dig){
                sum+=dig%10;
                dig/=10;
            }
        }
        return sum;
    }

    int getLucky(string s, int k) {
        int dig = solve(s);
        while(k!=1){
            int temp = 0;
            while(dig){
                temp+=dig%10;
                dig/=10;
            }
            dig = temp;
            k--;
        }
        return dig;
    }
};