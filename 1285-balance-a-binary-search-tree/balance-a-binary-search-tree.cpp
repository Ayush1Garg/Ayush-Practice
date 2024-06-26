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
    void dfs(TreeNode* root, vector<int> &a){
        if(!root) return;
        dfs(root->left,a);
        a.push_back(root->val);
        dfs(root->right,a);
    }
    TreeNode* balanceBST(vector<int> &arr, int l, int r){
        if (l>r) return NULL;
        const int m=(l+r)/2;
        TreeNode* left=(l>m-1)?NULL:balanceBST(arr,l, m-1);
        TreeNode* right=(m+1>r)?NULL:balanceBST(arr,m+1, r);
        return new TreeNode(arr[m], left, right);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        dfs(root,arr);
        return balanceBST(arr,0,arr.size()-1);
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();