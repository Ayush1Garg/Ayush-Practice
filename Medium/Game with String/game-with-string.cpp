//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        if(k>s.length()-2) return s.length()-k;
        vector<int> freq(26,0);
        for(int i=0; i<s.length(); i++){
            freq[s[i]-'a']++;
        }
        priority_queue<int> heap;
        for(int i=0; i<26; i++){
            if(freq[i]>0){
                heap.push(freq[i]);
            }
        }
        while(k>0 && !heap.empty()){
            int v = heap.top();
            heap.pop();
            v--;
            k--;
            heap.push(v);
        }
        int ans = 0;
        while(!heap.empty()){
            int val = heap.top();
            heap.pop();
            ans += val*val;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends