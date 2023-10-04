class MyHashMap {
public:
    vector<pair<int,int>> m;
    MyHashMap() 
    {
        
    }
    
    void put(int key, int value) 
    {
        for(auto &i:m)
        {
            if(i.first==key)
            {
                i.second=value;
                return;
            }
        }
        m.push_back({key,value});
    }
    
    int get(int key) 
    {
        for(auto &i:m)
        {
            if(i.first==key)
            {
                return i.second;
            }
        }
        return -1;
    }
    
    void remove(int key) 
    {
        for(auto i=m.begin();i!=m.end();i++)
        {
            if(i->first==key)
            {
                m.erase(i);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
