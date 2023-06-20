void ans(int n, int e1, int e2, vector<int> &v, vector<int> num){
    int cnt1 = 0, cnt2 = 0;
    for(int i=0; i<n; i++){
        if(e1 == num[i]){
            cnt1++;
        }
        else if(e2 == num[i]){
            cnt2++;
        }
    }
    if(cnt1 > n/3){
        v.push_back(e1);
    }
    if(cnt2 > n/3){
        v.push_back(e2);
    }
}

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();
        int cnt1 =0, cnt2=0, el1 = INT_MIN, el2 = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if(cnt1 == 0 && el2 != nums[i]){
                cnt1++;
                el1 = nums[i];
            }
            else if(cnt2 == 0 && el1 != nums[i]){
                cnt2++;
                 el2 = nums[i];
            }
            else if(el1 == nums[i]){
                cnt1++;
            }
            else if(el2 == nums[i]){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        ans(n, el1, el2, v, nums);
        return v;
    }
};