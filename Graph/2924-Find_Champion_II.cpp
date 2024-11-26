class Solution {
public:
    int findChampion(int n,vector<vector<int>> &edges) 
    {
        bitset<100> b;
        for(auto &i:edges)
        {
            b.set(i[1]);
        }
        int c=-1;
        for(int i=0;i<n;i++)
        {
            if(b[i]==0)
            {
                if(c!=-1)
                {
                    return -1;
                }
                c=i;
            }
        }
        return c;
    }
};
