class Solution {
public:
    unsigned long long combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target+1,0);
        dp[0] = 1;
        int ans = 0;
        for(int i=1; i<=target; i++){
            for(int x:nums){
                if(i>=x){
                    dp[i] += dp[i-x];
                }
            }
        }
        return dp[target];
    }
};