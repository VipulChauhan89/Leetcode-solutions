class KthLargest {
public:
    int size;
    priority_queue<int,vector<int>,greater<int>> p;
    KthLargest(int k,vector<int> &nums) 
    {
        size=k;
        for(auto i:nums)
        {
            p.push(i);
        }
    }
    
    int add(int val) 
    {
        p.push(val);
        while(size<p.size())
        {
            p.pop();
        }
        return p.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
