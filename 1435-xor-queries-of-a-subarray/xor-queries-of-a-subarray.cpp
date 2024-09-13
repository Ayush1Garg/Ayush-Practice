class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        vector<int> xors = arr;
        for(int i=1; i<arr.size(); i++) xors[i] = xors[i-1]^xors[i];
        vector<int> ans(queries.size());
        for(int i=0; i<ans.size(); i++){
            if(queries[i][0] == 0) ans[i] = xors[queries[i][1]];
            else ans[i] = xors[queries[i][1]] ^ xors[queries[i][0]-1];
        }
        return ans;
    }
};