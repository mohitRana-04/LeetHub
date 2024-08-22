class Solution {
public:
    int findComplement(int num) {
        int two = 0;
        int ans = 0;
        while(num){
            int rem = num%2;
            if(!rem){
                ans+= pow(2, two);
            }
            two++;
            num/=2;
        }
        return ans;
    }
};