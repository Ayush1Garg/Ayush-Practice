class Solution {
public:
    bool isCircularSentence(string s) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int i=1, n = s.size();
        char last = s[0];
        if(s[0]!=s[n-1]) return false;
        while(i<n){
            if(s[i-1]==' '){
                if(s[i]!=last) return false;
            }
            if(i+1<n && s[i+1]==' '){
                last = s[i];
            }
            i++;
        }
        return true;
    }
};