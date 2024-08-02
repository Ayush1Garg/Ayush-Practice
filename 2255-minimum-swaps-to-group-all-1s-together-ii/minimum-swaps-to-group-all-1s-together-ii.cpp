class Solution {
public:
    int minSwaps(vector<int>& nums) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int k = accumulate(nums.begin(), nums.end(), 0);
        // cout<<k<<endl;
        int n = nums.size();
        int cnt = accumulate(nums.begin(), nums.begin() + k, 0);
        // cout<<cnt<<endl;
        int mx = cnt;
        for (int i = k; i < n + k; ++i) {
            // cout<<" nums[i % n] "<<nums[i % n]<<" nums[i % n] "<<nums[i % n];
            cnt += nums[i % n] - nums[(i - k + n) % n];
            // cout<<" cnt : "<<cnt<<endl;
            mx = max(mx, cnt);
        }
        return k-mx;
    }
};