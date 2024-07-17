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
    void help(TreeNode* node, TreeNode* parent, TreeNode* root, set<int>& s, vector<TreeNode*>&ans, int dir = 1 ){
        if(!node) return;
        if(s.find(node->val)!=s.end()){
                if(!parent || root==node){
                    help(node->left,NULL,node->left,s,ans,0);
                    help(node->right,NULL,node->right,s,ans,1);
                }
                else{
                    if(dir){
                        parent->right = NULL;
                    }
                    else{
                        parent->left = NULL;
                    }
                    help(node->left,NULL,node->left,s,ans,0);
                    help(node->right,NULL,node->right,s,ans,1);
                }
        }
        else{
            if(node==root) ans.push_back(node);
            help(node->left,node,root,s,ans,0);
            help(node->right,node,root,s,ans,1);
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        vector<TreeNode*> ans;
        set<int> s;
        for(int i=0; i<to_delete.size(); i++){
            s.insert(to_delete[i]);
        }
        help(root,NULL,root,s,ans);
        return ans;
    }
};