class MyCalendarTwo {
public:
    map<int,int> m;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) 
    {
        m[start]++;
        m[end]--;
        int activeBookings=0;
        for(auto &i:m) 
        {
            activeBookings+=i.second;
            if(activeBookings>=3) 
            {
                m[start]--;
                m[end]++;
                if(m[start]==0) 
                {
                    m.erase(start);
                }
                if(m[end]==0) 
                {
                    m.erase(end);
                }
                return false;
            }
            if(i.first>end)
            {
                break;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
