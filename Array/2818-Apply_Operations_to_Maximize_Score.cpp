class Solution {
public:
    int PrimeFactorsCount(int n)
    {
        int num=0;
        if(n==1)
        {
            return 0;
        }
        if(n%2==0)
        {
            num++;
            while(n%2==0)
            {
                n/=2;
            }
        }
        for(int i=3;i*i<=n;i+=2)
        {
            if (n % i == 0)
            {
                num++;
                while(n%i==0)
                {
                    n/=i;
                }
            }
        }
        if(n>2)
        {
            num++;
        }
        return num;
    }
    int power(long long x,unsigned int y,int p=1e9+7)
    {
        int ans=1;
        x=x%p;
        if(x==0)
        {
            return 0;
        }
        while(y>0)
        {
            if(y&1)
            {
                ans=(ans*x)%p;
            }
            y=y>>1;
            x=(x*x)%p;
        }
        return ans;
    }
    int maximumScore(vector<int> &nums,int k) 
    {
        int n=nums.size(),mod=1e9+7;
        long long ans=1;
        vector<int> v(n),left(n,1),right(n,1);;
        stack<int> st,s;
        priority_queue<pair<int,int>> pq;
        st.push(0);
        for(int i=0;i<n;i++)
        {
            v[i]=PrimeFactorsCount(nums[i]);
        }
        for(int i=1;i<n;i++)
        {
            while(!st.empty() && v[i]>v[st.top()])
            {
                st.pop();
            } 
            if(st.empty())
            {
                left[i]=i+1;
            } 
            else
            {
                left[i]=i-st.top();
            }
            st.push(i);
        }
        st=s;
        st.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && v[i]>=v[st.top()])
            {
                st.pop();
            } 
            if(st.empty())
            {
                right[i]=n-i;
            } 
            else
            {
                right[i]=st.top()-i;
            } 
            st.push(i);
        }
        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i],i});            
        }
        while(!pq.empty())
        {
            auto it=pq.top();
            int x=it.second,y=it.first;
            long long t=(long long)(left[x])*(right[x]);
            int p=(int)min(t,(long long)k);
            k-=p;
            ans=(1ll*ans*power(y,p))%mod;
            ans%=mod;
            if(k<=0)
            {
                break;
            }
            pq.pop();
        }
        return ans;
    }
};
