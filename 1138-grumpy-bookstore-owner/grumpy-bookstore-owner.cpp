class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        if(minutes==grumpy.size()){
            return accumulate(customers.begin(),customers.end(),0);
        }
        int happy = 0 , n = customers.size();
        for(int i=0; i<n; i++){
            happy += grumpy[i] ? 0 : customers[i];
        }
        int i=0, j=0;
        while(j<minutes){
            happy += grumpy[j] ? customers[j] : 0;
            j++;
        }
        int ans = happy;
        while(j<n){
            happy -= grumpy[i] ? customers[i] : 0;
            i++;
            happy += grumpy[j] ? customers[j] : 0;
            j++;
            ans = max(ans,happy);
        }
        return ans;
    }
};