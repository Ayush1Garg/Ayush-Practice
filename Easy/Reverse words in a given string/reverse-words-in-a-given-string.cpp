//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        int n = S.length();
        int i=n-1, j = n-1;
        string s = "";
        while(i>=0){
            if(S[i]=='.'){
                s += S.substr(i+1,j-i) + '.';
                i--;
                j = i;
            }
            else{
                i--;
            }
        }
        s += S.substr(i+1,j-i);
        return s;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends