class Solution {
public:
    bool can(vector<long long> &a,int k,long long d)
    {
        int n=a.size();
        vector<long long> b=a;
        for(auto x:a)
        {
            b.push_back(x+a.back());
        }
        for(int i=0;i<n;i++)
        {
            int count=1;
            long long last=b[i];
            for(int j=i+1;j<i+n;j++)
            {
                if(b[j]-last>=d)
                {
                    count++;
                    last=b[j];
                }
                if(count>=k)
                {
                    return true;
                }
            }
        }
        return false;
    }
    int maxDistance(int side,vector<vector<int>> &points,int k)
    {
        vector<long long> a;
        for(auto &p:points)
        {
            int x=p[0],y=p[1];
            if(y==0)
            {
                a.push_back(x);
            }
            else if(x==side)
            {
                a.push_back(side+y);
            }
            else if(y==side)
            {
                a.push_back(2LL*side+(side-x));
            }
            else
            {
                a.push_back(3LL*side+(side-y));
            }
        }
        sort(a.begin(),a.end());
        long long low=0,high=4LL*side,ans=0;
        while(low<=high)
        {
            long long mid=(low+high)/2;
            if(can(a,k,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};
