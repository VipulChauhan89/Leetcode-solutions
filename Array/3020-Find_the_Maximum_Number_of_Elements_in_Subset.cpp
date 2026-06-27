class Solution {
public:
    int maximumLength(vector<int> &nums)
    {
        unordered_map<long long,int> freq;
        for(int x:nums)
        {
            freq[x]++;
        }
        int ans=1;
        if(freq.count(1))
        {
            int count=freq[1];
            ans=max(ans,(count%2==1)?count:count-1);
        }
        for(auto &[start,count]:freq)
        {
            if(start==1)
            {
                continue;
            }
            long long cur=start;
            int len=0;
            while(freq.count(cur))
            {
                if(freq[cur]>=2)
                {
                    len+=2;

                    cur=cur*cur;
                }
                else
                {
                    len++;
                    break;
                }
            }
            if(len%2==0)
            {
                len--;
            }
            ans=max(ans,len);
        }
        return ans;
    }
};
