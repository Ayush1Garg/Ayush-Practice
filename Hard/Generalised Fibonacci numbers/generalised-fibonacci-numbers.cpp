//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // long long genFibNum(long long a, long long b, long long c, long long n, long long m) {
    //     // code here
    //     if(n==1 || n==2) return 1%m;
    //     long long x = 1, y = 1, curr;
    //     c = c%m;
    //     while(n>0){
    //         curr = (((a*x)%m + (b*y)%m)%m + c)%m;
    //         y = x;
    //         x = curr;
    //         n--;
    //     }
    //     return curr;
    // }
    // /* Won't run due to time complexity O(n) instaed of O(log(n)) */
    
    vector<vector<long long>> multiply(vector<vector<long long>> &a, vector<vector<long long>> &b, long long mod){
        vector<vector<long long>> res (3, vector<long long>(3,0));
        for(int i =0; i<3; i++){
            for(int j =0; j<3; j++){
                for(int k =0; k<3; k++){
                    res[i][j] = (res[i][j] + a[i][k]*b[k][j])%mod;
                }
            }
        }
        return res;
    }
    
    vector<vector<long long>>  power(vector<vector<long long>> &arr, long long b, long long mod){
        vector<vector<long long >> res = {{1,0,0},{0,1,0},{0,0,1}};
        while(b > 0){
            if(b&1){
                res = multiply(res, arr, mod);
            }
            arr = multiply(arr, arr, mod);
            b /= 2;
        }
        return res;
    }
    long long genFibNum(long long a, long long b, long long c, long long n, long long mod) {
        // code here
        if(mod == 1) return 0;
        if(n <= 2) return 1; 
        n -= 2;
        //Most  important thing is to learn how to make the required matrix 
        // You can find it using this Mat*[g(n-1)  g(n-2)  c] = [g(n)  g(n-1)  c]
        //as these three are the only constraints which are being used 
        vector<vector<long long>> mat = {{a,b,1},{1,0,0},{0,0,1}};
        mat = power(mat, n, mod);
        long long res = (mat[0][0] + mat[0][1] + mat[0][2]*c)%mod;
        return res;
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a,b,c,n,m;
        
        cin>>a>>b>>c>>n>>m;

        Solution ob;
        cout << ob.genFibNum(a,b,c,n,m) << endl;
    }
    return 0;
}
// } Driver Code Ends