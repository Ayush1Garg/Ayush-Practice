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
    void helper(TreeNode* node, int &toadd){
        if(!node) return;
        helper(node->right, toadd);
        toadd += node->val;
        node->val = toadd;
        helper(node->left, toadd);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        int extra = 0;
        helper(root,extra);
        return root;
    }
};