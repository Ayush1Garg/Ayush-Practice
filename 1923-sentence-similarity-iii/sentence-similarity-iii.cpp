class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int n = s1.size(), m = s2.size();
        if(n < m) return areSentencesSimilar(s2,s1);
        int i=0, j=n-1, k=0, l=m-1, p1 = 0, p2 = m-1;
        while(i<n && k<m && s1[i]==s2[k]){
            if(s2[k]==' ') p1 = k;
            i++;
            k++;
            // if(k==m){
            //     if(i>=n || (i<n && s1[i]==' ')) return true;
            //     return false;
            // }
        }
        while(j>=0 && l>=p1 && s1[j]==s2[l]){
            if(s2[l]==' ') p2 = l;
            j--;
            l--;
            // if(l<0){
            //     if(j<0 || (j>=0 && s1[j]==' ')) return true;
            //     return false;
            // }
        }
        if( (k==m && (i>=n || (i<n && s1[i]==' ')) ) || ( l<0 && (j<0 || (j>=0 && s1[j]==' ')) )) return true;
        if(k==m || l<0) return false;
        // cout<<p1<<" "<<p2;
        return p1==p2 && s2[p1]==' ';
    }
};