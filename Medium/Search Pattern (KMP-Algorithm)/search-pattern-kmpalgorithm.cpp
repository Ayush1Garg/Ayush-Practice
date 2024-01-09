//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    vector <int> search(string pat, string txt)
    {
        //lps array
        vector<int> arr(pat.size(),0);
        int i=0;
        int j=1;
        while(j<pat.size())
        {
            while(i>0 and pat[i]!=pat[j])
            {
                i--;
            }
            
            if(pat[i]==pat[j])
            {
                arr[j]=i+1;
                i++;
            }
            else
            arr[j]=0;
            
            j++;
        }
        
        //matching pattern
        j=0;
        i=0;
        vector<int> ans;
        while(i<txt.size())
        {
            if(txt[i]==pat[j])
            {
                i++;
                j++;
            }
            
            if(j==pat.size())
            {
                ans.push_back(i-j+1);
                j=arr[j-1];
            }
            else if(i<txt.size() && txt[i] != pat[j])
            {
                if(j==0)
                i++;
                else
                j = arr[j-1];
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
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends