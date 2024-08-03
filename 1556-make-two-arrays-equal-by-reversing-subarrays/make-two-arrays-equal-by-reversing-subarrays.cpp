class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(arr.size()!=target.size()) return false;
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int a[1000] = {0};
        for(int i=0; i<arr.size(); i++){
            a[arr[i]-1]++;
        }
        for(int i=0; i<target.size(); i++){
            a[target[i]-1]--;
        }
        for(int i=0; i<arr.size(); i++){
            if(a[arr[i]-1]!=0) return false;
        }
        return true;
    }
};