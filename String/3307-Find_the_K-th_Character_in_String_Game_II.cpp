class Solution {
public:
    char kthCharacter(long long k,vector<int> &operations)
    {
        int shift=0;
        vector<long long> v;
        long long len=1;
        for(auto  &i:operations)
        {
            len*=2;
            v.push_back(len);
            if(len>=k)
            {
                break;
            }
        }
        for(int i=v.size()-1;i>=0;i--)
        {
            long long half=v[i]/2;
            int op=operations[i];
            if(k>half)
            {
                k-=half;
                if(op==1)
                {
                    shift++;
                }
            }
        }
        return (char)((('a'-'a'+shift)%26)+'a');
    }
};
