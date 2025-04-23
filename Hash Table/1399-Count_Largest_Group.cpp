class Solution {
public:
    int countLargestGroup(int n) 
    {
        unordered_map<int,int> count;
        int mxCount=0,mxFrequency=0;
        for(int i=1;i<=n;i++)
        {
            int sum=0,key=i;
            while(key>0)
            {
                sum+=key%10;
                key/=10;
            }
            count[sum]++;
            mxCount=max(mxCount,count[sum]);
        }    
        for(auto &i:count)
        {
            if(i.second==mxCount)
            {
                mxFrequency++;
            }
        }
        return mxFrequency;
    }
};
