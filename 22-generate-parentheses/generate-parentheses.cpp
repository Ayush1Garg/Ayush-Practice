class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp;
        dp.push_back({""});
        dp.push_back({"()"});
        for(int i = 2; i<=n; i++){
            vector<string> temp;
            for(int j=0; j<i; j++){
                for(auto& inPattern : dp[j]){
                    for(auto& outPattern : dp[i-j-1]){
                        temp.push_back("(" + inPattern + ")" + outPattern);
                    }
                }
            }
            dp.push_back(temp);
        }
        return dp[n];
    }
};