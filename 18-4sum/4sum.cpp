class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> s;
        int n = nums.size();
        long long sum;
        for(int a=0; a<n-3; a++){
            for(int b = a+1; b<n-2; b++){
                int c = b+1, d = n-1;
                while(c<d){
                    sum = (long)nums[a] + (long)nums[b] + (long)nums[c] + (long)nums[d];
                    if(sum==target){
                        s.insert({nums[a],nums[b],nums[c],nums[d]});
                        c++;
                        d--;
                    }
                    else if(sum>target) d--;
                    else c++;
                }
            }
        }
        for(auto& quad : s) ans.push_back(quad);
        return ans;
    }
};