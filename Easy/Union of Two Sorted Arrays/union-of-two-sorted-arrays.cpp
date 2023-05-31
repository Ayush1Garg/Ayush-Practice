//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        int i=0, j=0;
        vector<int> v;
        unordered_map<int,int> mp;
        while(i<n && j<m){
            if(arr1[i]<arr2[j]){
                v.push_back(arr1[i]);
                i++;
            }
            else if(arr1[i]>arr2[j]){
                v.push_back(arr2[j]);
                j++;
            }
            else{
                v.push_back(arr1[i]);
                i++;
                j++;
            }
        }
        while(i<n){
            v.push_back(arr1[i]);
            i++;
        }
        while(j<m){
            v.push_back(arr2[j]);
            j++;
        }
        for(int k=0; k<v.size(); k++){
            if(mp[v[k]] > 0){
                v.erase(v.begin() + k);
                k--;
            }
            else{
                mp[v[k]]++;
            }
        }
        return v;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends