class Solution {
public:
    int uniquePaths(int m, int n) {
        if(n==1 || m==1) return 1;
        vector<unsigned long int> prev(n,0), curr(n);
        for(int i=0; i<m; i++){
            curr[0] = 1;
            for(int j=1; j<n; j++){
                curr[j] = curr[j-1] + prev[j];
                prev[j] = curr[j];
            }
        }
        return prev[n-1];
    }
};