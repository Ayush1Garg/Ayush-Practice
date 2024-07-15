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
#define MX 100001
#pragma GCC optimize("03")
#pragma GCC target ("avx")
#pragma GCC target ("-fsplit-loops")
TreeNode* Nodes[MX];
TreeNode nodes[MX];
int P[MX];
int V[MX];
int cnt = 0;
int idx = 0;
TreeNode* p;
TreeNode* c;
auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    TreeNode* createBinaryTree(const vector<vector<int>>& descriptions) {
        while(cnt) Nodes[V[--cnt]] = nullptr, P[V[cnt]] = 0;
        idx = cnt;
        for(const vector<int> &desc : descriptions){
            int a = desc[0], b = desc[1];
            p = Nodes[a] ? Nodes[a] : (Nodes[a] = &(nodes[idx++] = TreeNode(V[cnt++] = a)));
            c = Nodes[b] ? Nodes[b] : (Nodes[b] = &(nodes[idx++] = TreeNode(V[cnt++] = b)));
            P[b] = a;
            if(desc[2]) p -> left = c; else p -> right = c;
        }
        for(const vector<int> &desc : descriptions) if(!P[desc[0]]) return Nodes[desc[0]];
        return NULL;
    }
};