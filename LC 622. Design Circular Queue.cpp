class MyCircularQueue {
public:
    int size, capacity, fp;
    vector<int> v;
    
    MyCircularQueue(int k) {
        this->capacity = k;
        this->fp = 0;
        this->size = 0;
    }
    
    bool enQueue(int value) {
        if(this->size < this->capacity){
            this->size++;
            this->v.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(this->size == 0){
            return false;
        }
        this->size--;
        fp++;
        return true;
    }
    
    int Front() {
        if(this->size == 0){
            return -1;
        }
        return v[fp];
    }
    
    int Rear() {
        if(this->size == 0){
            return -1;
        }
        return v[v.size()-1];
    }
    
    bool isEmpty() {
        return this->size == 0;
    }
    
    bool isFull() {
        return this->size == this->capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
