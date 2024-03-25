//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    void help(int &ones, int &zeroes, int &ind, string &s, vector<string> &ans, int &n){
        if(ind==n){
            if(ones>=zeroes && (ones+zeroes)==n) ans.push_back(s);
            return;
        }
        if(zeroes>n/2) return;
        
        s[ind] = '1';
        ones++;
        ind++;
        help(ones,zeroes,ind,s,ans,n);
        ones--;
        ind--;
        if(ones>zeroes){
            s[ind] = '0';
            ind++;
            zeroes++;
            help(ones,zeroes,ind,s,ans,n);
            ind--;
            zeroes--;
        }
    }
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    vector<string> ans;
	    string s = "";
	    for(int i=0; i<n; i++)
	    {
	        s += '1';
	    }
	    int ind = 1;
	    int ones = 1, zeroes = 0;
	    help(ones,zeroes,ind,s,ans,n);
	   // for(auto str: ans){
	   //     cout<<str<<" $ ";
	   // }
	   // cout<<endl;
	    return ans;
	    
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends