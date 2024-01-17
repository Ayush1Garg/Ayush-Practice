//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void helper(vector<int> &A, int curr, int n,set<vector<int>> &s){
        if(curr>=n){
            s.insert(A);
            return;
        }
        for(int i=curr;i<n;i++){
            swap(A[curr],A[i]);     //swap
            helper(A,curr+1,n,s);  //deal with it
            swap(A[curr],A[i]);   //return back to previous state
        }
    }
    vector<vector<int>> uniquePerms(vector<int> A ,int n) {
        set<vector<int>> s;
        vector<vector<int>> res;
        helper(A,0,n,s);
        for(auto itr: s){
            res.push_back(itr);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends