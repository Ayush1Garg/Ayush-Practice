class Solution {
    int numTreesHelper(int start, int end, unordered_map<string,int>& dp){
        if(start>=end) return 1;
        string key = to_string(start) + " " + to_string(end);
        if(dp.find(key)!=dp.end()) return dp[key];
        int trees = 0;
        for(int root = start; root<=end; root++){
            int leftTrees = numTreesHelper(start,root-1,dp);
            int rightTrees = numTreesHelper(root+1,end,dp);
            trees += leftTrees * rightTrees;
        }
        return dp[key] = trees;
    }
public:
    int numTrees(int n) {
        if(n<3) return n;
        unordered_map<string,int> dp;
        return numTreesHelper(1,n,dp);
    }
};