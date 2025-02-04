class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), ans = 0;
        vector<int> dp(n,0);
        for(int i=1; i<n; i++){
            if(s[i]=='(') continue;
            if(s[i-1]=='('){
                dp[i] = 2 + ( (i-2) > 0 ? dp[i-2] : 0 );
            }
            else{
                if(i - dp[i-1] - 1 >=0 && s[i-dp[i-1]-1] == '('){
                    dp[i] = 2 + dp[i-1] + ( (i-dp[i-1]-2)>=0 ? dp[i-dp[i-1]-2] : 0 );
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};