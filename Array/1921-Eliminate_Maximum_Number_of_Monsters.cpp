class Solution {
public:
    int eliminateMaximum(vector<int> &dist,vector<int> &speed) 
    {
        int n=dist.size(),j=0;
        for(int i=0;i<n;i++)
        {
            dist[i]=ceil(dist[i]/(double)speed[i]);
        }  
        sort(dist.begin(),dist.end());
        for(int i=0;i<n;i++)
        {
            if(j>=dist[i])
            {
                return j;
            }
            j++;
        }
        return n;
    }
};
