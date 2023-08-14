//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void solve(int i, int sum, vector<int> &a, vector<int> &v, vector<vector<int>> &sol){
        if(sum==0){
            sol.push_back(v);
            return;
        }
        if(i==a.size() || a[i]>sum){
            return;
        }
        v.push_back(a[i]);
        solve(i,sum-a[i],a,v,sol);
        v.pop_back();
        solve(i+1,sum,a,v,sol);
        
    }
    vector<vector<int> > combinationSum(vector<int> &A, int b) {
        // Your code here
        vector<int> temp;
        vector<vector<int>> ans;
        vector<int> a = A;
        sort(a.begin(),a.end());
        a.erase(unique(a.begin(),a.end()),a.end());
        solve(0,b,a,temp,ans);
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
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends