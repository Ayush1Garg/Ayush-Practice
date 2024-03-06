//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            //code here.
            int n = pattern.length(), m = text.length();
            int i = 0, j = 0;
            vector<int> ans;
            while(j<m){
                if(pattern[i]==text[j]){
                    int k = j;
                    while(i<n && j<m && pattern[i]==text[j]){
                        i++;
                        j++;
                    }
                    if(i==n){
                        ans.push_back(j-n+1);
                    }
                    i=0;
                    j = k+1;
                }
                else{
                    j++;
                }
            }
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends