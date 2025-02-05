class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n,0);
        dp[0] = triangle[0][0];
        cout<<dp[0]<<endl;
        for(int i=1; i<n; i++){
            for(int j=i; j>=0; j--){
                dp[j] = triangle[i][j] + min( (j==i ? INT_MAX : dp[j]) , (j==0? INT_MAX : dp[j-1]) );
                // cout<<dp[j]<<" ";
            }
            // cout<<endl;
        }
        int ans = dp[0];
        for(int i=0; i<n; i++){
            ans = min(ans,dp[i]);
        }
        return ans;
    }
};