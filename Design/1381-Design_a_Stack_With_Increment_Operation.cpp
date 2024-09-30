class CustomStack {
public:
    vector<int> st;
    int top;
    CustomStack(int maxSize) 
    {
        st.resize(maxSize);
        top=-1;
    }
    void push(int x) 
    {
        if(top==-1 || top<st.size()-1)
        {
            top++;
            st[top]=x;
        }
    }
    int pop() 
    {
        if(top!=-1)
        {
            return st[top--];
        }
        return -1;
    }
    void increment(int k,int val) 
    {
        for(int i=0;i<min(k,top+1);i++)
        {
            st[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
