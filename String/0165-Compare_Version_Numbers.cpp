class Solution {
public:
    int compareVersion(string version1,string version2) 
    {
        int n1=version1.size(),n2=version2.size(),x1=0,x2=0;
        for(int i=0,j=0;i<n1 || j<n2;i++,j++)
        {
            while(i<n1 && version1[i]!='.')
            {
                x1=10*x1+(version1[i++]-'0');
            }
            while(j<n2 && version2[j]!='.')
            {
                x2=10*x2+(version2[j++]-'0');
            }
            if(x1<x2)
            {
                return -1;
            }
            else if(x1>x2)
            {
                return 1;
            }
            x1=0;
            x2=0;
        }
        return 0;
    }
};
