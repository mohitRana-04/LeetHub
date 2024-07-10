class Solution {
public:
    vector<string> ans;

    void helper(int left, int right, string op){
        if(left == 0 && right == 0){
            ans.push_back(op);
            return;
        }
        
        if(left){
            string op1 = op;
            op1.push_back('(');
            helper(left-1, right, op1);
        }
        if(right>left){
            string op2 = op;
            op2.push_back(')');
            helper(left, right-1, op2);
        }
        return ;
    }

    vector<string> generateParenthesis(int n) {
    
        string op = "";
        int left = n;
        int right = n;
        helper(left, right, op);
        return ans;


    }
};