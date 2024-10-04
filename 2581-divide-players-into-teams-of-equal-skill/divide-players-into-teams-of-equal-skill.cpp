class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int n = skill.size();
        unordered_map<int,int> ignore, freq;
        long sum = 0;
        for(auto num : skill){
            sum += num;
            freq[num]++;
        }
        if(sum%(n/2)) return -1;
        sum = sum/(n/2);
        long long ans = 0;
        for(auto num : skill){
            if(ignore[num]>0){
                ignore[num]--;
                continue;
            }
            int num2 = sum - num;
            freq[num]--;
            if(freq[num2]<=0){
                return -1;
            }
            ans += num*num2;
            freq[num2]--;
            ignore[num2]++;
        }
        return ans;
    }
};