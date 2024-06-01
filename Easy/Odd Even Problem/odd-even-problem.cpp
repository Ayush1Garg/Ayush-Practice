//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
        unordered_map<char, int>mp;
        for(int i = 0; i<s.size(); i++)
        {
            mp[s[i]]++;
        }
        int cnt=0;
        for(auto it : mp)
        {
            char ch = it.first;
            if( ( (ch-'a')%2==1 && it.second%2==0) || ( (ch-'a')%2==0 && it.second%2==1 ) ){
                cnt++;
            }
            
        }
        return cnt%2==0 ? "EVEN":"ODD";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends