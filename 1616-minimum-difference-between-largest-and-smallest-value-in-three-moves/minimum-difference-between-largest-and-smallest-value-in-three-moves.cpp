class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n<5) return 0;
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        sort(nums.begin(),nums.end());
        int i = 0, j = n-1, k = 0;
        if(nums[i]==nums[j]) return 0;
        int ans = (nums[j] - nums[i] - 
        max(
            max(
                max(nums[3]-nums[0],nums[j]-nums[j-3]),nums[2]-nums[0] + nums[j]-nums[j-1]),nums[1]-nums[0] + nums[j]-nums[j-2]));
        return ans;
    }
};