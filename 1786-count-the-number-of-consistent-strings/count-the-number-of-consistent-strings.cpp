class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        unordered_map<char,bool> gud;
        for(auto c : allowed) gud[c] = true;
        int ans = 0;
        for(auto s : words){
            for(auto c : s){
                if(!gud[c]){
                    ans--;
                    break;
                }
            }
            ans++;
        }
        return ans;
    }
};