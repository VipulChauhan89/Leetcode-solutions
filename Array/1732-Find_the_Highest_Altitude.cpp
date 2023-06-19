class Solution {
public:
    int largestAltitude(vector<int> &gain) 
    {
        int mx=0,cur=0;
        for(int i=0;i<gain.size();i++)
        {
            cur+=gain[i];
            mx=max(mx,cur);
        }
        return mx;
    }
};
