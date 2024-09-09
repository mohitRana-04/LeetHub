/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    void helper(int m, int n, int i, int j, vector<vector<int>> &ans, 
    vector<vector<int>> &vis, ListNode* &head){
        if(i<0 || j<0 || i>=m || j>=n || vis[i][j] || head==NULL){
            return;
        }

        vis[i][j] = 1;
        ans[i][j] = head->val;
        head = head->next;

        if(i<=j+1){
            helper(m, n, i, j+1, ans, vis, head);
        }
        helper(m, n, i+1, j, ans, vis, head);
        helper(m, n, i, j-1, ans, vis, head);
        helper(m, n, i-1, j, ans, vis, head);
    }

    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        vector<vector<int>> ans(m, vector<int>(n, -1));
        vector<vector<int>> vis(m, vector<int>(n, 0));

        helper(m, n, 0, 0, ans, vis, head);
        return ans;
    }
};