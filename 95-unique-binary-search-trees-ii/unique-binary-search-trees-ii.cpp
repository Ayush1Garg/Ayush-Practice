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
    vector<TreeNode*> treeHelp(int start, int end, unordered_map<string,vector<TreeNode*>>& dp){
        string key = to_string(start) + " " + to_string(end);
        if(dp.find(key)!=dp.end()) return dp[key];
        vector<TreeNode*> trees;
        if(start>end){
            trees.push_back(nullptr);
            return trees;
        }
        for(int root = start; root<=end; root++){
            vector<TreeNode*> leftTrees = treeHelp(start, root-1 , dp);
            vector<TreeNode*> rightTrees = treeHelp(root+1, end, dp);
            for(auto& leftTree : leftTrees){
                for(auto& rightTree : rightTrees){
                    TreeNode* node = new TreeNode(root,leftTree,rightTree);
                    trees.push_back(node);
                }
            }
        }
        dp[key] = trees;
        return trees;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return vector<TreeNode*>();
        unordered_map<string,vector<TreeNode*>> dp;
        return treeHelp(1,n,dp);
    }
};