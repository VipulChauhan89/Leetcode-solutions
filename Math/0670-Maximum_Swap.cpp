class Solution {
public:
    int maximumSwap(int num) 
    {
        string s=to_string(num);
        int n=s.size();
        vector<int> l(10,-1);
        for(int i=0;i<n;i++)
        {
            l[s[i]-'0']=i;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=9;j>s[i]-'0';j--)
            {
                if(l[j]>i)
                {
                    swap(s[i],s[l[j]]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};
