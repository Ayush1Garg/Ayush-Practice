class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1));
        dp[0][0] = true;
        for(int i=0; i<m && p[i]=='*'; i++){
            dp[0][i+1] = true;
        }
        for(int j=1; j<=m; j++){
            for(int i=1; i<=n; i++){
                if(p[j-1]=='*'){
                    dp[i][j] = dp[i][j-1] || dp[i-1][j] || dp[i-1][j-1];
                }
                else{
                    dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '?');
                }
            }
        }
        return dp[n][m];
    }
};