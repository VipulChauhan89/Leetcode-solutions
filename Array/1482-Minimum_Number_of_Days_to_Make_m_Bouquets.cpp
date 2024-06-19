class Solution {
public:
    bool canMake(vector<int> &bloomDay,int m,int k,int day)
    {
        int total=0,n=bloomDay.size();
        for(int i=0;i<n;i++)
        {
            int count=0;
            while(i<n && count<k && bloomDay[i]<=day)
            {
                count++;
                i++;
            }
            if(count==k)
            {
                total++;
                i--;
            }
            if(total>=m)
            {
                return true;
            }
        }
        return false;
    }
    int minDays(vector<int> &bloomDay,int m,int k) 
    {
        if((long long)m*k>bloomDay.size())
        {
            return -1;
        }
        int l=1,h=1e9;
        while(l<h)
        {
            int mid=l+(h-l)/2;
            if(canMake(bloomDay,m,k,mid))
            {
                h=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
    }
};
