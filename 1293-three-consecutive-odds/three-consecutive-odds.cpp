class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        if(n<3) return false;
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int i=0, j=0;
        while(i<n && j<n){
            if(j<i) j = i;
            while(j<n && arr[j]%2){
                j++;
                if(j-i >= 3 ) return true;
            }
            i=max(i+1,j);
        }
        return false;
    }
};