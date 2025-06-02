class Solution {
public:
    int candy(vector<int> &ratings) 
    {
        int n=ratings.size(),count=0;
        vector<int> c(n,1);
        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                c[i]=c[i-1]+1;
            }
        }
        for(int i=n-1;i>0;i--)
        {
            if(ratings[i-1]>ratings[i])
            {
                c[i-1]=max(c[i]+1,c[i-1]);
            }
            count+=c[i-1];
        }
        count+=c[n-1];
        return count;
    }
};
