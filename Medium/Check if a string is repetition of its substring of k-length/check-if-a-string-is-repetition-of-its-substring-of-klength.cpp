//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int kSubstrConcat (int n, string s, int k)
	{
	    if(n%k != 0)return 0;
	    
	    unordered_map<string,int> mp;
	    
	    for(int i=0;i<n;i = i+k){
	        string sub = s.substr(i,k);
	        mp[sub]++;
	    }
	    if(mp.size()>2)return 0;
	    if(mp.size() == 1)return 1;
	    vector<int> v;
	    for(auto p : mp){
	        v.push_back(p.second);
	    }
	    if(v[0] == 1 && v[1] == 1)return 1;
	    else if(v[0] >1 && v[1] == 1)return 1;
	    else if(v[0] == 1 && v[1]>1)return 1;
	    return 0;
	}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int k; cin >> k;
        Solution  ob;
		cout << ob.kSubstrConcat (n, s, k) << endl;
	}
}
// } Driver Code Ends