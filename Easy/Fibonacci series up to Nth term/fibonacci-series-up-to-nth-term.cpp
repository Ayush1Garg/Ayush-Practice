//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod = 1e9 + 7;
    vector<int> Series(int n) {
        // Code here
        n++;
        vector<int> ans(n,0);
        if(n==1) return ans;
        ans[1] = 1;
        int i=2;
        while(i<n){
            ans[i] = (ans[i-1] + ans[i-2])%mod;
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends