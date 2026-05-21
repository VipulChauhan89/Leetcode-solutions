class Solution {
public:
    int digits(int x)
    {
        int count=0;
        while(x>0)
        {
            count++;
            x/=10;
        }
        return count;
    }
    int longestCommonPrefix(vector<int> &arr1,vector<int> &arr2)
    {
        unordered_set<int> prefixes;
        for(int num:arr1)
        {
            int x=num;
            while(x>0)
            {
                prefixes.insert(x);
                x/=10;
            }
        }
        int ans=0;
        for(int num:arr2)
        {
            int x=num,len=digits(num);
            while(x>0)
            {
                if(prefixes.count(x))
                {
                    ans=max(ans,len);
                    break;
                }
                x/=10;
                len--;
            }
        }
        return ans;
    }
};
