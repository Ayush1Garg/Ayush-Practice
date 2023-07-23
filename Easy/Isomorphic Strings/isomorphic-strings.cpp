//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        // Your code here
        vector<int> f1, f2;
        int n1, n2;
        n1 = str1.length();
        n2 = str2.length();
        if(n1 != n2){
            return false;
        }
        bool marked[26] = {false};
        int map[26];
        memset(map,-1,sizeof(map));
        for(int i=0; i<n1; i++){
            if(map[str1[i]-'a']==-1){
                if(marked[str2[i]-'a'])
                return false;
                
                marked[str2[i]-'a'] = true;
                map[str1[i]-'a'] = str2[i];
                
            }
            else{
                if(map[str1[i]-'a'] != str2[i])
                return false;
            }
        }
        return true;
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends