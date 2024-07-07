class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = numBottles, full = 0, ans = numBottles;
        while(full+empty >= numExchange){
            if(empty >= numExchange){
                full += empty/numExchange;
                empty = empty%numExchange;
            }
            ans += full;
            empty += full;
            full = 0;
        }
        return ans;
    }
};