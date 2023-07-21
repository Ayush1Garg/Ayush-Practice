//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

string reverse(string S){
    string st = "";
    for(int i= S.length()-1; i>=0; i--){
        st += S[i];
    }
    return st;
}

class Solution
{
  public:
    string reverseWords (string s)
    {
        //code here.
        int n = s.length();
        int i=0, j=0;
        string rs  = "";
        while(j<n){
            if(s[j]=='.'){
                rs += reverse(s.substr(i,j-i)) + '.';
                j++;
                i=j;
            }
            else{
                j++;
            }
        }
        rs += reverse(s.substr(i,j-i));
        return rs;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends