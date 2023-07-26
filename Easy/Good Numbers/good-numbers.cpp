//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool isgood(int num, int d, int prev){
        if(num==0){
            return true;
        }
        int curr = num%10;
        if(curr!=d && curr>prev)
        return isgood(num/10,d,prev+curr);
        return false;
    }
    
    vector<int> goodNumbers(int L, int R, int D) {
        // code here
        vector<int> v;
        if(L>R){
            return v;
        }
        while(L<=R){
            int prev = L%10;
            if(prev!=D && isgood(L/10,D,prev)){
                v.push_back(L);
            }
            L++;
        }
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R, D;
        cin >> L >> R >> D;
        Solution ob;
        vector<int> ans = ob.goodNumbers(L, R, D);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends