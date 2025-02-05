class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n);
        if(s[0]=='0') return 0;
        dp[0] = 1;
        for(int i=1; i<n; i++){
            if(s[i]=='0'){
                if(s[i-1]!='1' && s[i-1]!='2') return 0;
                if(i-2>=0) dp[i] = dp[i-2];
                else dp[i] = 1;
                cout<<dp[i]<<"#0 ";
            }
            else if(s[i-1]=='1'){
                dp[i] = dp[i-1] + ((i-2)>=0 ? dp[i-2] : 1);
                cout<<dp[i]<<"#1 ";
            }
            else if(s[i-1]=='2' && (s[i]<'7' && s[i]>='0') ){
                dp[i] = dp[i-1] + ((i-2)>=0 ? dp[i-2] : 1);
                cout<<dp[i]<<"#2 ";
            }
            else{ 
                dp[i] = dp[i-1];
                cout<<dp[i]<<"# ";
            }
        }
        return dp[n-1];

    }
};