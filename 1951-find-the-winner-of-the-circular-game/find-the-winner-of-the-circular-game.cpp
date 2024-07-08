class Solution {
public:
int solve(int n,int k,vector<int>& arr,int s){
    if(arr.size()==1){
        return arr[0];//or return arr[0];
    }
    s=(s+k-1)%n;
    arr.erase(arr.begin()+s);
    int ans = solve(n-1,k,arr,s);
    return ans;


}
    int findTheWinner(int n, int k) {
       vector<int> arr;
       int s=0;
       for(int i=0;i<n;i++){
        arr.push_back(i+1);
       }
       int ans = solve(n,k,arr,s); 
       return ans;
    }
};