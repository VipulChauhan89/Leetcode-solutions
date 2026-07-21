class Solution {
public:
    int maxActiveSectionsAfterTrade(string s)
    {
        int n=s.size();
        int count=0,len=0,j=0,B[2]={0},adj2=0;
        char prev='@';
        for(char c:s)
        {
            count+=c=='1';
            if((prev!=c) & (c=='0'))
            {
                B[++j&1]=0; 
            }
            B[j&1]+=c=='0';
            if((prev!=c) & (c=='1'))
            {
                adj2=max(adj2,B[0]+B[1]);
            }
            prev=c;
        }
        adj2=max(adj2,B[0]+B[1]);
        return (j<2)?count:count+adj2;
    }
};
