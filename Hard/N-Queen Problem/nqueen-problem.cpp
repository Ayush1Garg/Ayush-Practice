//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isvalid(int i, int j, vector<int> &ds){
        for(int k=i-1; k>=0; k--){
            if(j==ds[k]-1) return false;
            int c = (i-k);
            if(ds[k]==(j+1+c) || ds[k]==(j+1-c)) return false;
        }
        return true;
    }
    void solve(int i, int n, vector<vector<int>> &ans, vector<int> ds){
        if(i==n){
            ans.push_back(ds);
            return;
        }
        for(int j=0; j<n; j++){
            if(isvalid(i,j,ds)){
                ds.push_back(j+1);
                solve(i+1,n,ans,ds);
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans;
        vector<int> ds;
        // vector<int>
        solve(0,n,ans,ds);
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends