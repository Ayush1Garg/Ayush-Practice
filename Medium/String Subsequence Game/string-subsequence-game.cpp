//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    bool isvowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        return true;
        return false;
    }
    void solve(int index, int n, string s, set<string>& v, string S){
	        if(index>=n){
	            if( isvowel(s[0]) && !isvowel(s[s.length()-1]) )
	            v.insert(s);
	            return;
	        }
	        solve(index+1,n,s,v,S);
	        char c = S[index];
	        s.push_back(c);
	        solve(index+1,n,s,v,S);
	    }
    set<string> allPossibleSubsequences(string S) {
        // code here
        set<string> st;
        int index = 0;
        string s = "";
        solve(index,S.length(),s,st,S);
        return st;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        set<string> ans = ob.allPossibleSubsequences(S);
        if (ans.size() == 0)
            cout << -1 << endl;
        else {
            for (auto i : ans) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends