//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

bool compare(string s1, string s2){
    int n = s1.size();
    if(n>s2.size()){
        return false;
    }
    for(int i=0; i<n; i++){
        if(s1[i]!=s2[i]){
            return false;
        }
    }
    return true;
}

class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        // code here
        vector<string> res;
        int n=0;
        string s1 = "", s2= "";
        for(int i=0; i<Dictionary.size(); i++){
            s2 += Dictionary[i];
            n = s2.size();
            for(int j=0; j<n; j++){
                if(s2[j]>='A' && s2[j]<='Z'){
                    s1 += s2[j];
                }
            }
            if(compare(Pattern,s1)){
                res.push_back(s2);
            }
            s1="";
            s2="";
        }
        if(res.empty())
        res.push_back("-1");
        
        return res;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends