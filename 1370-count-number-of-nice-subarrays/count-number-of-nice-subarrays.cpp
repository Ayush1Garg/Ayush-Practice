class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1); 
    }
    
    int atMost(vector<int>& nums, int k) {
        int odds=0, cnt=0, n = nums.size();
        for(int l=0, r=0; r<n; r++){
            int x=nums[r];
            odds+=(x&1);
            while(odds>k){
                int y=nums[l];
                odds-=(y&1);
                l++;
            }
            cnt+=(r-l+1);
        }
        return cnt;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();