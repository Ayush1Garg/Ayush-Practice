class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int n = values.size(), ans = 0;
        vector<int> bestleft(n,0);
        for(int i=1; i<n; i++){
            bestleft[i] = max(values[i-1] + i-1, bestleft[i-1]);
            ans = max(ans,bestleft[i] + values[i] - i);
        }
        return ans;
    }
};