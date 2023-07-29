//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void solve(int index, int n, string s, vector<string>& v, string S){
	        if(index>=n){
	            v.push_back(s);
	            return;
	        }
	        solve(index+1,n,s,v,S);
	        char c = S[index];
	        s.push_back(c);
	        solve(index+1,n,s,v,S);
	    }
	
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    int index = 0;
		    string output = "";
		    vector<string> ans;
		    solve(index,s.length(),output,ans,s);
		    sort(ans.begin(),ans.end());
		    ans.erase(ans.begin());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends