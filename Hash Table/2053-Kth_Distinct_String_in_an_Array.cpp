class Solution {
public:
    string kthDistinct(vector<string> &arr,int k) 
    {
        string ans="";
        unordered_map<string,int> m;
        for(auto i:arr)
        {
            m[i]++;
        }
        for(auto i:arr)
        {
            if(m[i]==1)
            {
                k--;
                ans=i;
                if(k==0)
                {
                    break;
                }
            }
        }
        return ((k>=m.size() || k>0)?"":ans);
    }
};
