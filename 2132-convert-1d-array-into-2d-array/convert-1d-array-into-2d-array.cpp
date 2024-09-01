class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size()!=m*n) return {};
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        vector<vector<int>> ans(m,vector<int>(n));
        int r = 0, c = 0;
        for(int i=0; i<original.size(); i++){
            ans[r][c] = original[i];
            c++;
            if(c==n){
                c = 0;
                r++;
            }
        }
        return ans;
    }
};