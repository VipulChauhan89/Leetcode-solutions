class Solution {
public:
    long long largestSquareArea(vector<vector<int>> &bottomLeft,vector<vector<int>> &topRight)
    {
        int n=bottomLeft.size();
        long long maxSide=0;
        for(int i=0;i<n-1;i++)
        {
            int a=bottomLeft[i][0],b=bottomLeft[i][1],c=topRight[i][0],d=topRight[i][1];
            for(int j=i+1;j<n;j++)
            {
                int aj=bottomLeft[j][0],bj=bottomLeft[j][1],cj=topRight[j][0],dj=topRight[j][1];
                long long width=min(cj,c)-max(aj,a),height=min(dj,d)-max(bj,b),s=min(width,height);
                if(s>maxSide)
                {
                    maxSide=s;
                }
            }
        }
        return maxSide*maxSide;
    }
};
