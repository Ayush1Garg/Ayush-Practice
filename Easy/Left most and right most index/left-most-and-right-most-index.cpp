//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    int BS(vector<long long> &arr, long long K)
    { 
    
       //
       int N = arr.size();
       int s = 0, e = N-1;
       while(s<=e){
           
           int mid = s + (e-s)/2;
           
           if(K == arr[mid]) return mid;
           
           if(arr[mid] < K) s = mid + 1;
           else e = mid - 1;
       }
       //
       return -1;
       
    }
    
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        //
        int n = v.size();
        pair<long ,long> p;
        p.first = p.second = -1;
        
        //
        int indx = BS(v, x);
        if(indx == -1) return p;
        
        //
        int s,e;
        s = e = indx;
        
        while((s >=0 && v[s] == x) || (e < n && v[e] == x)){
            
            if(s >=0 && v[s] == x) s -= 1;
            if(e < n && v[e] == x) e += 1;
            
        }
        p.first = s + 1;
        p.second = e - 1;
        //
        return p;
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends