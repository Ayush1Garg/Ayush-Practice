//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    void solve(int in, int n, vector<int> &a, vector<int> &ds, vector<vector<int>> &ans){
        ans.push_back(ds);
        if(in==n){
            return;
        }
        for(int i=in; i<n; i++){
            if(i==in || a[i]!=a[i-1]){
                ds.push_back(a[i]);
                solve(i+1,n,a,ds,ans);
                ds.pop_back();
            }
        }
    }
    
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        // Write your code here
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> num = nums;
        sort(num.begin(),num.end());
        solve(0,num.size(),num,ds,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends