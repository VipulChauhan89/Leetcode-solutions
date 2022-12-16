class MyQueue {
public:
    stack<int> s, temp;
    MyQueue() 
    {
        
    }
    void push(int x) 
    {
        while(!s.empty())
        {
            temp.push(s.top());
            s.pop();
        }
        temp.push(x);
        while(!temp.empty())
        {
            s.push(temp.top());
            temp.pop();
        }
    }
    int pop() 
    {
        int t = s.top();
        s.pop();
        return t;
    }
    int peek() 
    {
        return s.top();
    }
    bool empty() 
    {
        return (s.empty());
    }
};
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
