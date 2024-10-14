class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        long long ans = 0;
        priority_queue<int> pq;
        for(auto num : nums) pq.push(num);
        while(k>0){
            int x = pq.top();
            if(x==0) break;
            pq.pop();
            ans += x;
            pq.push(ceil(x/3.0));
            k--;
        }
        return ans;
    }
};