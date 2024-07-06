class Solution {
public:
    int numberOfChild(int n, int k) {
        return (k/(n-1))%2 ? n-1-k%(n-1) : k%(n-1);
    }
};