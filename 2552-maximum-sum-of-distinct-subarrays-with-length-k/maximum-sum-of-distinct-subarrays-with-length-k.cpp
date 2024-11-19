class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        unordered_map<int,int> freq;
        long long j = 0, n = nums.size(), mult = 0, sum = nums[0], ans = 0;
        freq[nums[0]]++;
        if(k==1) ans = nums[0];
        for(int i=1; i<n; i++){
            freq[nums[i]]++;
            sum += nums[i];
            if(freq[nums[i]]>1) mult++;
            while(mult || i-j+1>k){
                if(freq[nums[j]]>1) mult--;
                freq[nums[j]]--;
                sum -= nums[j];
                j++;
            }
            if(mult==0 && i-j+1==k) ans = max(ans,sum);
        }
        return ans;
    }
};