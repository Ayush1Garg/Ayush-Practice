class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int start = 0, end = 0;
        for(int i=0; i<n; i++) dp[i][i] = true;
        for(int i=0; i<n-1; i++){
            if(s[i]==s[i+1]){
                dp[i][i+1] = true;
                start = i; end = i+1;
            } 
        }
        for(int diff = 2; diff < n; diff++){
            for(int i=0; i<n-diff; i++){
                int j = i + diff;
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    start = i; end = j;
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};