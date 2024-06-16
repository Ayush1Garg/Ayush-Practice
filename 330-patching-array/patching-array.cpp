class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        long long ans = 0, sum = 0;
        for(int i = 0; i < nums.size() && sum < n; i++) {
            if(nums[i] <= sum + 1) {
                sum += nums[i];
            } else {
                i--;
                ans++;
                sum = sum * 2 + 1;
            }
        }
        while(sum < n) {
            sum = sum * 2 + 1;
            ans++;
        }
        return ans;
    }
};