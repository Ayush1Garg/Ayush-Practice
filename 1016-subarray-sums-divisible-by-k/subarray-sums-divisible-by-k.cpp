class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, sum = 0;
        unordered_map<int,int> count;
        count[0] = 1;
        for(int i : nums){
            sum = (sum+i)%k;
            if(sum<0) sum += k;
            if(count.find(sum)==count.end()){
                count[sum] = 1;
            }
            else{
                ans += count[sum];
                count[sum]++;
            }
        }
        return ans;
    }
};