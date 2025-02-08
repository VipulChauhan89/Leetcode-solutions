class NumberContainers {
public:
    unordered_map<int,priority_queue<int,vector<int>,greater<long>>> m;
    unordered_map<int,int> idx;
    NumberContainers() {}
    void change(int index,int number) 
    {
        idx[index]=number;
        m[number].push(index);
    }
    int find(int number) 
    {
        while(!m[number].empty())
        {
            int mnIndex=m[number].top();
            if(idx[mnIndex]==number)
            {
                return mnIndex;
            }
            m[number].pop();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
