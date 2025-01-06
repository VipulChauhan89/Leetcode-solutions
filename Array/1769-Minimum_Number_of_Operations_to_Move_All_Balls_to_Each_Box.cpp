class Solution {
public:
    vector<int> minOperations(string boxes) 
    {
        int n=boxes.size();
        vector<int> l(n,0),r(n,0),ans(n);
        int c1=(boxes[0]=='1'?1:0),c2=(boxes[n-1]=='1'?1:0);
        for(int i=1;i<n;i++)
        {
            l[i]=l[i-1]+c1;
            c1+=(boxes[i]=='1'?1:0);
            r[n-i-1]=r[n-i]+c2;
            c2+=(boxes[n-i-1]=='1'?1:0);
        }
        for(int i=0;i<n;i++)
        {
            ans[i]=l[i]+r[i];
        }
        return ans;
    }
};
