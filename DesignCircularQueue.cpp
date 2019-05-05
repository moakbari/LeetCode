class MyCircularQueue {
    int frontIndex;
    int rearIndex;
    int capacity;
    vector<int> circularBuffer;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) 
    :frontIndex(0)
    ,rearIndex(0)
    ,capacity(k + 1)
    ,circularBuffer(capacity, 0)
    {}   
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        
        circularBuffer[rearIndex] = value;
        rearIndex =  (rearIndex + 1) % capacity;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        
        frontIndex = (frontIndex + 1) % capacity;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()){
            return -1;
        }
        
        return circularBuffer[frontIndex];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()){
            return -1;
        }
        int index = rearIndex == 0 ? capacity - 1 : rearIndex - 1;
        return circularBuffer[index];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return frontIndex == rearIndex;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return ((rearIndex + 1) % capacity) == frontIndex;
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
