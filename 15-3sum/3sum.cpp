class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        for(int i=0; i<nums.size(); i++){
            int j = i+1, k = nums.size()-1, sum;
            while(j<k){
                sum = nums[i] + nums[j] + nums[k];
                if(sum==0){
                    s.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(sum>0) k--;
                else j++;
            }
        }
        vector<vector<int>> ans;
        for(auto& triplet : s) ans.push_back(triplet);
        return ans;
    }
};