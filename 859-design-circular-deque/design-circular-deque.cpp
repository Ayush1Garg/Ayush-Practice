class MyCircularDeque {
    vector<int> v;
    int front, back, size, capacity;
public:
    MyCircularDeque(int k) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        v = vector<int> (k,-1);
        front = 0; back = 0; size = 0; capacity = k;
    }
    
    bool insertFront(int value) {
        if(size==capacity) return false;
        front--;
        if(front==-1) front = capacity-1;
        v[front] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(size==capacity) return false;
        v[back] = value;
        back++;
        if(back==capacity) back = 0;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(size==0) return false;
        v[front] = -1;
        front++;
        if(front==capacity) front = 0;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(size==0) return false;
        back--;
        if(back==-1) back = capacity-1;
        v[back] = -1;
        size--;
        return true;
    }
    
    int getFront() {
        if(size==0) return -1;
        return v[front];
    }
    
    int getRear() {
        if(size==0) return -1;
        if(back==0) return v[capacity-1];
        return v[back-1];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */