//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    void solve(int i, string &str, int n, int &ans){
        if(i==n) return;
        if(str[i]<'0' || str[i]>'9'){
            ans = -1;
            return;
        }
        ans = ans*10 + (str[i] - '0');
        solve(i+1,str,n,ans);
    }
    int atoi(string str) {
        //Your code here
        int ans = 0;
        int i = 0, len = str.length(), mul = 1;
        if(str[i]=='-'){
            mul = -1;
            i++;
        }
        solve(i,str,len,ans);
        if(ans==-1) return ans;
        return mul*ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends