//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
        if(s.size() <= 2){
            int val = stoi(s);
            if(val % 8 == 0)
             return 1;
        }
        if(s.size() >= 3){
            int value = stoi(s.substr(s.length()-3,3));
            if(value % 8 == 0 )
             return 1;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends