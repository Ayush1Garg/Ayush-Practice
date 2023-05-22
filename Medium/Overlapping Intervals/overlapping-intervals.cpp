//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[0] < v2[0];
}
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& interval) {
         // Code here
         int k = INT_MIN;
         sort( interval.begin(), interval.end(), sortcol );
         for(int i=0; i<interval.size()-1; i++){
             if(interval[i][1] >= interval[i+1][0]){
                 interval[i][1] = max(interval[i][1], interval[i+1][1]);
                 interval.erase(interval.begin()+i+1);
                 i--;
             }
         }
         return interval;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends