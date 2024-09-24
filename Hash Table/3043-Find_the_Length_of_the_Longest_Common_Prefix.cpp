class Solution {
public:
    int longestCommonPrefix(vector<int> &arr1,vector<int> &arr2) 
    {
        unordered_map<int,int> m;
        for(auto i:arr1)
        {
            while(i>0)
            {
                m[i]++;
                i/=10;
            }
        }
        int mx=INT_MIN;
        for(auto i:arr2)
        {
            int len=log10(i)+1;
            while(i>0)
            {
                if(m.find(i)!=m.end())
                {
                    break;
                }
                i/=10;
                len--;
            }
            mx=max(mx,len);
        }
        return mx;
    }
};
