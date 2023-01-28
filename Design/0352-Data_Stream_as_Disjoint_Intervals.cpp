class SummaryRanges {
public:
    set<int> data_stream;
    SummaryRanges() 
    {
        
    }
    
    void addNum(int value) 
    {
        data_stream.insert(value);
    }
    
    vector<vector<int>> getIntervals() 
    {
        vector<vector<int>> ans;
        int start=-1,end=-1;
        for(auto &i:data_stream)
        {
            if(start==-1)
            {
                start=i;
                end=i;
            }
            else if(i==end+1)
            {
                end=i;
            }
            else
            {
                ans.push_back({start,end});
                start=end=i;
            }
        }
        if(start!=-1)
        {
            ans.push_back({start,end});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
