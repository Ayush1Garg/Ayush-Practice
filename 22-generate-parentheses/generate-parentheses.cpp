class Solution {
public:
    void generator(int &open, int &closed, int n, vector<string> &ans, string& pattern){
        if(closed==n){
            ans.push_back(pattern);
            return;
        }
        if(open<n){
            pattern.push_back('(');
            open++;
            generator(open,closed,n,ans,pattern);
            open--;
            pattern.pop_back();
        }
        if(closed<open){
            pattern.push_back(')');
            closed++;
            generator(open,closed,n,ans,pattern);
            pattern.pop_back();
            closed--;
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open = 0, close = 0;
        string pattern = "";
        generator(open,close,n,ans,pattern);
        return ans;
    }
};