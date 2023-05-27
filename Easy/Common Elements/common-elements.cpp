//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

bool compare(int i, int j){
    return i<j;
}

class Solution{
    public:
        vector<int> common_element(vector<int>v1,vector<int>v2)
    {
        // Your code here
        vector<int> v;
        sort(v1.begin(), v1.end(), compare);
        sort(v2.begin(), v2.end(), compare);
        int i=0, j=0;
        while(i<v1.size() && j<v2.size()){
            if(v1[i] == v2[j]){
                v.push_back(v1[i]);
                i++;
                j++;
            }
            else if(v1[i]<v2[j]){
                i++;
            }
            else {
                j++;
            }
        }
        sort(v.begin(), v.end(), compare);
        return v;
        
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int>v1(n,0);
        for(int i=0;i<n;i++)
        {
            cin>>v1[i];
        }
        int m;
        cin>>m;
        vector<int>v2(m,0);
        for(int i=0;i<m;i++)
        {
            cin>>v2[i];
        }
        Solution ob;
        vector<int>result;
        result=ob.common_element(v1,v2);
        for(auto i:result)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        
    }
}
// } Driver Code Ends