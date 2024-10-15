class Solution {
public:
    long long minimumSteps(string s) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        long long ans = 0, bball = 0, n = s.size();
        for(int i=n-1; i>=0; i--){
            if(s[i]=='1'){
                bball++;
                ans += (n - i) - bball;
            }
        }
        return ans;
    }
};