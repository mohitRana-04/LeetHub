/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int start, int end, int &ind){
        // if(start>end) return NULL;

        // int val = preorder[ind];
        // int i = start;
        // for( ; i<=end; i++ ){
        //     if(inorder[i] == val) break;
        // }
        // ind++;
        // TreeNode* root = new TreeNode(val);
        // root->left = helper(preorder, inorder, start, i-1, ind);
        // root->right = helper(preorder, inorder, i+1, end, ind);
        // return root;


        if(start>end) return NULL;

        int val = preorder[ind];
        int i = start;
        for(i; i<preorder.size(); i++){
            if(inorder[i] == val) break;
        }

        ind++;
        TreeNode* root = new TreeNode(val);
        root->left = helper(preorder, inorder, start, i-1, ind);
        root->right = helper(preorder, inorder, i+1, end, ind);
        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ind  = 0;
        return helper(preorder, inorder, 0, preorder.size()-1, ind);
    }
};