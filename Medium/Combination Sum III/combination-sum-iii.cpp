//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void solve(int i, int k, int sum, vector<int> &ds, int size, vector<vector<int>> &ans){
        if(sum==0){
            if(size==k) ans.push_back(ds);
            return;
        }
        if(size>k || i>9 || i>sum) return;
        ds.push_back(i);
        solve(i+1,k,sum-i,ds,size+1,ans);
        ds.pop_back();
        solve(i+1,k,sum,ds,size,ans);
    }
    vector<vector<int>> combinationSum(int K, int N) {
        // code here
        vector<vector<int>> ans;
        vector<int> ds;
        solve(1,K,N,ds,0,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends