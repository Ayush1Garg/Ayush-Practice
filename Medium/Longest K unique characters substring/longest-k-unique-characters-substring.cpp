//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        // your code here
        if(k==0) return -1;;
        int n = s.length();
        unordered_map<char,int> mp;
        int ans = -1;
        int i = 0, j = 0;
        int size = 0;
        while(i<n && j<n){
            mp[s[j]]++;
            if(mp[s[j]]==1) size++;
            while(size>k && i<j){
                mp[s[i]]--;
                if(mp[s[i]]==0) size--;
                i++;
            }
            if(size==k) ans = max(ans,1+j-i);
            j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends