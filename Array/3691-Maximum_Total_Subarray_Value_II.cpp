class Solution {
public:
    int size;
    vector<int> seg_max,seg_min;
    pair<int,int> query(int l,int r)
    {
        int mx=INT_MIN,mn=INT_MAX;
        for(l+=size,r+=size;l<=r;l/=2,r/=2)
        {
            if(l%2==1)
            {
                mx=max(mx,seg_max[l]);
                mn=min(mn,seg_min[l]);
                l++;
            }
            if(r%2==0)
            {
                mx=max(mx,seg_max[r]);
                mn=min(mn,seg_min[r]);
                r--;
            }
        }
        return {mx,mn};
    }
    long long maxTotalValue(vector<int> &nums,int k)
    {
        int n=nums.size();
        size=1;
        while(size<n)
        {
            size*=2;
        }
        seg_max.assign(2*size,INT_MIN);
        seg_min.assign(2*size,INT_MAX);
        for (int i=0;i<n;i++)
        {
            seg_max[size+i]=seg_min[size+i]=nums[i];
        }
        for(int i=size-1;i>0;i--)
        {
            seg_max[i]=max(seg_max[2*i],seg_max[2*i+1]);
            seg_min[i]=min(seg_min[2*i],seg_min[2*i+1]);
        }
        priority_queue<pair<int,pair<int,int>>> heap;
        for(int l=0;l<n;l++)
        {
            auto res=query(l,n-1);
            heap.push({res.first-res.second,{l,n-1}});
        }
        long long ans=0;
        while(k-- && !heap.empty())
        {
            auto top=heap.top();
            heap.pop();
            ans+=top.first;
            int l=top.second.first,r=top.second.second;
            if(r>l)
            {
                auto res=query(l,r-1);
                heap.push({res.first-res.second,{l,r-1}});
            }
        }
        return ans;
    }
};
