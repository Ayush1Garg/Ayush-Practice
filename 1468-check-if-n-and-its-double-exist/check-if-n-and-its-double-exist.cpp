class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int n = arr.size();
        unordered_map<int,bool> mp;
        for(int& num : arr){
            if(mp[2*num] || num%2==0 && mp[num/2]) return true;
            mp[num] = true;
        }
        return false;
    }
};