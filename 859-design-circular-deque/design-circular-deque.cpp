class MyCircularDeque {
public:
deque<int>q;
int size;
    MyCircularDeque(int k) {
        size=k;
    }
    
    bool insertFront(int value) {
        if(q.size()<size)
        {
            q.push_front(value);
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
         if(q.size()<size)
        {
            q.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
       if(q.empty())
       {
        return false;
       } 
       q.pop_front();
       return true;
    }
    
    bool deleteLast() {
if(q.empty())
       {
        return false;
       } 
       q.pop_back();
       return true;
    }
    
    int getFront() {
        if(!q.empty())
        {
            return q.front();
        }
        return -1;
    }
    
    int getRear() {
        if(!q.empty())
        {
            return q.back();
        }
        return -1;
    }
    
    bool isEmpty() {
        if(q.empty())
        {
            return true;
        }return false;
    }
    
    bool isFull() {
        if(q.size()==size)
        {
            return true;
        }
        return false;
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