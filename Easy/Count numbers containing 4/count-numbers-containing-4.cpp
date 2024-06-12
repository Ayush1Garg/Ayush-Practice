//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool contains4 (int k){
        while(k>0){
            if(k%10==4) return true;
            k = k/10;
        }
        return false;
    }
    int countNumberswith4(int n) {
        // code here
        int ans = 0;
        for(int i=0; i<=n; i++){
            if(contains4(i)) ans++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends