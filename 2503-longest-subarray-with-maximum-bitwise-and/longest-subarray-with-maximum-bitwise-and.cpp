static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len = 1;
        int mx = *max_element(nums.begin(),nums.end());
        int tmp_len=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==mx){
                tmp_len++;
            }
            else{
                len = max(len, tmp_len);
                tmp_len=0;
            }
        }
        return max(len, tmp_len); 
    }
};