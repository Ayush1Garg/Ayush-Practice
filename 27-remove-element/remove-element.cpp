class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, n = nums.size()-1;
        while(i<=n){
            if(nums[i]==val){
                swap(nums[i],nums[n]);
                n--;
            }
            else i++;
        }
        return i;
    }
};