//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        if(s<1 || s>9*d) return"-1";
        string ans(d,'0');
        ans[0] = '1';
        int sum = 1;
        int i = d-1;
        while(sum!=s && i>=0){
            if(s-sum >= 9){
                ans[i] = '9';
                sum += 9;
            }
            else{
                ans[i] = ans[i] + s-sum;
                sum = s;
                break;
            }
            i--;
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
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends