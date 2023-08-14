//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void solve(int i, int sum, vector<int> &input, unordered_map<int,int> &mp, vector<int> &ds, vector<vector<int>> &ans){
        if(sum==0){
            ans.push_back(ds);
            return;
        }
        if(i==input.size() || input[i]>sum){
            return;
        }
        ds.push_back(input[i]);
        solve(i+1,sum-input[i],input,mp,ds,ans);
        ds.pop_back();
        solve(mp[input[i]],sum,input,mp,ds,ans);
    }
    
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        // Write your code here
        vector<int> temp;
        int n = candidates.size();
        vector<int> a=candidates;
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        unordered_map<int,int> next;
        int i=0, j=1;
        while(i<n && j<n){
            if(a[i]!=a[j]){
                next[a[i]] = j;
                i = j;
            }
            j++;
        }
        next[a[i]] = j;
        solve(0,target,a,next,temp,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends