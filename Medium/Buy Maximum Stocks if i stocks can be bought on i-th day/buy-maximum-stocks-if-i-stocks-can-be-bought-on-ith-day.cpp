//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

bool compare(const pair<int,int> &a, const pair<int,int> &b){
    if(a.first == b.first) return (a.second < b.second);
    return (a.first < b.first);
}

class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector< pair<int,int> > v;
        for(int i=0; i<n; i++){
            v.push_back(make_pair(price[i],i+1));
        }
        sort(v.begin(), v.end(), compare);
        int ans = 0, i = 0;
        while(k>=0 && i<n){
            if(k <= v[i].first*v[i].second ){
                ans += k/v[i].first;
                k=0;
                break;
            }
            ans += v[i].second;
            k -= v[i].first*v[i].second;
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends