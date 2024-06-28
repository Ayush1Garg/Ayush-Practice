class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int> mp(n);
        for(auto& edge : roads)
        {
            mp[edge[0]]++;
            mp[edge[1]]++;
        }
        sort(mp.begin(), mp.end());
        long long res = 0;
        for(int i = 0; i < n; i++)
        {
            res += (long long)(i + 1) * mp[i];
        }
        return res;

    }
};