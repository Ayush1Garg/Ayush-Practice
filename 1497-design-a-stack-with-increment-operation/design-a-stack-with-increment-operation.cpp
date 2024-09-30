static const int speedup = []{ios::sync_with_stdio(0); cin.tie(0); return 0;}();
class CustomStack {
    vector<int> st;
    int top;
public:
    CustomStack(int maxSize) {
        st.resize(maxSize);
        top = -1;
    }
    
    void push(int x) {
        if(top==st.size()-1) return;
        st[++top] = x;
    }
    
    int pop() {
        return (top==-1 ? -1 : st[top--]);
    }
    
    void increment(int k, int val) {
        k = min(k,top+1);
        for(int i=0; i<k; i++) st[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */