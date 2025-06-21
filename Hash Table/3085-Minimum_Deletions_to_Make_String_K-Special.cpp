class Solution {
public:
    int minimumDeletions(string word,int k) 
    {
        unordered_map<char,int> m;
        vector<int> v;
        for(auto &i:word)
        {   
            m[i]++;
        }
        for(auto &i:m)
        {
            v.push_back(i.second);
        }
        sort(begin(v),end(v));
        int n=v.size(),ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int range=v[i]+k,total=v[i];
            for(int j=i+1;j<n;j++)
            {
                if(v[j]>range)
                { 
                    total+=range; 
                }
                else
                {
                    total+=v[j];
                }
            }
            int remain=word.size()-total;
            ans=min(ans,remain);
        }
        return ans;
    }
};
