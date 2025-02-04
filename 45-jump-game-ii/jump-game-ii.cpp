class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,10000);
        dp[n-1] = 0;
        for(int i=n-2; i>=0; i--){
            int minJumps = 10000;
            for(int j = i; j<= min(n-1, i + nums[i]); j++){
                minJumps = min(minJumps,dp[j]);
            }
            dp[i] = minJumps + 1;
        }
        return dp[0];
    }
};