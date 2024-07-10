class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = 0;
        for(auto s : logs){
            if(s=="../"){
                n = max(0,n-1);
            }
            else if(s=="./") continue;
            else n++;
        }
        return n;
    }
};