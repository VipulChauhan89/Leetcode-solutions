class MyCircularDeque {
public:
    vector<int> v;
    int front,back,sizee,capacity;
    MyCircularDeque(int k) 
    {
        v=vector<int>(k,-1);
        front=0;
        back=0;
        sizee=0;
        capacity=k;
    }
    bool insertFront(int value) 
    {
        if(isFull()) 
        {
            return false;
        }
        if(front==0) 
        {
            front=capacity-1;
        } 
        else 
        {
            front--;
        }
        v[front]=value;
        sizee++;
        return true;
    }
    bool insertLast(int value) 
    {
        if(isFull()) 
        {
            return false;
        }
        v[back]=value;
        if(back==capacity-1) 
        {
            back=0;
        } 
        else 
        {
            back++;
        }
        sizee++;
        return true;
    }
    bool deleteFront() 
    {
        if(isEmpty()) 
        {
            return false;
        }
        v[front]=-1;
        if(front==capacity-1) 
        {
            front=0;
        } 
        else 
        {
            front++;
        }
        sizee--;
        return true;
    }
    bool deleteLast() 
    {
        if(isEmpty()) 
        {
            return false;
        }
        if(back==0) 
        {
            back=capacity-1;
        } 
        else 
        {
            back--;
        }
        v[back]=-1;
        sizee--;
        return true;
    }
    int getFront() 
    {
        if(isEmpty())
        {
            return -1;
        }
        return v[front];
    }
    
    int getRear() 
    {
        if(isEmpty())
        {
            return -1;
        } 
        if(back==0) 
        {
            return v[capacity-1];
        } 
        else 
        {
            return v[back-1];
        }
    }
    bool isEmpty() 
    {
        return sizee==0;
    }
    
    bool isFull() 
    {
        return sizee==capacity;
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
