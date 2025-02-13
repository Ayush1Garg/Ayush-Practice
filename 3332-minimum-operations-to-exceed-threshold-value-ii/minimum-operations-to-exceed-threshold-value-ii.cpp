//@yjian012 https://hyper-meta.blogspot.com/
#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")
auto _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
void replace_top(const vector<int>::iterator &st,const vector<int>::iterator &ed){
    int ind=0,v=*st,sz=ed-st;
    while(1){
        int chd=2*ind+1;
        if(chd>=sz) break;
        chd+=chd+1<sz&&*(st+chd)>*(st+chd+1);
        if(*(st+chd)>=v) break;
        *(st+ind)=*(st+chd);
        ind=chd;
    }
    *(st+ind)=v;
}
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sz=nums.size();
        for(int i=0;i<sz;){
            if(nums[i]>=k) nums[i]=nums[--sz];
            else ++i;
        }
        make_heap(nums.begin(),nums.begin()+sz,greater<>{});
        int cnt=0;
        while(sz>=2){
            cnt++;
            int x=nums[0];
            pop_heap(nums.begin(),nums.begin()+sz--,greater<>{});
            if(nums[0]>=k-2*x) return cnt+sz/2;
            nums[0]+=2*x;
            replace_top(nums.begin(),nums.begin()+sz);
        }
        return cnt+sz;
    }
};