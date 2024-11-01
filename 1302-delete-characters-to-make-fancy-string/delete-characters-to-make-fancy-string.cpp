class Solution {
public:
    string makeFancyString(string s) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        string ans = "";
        char last = s[0];
        ans += s[0];
        int count = 1, i = 1;
        while(i<s.size()){
            if(i>0 && s[i]==s[i-1]){
                i++;
                if(count>=2) continue;
                count++;
                ans += last;
            }
            else{
                last = s[i];
                i++;
                ans+= last;
                count = 1;
            }
        }
        return ans;
    }
};