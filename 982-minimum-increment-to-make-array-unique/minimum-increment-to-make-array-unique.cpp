class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i=1; i<n; i++){
            if(nums[i]<=nums[i-1]){
                ans += nums[i-1] - nums[i] + 1;
                nums[i] = nums[i-1] + 1;
            }
        }
        return ans;
    }
};