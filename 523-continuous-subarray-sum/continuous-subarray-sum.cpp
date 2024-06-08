class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, ans = 0;
        unordered_map<int,int> mp;
        mp[0] = -1;
        for(int i=0; i<n; i++){
            sum = (sum+nums[i])%k;
            // cout<<sum<<" ";
            if(sum<0)
                sum = sum + k;
            if(mp.find(sum)==mp.end()){
                mp[sum] = i;
            }
            else{
                ans = max(ans,i-mp[sum]);
                // cout<<endl<<"$"<<ans<<"$"<<endl;
            }
        }
        if(ans<2) return false;
        return true;
    }
};