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
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return NULL;
        if(root==p || root==q) return root;
        TreeNode* left = LCA(root->left,p,q);
        TreeNode* right = LCA(root->right,p,q);
        if(left==NULL) return right;
        if(right==NULL) return left;
        return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        return LCA(root,p,q);
    }
};