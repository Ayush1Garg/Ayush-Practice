//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        // your code here
        vector<bool> hash(26,false);
        for(int i=0; i<s.length(); i++){
            if(s[i]>='a' && s[i]<='z'){
                hash[s[i]-'a'] = true;
            }
            else if(s[i]>='A' && s[i]<='Z'){
                hash[s[i]-'A'] = true;
            }
        }
        for(int i=0; i<26; i++){
            if(hash[i]==false) return false;
        }
        return true;
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends