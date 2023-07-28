//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void generate(int n, vector<string>& v, int lp=1, int rp=0, string s = "("){
        if(rp==n){
            cout<<s<<endl;
            return;
        }
        if(lp<n){
            s += '(';
            generate(n,v,lp+1,rp,s);
            s.pop_back();
        }
        if(lp>rp){
            s += ')';
            generate(n,v,lp,rp+1,s);
        }
    }
    
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string> v;
        generate(n,v);
        return v;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends