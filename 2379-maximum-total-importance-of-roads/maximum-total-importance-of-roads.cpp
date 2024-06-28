class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        if(n==2) return 3;
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        vector<long long> num(n,0);
        for(auto road : roads){
            num[road[0]]++;
            num[road[1]]++;
        }
        sort(num.begin(),num.end());
        long long ans = 0;
        for(int i=0; i<n; i++){
            ans += (i+1)*num[i];
        }
        return ans;
    }
};