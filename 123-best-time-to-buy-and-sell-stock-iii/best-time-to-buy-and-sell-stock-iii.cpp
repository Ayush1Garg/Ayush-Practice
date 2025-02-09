class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(5));
        for(int day = n; day>=0; day--){
            for(int transactionsLeft = 0; transactionsLeft<5; transactionsLeft++){
                int &ans = dp[day][transactionsLeft];
                if(day==n || transactionsLeft==0) ans = 0;
                else{
                    int ans1 = dp[day+1][transactionsLeft];
                    int ans2 = 0;
                    bool buy = transactionsLeft%2==0;
                    if(buy){
                        ans2 = -prices[day] + dp[day+1][transactionsLeft-1];
                    }else{
                        ans2 = prices[day] + dp[day+1][transactionsLeft-1];
                    }
                    ans = max(ans1,ans2);
                }
            }
        }
        return dp[0][4];
    }
};