class MyCalendar {
public:
    map<int,int> m;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto next=m.lower_bound(start);
        return (((next!=m.end() && next->first<end) || (next!=m.begin() && prev(next)->second>start))?false:(m[start]=end,true));
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
