class MyCircularDeque {
private: 
    queue<int>q;
    int maxSizeofQ;
    int rear;
public:
    MyCircularDeque(int k) {
        maxSizeofQ=k;
    }
    
    bool insertFront(int value) {
        // not allowed to be insert anything,it's already full
        if(isFull()) return false;

        // otherwise,let's do the process
        queue<int>temp=q;
        // clearing q,while copying it to temp
        while(!q.empty()) q.pop();
        // now push first value
        q.push(value);
        // now push everything back to q
        while(!temp.empty()){
            q.push(temp.front());
            temp.pop();
        }
        return true;

    }
    
    bool insertLast(int value) {
        
        if(isFull()) return false;
        
        q.push(value);
        return true;
    }
    
    bool deleteFront() {
        // early
        if(isEmpty()) return false;
        q.pop();
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        queue<int>temp;
        while(q.size() > 1){
            temp.push(q.front());
            q.pop();
        }
        q.pop();
        q=temp;
        return true;  
    }
    
    int getFront() {
        return q.size() > 0 ? q.front() : -1;
    }
    
    int getRear() {
        return q.size() > 0 ? q.back() : -1;
    }
    
    bool isEmpty() {
        return q.size()==0;
    }
    
    bool isFull() {
        return q.size() == maxSizeofQ;
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