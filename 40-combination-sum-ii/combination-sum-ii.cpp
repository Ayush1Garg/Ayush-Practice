class Solution {
public:
    void solve(int i, int n, vector<int> &guys, int &target, vector<int> &temp, vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i>=n || i<0 || target<0 || guys[i]>target) return;
        temp.push_back(guys[i]);
        target -= guys[i];
        solve(i+1,n,guys,target,temp,ans);
        target += guys[i];
        temp.pop_back();
        int j=i;
        while(j<n && guys[j]==guys[i]) j++;
        solve(j,n,guys,target,temp,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        vector<vector<int>> ans;
        int n = candidates.size();
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        solve(0,n,candidates,target,temp,ans);
        return ans;
    }
};