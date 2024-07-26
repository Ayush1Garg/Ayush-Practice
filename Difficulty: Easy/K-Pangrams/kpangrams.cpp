//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        if(str.size()<26) return false;
        int a[26] = {0};
        int alpha = 0;
        for(auto c : str){
            if(c>='a' && c<='z'){
                alpha++;
                a[c-'a'] = 1;
            }
        }
        if(alpha<26) return false;
        for(int i=0; i<26; i++){
            if(a[i]==0){
                if(k>0) k--;
                else return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends