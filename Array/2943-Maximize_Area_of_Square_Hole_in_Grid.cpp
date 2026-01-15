class Solution {
public:
    int maximizeSquareHoleArea(int n,int m,vector<int> &hBars,vector<int> &vBars)
    {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int maxiH=1,maxiV=1,maxi=1;
        for(int i=1;i<hBars.size();i++)
        {
            if(hBars[i]==hBars[i-1]+1)
            {
                maxi++;
            }
            else
            {
                maxiH=max(maxiH,maxi);
                maxi=1;
            }
        }
        maxiH=max(maxiH,maxi);
        maxi=1;
        for(int i=1;i<vBars.size();i++)
        {
            if(vBars[i]==vBars[i-1]+1)
            {
                maxi++;
            }
            else
            {
                maxiV=max(maxiV,maxi);
                maxi=1;
            }
        }
        maxiV=max(maxiV,maxi);
        int side=min(maxiH+1,maxiV+1);
        return side*side;
    }
};
