class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, msum = nums[0];
        for(auto& num : nums){
            sum += num;
            msum = max(msum,sum);
            if(sum<0) sum = 0;
        }
        return msum;
    }
};