//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string num, int k) {
        string answer="";
        for(char &ch:num){
            while(answer.size() and answer.back()>ch and k){
                answer.pop_back();
                k--;
            }
            if(answer.size() or ch!='0')
                answer.push_back(ch);
        }
        while(answer.size()  and k--)
            answer.pop_back();
        if(answer=="")
            return "0";
        return answer;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends