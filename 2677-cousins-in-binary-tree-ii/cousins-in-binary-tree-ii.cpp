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
    TreeNode* replaceValueInTree(TreeNode* root) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        queue<TreeNode *> q;
        vector<int> levelsum;
        int nodes = 1, sum = 0, k = 0;
        q.push(root);
        while(!q.empty()){
            nodes = q.size();
            sum = 0;
            while(nodes--){
                TreeNode *node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                sum += node->val;
            }
            levelsum.push_back(sum);
        }
        root->val = 0;
        q.push(root);
        while(!q.empty()){
            nodes = q.size();
            k++;
            while(nodes--){
                TreeNode* node = q.front();
                q.pop();
                int childsum = (node->left ? node->left->val : 0) + (node->right ? node->right->val : 0);
                if(node->left){
                    node->left->val = levelsum[k] - childsum;
                    q.push(node->left);
                }
                if(node->right){
                    node->right->val = levelsum[k] - childsum;
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};