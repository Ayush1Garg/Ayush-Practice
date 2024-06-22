//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string s) {

        // code here
        long long ans = -1, num = 0;
        int i=0, n = s.size();
        while(i<n){
            while(i<n && (s[i]>'9' || s[i]<'0') ) i++;
            num = -1;
            while(i<n && (s[i]>='0' && s[i]<='9') ){
                int c = s[i] - '0';
                if(c==9){
                    num = -1;
                    while(i<n && (s[i]>='0' && s[i]<='9') ) i++;
                }
                else{
                    if(num==-1) num = 0;
                    num = num*10 + c;
                    i++;
                }
            }
            ans = max(ans,num);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends