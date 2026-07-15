class MyCircularQueue {
public:
        int* arr;
        int f;
        int r;
        int capacity;
        int size;

    MyCircularQueue(int k) {
        capacity=k; 
        size = 0;
        arr=new int[k];
        f=0;
        r=-1;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        else{
            r=(r+1)%capacity;
            arr[r]=value;
            size++;
            return true;
        }
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        
        f=(f+1)%capacity;
        size--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        else{
            return arr[f];
        }
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        else{
            return arr[r];
        }
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==capacity;
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