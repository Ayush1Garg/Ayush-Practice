//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

bool compare(pair<int,int>&p1,pair<int,int>&p2){
    if(p1.first==p2.first) return p1.second<p2.second;
    return p1.first>p2.first;
}
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        unordered_map<int,int>mp;/*This is to store the elements with their frequency*/
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        vector<pair<int,int>>v;/*Store the elements first their frequency and then el*/
        for(auto it:mp){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end(),compare); /*Custom sorting*/
        vector<int>ans; /*To store the sorted list*/
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].first;j++){
                ans.push_back(v[i].second);
            }
        }
        return ans; /*Finally return the ans*/
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends