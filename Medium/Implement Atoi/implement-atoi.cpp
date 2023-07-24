//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int ans=0;
        int i=0, p =1;
        if(str[i]=='-'){
            p = -1;
            i++;
        }
        for( i; i<str.length(); i++){
            int x = str[i] - '0';
            if(x<0 || x>9)
            return -1;
            ans = ans*10 + x;
        }
        return p*ans;
        
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