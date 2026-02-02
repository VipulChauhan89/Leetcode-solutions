class Solution {
public:
    long long minimumCost(vector<int> &nums,int k,int dist)
    {
        int n=nums.size();
        set<pair<int,int>> st;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        long long sum=nums[0],minSum=LLONG_MAX;
        for(int i=0;i<=dist;i++)
        {
            pq.push({nums[i+1],i+1});
        }
        for(int i=0;i<k-1;i++)
        {
            st.insert(pq.top());
            sum+=1ll*(pq.top().first);
            pq.pop();
        }
        minSum=min(minSum,sum);
        int start=1,end=dist+1;
        while(end+1<n)
        {
            pq.push({nums[end+1],end+1});
            pair<int,int> remove={nums[start], start};
            if(st.find(remove)!=st.end())
            {
                sum-=remove.first;
                st.erase(remove);
            }
            while(pq.top().second<=start)
            {
                pq.pop();
            } 
            pair<int,int> top=pq.top();
            st.insert(top);
            sum+=1ll*(top.first);
            pq.pop();
            while(st.size()>k-1)
            {
                auto it=st.rbegin();
                int idx=it->second,num=it->first;
                sum-=num;
                pq.push({it->first,it->second});
                st.erase({it->first,it->second});
            }
            minSum=min(minSum,sum);
            start++;
            end++;
        }
        return minSum;
    }
};
