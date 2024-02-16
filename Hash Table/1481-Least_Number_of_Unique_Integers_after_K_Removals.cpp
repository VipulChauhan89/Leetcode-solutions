class Solution {
public:
    static bool comp(auto &a,auto &b)
    {
        return a.second>b.second;
    }
    int findLeastNumOfUniqueInts(vector<int> &arr,int k) 
    {
        unordered_map<int,int> m;
        for(auto i:arr)
        {
            m[i]++;
        }    
        vector<pair<int,int>> v;
        for(auto i:m)
        {
            v.push_back({i.second,i.first});
        }
        sort(v.begin(),v.end());
        int ans=v.size(),i=0;
        while(k>0)
        {
            while(v[i].first>0 && k>0)
            {
                v[i].first--;
                k--;
            }
            if(v[i].first==0)
            {
                i++;
                ans--;
            }
        }
        return ans;
    }
};
