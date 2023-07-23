//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
        if(s1.length()!=s2.length()) return false;
        queue<char> q1, q2;
        for(int i=0; i<s1.length(); i++){
            q1.push(s1[i]);
            q2.push(s2[i]);
        }
        if(q1==q2)
        return true;
        
        int k = s1.size();
        while(k>0){
            char c = q2.front();
            q2.pop();
            q2.push(c);
            k--;
            if(q1==q2){
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends