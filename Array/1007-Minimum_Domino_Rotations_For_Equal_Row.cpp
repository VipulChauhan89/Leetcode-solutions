class Solution {
public:
    int minDominoRotations(vector<int> &tops,vector<int> &bottoms) 
    {
        int n=tops.size(),ans=INT_MAX;
        for(int i=1;i<=6;i++)
        {
            int top=0,bottom=0;
            bool valid=true;
            for(int j=0;j<n;j++)
            {
                if(tops[j]!=i && bottoms[j]!=i)
                {
                    valid=false;
                    break;
                }
                if(tops[j]!=i)
                {
                    top++;
                }
                if(bottoms[j]!=i)
                {
                    bottom++;
                }
            }
            if(valid)
            {
                ans=min(ans,min(top,bottom));
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};
