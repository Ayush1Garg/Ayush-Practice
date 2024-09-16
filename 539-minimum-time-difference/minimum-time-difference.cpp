class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        vector<int> times(timePoints.size());
        for(int i=0; i<times.size(); i++){
            times[i] = ((timePoints[i][0] - '0')*10 + (timePoints[i][1] - '0'))*60 + ((timePoints[i][3] - '0')*10 + (timePoints[i][4] - '0'));
            // cout<<times[i]<<" ";
        }
        sort(times.begin(),times.end());
        int n = times.size();
        int ans = (24*60 - times[n-1] + times[0]);
        for(int i=1; i<n; i++){
            ans = min(ans,times[i] - times[i-1]);
        }
        return ans;
    }
};