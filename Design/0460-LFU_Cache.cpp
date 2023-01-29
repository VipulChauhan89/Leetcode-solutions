class LFUCache {
    unordered_map<int,pair<int,int>> m1;
    unordered_map<int,list<int>> m2;
    unordered_map<int,list<int>::iterator> m3;
    int capacity,minFreq;
public:
    LFUCache(int capacity) 
    {
        this->capacity=capacity;
        minFreq=0;
    }
    
    int get(int key) 
    {
        if(m1.find(key)==m1.end())
        {
            return -1;
        }
        m2[m1[key].second].erase(m3[key]);
        m1[key].second++;
        m2[m1[key].second].push_back(key);
        m3[key]=--m2[m1[key].second].end();
        if(m2[minFreq].empty())
        {
            minFreq++;
        }
        return m1[key].first;
    }
    
    void put(int key,int value) 
    {
        if(!capacity)
        {
            return;
        }
        if(m1.find(key)!=m1.end()) 
        {
            m1[key].first=value;
            m2[m1[key].second].erase(m3[key]);
            m1[key].second++;
            m2[m1[key].second].push_back(key);
            m3[key]=--m2[m1[key].second].end();
            if(m2[minFreq].empty())
            {
                minFreq++;
            }
            return;
        }
        if(m1.size()==capacity) 
        {
            int delKey=m2[minFreq].front();
            m1.erase(delKey);
            m3.erase(delKey);
            m2[minFreq].pop_front();
        }
        m1[key]={value,1};
        m2[1].push_back(key);
        m3[key] = --m2[1].end();
        minFreq = 1;
    }
};



/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
