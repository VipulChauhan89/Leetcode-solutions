class Solution {
public:
    int getLastMoment(int n,vector<int> &left,vector<int> &right) 
    {
        int time=0;
        for(auto i:left)
        {
            time=max(time,i);
        }
        for(auto i:right)
        {
            time=max(time,n-i);
        }
        return time;
    }
};
