class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> curr;
        curr.push_back(1);
        for(int i=1; i<=rowIndex; i++){
            vector<int> prev = curr;
            for(int j=1; j<i; j++){
                curr[j] = prev[j-1] + prev[j];
            }
            curr.push_back(1);
        }
        return curr;
    }
};