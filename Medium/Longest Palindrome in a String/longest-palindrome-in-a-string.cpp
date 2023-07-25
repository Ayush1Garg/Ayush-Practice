//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        // code here
        int n = s.length();
        string str = "";
        if(n==0){
            return str;
        }
        int low, high;
        int start = 0, end = 1,size = 1;
        for(int i=0; i<n-1; i++){
            low = i;
            high = i+1;
            while(low>-1 && high<n && s[low]==s[high]){
                if(size<high-low+1){
                    start = low;
                    end = high;
                    size = high-low+1;
                }
                high++;
                low--;
            }
        }
        for(int i=1; i<n-1; i++){
            high = i+1;
            low = i-1;
            while(low>-1 && high<n && s[low]==s[high]){
                if(size<high-low+1){
                    start = low;
                    end = high;
                    size = high-low+1;
                }
                high++;
                low--;
            }
        }
        str = s.substr(start,size);
        return str;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends