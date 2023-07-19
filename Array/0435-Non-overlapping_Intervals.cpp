class Solution {
public:
    static const bool comp(const vector<int> &a,const vector<int> &b)
    {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(),intervals.end(),comp);
        int remove=0,end=INT_MIN;
        for(auto &i:intervals)
        {
            if(i[0]>=end)
            {
                end=i[1];
            }
            else
            {
                remove++;
            }
        }
        return remove;
    }
};
