class Solution {
public:
    int fn(int n,int k){
        if(n==2){
            if(k%2==0)return 1+k;
            return k+2;
        }
        int pos=fn(n-1,k);
        if(pos>n)pos=pos%n;
        if(pos==0)pos=n;
        return pos+k;
    }
    int findTheWinner(int n, int k) {
        if(n==1)return 1;
        if(n==2){
            if(k%2==0)return 1;
            return 2;
        }
        int res=fn(n-1,k);
        if(res>n)return res%n;
        return res;
    }
};