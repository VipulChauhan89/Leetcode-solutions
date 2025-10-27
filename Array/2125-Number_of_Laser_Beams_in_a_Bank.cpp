class Solution {
public:
    int numberOfBeams(vector<string> &bank)
    {
        int ans=0,prev=0;
        for(auto &i:bank)
        {
            int device=count(i.begin(),i.end(),'1');
            if(device>0)
            {
                ans+=device*prev;
                prev=device;
            }
        }
        return ans;
    }
};
