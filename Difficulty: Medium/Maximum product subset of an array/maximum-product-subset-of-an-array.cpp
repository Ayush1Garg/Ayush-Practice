//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int mod = 1e9 + 7;
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        int m = 1e9+7 ;
        long long int ans = 1;
        long long int mini = INT_MIN ;
        bool zero = false ;
        for(int i :arr){
            if(i<0)mini = max(mini,i*1LL);
            if(i!=0){
                ans = ((ans%m)*i)%m ;
            }
            if(i == 0)zero = true ;
        }
        if(ans>0)return ans ;
        if(ans != mini){
            return ans/mini;
        }
        if(zero)return 0 ;
        return ans ;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends