class Solution {
public:
    void sortColors(vector<int>& nums) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int i=-1, j=0, k = nums.size();
        while(j<nums.size() && j<k){
            if(nums[j]==0){
                i++;
                swap(nums[i],nums[j]);
                j++;
            }
            else if(nums[j]==2){
                k--;
                swap(nums[j],nums[k]);
            }
            else{
                j++;
            }
        }
    }
};