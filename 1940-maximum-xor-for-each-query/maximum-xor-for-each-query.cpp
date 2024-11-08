class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int x = 0, n = nums.size();
        for(auto num : nums) x = x^num;
        long num = pow(2,maximumBit);
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            ans[i] = (num-1)^x;
            x = x^nums[n-1-i];
        }
        return ans;
    }
};