class Solution {
public:
    void helper(int i,unordered_map<int,int> &mp,int &n,vector<int> &temp,vector<vector<int>> &ans)
    {
        if(i==n) ans.push_back(temp);

        for(auto it:mp)
        {
            if(it.second>0)
            {
                temp.push_back(it.first);
                mp[it.first]--;
                helper(i+1,mp,n,temp,ans);
                mp[it.first]++;
                temp.pop_back();
            }
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
          mp[nums[i]]++;

        vector<vector<int>>ans;
        vector<int>temp;
        helper(0,mp,n,temp,ans);
        return ans;
    }
};