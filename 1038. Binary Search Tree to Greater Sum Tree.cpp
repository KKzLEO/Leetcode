/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        ModifyTree(root, 0);
        return root;
    }
    
    
    TreeNode* ModifyTree(TreeNode* root, int val){
        if(!root) return NULL;
        
        root->val += SumOfValue(root->right) + val;
        ModifyTree(root->right, val);
        ModifyTree(root->left, root->val);
        
        return root;
    }
    
    int SumOfValue(TreeNode* root){
        if(!root) return 0;
        
        return root->val + SumOfValue(root->right) + SumOfValue(root->left);
    }
    
    
};