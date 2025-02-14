class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0] + nums[1] + nums[2], n = nums.size(), sum = 0, diff = abs(target - ans);
        sort(nums.begin(),nums.end());
        for(int i=0; i<n-2; i++){
            int j = i+1, k = n-1;
            while(j<k){
                sum = nums[i] + nums[j] + nums[k];
                if(abs(target - sum) < diff){
                    ans = sum;
                    diff = abs(target - sum);
                }
                if(sum>target) k--;
                else if(sum<target) j++;
                else return target;
            }
        }
        return ans;
    }
};