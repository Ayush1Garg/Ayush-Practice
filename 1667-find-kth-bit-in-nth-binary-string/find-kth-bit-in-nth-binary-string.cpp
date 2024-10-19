class Solution {
    inline char invert(char a){
        if(a=='0') return '1';
        return '0';
    }
public:
    char findKthBit(int n, int k) {
        if(n<=1) return '0';
        int size = pow(2,n) - 1;
        if(k==(size+1)/2){
            cout<<"mid"<<endl;
            return '1';
        }
        if(k<(size+1)/2){
            cout<<"first half"<<endl;
            return findKthBit(n-1,k);
        }
        cout<<"second half"<<endl;
        return invert(findKthBit(n-1,size+1-k));
    }
};