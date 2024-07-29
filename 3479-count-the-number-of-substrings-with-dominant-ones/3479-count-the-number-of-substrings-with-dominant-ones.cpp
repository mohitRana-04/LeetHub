class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> pre(s.size(), 0);
        pre[0] = s[0] == '1'?1:0;
        int ans = 0;

        for(int i = 1; i< s.size(); i++){
            if(s[i] == '1'){
                pre[i] = pre[i-1]+1;
            } else{
                pre[i] = pre[i-1];
            }
        }

        for(int i = 0; i< s.size(); i++){
            for(int j = i; j< s.size(); j++){
                int one = 0, zero = 0;
                if(i == 0){
                    one = pre[j];
                } else{
                    one = pre[j]-pre[i-1];
                }
                zero = j-i+1-one;

                if(zero*zero<=one){
                    ans++;
                    int temp = static_cast<int>(sqrt(one));
                    if(temp>zero){
                        if(j+temp-zero>=s.size()){
                            ans = ans+ (s.size()-j-1);
                        } else{
                            ans = ans+(temp-zero);
                        }
                        j = j+temp-zero;
                    }
                } else{
                    j = j+ (zero*zero)-one-1;
                }
            }
        }
        return ans;

    }
};