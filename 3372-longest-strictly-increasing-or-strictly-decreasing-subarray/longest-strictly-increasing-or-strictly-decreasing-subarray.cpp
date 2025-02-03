class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int l = 0, ans = 1, prev = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>prev){
                l++;
                ans = max(l,ans);
            }
            else{
                l = 1;
            }
            prev = nums[i];
        }
        prev = 51;
        l = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<prev){
                l++;
                ans = max(l,ans);
            }
            else{
                l = 1;
            }
            prev = nums[i];
        }
        return ans;
    }
};