class Solution {
public:
    vector<int> lexicalOrder(int n) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        vector<int> ans;
        int curr = 1;
        for(int i=1; i<=n; i++){
            ans.push_back(curr);
            if(curr*10<=n)
                curr = curr*10;
            else{
                while(curr%10==9 || curr>=n){
                    curr = curr/10;
                }
                curr++;
            }
        }
        return ans;
    }
};